#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "keypad.h"
#include "SPI_INTERFACE.h"
#include"motor.h"
#include "main_confgration.h"
#include <util/delay.h>


u8 pass[4]={'1','2','3','4'};

int main()
{
	/*********************************** Drivers Initialization ***************************/
	LCD_voidInit();
	KPD_INIT();
	SPI_voidINITMaster();

	/************************************** WELCOME MASSEGE ********************************/
	LCD_voidSendString("HOLA,");
	LCD_voidGoToXY(1,0);
	LCD_voidSendString("IN UR SMART HOME");
	_delay_ms(2000);
	LCD_voidClearScreen();
	/***************************************  Enter Password *********************************/
	u8 Local_Counter=0,Local_Counter1=3,Local_flag=0;
	while(1){
		LCD_voidClearScreen();

		u8 Local_u8pass;
		for(Local_Counter1=3;Local_Counter1>0;Local_Counter1--){
			LCD_voidSendString("Enter Your Pass");
			LCD_voidGoToXY(1,0);
			for(Local_Counter=0;Local_Counter<4;Local_Counter++){

				do{
					Local_u8pass=KPD_u8GetPressedKey();

				}
				while(Local_u8pass==0xff );
				if(pass[Local_Counter]!=Local_u8pass)
				{
					Local_flag=1;

				}

				LCD_voidSendData('*');
			}
			if(Local_flag==1){
				LCD_voidGoToXY(1,0);
				LCD_voidSendString("WRONG PASSWORD");
				_delay_ms(2000);
				LCD_voidClearScreen();
				Local_flag=0;
			}
			else if(Local_flag==0)
			{
				LCD_voidClearScreen();
				LCD_voidSendString("HEY!!");
				LCD_voidGoToXY(1,0);
				LCD_voidSendString("YOU'Re Good Man");
				 motorinit();
				 anticlock();
				_delay_ms(2000);
				clockwise();
				_delay_ms(2000);
				stop();
				break;
			}
		}

		if(Local_Counter1==0)
		{
			LCD_voidGoToXY(0,0);
			LCD_voidSendString("SORRY,");
			LCD_voidGoToXY(1,0);
			LCD_voidSendString("You Tried 3 Times");
			break;
		}

		Options();

	}

}


