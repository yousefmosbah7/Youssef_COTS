#include "STD_TYPES.h"
#include "ErrType.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "DCMOTOR_interface.h"
#include <util/delay.h>


uint8 DCMOTOR_voidRotateCW(DC_cfg_t *Pst_obj)
{
	uint8 Local_u8ErrorState = OK;

	if(Pst_obj != NULL)
	{
		/*Low must be first to avoid being all high during shifting*/
	DIO_u8SetPinValue(Pst_obj->DC_u8Port,Pst_obj->DC_u8PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Pst_obj->DC_u8Port,Pst_obj->DC_u8PIN4,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Pst_obj->DC_u8Port,Pst_obj->DC_u8PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Pst_obj->DC_u8Port,Pst_obj->DC_u8PIN3,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;

}

uint8 DCMOTOR_voidRotateCCW(DC_cfg_t *Pst_obj)
{
	uint8 Local_u8ErrorState = OK;

	if(Pst_obj != NULL)
	{
		/*Low must be first to avoid being all high during shifting*/

	DIO_u8SetPinValue(Pst_obj->DC_u8Port,Pst_obj->DC_u8PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Pst_obj->DC_u8Port,Pst_obj->DC_u8PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Pst_obj->DC_u8Port,Pst_obj->DC_u8PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Pst_obj->DC_u8Port,Pst_obj->DC_u8PIN4,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
	}

uint8 DCMOTOR_voidStop(DC_cfg_t *Pst_obj)
{
	uint8 Local_u8ErrorState = OK;

	if(Pst_obj != NULL)
	{
	DIO_u8SetPinValue(Pst_obj->DC_u8Port,Pst_obj->DC_u8PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Pst_obj->DC_u8Port,Pst_obj->DC_u8PIN3,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Pst_obj->DC_u8Port,Pst_obj->DC_u8PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Pst_obj->DC_u8Port,Pst_obj->DC_u8PIN4,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
	}
