#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include "EXTINT_interface.h"
#include "EXTINT_cfg.h"
#include "EXTINT_reg.h"

/*array of three pointers to functions to hold ISR callbacks*/
static void (*EXTI_pfINTFunPtr[3])(void) = {NULL};

void EXTI_voidInitInt0(void)
{
	/*implement int0 sense control configurations*/
#if  INT0_SENSE_CTRL == EXTI_u8LOW_LEVEL
	 CLR_BIT(MCUCR,MCUCR_ISC00);
	 CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE_CTRL == EXTI_u8ON_CHANGE
	 SET_BIT(MCUCR,MCUCR_ISC00);
	 CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE_CTRL == EXTI_u8FALLING_EDGE
	 CLR_BIT(MCUCR,MCUCR_ISC00);
	 SET_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE_CTRL == EXTI_u8RISING_EDGE
	 SET_BIT(MCUCR,MCUCR_ISC00);
	 SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error wrong int0 sense control configuration

#endif

		/*implement int0 initial state configurations*/
#if  INT0_INITIAL_STATE == DISABLED
	 CLR_BIT(GICR, GICR_INT0);
#elif INT0_INITIAL_STATE == ENABLED
	 SET_BIT(GICR, GICR_INT0);
#else
#error wrong int0 initial state configuration
#endif

}

void EXTI_voidInitInt1(void)
{
	/*implement int1 sense control configurations*/
#if  INT1_SENSE_CTRL == EXTI_u8LOW_LEVEL
	 CLR_BIT(MCUCR,MCUCR_ISC10);
	 CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE_CTRL == EXTI_u8ON_CHANGE
	 SET_BIT(MCUCR,MCUCR_ISC10);
	 CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE_CTRL == EXTI_u8FALLING_EDGE
	 CLR_BIT(MCUCR,MCUCR_ISC10);
	 SET_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE_CTRL == EXTI_u8RISING_EDGE
	 SET_BIT(MCUCR,MCUCR_ISC10);
	 SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error wrong int0 sense control configuration

#endif

		/*implement int0 initial state configurations*/
#if  INT1_INITIAL_STATE == DISABLED
	 CLR_BIT(GICR, GICR_INT1);
#elif INT1_INITIAL_STATE == ENABLED
	 SET_BIT(GICR, GICR_INT1);
#else
#error wrong int1 initial state configuration
#endif
}

void EXTI_voidInitInt2(void)
{
	/*implement int0 sense control configurations*/

#if INT2_SENSE_CTRL == EXTI_u8FALLING_EDGE
	 CLR_BIT(MCUCSR,MCUCSR_ISC2);

#elif INT2_SENSE_CTRL == EXTI_u8RISING_EDGE
	 SET_BIT(MCUCSR,MCUCSR_ISC2);

#else
#error wrong int2 sense control configuration

#endif

		/*implement int0 initial state configurations*/
#if  INT2_INITIAL_STATE == DISABLED
	 CLR_BIT(GICR, GICR_INT2);
#elif INT2_INITIAL_STATE == ENABLED
	 SET_BIT(GICR, GICR_INT2);
#else
#error wrong int0 initial state configuration
#endif
}

uint8 EXTI_u8SetSenseCtrl(uint8 Copy_u8IntNum, uint8 Copy_u8Sense)
{
	uint8 Local_u8ErrorState = OK;
	switch(Copy_u8IntNum)
	{
		case EXTI_u8INT0:
			switch(Copy_u8Sense)
			{
			 	 case EXTI_u8LOW_LEVEL: CLR_BIT(MCUCR,MCUCR_ISC00);CLR_BIT(MCUCR,MCUCR_ISC01);break;
			 	 case EXTI_u8ON_CHANGE: SET_BIT(MCUCR,MCUCR_ISC00);CLR_BIT(MCUCR,MCUCR_ISC01);break;
			 	 case EXTI_u8FALLING_EDGE: CLR_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01);break;
			 	 case EXTI_u8RISING_EDGE: SET_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01);break;
			 	 default : Local_u8ErrorState = NOK; break;
			}
			break;
		case EXTI_u8INT1:
			switch(Copy_u8Sense)
			{
			 	 case EXTI_u8LOW_LEVEL: CLR_BIT(MCUCR,MCUCR_ISC10);CLR_BIT(MCUCR,MCUCR_ISC11);break;
			 	 case EXTI_u8ON_CHANGE: SET_BIT(MCUCR,MCUCR_ISC10);CLR_BIT(MCUCR,MCUCR_ISC11);break;
			 	 case EXTI_u8FALLING_EDGE: CLR_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11);break;
			 	 case EXTI_u8RISING_EDGE: SET_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11);break;
			 	 default : Local_u8ErrorState = NOK; break;
			}
			break;
		case EXTI_u8INT2:
			switch(Copy_u8Sense)
			{
			 	 case EXTI_u8FALLING_EDGE: CLR_BIT(MCUCSR,MCUCSR_ISC2);break;
			 	 case EXTI_u8RISING_EDGE: SET_BIT(MCUCSR,MCUCSR_ISC2);break;
			 	 default : Local_u8ErrorState = NOK; break;
			}
			break;
}
	return Local_u8ErrorState;
}

uint8 EXTI_u8IntEnable(uint8 Copy_u8IntNum)
{
	uint8 Local_u8ErrorState = OK;

	switch(Copy_u8IntNum)
	{
		case EXTI_u8INT0: SET_BIT(GICR,GICR_INT0);break;
		case EXTI_u8INT1: SET_BIT(GICR,GICR_INT1);break;
		case EXTI_u8INT2: SET_BIT(GICR,GICR_INT2);break;
		default:Local_u8ErrorState=NOK;break;
	}

	return Local_u8ErrorState;
}

uint8 EXTI_u8IntDisable(uint8 Copy_u8IntNum)
{
	uint8 Local_u8ErrorState = OK;
	switch(Copy_u8IntNum)
	{
		case EXTI_u8INT0: CLR_BIT(GICR,GICR_INT0);break;
		case EXTI_u8INT1: CLR_BIT(GICR,GICR_INT1);break;
		case EXTI_u8INT2: CLR_BIT(GICR,GICR_INT2);break;
		default:Local_u8ErrorState=NOK;break;
	}
	return Local_u8ErrorState;
}

uint8 EXTI_u8SetCallBack(uint8 Copy_u8IntNum,void(*Copy_pfFuncPtr)(void))
{
	uint8 Local_ErrorState=OK;
	if(Copy_pfFuncPtr!=NULL)
	{
		EXTI_pfINTFunPtr[Copy_u8IntNum]=Copy_pfFuncPtr;
	}
	else
	{
		Local_ErrorState=NULL_PTR_ERR;
	}

	return Local_ErrorState;
}
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pfINTFunPtr[EXTI_u8INT0]!=NULL)
	{
		EXTI_pfINTFunPtr[EXTI_u8INT0]();
	}
}
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pfINTFunPtr[EXTI_u8INT1]!=NULL)
	{
		EXTI_pfINTFunPtr[EXTI_u8INT1]();
	}
}
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pfINTFunPtr[EXTI_u8INT2]!=NULL)
	{
		EXTI_pfINTFunPtr[EXTI_u8INT2]();
	}
}
