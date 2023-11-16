/*
 * BUTTON_prog.c
 *
 *  Created on: Nov 6, 2023
 *      Author: yosef
 */
#include "STD_TYPES.h"
#include "ErrType.h"
#include "DIO_interface.h"
#include "BUTTON_interface.h"
#include "BUTTON_prv.h"


uint8 BUTTON_u8GetState(const BUTTON_config_t *Pst_obj, uint8 *Copy_pu8State)
{
	uint8 Local_u8ErrorState = OK;
	uint8 Local_u8PinRead;
	if(Pst_obj != NULL)
	{
		if(Pst_obj->pull == PULL_UP)
		{
			//DIO_u8SetPinDirection(Pst_obj->port, Pst_obj->pin, DIO_u8PIN_INPUT);
			//DIO_u8SetPinValue(Pst_obj->port, Pst_obj->pin, DIO_u8PIN_HIGH);
			DIO_u8ReadPinValue(Pst_obj->port, Pst_obj->pin, &Local_u8PinRead);
			if(Local_u8PinRead == DIO_u8PIN_LOW)
			{
				*Copy_pu8State = PRESSED;
			}
			else if(Local_u8PinRead == DIO_u8PIN_HIGH)
			{
				*Copy_pu8State = RELEASED;
			}
		}
		else if(Pst_obj->pull == PULL_DOWN)
		{
			//DIO_u8SetPinDirection(Pst_obj->port, Pst_obj->pin, DIO_u8PIN_INPUT);
			//DIO_u8SetPinValue(Pst_obj->port, Pst_obj->pin, DIO_u8PIN_LOW);
			SDIO_u8ReadPinValue(Pst_obj->port, Pst_obj->pin, &Local_u8PinRead);
			if(Local_u8PinRead == DIO_u8PIN_HIGH)
			{
				*Copy_pu8State = PRESSED;
			}
			else if(Local_u8PinRead == DIO_u8PIN_LOW)
			{
				*Copy_pu8State = RELEASED;
			}
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;

}

