/*
 * ADC_cfg.h
 *
 *  Created on: Nov 23, 2023
 *      Author: yosef
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/**
 * choose to configure reference voltage options 1-AREF_REF
 * 												 2-AVCC_REF
 * 												 3-INTERNAL_2560mV_REF
 * */
#define ADC_u8REF_VOLT				AVCC_REF


/**
 * choose ADC resolution options 1-EIGHT_BITS
 * 								 2-TEN_BITS
 * */
#define ADC_u8RESOLUTION			EIGHT_BITS

/**
 * choose ADC auto trigger options 1-ENABLE
 * 								   2-DISABLE
 * */
#define ADC_u8AUTO_TRIGGER			DISABLE

/**
 * Interrupt enable configurations options 1-ENABLE
 * 										   2-DISABLED
 * */
#define ADC_u8INT_ENABLE			DISABLED


#define ADC_u8PRESCALAR_VALUE		DIVISION_BY_128


#define ADC_u32TIMEOUT				50000u

#endif /* ADC_CFG_H_ */
