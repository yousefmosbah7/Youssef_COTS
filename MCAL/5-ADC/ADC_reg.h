/*
 * ADC_reg.h
 *
 *  Created on: Nov 23, 2023
 *      Author: yosef
 */

#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX				*((volatile uint8 *)0x27)
#define ADMUX_MUX0			0u
#define ADMUX_MUX1			1u
#define ADMUX_MUX2			2u
#define ADMUX_MUX3			3u
#define ADMUX_MUX4			4u
#define ADMUX_ADLAR			5u
#define ADMUX_REFS0			6u
#define ADMUX_REFS1			7u

#define ADCSRA				*((volatile uint8 *)0x26)
#define ADCSRA_ADPS0		0u
#define ADCSRA_ADPS1		1u
#define ADCSRA_ADPS2		2u
#define ADCSRA_ADIE			3u
#define ADCSRA_ADIF			4u
#define ADCSRA_ADATE		5u
#define ADCSRA_ADSC			6u
#define ADCSRA_ADEN			7u

#define ADCH				*((volatile uint8 *)0x25)
#define ADCL				*((volatile uint8 *)0x24)

#define ADC					*((volatile uint16 *)0x24)

#endif /* ADC_REG_H_ */
