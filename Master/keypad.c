/*
 * keypad.c
 *
 *  Created on: Aug 14, 2023
 *      Author: nor
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include <avr/io.h>
//#include <util/delay.h>
#include "keypad.h"
void KPD_INIT()
{
	/* Initialize first 3 bits in keypad as output pins */
	DIO_u8SetPinDir(keypad_port,keypad_col0_pin,1);
	DIO_u8SetPinDir(keypad_port,keypad_col1_pin,1);
	DIO_u8SetPinDir(keypad_port,keypad_col2_pin,1);
	/* initalize second four bits in keypad as input pins */
	DIO_u8SetPinDir(keypad_port,keypad_row0_pin,0);
	DIO_u8SetPinDir(keypad_port,keypad_row1_pin,0);
	DIO_u8SetPinDir(keypad_port,keypad_row2_pin,0);
	DIO_u8SetPinDir(keypad_port,keypad_row3_pin,0);
	/*connect pull up resistance to the input pins*/
	DIO_u8SetPortValue(keypad_port,0xff);
}
u8 KPD_u8GetPressedKey()
{
	u8 nopress=0xff;
	u8 Local_u8state;
	static u8 Local_u8KPDArr[rownum][colnum]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
	static u8 Local_u8colarray[colnum]={keypad_col0_pin,keypad_col1_pin,keypad_col2_pin};
	static u8 Local_u8rowarray[rownum]={keypad_row0_pin,keypad_row1_pin,keypad_row2_pin,keypad_row3_pin};
	for(u8 Local_u8CoulmnIndex=0;Local_u8CoulmnIndex<colnum;Local_u8CoulmnIndex++)
	{DIO_u8SetPinValue(keypad_port,Local_u8colarray[Local_u8CoulmnIndex],DIO_LOW);
		for(u8 Local_u8RowIndex=0;Local_u8RowIndex<rownum;Local_u8RowIndex++)
		{
			DIO_u8GetPinValue(keypad_port,Local_u8rowarray[Local_u8RowIndex],&Local_u8state);
			if(Local_u8state==DIO_LOW)
			{
				nopress=Local_u8KPDArr[Local_u8RowIndex][Local_u8CoulmnIndex];//put the selected pressed key to the retrurnval
				while(Local_u8state==DIO_LOW)
				{
					DIO_u8GetPinValue(keypad_port,Local_u8rowarray[Local_u8RowIndex],&Local_u8state);
				}
				return nopress;
			}
		}
		DIO_u8SetPinValue(keypad_port,Local_u8colarray[Local_u8CoulmnIndex],DIO_HIGH);
	}
	return nopress;//return the pressed key in case of key pressed or return 0xff in case of no key pressed

}
