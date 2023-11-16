/*
 * main.c
 *
 *  Created on: Nov 6, 2023
 *      Author: yosef
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_prv.h"

#include <util/delay.h>

void main(void){

	LED_config_t Led_one = {
			.port = DIO_u8PORTC,
			.pin = DIO_u8PIN4,
			.active = ACTIVE_HIGH ,
	};

	DIO_u8SetPortDirection(Led_one.port, DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(Led_one.port, Led_one.pin, DIO_u8PIN_OUTPUT);

	while(1)
	{
		LED_u8On(&Led_one);
		_delay_ms(1000);
		LED_u8Off(&Led_one);
		_delay_ms(1000);

	}
}

