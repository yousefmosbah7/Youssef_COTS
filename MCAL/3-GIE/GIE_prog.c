/*
 * GIE_prog.c
 *
 *  Created on: Nov 18, 2023
 *      Author: yosef
 */
#include "STD_TYPES.h"
#include "BIT_MATh.h"
#include "GIE_interface.h"
#include "GIE_reg.h"


void GIE_voidGie_Enable(void)
{
	//SET_BIT(SREG, SREG_PIN);
	/*instead of taking 3 clock cycles we can use this assembly instruction to take one instruction*/
	__asm __volatile("SEI");

}

void GIE_voidGie_Disable(void)
{
	//CLR_BIT(SREG, SREG_PIN);
	/*instead of taking 3 clock cycles we can use this assembly instruction to take one instruction*/
	__asm __volatile("SEI");

}

