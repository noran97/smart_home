/***************************************************/
/***************************************************/
/*************     Author: Sara Gomaa **************/
/*************     Layer:   MCAL      **************/
/*************     SWC:     SPI       **************/
/*************     Version: 1.00      **************/
/***************************************************/
/***************************************************/


#ifndef  SPI_INTERFACE_H
#define  SPI_INTERFACE_H


void  SPI_voidINITMaster(void);

void  SPI_voidINITSlave(void);

u8   SPI_u8Transceive(u8  Copy_u8Data);

void spi_transmit(u8 val);

u8 spi_receive();

#endif  /*SPI_INTERFACE_H_ */
