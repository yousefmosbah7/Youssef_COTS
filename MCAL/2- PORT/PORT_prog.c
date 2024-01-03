#include "STD_TYPES.h"

#include "PORT_prv.h"
#include "PORT_cfg.h"
#include "PORT_interface.h"
#include "PORT_reg.h"

/**
 * @brief This function is used to configure all pins directions and initial states 
*/

void PORT_voidInit(void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	
	PORTA = PORTA_INIT_VAL;
	PORTB = PORTB_INIT_VAL;
	PORTC = PORTC_INIT_VAL;
	PORTD = PORTD_INIT_VAL;
}

