#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
/* Configuration     */
/***************************************************************/
#define Fun_Enable           0b00111000
#define DISPLAY_ON_OF        0b00001100
#define DISPLAY_Clr            0x01

/*************************************************************/
/* LCD Macros */
#define LCD_DATA_PORT	    DIO_PORTD
#define LCD_CONTROL_PORT	DIO_PORTA
#define LCD_RS_PIN           DIO_PIN1
#define LCD_RW_PIN           DIO_PIN2
#define LCD_E_PIN            DIO_PIN3
/*************************************************************/
/*
	Function Name        : LCD_voidInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize the LCD screen to be ready for use.
*/
void LCD_voidInit(void);
/*
	Function Name        : LCD_voidSendCommand
	Function Returns     : void
	Function Arguments   : u8 copy_u8Command
	Function Description : Send the given command to be executed by the LCD.
*/
void LCD_voidSendCommand(u8 copy_u8Command);
/*
	Function Name        : LCD_voidSendData
	Function Returns     : void
	Function Arguments   : u8 copy_u8Data
	Function Description : Print the given data on the LCD screen at the current cursor location.
*/
void LCD_voidSendData(u8 copy_u8Data);
/*
	Function Name        : LCD_voidSendString
	Function Returns     : void
	Function Arguments   : char* Copy_u8String
	Function Description : Print the given string at the current cursor location.
*/
void LCD_voidSendString(const char* Copy_u8String);
/*
	Function Name        : LCD_voidGoToXY
	Function Returns     : void
	Function Arguments   : u8 Copy_u8Xposition,u8 Copy_u8Yposition
	Function Description : Move the cursor at the given row and column (Rows 1:2 , Cols 1:16)
*/
void LCD_voidGoToXY(u8 Copy_u8Xposition,u8 Copy_u8Yposition);
/*
	Function Name        : LCD_voidWriteNumber
	Function Returns     : void
	Function Arguments   : u32 copy_u32Number
	Function Description : Print the given Number on the LCD screen at the current cursor location.
*/
void LCD_voidWriteNumber(u32 copy_u32Number);

/*
	Function Name        : LCD_clearscreen
	Function Returns     : void
	Function Arguments   : void
	Function Description : Clear all printed characters and move the cursor to the first location at the first line
*/
void LCD_voidClearScreen(void);





#endif /* CLCD_INTERFACE_H_ */
