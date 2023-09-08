/***************************************************/
/***************************************************/
/*************     Author: Sara Gomaa **************/
/*************     Layer:   MCAL      **************/
/*************     SWC:     TIMER     **************/
/*************     Version: 1.00      **************/
/***************************************************/
/***************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"TIMER_CONFIG.h"
#include"TIMER_INTERFACE.h"
#include"TIMER_PRIVATE.h"
#include"TIMER_REGISTER.h"


static void (*TIMER0_pvCallBackFunc)(void)=NULL;


void  TIMER0_voidINIT(void)
{
	/*CTC Mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Output Compare Match Interrupt Enable*/
     SET_BIT(TIMSK,TIMSK_OCIE0);

     /*Set Compare Match Value to 250 (1sec)*/
     OCR0=250;

     /*Prescaler: Devision By 8*/
     CLR_BIT(TCCR0,TCCR0_CS00);
     SET_BIT(TCCR0,TCCR0_CS01);
     CLR_BIT(TCCR0,TCCR0_CS02);

}

u8   TIMER0_u8SetCallBack(u8  (*copy_pvCallBackFunc)(void))
{
    u8  Local_u8errorStatus = ok;

    if(copy_pvCallBackFunc!=NULL)
    {
    	TIMER0_pvCallBackFunc=copy_pvCallBackFunc;
    }
    else
    {
    	Local_u8errorStatus=Nok;
    }
    return Local_u8errorStatus;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
