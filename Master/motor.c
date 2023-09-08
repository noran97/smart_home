/*
 *
 motor.c
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
void motorinit()
{
	DIO_u8SetPinDir(motorport,motorpin1,DIO_PIN_OUT);
	DIO_u8SetPinDir(motorport,motorpin2,DIO_PIN_OUT);
}
void clockwise()
{
	DIO_u8SetPinValue(motorport,motorpin1,1);
	DIO_u8SetPinValue(motorport,motorpin2,DIO_LOW);

}
void anticlock()
{
	DIO_u8SetPinValue(motorport,motorpin1,DIO_LOW);
	DIO_u8SetPinValue(motorport,motorpin2,DIO_HIGH);
}
void stop()
{
	DIO_u8SetPinValue(motorport,motorpin1,DIO_LOW);
	DIO_u8SetPinValue(motorport,motorpin2,DIO_LOW);
}
