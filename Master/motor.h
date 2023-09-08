/*
 * motor.h
 *
 *  Created on: Aug 15, 2023
 *      Author: nor
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#define motorport DIO_PORTD
#define motorpin1 DIO_PIN6
#define motorpin2 DIO_PIN7
void motorinit();
void clockwise();
void anticlock();
void stop();
#endif /* MOTOR_H_ */
