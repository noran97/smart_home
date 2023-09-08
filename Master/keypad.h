/*
 * keypad.h
 *
 *  Created on: Aug 14, 2023
 *      Author: nor
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#define keypad_port 	DIO_PORTA
#define keypad_col0_pin DIO_PIN5
#define keypad_col1_pin DIO_PIN6
#define keypad_col2_pin DIO_PIN7
#define keypad_row0_pin DIO_PIN1
#define keypad_row1_pin DIO_PIN2
#define keypad_row2_pin DIO_PIN3
#define keypad_row3_pin DIO_PIN4
#define colnum 3
#define rownum 4
/*
	Function Name        : KPD_u8GetPressedKey
	Function Returns     : u8
	Function Arguments   : void
	Function Description : Returns the pressed key or return nopress if no keys are pressed.
*/
u8 KPD_u8GetPressedKey();
/*
	Function Name        : KPD_INIT
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize the keypad.
*/
void KPD_INIT();


#endif /* KEYPAD_H_ */
