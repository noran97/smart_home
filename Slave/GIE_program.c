
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_INTERFACE.h"
#include "GIE_REGISTER.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);

}
