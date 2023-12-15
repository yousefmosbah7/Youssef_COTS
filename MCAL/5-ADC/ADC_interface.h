/*
 * ADC_interface.h
 *
 *  Created on: Nov 23, 2023
 *      Author: yosef
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_SINGLE_ENDED_CH0				0u
#define ADC_SINGLE_ENDED_CH1				1u
#define ADC_SINGLE_ENDED_CH2				2u
#define ADC_SINGLE_ENDED_CH3				3u
#define ADC_SINGLE_ENDED_CH4				4u
#define ADC_SINGLE_ENDED_CH5				5u
#define ADC_SINGLE_ENDED_CH6				6u
#define ADC_SINGLE_ENDED_CH7				7u

typedef struct{
	uint8 ChainSize;
	uint8 *ChannelArr;
	uint16 *ResultArr;
	void(*Copy_puNotificationFunc)(void);
}Chaining_t;

void ADC_voidInit(void);

uint8 ADC_u8StartConversionSynch(uint8 Copy_u8_Channel ,uint16* Copy_pu16Result);

uint8 ADC_u8StartConversionAsynch(uint8 Copy_u8Channel, uint16* Copy_u16Result, void(*Copy_puNotificationFunc)(void));

uint8 ADC_u8StartChainConversionAsynch(Chaining_t *Chaining_Obj);

#endif /* ADC_INTERFACE_H_ */
