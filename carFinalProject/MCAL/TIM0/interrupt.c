
#include "../../includes/definitions.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIM0/TIM0.h"

extern uint8_t flag;
extern float TON, TOFF;

void __vector_11 (void)
{
	if (flag==0)
	{
		DIO_WRITE_BIT(PORT_B, EN1 , HIGH);
		DIO_WRITE_BIT(PORT_B, EN2 , HIGH);
		_TCNT0_=TON;
		flag=1;
	}
	else
	{
		DIO_WRITE_BIT(PORT_B, EN1 , LOW);
		DIO_WRITE_BIT(PORT_B, EN2 , LOW);
		_TCNT0_= TOFF;
		flag=0;
	}
}