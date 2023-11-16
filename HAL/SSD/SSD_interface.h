/*
 * SSD_interface.h
 *
 *  Created on: Nov 5, 2023
 *      Author: yosef
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef struct{
	uint8 type;
	uint8 led_port;
	uint8 enable_port;
	uint8 enable_pin;
	uint8 start_pin;
}SSD_config_t;


uint8 SSD_u8On(const SSD_config_t *Pst_obj);

uint8 SSD_u8Off(const SSD_config_t *Pst_obj);

uint8 SSD_u8SetNumber(const SSD_config_t *Pst_obj, uint8 number);

#endif /* SSD_INTERFACE_H_ */
