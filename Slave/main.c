
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "SPI_INTERFACE.h"
#include "ADC_interface.h"
#include "options.h"
#include "LM35.h"
#include "TIMER_INTERFACE.h"
#include <util/delay.h>
#include "LCD_INTERFACE.h"
void ISR(void);

int main()
{
	LCD_voidInit();
	ADC_voidInit();
	TIMER0_voidINIT();
	TIMER0_u8SetCallBack(&ISR);
	GIE_voidEnable();

while(1)
{
	_delay_ms(1000);
	u8 Local_u8ReceiveRoom;
	u8 Local_u8ReceiveComp;
	u8 Local_u8RecieveStatus;
	SPI_voidINITSlave();

	  Local_u8ReceiveRoom = spi_receive();

   	Local_u8ReceiveComp= spi_receive();


	if (Local_u8ReceiveComp=='1')
	{
            GET_STATUS(Local_u8ReceiveRoom,Local_u8ReceiveComp);
		Local_u8RecieveStatus= spi_receive();
		LED(Local_u8ReceiveRoom ,Local_u8RecieveStatus );
	}

	else if (Local_u8ReceiveComp=='2')
	{
        GET_STATUS(Local_u8ReceiveRoom,Local_u8ReceiveComp);

		Local_u8RecieveStatus= spi_receive();
		AC(Local_u8ReceiveRoom ,Local_u8RecieveStatus );
	}
	else if (Local_u8ReceiveComp=='3')
	{
        GET_STATUS(Local_u8ReceiveRoom,Local_u8ReceiveComp);

		Local_u8RecieveStatus= spi_receive();
		TV(Local_u8ReceiveRoom ,Local_u8RecieveStatus );
	}

	else
	{
	}
}
}


void ISR(void)
{
    static u16 counter=0;
    counter++;

    if(counter==4000)
    {
    	u8 Temp;
    	Temp=LM35();
    	if(Temp<50)
		{
    		DIO_u8SetPinDir(DIO_PORTA,DIO_PIN6,DIO_PIN_OUT);
    		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_LOW);
    		DIO_u8SetPinDir(DIO_PORTA,DIO_PIN7,DIO_PIN_OUT);
    		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_HIGH);
    		 LCD_voidClearScreen();
    		 LCD_voidGoToXY(0,0);
    		 LCD_voidSendString("Temperature= ");
    		 LCD_voidWriteNumber(Temp);
    		 LCD_voidSendData('c');
		}
    	else if(Temp>50)
    	{
    		DIO_u8SetPinDir(DIO_PORTA,DIO_PIN7,DIO_PIN_OUT);
    		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_LOW);
    		DIO_u8SetPinDir(DIO_PORTA,DIO_PIN6,DIO_PIN_OUT);
    		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_HIGH);
    		DIO_u8SetPinDir(DIO_PORTB,DIO_PIN0,DIO_PIN_IN);

    		 LCD_voidClearScreen();
    		 LCD_voidGoToXY(0,5);
    		 LCD_voidSendString("WARNING");
    		 _delay_ms(700);
    		 LCD_voidClearScreen();
    		 LCD_voidGoToXY(0,3);
    		 LCD_voidSendString("TEMPERATURE");
    		 LCD_voidGoToXY(1,4);
    		 LCD_voidSendString("INCREASED");
    	}

    }
}





