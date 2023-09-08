/*

 * GIE_program.c
 *
 *  Created on: Aug 23, 2023
 *      Author: nor
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>
#include "GIE_REGISTER.h"
#include "GIE_interface.h"
void GIE_voidEnable(void)
{
SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}


