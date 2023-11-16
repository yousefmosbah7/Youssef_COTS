/*
 * main.c
 *
 *  Created on: Nov 5, 2023
 *      Author: yosef
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_prv.h"

#include <util/delay.h>

void main(void){

	SSD_config_t SSDone = {

			.type = COM_CATHODE,
			.led_port = DIO_u8PORTA,
			.enable_port = DIO_u8PORTC,
			.enable_pin = DIO_u8PIN6,
			.start_pin = START_PIN1,
	};

	SSD_config_t SSDtwo = {

			.type = COM_CATHODE,
			.led_port = DIO_u8PORTA,
			.enable_port = DIO_u8PORTC,
			.enable_pin = DIO_u8PIN7,
			.start_pin = START_PIN1,
	};

	DIO_u8SetPortDirection(SSDone.led_port,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(SSDone.enable_port,SSDone.enable_pin,DIO_u8PIN_OUTPUT);

	DIO_u8SetPortDirection(SSDtwo.led_port,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(SSDtwo.enable_port,SSDone.enable_pin,DIO_u8PIN_OUTPUT);

	while(1)
	{

	SSD_u8On(&SSDone);
	SSD_u8Off(&SSDtwo);
	SSD_u8SetNumber(&SSDone,3);
	_delay_ms(10);

	SSD_u8On(&SSDtwo);
	SSD_u8Off(&SSDone);
	SSD_u8SetNumber(&SSDtwo,2);
	_delay_ms(10);

	}

}
