/*
 * SSD_prog.c
 *
 *  Created on: Nov 5, 2023
 *      Author: yosef
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_prv.h"
#include "ErrType.h"


uint8 SSD_u8On(const SSD_config_t *Pst_obj)
{
	uint8 Local_u8ErrorState = OK;

	if(Pst_obj != NULL)
	{
		if(Pst_obj->type == COM_ANODE)
		{
			DIO_u8SetPinValue(Pst_obj->enable_port,Pst_obj->enable_pin,DIO_u8PIN_LOW);
		}
		else if((Pst_obj->type == COM_CATHODE)||(Pst_obj->type == ETA_KIT))
		{
			DIO_u8SetPinValue(Pst_obj->enable_port,Pst_obj->enable_pin,DIO_u8PIN_HIGH);
		}
	}
	else
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

uint8 SSD_u8Off(const SSD_config_t *Pst_obj)
{
	uint8 Local_u8ErrorState = OK;

	if(Pst_obj != NULL)
	{
		if(Pst_obj->type == COM_ANODE)
		{
			DIO_u8SetPinValue(Pst_obj->enable_port,Pst_obj->enable_pin,DIO_u8PIN_HIGH);
		}
		else if((Pst_obj->type == COM_CATHODE)||(Pst_obj->type == ETA_KIT))
		{
			DIO_u8SetPinValue(Pst_obj->enable_port,Pst_obj->enable_pin,DIO_u8PIN_LOW);
		}
	}
	else
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

uint8 SSD_u8SetNumber(const SSD_config_t *Pst_obj, uint8 number)
{
	static uint8 SSD_ARR[10]={0b000111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b01000111,0b01111111,0b01101111};

	uint8 Local_u8ErrorState = OK;
	if(Pst_obj != NULL)
	{
			if (Pst_obj->start_pin == START_PIN0)
			{
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN0,(SSD_ARR[number] & 0x01));//first bit
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN1,(SSD_ARR[number] >> 1) & 0x01);//second bit
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN2,(SSD_ARR[number] >> 2) & 0x01);//third bit
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN3,(SSD_ARR[number] >> 3) & 0x01);//fourth bit
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN4,(SSD_ARR[number] >> 4) & 0x01);//fifth bit
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN5,(SSD_ARR[number] >> 5) & 0x01);//sixth bit
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN6,(SSD_ARR[number] >> 6) & 0x01);//seventh bit

			}
			else if(Pst_obj->start_pin == START_PIN1)
			{
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN1,(SSD_ARR[number] & 0x01));//first bit
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN2,(SSD_ARR[number] >> 1) & 0x01);//second bit
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN3,(SSD_ARR[number] >> 2) & 0x01);//third bit
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN4,(SSD_ARR[number] >> 3) & 0x01);//fourth bit
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN5,(SSD_ARR[number] >> 4) & 0x01);//fifth bit
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN6,(SSD_ARR[number] >> 5) & 0x01);//sixth bit
				DIO_u8SetPinValue(Pst_obj->led_port,DIO_u8PIN7,(SSD_ARR[number] >> 6) & 0x01);//seventh bit
			}


	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
