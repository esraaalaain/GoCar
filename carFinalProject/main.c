
#include "includes/types.h"
#include "MCAL/TIM0/TIM0.h"
#include "MCAL/TIM0_PWM/TIM0_PWM.h"
#include "MCAL/TIM0/interrupt.h"
#include "ECUAL/CAR/CAR.h"
#include "APP/APP.h"
volatile uint8_t flag = 0;

float period;
float TOFF;
float TON;
int direction = 1;
float freq = 51;
int duty = DUTY_30;
int count = 1;

int main(void)
{

	APP_INIT();
	
	
    while (1) 
    {
		
		APP_UPDATE();
		
    }
}

void __vector_11 (void)
{
	if (flag==0)
	{
		CAR_MOTOR_ON();
		_TCNT0_=TON;
		flag=1;
	}
	else
	{
		CAR_MOTOR_OFF();
		_TCNT0_= TOFF;
		flag=0;
	}
}