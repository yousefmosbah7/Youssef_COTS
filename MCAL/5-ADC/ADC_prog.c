#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "ADC_interface.h"
#include "ADC_reg.h"

static uint16* ADC_pu16ConversionResult = NULL;
static void(*ADC_puNotification)(void) = NULL;
static uint8 ADC_u8BusyFlag = IDEAL;
static Chaining_t* ADC_pstChainData = NULL;
uint8 Conv_Num;
uint8 Choice=0;


void ADC_voidInit(void)
{
	/*voltage reference selection*/
#if ADC_u8REF_VOLT == AVCC_REF
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_u8REF_VOLT == AREF_REF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_u8REF_VOLT == INTERNAL_2560mV_REF
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
#error Wrong ADC_REF voltage configuration option
#endif

	/*prepare left adjust for 8bits mode*/
#if ADC_u8RESOLUTION == EIGHT_BITS
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_u8RESOLUTION == TEN_BITS
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error Wrong ADC resolution configuration option
#endif

	/*Auto trigger Disable*/
#if ADC_u8AUTO_TRIGGER == ENABLE
	SET_BIT(ADCSRA,ADCSRA_ADATE);
#elif ADC_u8AUTO_TRIGGER == DISABLE
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
#else
#error wrong ADC autotrigger configuration option
#endif

	/*Interrupt Disabled*/
#if ADC_u8INT_ENABLE == ENABLE
	SET_BIT(ADCSRA,ADCSRA_ADIE);
#elif ADC_u8INT_ENABLE == DISABLED
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
#else
#error wrong ADC interrupt enable configuration option
#endif

	/*prescalar settings (/128) the slowest*/
	ADCSRA &= PRESCALAR_MASK;
	ADCSRA |= ADC_u8PRESCALAR_VALUE;

	/*enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

uint8 ADC_u8StartConversionSynch(uint8 Copy_u8_Channel ,uint16* Copy_pu16Result)
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pu16Result != NULL)
	{
	/*check if ADC is not busy*/
	if(ADC_u8BusyFlag == IDEAL)
	{
		uint32 Local_u32TimeoutCounter=0;

		/*make it busy*/
		ADC_u8BusyFlag = BUSY;

	/*set the required channel*/
	ADMUX &= CHANNEL_MASK;
	ADMUX |= Copy_u8_Channel;

	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*Polling for ADC conversion complete or the timeout is passed*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0)&&(Local_u32TimeoutCounter<ADC_u32TIMEOUT))
	{
		Local_u32TimeoutCounter++;
	}
	if(Local_u32TimeoutCounter >=  ADC_u32TIMEOUT)
	{
			Local_u8ErrorState = TIMEOUT_ERR;
	}
	else
	{
		/*Loop is broken because flag is raised before the timeout*/
		/*Clear flag*/
		SET_BIT(ADCSRA,ADCSRA_ADIF);

		/*Read data*/
	#if ADC_u8RESOLUTION == EIGHT_BITS
		*Copy_pu16Result = ADCH;
	#elif ADC_u8RESOLUTION == TEN_BITS
		*Copy_pu16Result = ADC;
	#endif
		/*ADC flag is now available*/
	ADC_u8BusyFlag = IDEAL;
	}
	}
	else
	{
		/*ADC was busy*/
		Local_u8ErrorState = BUSY_STATE_ERR;
	}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}
uint8 ADC_u8StartConversionAsynch(uint8 Copy_u8Channel, uint16* Copy_u16Result, void(*Copy_puNotificationFunc)(void))
{
	uint8 Local_u8ErrorState = OK;

	if((Copy_u16Result != NULL)&&(Copy_puNotificationFunc != NULL))
	{
		if(ADC_u8BusyFlag == IDEAL)
		{
			/*make it busy*/
			ADC_u8BusyFlag = BUSY;
			Choice=SINGLE_CONVERSION_ASYNCH;

		/*initialize the result pointer globally*/
		ADC_pu16ConversionResult = Copy_u16Result;

		/*initialize the notification function globally*/
		ADC_puNotification = Copy_puNotificationFunc;

		/*set the required channel*/
			ADMUX &= CHANNEL_MASK;
			ADMUX |= Copy_u8Channel;

		/*start conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*Enable ADC conversion complete interrupt*/
		SET_BIT(ADCSRA,ADCSRA_ADIE);

	}
	else
	{
		/*ADC was busy*/
		Local_u8ErrorState = BUSY_STATE_ERR;
	}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

uint8 ADC_u8StartChainConversionAsynch(Chaining_t *Chaining_Obj)
{
	uint8 Local_u8ErrorState = OK;
	if((Chaining_Obj != NULL)&&(Chaining_Obj->ChannelArr != NULL)&&(Chaining_Obj->ResultArr != NULL)&&(Chaining_Obj->Copy_puNotificationFunc != NULL))
	{
	if(ADC_u8BusyFlag == IDEAL)
	{
		ADC_u8BusyFlag = BUSY;
		Choice=CHAIN_CONVERSION_ASYNCH;

		ADC_pstChainData = Chaining_Obj;
		Conv_Num=0;

		ADMUX &= CHANNEL_MASK;
		ADMUX |= ADC_pstChainData->ChannelArr[Conv_Num];
		/*start conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);
		/*Enable ADC conversion complete interrupt*/
		SET_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else
	{
		Local_u8ErrorState = BUSY_STATE_ERR;
	}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

/**
 * @brief ADC conversion complete ISR
 * */


void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if(Choice==CHAIN_CONVERSION_ASYNCH)
	{
		/*Read data*/
		#if ADC_u8RESOLUTION == EIGHT_BITS
		ADC_pstChainData->ResultArr[Conv_Num] = ADCH;
		#elif ADC_u8RESOLUTION == TEN_BITS
		Results_Ptr[Conv_Num]= ADC;
		#endif
		Conv_Num++;
		if(Conv_Num < ADC_pstChainData->ChainSize)
		{
			ADMUX &= CHANNEL_MASK;
			ADMUX |= ADC_pstChainData->ChannelArr[Conv_Num];
			/*start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
		else
		{
			/*Disable ADC conversion complete interrupt*/
			CLR_BIT(ADCSRA,ADCSRA_ADIE);

			/*ADC flag is now available*/
			ADC_u8BusyFlag = IDEAL;

			/*Invoke the application notification function*/
			if(ADC_pstChainData->Copy_puNotificationFunc != NULL)
			{
				ADC_pstChainData->Copy_puNotificationFunc();
			}
			else
			{
				/*notification function pointer is null*/
			}
		}
	}
	else if(Choice==SINGLE_CONVERSION_ASYNCH)
	{

		if(ADC_pu16ConversionResult != NULL)
		{
			/*Read data*/
			#if ADC_u8RESOLUTION == EIGHT_BITS
			*ADC_pu16ConversionResult = ADCH;
			#elif ADC_u8RESOLUTION == TEN_BITS
			*ADC_pu16ConversionResult= ADC;
			#endif

			/*Disable ADC conversion complete interrupt*/
			CLR_BIT(ADCSRA,ADCSRA_ADIE);

			/*ADC flag is now available*/
			ADC_u8BusyFlag = IDEAL;

			/*Invoke the application notification function*/
			if(ADC_puNotification != NULL)
			{
				ADC_puNotification();
			}
			else
			{
				/*notification function pointer is null*/
			}

		}
		else
		{
			/*Conversion result pointer is null*/
		}
	}
}
