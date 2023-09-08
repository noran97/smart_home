/*
 * option.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Sara Gomaa
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "LM35.h"
#include"DIO_INTERFACE.h"
#include"SPI_INTERFACE.h"
#include"LCD_INTERFACE.h"
#include"ADC_interface.h"
#include"options.h"

void GET_STATUS(u8  Copy_u8ROOM,u8 Local_u8ReceiveComp)
{
	static u8 Status=1;
	 u8 Local_u8Status=0;

	if(Copy_u8ROOM=='1')
	{
		if(Local_u8ReceiveComp=='1')
		{
			DIO_u8GetPinValue(DIO_PORTC,DIO_PIN0,&Status);
				SPI_u8Transceive(Status);

		}
		else if(Local_u8ReceiveComp=='2')
		{
			Local_u8Status=DIO_u8GetPinValue(DIO_PORTC,DIO_PIN2,&Status);
			SPI_u8Transceive(Status);
		}
		else if(Local_u8ReceiveComp=='3')
		{
			Local_u8Status=DIO_u8GetPinValue(DIO_PORTC,DIO_PIN1,&Status);
			SPI_u8Transceive(Status);
		}
	}
	if(Copy_u8ROOM=='2')
	{
		if(Local_u8ReceiveComp=='1')
		{
			Status=DIO_u8GetPinValue(DIO_PORTC,DIO_PIN3,&Status);
			SPI_u8Transceive(Status);
		}
		else if(Local_u8ReceiveComp=='2')
		{
			Status=DIO_u8GetPinValue(DIO_PORTC,DIO_PIN5,&Status);
			SPI_u8Transceive(Status);
		}
		else if(Local_u8ReceiveComp=='3')
		{
			Status=DIO_u8GetPinValue(DIO_PORTC,DIO_PIN4,&Status);
			SPI_u8Transceive(Status);
		}
	}

}
void LED (u8  Copy_u8ROOM , u8 Copy_u8Status)
{

	if(Copy_u8ROOM=='1')
	{
		if(Copy_u8Status=='1')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN0,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_HIGH);
		}
		else if(Copy_u8Status=='2')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN0,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_LOW);
		}}
	else if(Copy_u8ROOM=='2')
	{
		if(Copy_u8Status=='1')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_HIGH);
		}
		else if(Copy_u8Status=='2')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_LOW);
		}
	}
}

void TV  (u8  Copy_u8ROOM , u8 Copy_u8Status)
{

	if(Copy_u8ROOM=='1')
	{
		if(Copy_u8Status=='1')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN1,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_HIGH);
		}
		else if(Copy_u8Status=='2')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN1,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_LOW);
		}}
	else if(Copy_u8ROOM=='2')
	{
		if(Copy_u8Status=='1')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN4,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_HIGH);
		}
		else if(Copy_u8Status=='2')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN4,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_LOW);
		}
	}
}

void AC  (u8  Copy_u8ROOM , u8 Copy_u8Status)
{

	if(Copy_u8ROOM=='1')
	{
		if(Copy_u8Status=='1')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_HIGH);
			DIO_u8SetPinDir(DIO_PORTA,DIO_PIN5,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_HIGH);

		}
		else if(Copy_u8Status=='2')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_LOW);
			DIO_u8SetPinDir(DIO_PORTA,DIO_PIN5,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_LOW);
		}}
	else if(Copy_u8ROOM=='2')
	{
		if(Copy_u8Status=='1')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN5,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_HIGH);
			DIO_u8SetPinDir(DIO_PORTA,DIO_PIN4,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_HIGH);

		}
		else if(Copy_u8Status=='2')
		{
			DIO_u8SetPinDir(DIO_PORTC,DIO_PIN5,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_LOW);
			DIO_u8SetPinDir(DIO_PORTA,DIO_PIN4,DIO_PIN_OUT);
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_LOW);
		}
	}
}
void ROOM  (u8  Copy_u8ROOM )
{
	if(Copy_u8ROOM=='1')
	{

		DIO_u8SetPinDir(DIO_PORTC,DIO_PIN6,DIO_PIN_OUT);
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_HIGH);

	}
	else if(Copy_u8ROOM=='2')
	{

		DIO_u8SetPinDir(DIO_PORTC,DIO_PIN7,DIO_PIN_OUT);
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);

	}
}
u8 LM35(void){

	DIO_u8SetPinDir(DIO_PORTA,DIO_PIN0,DIO_PORT_IN);
	u8 Local_u8Temp=0;

	Local_u8Temp=TEMP_u8Read(0);

	return Local_u8Temp;
}
