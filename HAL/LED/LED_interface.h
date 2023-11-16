/*
 * LED_interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: yosef
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef struct{
	uint8 port;
	uint8 pin;
	uint8 active;
}LED_config_t;

uint8 LED_u8On(const LED_config_t *Pst_obj);

uint8 LED_u8Off(const LED_config_t *Pst_obj);

uint8 LED_u8Toggle(const LED_config_t *Pst_obj);


#endif /* LED_INTERFACE_H_ */
