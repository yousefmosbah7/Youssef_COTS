/*
 * BUTTON_interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: yosef
 */

#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

typedef struct{
	uint8 port;
	uint8 pin;
	uint8 pull;
}BUTTON_config_t;

uint8 BUTTON_u8GetState(const BUTTON_config_t *Pst_obj, uint8 *Copy_pu8State);

#endif /* BUTTON_INTERFACE_H_ */
