/*
 * DCMOTOR_interface.h
 *
 *  Created on: Nov 13, 2023
 *      Author: yosef
 */

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

typedef struct
{
	uint8 DC_u8Port;
	uint8 DC_u8PIN1;
	uint8 DC_u8PIN2;
	uint8 DC_u8PIN3;
	uint8 DC_u8PIN4;

}DC_cfg_t;

uint8 DCMOTOR_voidRotateCW(DC_cfg_t *Pst_obj);

uint8 DCMOTOR_voidRotateCCW(DC_cfg_t *Pst_obj);

uint8 DCMOTOR_voidStop(DC_cfg_t *Pst_obj);

#endif /* DCMOTOR_INTERFACE_H_ */
