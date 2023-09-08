/***************************************************/
/***************************************************/
/*************     Author: Sara Gomaa **************/
/*************     Layer:   MCAL      **************/
/*************     SWC:     SPI       **************/
/*************     Version: 1.00      **************/
/***************************************************/
/***************************************************/


#ifndef  SPI_REGISTER_H
#define  SPI_REGISTER_H

#define  SPDR    *((volatile  u8*)0X2F)


#define  SPSR    *((volatile  u8*)0X2E)
#define  SPSR_SPIF      7
#define  SPSR_SPI2X     0


#define SPCR     *((volatile  u8*)0X2D)
#define SPCR_SPE       6
#define SPCR_MSTR      4
#define SPCR_SPR1      1
#define SPCR_SPR0      0

#endif
