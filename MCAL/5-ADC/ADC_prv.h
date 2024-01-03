/*
 * ADC-prv.h
 *
 *  Created on: Nov 23, 2023
 *      Author: yosef
 */

#ifndef ADC_PRV_H_
#define ADC_PRV_H_

#define PRESCALAR_MASK					0b11111000
#define CHANNEL_MASK					0b11100000

#define AREF_REF					1u
#define AVCC_REF					2u
#define INTERNAL_2560mV_REF			3u


#define EIGHT_BITS					1u
#define TEN_BITS					2u

#define ENABLE						1u
#define DISABLE						2u

#define DIVISION_BY_2				1u
#define DIVISION_BY_4				2u
#define DIVISION_BY_8				3u
#define DIVISION_BY_16				4u
#define DIVISION_BY_32				5u
#define DIVISION_BY_64				6u
#define DIVISION_BY_128				7u


#define SINGLE_CONVERSION_ASYNCH	0u
#define CHAIN_CONVERSION_ASYNCH		1u

#define BUSY						0u
#define IDEAL						1u

#endif /* ADC_PRV_H_ */
