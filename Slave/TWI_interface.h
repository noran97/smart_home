
#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

void TWI_voidMasterInit(void);

void TWI_voidStartCondition(void);

void TWI_voidStopCondition(void);

void TWI_voidSendData(u8 Copy_u8Data);


u8 TWI_u8ReceiveData(void);


#endif
