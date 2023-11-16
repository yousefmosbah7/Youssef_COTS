/*
 * LED_prog.c
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

uint8 LED_u8On(const LED_config_t *Pst_obj)
{
	uint8 Local_u8ErrorState = OK;

	if(Pst_obj != NULL)
	{
		if(Pst_obj->active == ACTIVE_HIGH)
		{
			DIO_u8SetPinValue(Pst_obj->port, Pst_obj->pin, DIO_u8PIN_HIGH);
		}
		else if(Pst_obj->active == ACTIVE_LOW)
		{
			DIO_u8SetPinValue(Pst_obj->port, Pst_obj->pin, DIO_u8PIN_LOW);
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;

}

uint8 LED_u8Off(const LED_config_t *Pst_obj)
{
	uint8 Local_u8ErrorState = OK;

	if(Pst_obj != NULL)
	{
		if(Pst_obj->active == ACTIVE_HIGH)
		{
			DIO_u8SetPinValue(Pst_obj->port, Pst_obj->pin, DIO_u8PIN_LOW);
		}
		else if(Pst_obj->active == ACTIVE_LOW)
		{
			DIO_u8SetPinValue(Pst_obj->port, Pst_obj->pin, DIO_u8PIN_HIGH);
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

uint8 LED_u8Toggle(const LED_config_t *Pst_obj)
{
	uint8 Local_u8ErrorState = OK;

	if(Pst_obj != NULL)
	{
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

