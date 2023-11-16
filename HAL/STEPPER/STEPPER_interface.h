/*
 * STEPPER_interface.h
 *
 *  Created on: Nov 15, 2023
 *      Author: yosef
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

typedef struct
{
	uint8 u8Port;
	uint8 u8Pin_Blue;
	uint8 u8Pin_Pink;
	uint8 u8Pin_Yellow;
	uint8 u8Pin_Orange;

}STEPPER_cfg_t;

uint8 STEPPER_u8Rotate_CW(STEPPER_cfg_t *Pst_obj , uint16 Copy_u16Degree);

uint8 STEPPER_u8Rotate_CCW(STEPPER_cfg_t *Pst_obj , uint16 Copy_u16Degree);

#endif /* STEPPER_INTERFACE_H_ */
