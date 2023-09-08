
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"ADC_config.h"
#include"ADC_interface.h"
#include"ADC_private.h"
#include"ADC_register.h"


void  ADC_voidInit(void)
{
	/*Set Voltage Reference */
#if VOLT_REF==1
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif VOLT_REF==2
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif VOLT_REF==3
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);

#else
    #error "Wrong Choose TO Voltage Reference"
#endif

	/*Set Prescaler Devision Factor*/
		/*Using Bit_Masked*/
		ADCSRA &=0b11111000;
		ADCSRA |=PRESC;

	/*Activate Left Adjust Result*/
	SET_BIT(ADMUX,ADMUX_ADLAR);
	/* Set ADC Enable State*/
#if  ADCSRA_ADEN_State==Enable
	SET_BIT(ADCSRA,ADCSRA_ADEN);
#elif  ADCSRA_ADEN_State==Disable
	SCLR_BIT(ADCSRA,ADCSRA_ADEN);
#else
    #error "Wrong Choose TO ADC Enable State"

#endif


}

u8    ADC_u8GetChannelReading(u8  copy_u8Channel)
{
  /*Use Bit_Masked To Choose Channel*/
	  /*1_Clear The Mux Bits in ADMUX*/
	       ADMUX &=0b11100000;
	  /*2_Set The Chosen Channel To Mux Bits*/
           ADMUX |= copy_u8Channel;


  /*Start Conversion */
    	SET_BIT(ADCSRA,ADCSRA_ADSC);

  /*Pulling (Busy Waiting) Until Setting The Conversion Flag */
    	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

  /*Clear Conversion Flag*/
    	SET_BIT(ADCSRA,ADCSRA_ADIF);

   /*Return Reading*/  /*Suppose Using 8bit*/
    	return ADCH;

}

