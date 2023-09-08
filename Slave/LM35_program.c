
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "LM35.h"


u8 TEMP_u8Read(u8 Copy_u8Channel)
{
    u8 Local_u16Value = ADC_u8GetChannelReading(Copy_u8Channel);

    // Convert ADC value to millivolts
    u16 MilliVolt = (u16)(((u32)Local_u16Value * 5000UL) /255UL);

    // Convert millivolts to Celsius
    u8 Local_u8Temp = (u8)(MilliVolt / 10);

    return Local_u8Temp;
}


