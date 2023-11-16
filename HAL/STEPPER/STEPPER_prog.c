#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ErrType.h"

#include "STEPPER_interface.h"

#include <util/delay.h>

uint8 STEPPER_u8Rotate_CW(STEPPER_cfg_t *Pst_obj , uint16 Copy_u16Degree)
{
	uint8 Local_u8ErrorState = OK;
	uint16 Local_u16Number_Of_Steps=0;

	if(Pst_obj != NULL)
	{
		Local_u16Number_Of_Steps = (uint16)(((uint32)Copy_u16Degree*(uint32)2048)/(uint32)360);

		for(uint16 Local_u16Counter=0 ; Local_u16Counter< Local_u16Number_Of_Steps ; Local_u16Counter++){

			/*rotate 180 degree*/

					/*to handle integer division*/
					if(Local_u16Counter%4==0)
					{
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Blue,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Pink,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Yellow,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Orange,DIO_u8PIN_HIGH);

					_delay_ms(10);
					}

					else if(Local_u16Counter%4==1)
					{
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Blue,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Pink,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Yellow,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Orange,DIO_u8PIN_HIGH);

					_delay_ms(10);
					}

					else if(Local_u16Counter%4==2)
					{
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Blue,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Pink,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Yellow,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Orange,DIO_u8PIN_HIGH);

					_delay_ms(10);
					}

					else if(Local_u16Counter%4==3)
					{
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Blue,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Pink,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Yellow,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Orange,DIO_u8PIN_LOW);

					_delay_ms(10);
					}
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;

}

uint8 STEPPER_u8Rotate_CCW(STEPPER_cfg_t *Pst_obj , uint16 Copy_u16Degree)
{
	uint8 Local_u8ErrorState = OK;
	uint16 Local_u16Number_Of_Steps=0;

	if(Pst_obj != NULL)
	{
		Local_u16Number_Of_Steps = (uint16)(((uint32)Copy_u16Degree*(uint32)2048)/(uint32)360);

		for(uint16 Local_u16Counter=0 ; Local_u16Counter< Local_u16Number_Of_Steps ; Local_u16Counter++){

				if(Local_u16Counter%4==0)
					{
						DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Blue,DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Pink,DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Yellow,DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Orange,DIO_u8PIN_LOW);

						_delay_ms(10);
					}
				else if(Local_u16Counter%4==1)
					{
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Blue,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Pink,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Yellow,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Orange,DIO_u8PIN_HIGH);

					_delay_ms(10);
					}
				else if(Local_u16Counter%4==2)
					{
						DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Blue,DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Pink,DIO_u8PIN_LOW);
						DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Yellow,DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Orange,DIO_u8PIN_HIGH);

						_delay_ms(10);
					}
				else if(Local_u16Counter%4==3)
					{
						DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Blue,DIO_u8PIN_LOW);
						DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Pink,DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Yellow,DIO_u8PIN_HIGH);
						DIO_u8SetPinValue(Pst_obj->u8Port,Pst_obj->u8Pin_Orange,DIO_u8PIN_HIGH);

						_delay_ms(10);
					}

		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

