/*
 *
 mainconfig.c
 *
 *  Created on: Sep 5, 2023
 *      Author: nor
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "keypad.h"
#include "main_confgration.h"
#include "SPI_INTERFACE.h"
#include <util/delay.h>
void ROOM_OPTIONS(u8 roomnum)
{
	u8 Local_press=0;


	if(roomnum==ROOM1)
	{
		DIO_u8SetPinDir(DIO_PORTD,DIO_PIN3,DIO_PIN_OUT);
		DIO_u8SetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);}
	else if(roomnum==ROOM2)
	{
		DIO_u8SetPinDir(DIO_PORTD,DIO_PIN4,DIO_PIN_OUT);
		DIO_u8SetPinValue(DIO_PORTD,DIO_PIN4,DIO_HIGH);
	}
	/********************************************* Choose Device *********************************************/
	LCD_voidClearScreen();
	LCD_voidSendString("1-LIGHT ");
	LCD_voidGoToXY(0,9);
	LCD_voidSendString("2-AC ");
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("3-TV ");
	LCD_voidGoToXY(1,9);
	LCD_voidSendString("4-Rooms");
	do
	{
		Local_press=KPD_u8GetPressedKey();

	}
	while(Local_press==0xff );

	spi_transmit(Local_press);
	            /****************************** CONTROL Lighting **********************************/
	if(Local_press=='1')
	{
		u8 Local_u8RecieveStatus=0;

		LCD_voidClearScreen();
	                   	/******************      Current Status    *******************/
		Local_u8RecieveStatus=SPI_u8Transceive(10);
		LCD_voidSendString("Status:" );
		if(Local_u8RecieveStatus==1)
		{
			LCD_voidSendString("ON");
		}
		else if(Local_u8RecieveStatus==0)
		{
			LCD_voidSendString("OFF");
		}

	                 	/******************      Choose Status    *******************/

		LCD_voidGoToXY(1,0);
		LCD_voidSendString("1-ON ");
		LCD_voidGoToXY(1,7);
		LCD_voidSendString("2-OFF");
		do
		{
			Local_press=KPD_u8GetPressedKey();

		} while(Local_press==0xff );


		spi_transmit(Local_press);
		if(roomnum==ROOM1)
			{
				DIO_u8SetPinValue(DIO_PORTD,DIO_PIN3,DIO_LOW);}
			else if(roomnum==ROOM2)
			{

				DIO_u8SetPinValue(DIO_PORTD,DIO_PIN4,DIO_LOW);
			}

		Options();


	}
            	/****************************** CONTROL Air_Con **********************************/
	else if(Local_press=='2')
	{
		u8 Local_u8RecieveStatus=0;
		LCD_voidClearScreen();
		                    /******************      Current Status    *******************/
		Local_u8RecieveStatus=SPI_u8Transceive(10);
		LCD_voidSendString("Status:" );
		if(Local_u8RecieveStatus==1)
		{
			LCD_voidSendString("ON");
		}
		else if(Local_u8RecieveStatus==0)
		{
			LCD_voidSendString("OFF");
		}

		                   /******************      Choose Status    *******************/

		LCD_voidGoToXY(1,0);
		LCD_voidSendString("1-ON ");
		LCD_voidGoToXY(1,7);
		LCD_voidSendString("2-OFF");
		do{
			Local_press=KPD_u8GetPressedKey();

		} while(Local_press==0xff );

		spi_transmit(Local_press);
		if(roomnum==ROOM1)
		{
			DIO_u8SetPinValue(DIO_PORTD,DIO_PIN3,DIO_LOW);}
		else if(roomnum==ROOM2)
		{

			DIO_u8SetPinValue(DIO_PORTD,DIO_PIN4,DIO_LOW);
		}
		Options();

	}
	                /***************************** CONTROL TV **********************************/
	else if(Local_press=='3')
	{
		u8 Local_u8RecieveStatus=0;
		LCD_voidClearScreen();
		                  /******************      Current Status    *******************/
		Local_u8RecieveStatus=SPI_u8Transceive(10);
		LCD_voidSendString("Status:" );
		if(Local_u8RecieveStatus==1)
		{
			LCD_voidSendString("ON");
		}
		else if(Local_u8RecieveStatus==0)
		{
			LCD_voidSendString("OFF");
		}

		                   /******************      Choose Status    *******************/

		LCD_voidGoToXY(1,0);
		LCD_voidSendString("1-ON ");
		LCD_voidGoToXY(1,7);
		LCD_voidSendString("2-OFF");

		do
		{
			Local_press=KPD_u8GetPressedKey();

		} while(Local_press==0xff );

		spi_transmit(Local_press);
		if(roomnum==ROOM1)
		{
			DIO_u8SetPinValue(DIO_PORTD,DIO_PIN3,DIO_LOW);}
		else if(roomnum==ROOM2)
		{
			DIO_u8SetPinValue(DIO_PORTD,DIO_PIN4,DIO_LOW);
		}
		Options();

	}

          /*********************************** Back To Rooms **************************************/
	else if(Local_press=='4')
	{
		if(roomnum==ROOM1)
		{
			DIO_u8SetPinValue(DIO_PORTD,DIO_PIN3,DIO_LOW);}
		else if(roomnum==ROOM2)
		{
			DIO_u8SetPinValue(DIO_PORTD,DIO_PIN4,DIO_LOW);
		}
             Options();
	}


}


/******************************************* Choose Room ***********************************************/
void Options(void)
{
	u8 Local_press=0,Local_flag=0;
	LCD_voidClearScreen();
	LCD_voidSendString("PLZ Choose Room:");
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("1-ROOM1");
	LCD_voidGoToXY(1,8);
	LCD_voidSendString("2-ROOM2");

	do{
		Local_press=KPD_u8GetPressedKey();

	}
	while(Local_press==0xff );


	if(Local_press!=0){
		Local_flag=1;

	}
	if(Local_flag==1)
	{
		spi_transmit(Local_press);
		LCD_voidSendData(Local_press);
		ROOM_OPTIONS(Local_press);
	}

}

