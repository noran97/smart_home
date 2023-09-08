#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI_interface.h"
#include <avr/io.h>

void TWI_voidMasterInit(void)
{
	/*SCL CLOCK*/
TWBR =255;
CLR_BIT(TWSR,TWPS0);
CLR_BIT(TWSR,TWPS1);
/*ENABLE*/
TWCR=(1<<TWEN);
}
void TWI_voidStartCondition(void)
{
TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
while(GET_BIT(TWCR,TWINT)==0);
}
void TWI_voidStopCondition(void)
{
	TWCR=(1<<TWSTO)|(1<<TWEN)|(1<<TWINT);
}
void TWI_voidSendData(u8 Copy_u8Data)
{
TWDR=Copy_u8Data;
TWCR=(1<<TWEN)|(1<<TWINT);
while(GET_BIT(TWCR,TWINT)==0);
}
u8 TWI_u8ReceiveData(void)
{
	TWCR=(1<<TWEN)|(1<<TWINT);
	while(GET_BIT(TWCR,TWINT)==0);
return TWDR;
}
