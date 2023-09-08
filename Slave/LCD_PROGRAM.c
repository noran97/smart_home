#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD_INTERFACE.h"
#include "DIO_INTERFACE.h"
#include <util/delay.h>


void LCD_voidSendCommand(u8 copy_u8Command)
{
/*  DIRCTION OF LCD   */
DIO_u8SetPortDir(LCD_DATA_PORT,DIO_PIN_OUT);
/*   DIRCTION OF RS/RW/E   */
DIO_u8SetPinDir(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_PIN_OUT);
DIO_u8SetPinDir(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_PIN_OUT);
DIO_u8SetPinDir(LCD_CONTROL_PORT,LCD_E_PIN,DIO_PIN_OUT);

/*Setting RS pin to low*/
DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);
/*Setting RW pin low for write*/
DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
/*Set command data pins*/
DIO_u8SetPortValue(LCD_DATA_PORT,copy_u8Command);
/*Send Enable pulse*/
DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
_delay_ms(2);
DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
}

void LCD_voidInit(void)
{
	/*Wait more that 40 ms*/
	_delay_ms(40);
	LCD_voidSendCommand(Fun_Enable);

	LCD_voidSendCommand(DISPLAY_ON_OF);

	LCD_voidSendCommand(DISPLAY_Clr);



}


void LCD_voidSendData(u8 copy_u8Data)
{

	/*Setting RS pin to HIGH*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);
	/*Setting RW pin low for write*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

	/*Set data pins*/
	DIO_u8SetPortValue(LCD_DATA_PORT,copy_u8Data);

	/*Send Enable pulse*/
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);


}

void LCD_voidSendString(const char* Copy_u8String)
{
u8 Local_u8Counter=0;
while(Copy_u8String[Local_u8Counter]!='\0')
{
    LCD_voidSendData(Copy_u8String[Local_u8Counter]);
    Local_u8Counter++;
}

}


void LCD_voidGoToXY(u8 Copy_u8Xposition,u8 Copy_u8Yposition)
{
  u8 Local_u8Address;

  if(Copy_u8Xposition==0)
  {
	  Local_u8Address=Copy_u8Yposition;
  }
  else if(Copy_u8Xposition==1)

  {
	  Local_u8Address=Copy_u8Yposition+0x40;
  }

  LCD_voidSendCommand(Local_u8Address|(1<<7));

  //LCD_voidSendCommand(SET_BIT(Local_u8Address,7));
}


void LCD_voidWriteNumber(u32 copy_u32Number)
{
	u8 Local_u8Digit;
	u8 Local_u8Counter1=0;
	s8 Local_u8Counter2;
	static u8 Local_ArrayOfChar[10]={'0','1','2','3','4','5','6','7','8','9'};
	static u8 Local_ArrayOfDigits[10];

	if(copy_u32Number==0)
	{
		LCD_voidSendData(Local_ArrayOfChar[0]);
	}
	else
	{

		while(copy_u32Number>0)
		{
			Local_u8Digit=copy_u32Number%10;
			copy_u32Number=copy_u32Number/10;
			Local_ArrayOfDigits[Local_u8Counter1]=Local_ArrayOfChar[Local_u8Digit];
			Local_u8Counter1++;
		}

		for(Local_u8Counter2=Local_u8Counter1-1;Local_u8Counter2>=0;Local_u8Counter2--)
		{
			LCD_voidSendData(Local_ArrayOfDigits[Local_u8Counter2]);
		}
	}
}

void LCD_voidClearScreen(void){
	LCD_voidSendCommand(DISPLAY_Clr);
}
