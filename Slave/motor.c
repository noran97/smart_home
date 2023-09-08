/*
 * motor.c
 *
 *  Created on: Aug 15, 2023
 *      Author: nor
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include <avr/io.h>
#include <util/delay.h>
#include "motor.h"
void clockwise()
{
	DIO_u8SetPinValue(motorport,motorpin1,DIO_HIGH);
	DIO_u8SetPinValue(motorport,motorpin2,DIO_LOW);

}
void anticlock()
{
	DIO_u8SetPinValue(motorport,motorpin1,DIO_LOW);
	DIO_u8SetPinValue(motorport,motorpin2,DIO_HIGH);
}
