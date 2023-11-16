#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "STEPPER_interface.h"
#include <util/delay.h>

void main(void)
{
	PORT_voidInit();

	STEPPER_cfg_t Stepper1 = {
			.u8Port=DIO_u8PORTB,
			.u8Pin_Blue=DIO_u8PIN0,
			.u8Pin_Pink=DIO_u8PIN1,
			.u8Pin_Yellow=DIO_u8PIN2,
			.u8Pin_Orange=DIO_u8PIN3,
	};
	/*
	DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8PORT_OUTPUT);

	for(uint16 i=0;i<612;i++){
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_HIGH);
			_delay_ms(10);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_HIGH);
			_delay_ms(10);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_HIGH);
			_delay_ms(10);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_LOW);
			_delay_ms(10);
	}
*/

	while(1)
	{

		STEPPER_u8Rotate_CW(&Stepper1,180);
		_delay_ms(1000);
		STEPPER_u8Rotate_CCW(&Stepper1,180);
		_delay_ms(1000);

	}
}
