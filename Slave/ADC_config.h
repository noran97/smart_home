/***************************************************/
/*************     Author: Sara Gomaa **************/
/*************     Layer:   MCAL      **************/
/*************     SWC:     ADC       **************/
/*************     Version: 1.00      **************/
/***************************************************/
/***************************************************/


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*Choose Voltage Reference Method*/
/*
    (1)_Turn off internal voltage reference AREF
    (2)_Use AVCC
    (3)_Use Internal (2.56V) Reference

*/

#define  VOLT_REF    2

/*Choose ADC Enable State

   (1)_Enable
   (2)_Disable

 */

#define ADCSRA_ADEN_State  Enable


/*Choose CLK Devision Factor*/
/*
   *)DIV_By_2
   *)DIV_By_4
   *)DIV_By_8
   *)DIV_By_16
   *)DIV_By_32
   *)DIV_By_64
   *)DIV_By_128

*/

#define PRESC   DIV_By_128


#endif
