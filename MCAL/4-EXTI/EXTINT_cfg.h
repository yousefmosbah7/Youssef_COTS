/*
 * EXTINT_cfg.h
 *
 *  Created on: Nov 18, 2023
 *      Author: yosef
 */

#ifndef EXTINT_CFG_H_
#define EXTINT_CFG_H_


/**
 * choose between 1-EXTI_u8LOW_LEVEL
 * 				  2-EXTI_u8ON_CHANGE
 * 				  3-EXTI_u8FALLING_EDGE
 * 				  4-EXTI_u8RISING_EDGE
 * */
#define INT0_SENSE_CTRL					EXTI_u8FALLING_EDGE

/**
 * choose the initial state of INT0 1-ENABLED
 * 									2-DISABLED
 * */
#define INT0_INITIAL_STATE				ENABLED

/**
 * choose between 1-EXTI_u8LOW_LEVEL
 * 				  2-EXTI_u8ON_CHANGE
 * 				  3-EXTI_u8FALLING_EDGE
 * 				  4-EXTI_u8RISING_EDGE
 * */
#define INT1_SENSE_CTRL					EXTI_u8FALLING_EDGE

/**
 * choose the initial state of INT1 1-ENABLED
 * 									2-DISABLED
 * */
#define INT1_INITIAL_STATE				ENABLED

/**
 * choose between 1-EXTI_u8FALLING_EDGE
 * 				  2-EXTI_u8RISING_EDGE
 * */
#define INT2_SENSE_CTRL					EXTI_u8FALLING_EDGE

/**
 * choose the initial state of INT0 1-ENABLED
 * 									2-DISABLED
 * */
#define INT2_INITIAL_STATE				ENABLED



#endif /* EXTINT_CFG_H_ */
