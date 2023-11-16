/*
 * main.c
 *
 *  Created on: Nov 6, 2023
 *      Author: yosef
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "BUTTON_interface.h"
#include "BUTTON_prv.h"

#include <util/delay.h>

void main(void)
{
	BUTTON_config_t Button_one = {
			.port = DIO_u8PORTD,
			.pin = DIO_u8PIN2,
			.pull = PULL_UP,
	};

	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(Button_one.port, Button_one.pin, DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(Button_one.port, Button_one.pin, DIO_u8PIN_HIGH);

	while(1)
	{
		uint8 Ret_u8Value;
		BUTTON_u8GetState(&Button_one, &Ret_u8Value);
		if(Ret_u8Value == PRESSED)
		{

			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_HIGH);

		}
		else if(Ret_u8Value == RELEASED)
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN4,DIO_u8PIN_LOW);
		}
	}
}
