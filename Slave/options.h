/*
 * options.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Sara Gomaa
 */

#ifndef   OPTIONS_H_
#define  OPTIONS_H_

void GET_STATUS(u8  Copy_u8ROOM,u8 Local_u8ReceiveComp);

void LED (u8  Copy_u8ROOM , u8 Copy_u8Status);

void AC  (u8  Copy_u8ROOM , u8 Copy_u8Status);

void TV  (u8  Copy_u8ROOM , u8 Copy_u8Status);

u8 LM35(void);



#endif
