/*
 * BIT_MATH.h
 *
 *  Created on: Aug 23, 2023
 *      Author: nor
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Reg,bit) (Reg=Reg|(1<<bit))
/*Clear bit*/
#define CLR_BIT(Reg,bit) (Reg=Reg&(~(1<<bit)))
/*Get bit*/
#define GET_BIT(Reg,bit) (((Reg>>bit)&1))
/*Toggle bit*/
#define TOGGLE_BIT(Reg,bit) (Reg=Reg^(1<<bit))


#endif /* BIT_MATH_H_ */
