/*
 * EXTINT_reg.h
 *
 *  Created on: Nov 18, 2023
 *      Author: yosef
 */

#ifndef EXTINT_REG_H_
#define EXTINT_REG_H_

#define MCUCSR			*((volatile uint8 *)0x54) /*@brief MCU control and status register*/
#define MCUCSR_ISC2			6u

#define MCUCR			*((volatile uint8 *)0x55) /*@brief MCU control register*/
#define MCUCR_ISC00			0u
#define MCUCR_ISC01			1u
#define MCUCR_ISC10			2u
#define MCUCR_ISC11			3u

#define GICR			*((volatile uint8 *)0x5B) /*@brief Global interrupt control register*/
#define GICR_INT0			6u
#define GICR_INT1			7u
#define GICR_INT2			5u

#endif /* EXTINT_REG_H_ */
