/***************************************************/
/***************************************************/
/*************     Author: Sara Gomaa **************/
/*************     Layer:   MCAL      **************/
/*************     SWC:     SPI       **************/
/*************     Version: 1.00      **************/
/***************************************************/
/***************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include"SPI_REGISTER.h"
#include"SPI_INTERFACE.h"


void  SPI_voidINITMaster(void)
{      /*Master DIRECTION*/
	    DIO_u8SetPinDir(DIO_PORTB,DIO_PIN4,DIO_PIN_IN);
		DIO_u8SetPinValue(DIO_PORTB,DIO_PIN4,DIO_HIGH);
		DIO_u8SetPinDir(DIO_PORTB,DIO_PIN5,DIO_PIN_OUT);
		DIO_u8SetPinDir(DIO_PORTB,DIO_PIN6,DIO_PIN_IN);
		DIO_u8SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_OUT);
	/* Master Initialization */
	   SET_BIT(SPCR,SPCR_MSTR);

    /*Set Prescaler Devision Factor: Div_By_16*/
	   SET_BIT(SPCR,SPCR_SPR0);
	   CLR_BIT(SPCR,SPCR_SPR1);
	   CLR_BIT(SPSR,SPSR_SPI2X);

	/* Set SPI Enable State*/
	   SET_BIT(SPCR,SPCR_SPE);

}

void  SPI_voidINITSlave(void)
{
	/** Slave Direction**/
	        DIO_u8SetPinDir(DIO_PORTB,DIO_PIN4,DIO_PIN_IN);
			DIO_u8SetPinDir(DIO_PORTB,DIO_PIN5,DIO_PIN_IN);
			DIO_u8SetPinDir(DIO_PORTB,DIO_PIN6,DIO_PIN_OUT);
			DIO_u8SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_IN);
			DIO_u8SetPinDir(DIO_PORTA,DIO_PIN0,DIO_PIN_OUT);

	/* Slave Initialization */
	   CLR_BIT(SPCR,SPCR_MSTR);

    /* Set SPI Enable State*/
	   SET_BIT(SPCR,SPCR_SPE);

}

u8   SPI_u8Transceive(u8  Copy_u8Data)
{
	/*Sending The Data*/
        SPDR = Copy_u8Data;

    /*Busy Waiting Until Complete Transfer */
       while(GET_BIT(SPSR,SPSR_SPIF)==0);

   /*Get The Exchanged Data*/
       return SPDR;
}

void spi_transmit(u8 val)
{SPDR=val;
	while(GET_BIT(SPSR,SPSR_SPIF)==0){}

}
u8 spi_receive()
{
	while(GET_BIT(SPSR,SPSR_SPIF)==0){}
		return SPDR;
}
