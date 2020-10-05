

/* motor 6V >> 3100rpm >> 51HZ*/
/*Time Response for Motor =1/51 >> 19.3ms*/
/*max time 0.065536 >> 256-pre*/
/* So.. We will use prescaler 256*/

#include "../../includes/types.h"
#include "../../MCAL/TIM0/TIM0.h"
#include "../TIM0_PWM/TIM0_PWM.h"
#include "../../includes/definitions.h"

extern float TON, TOFF, period;

void TIM0_PWM_start(float duty, float freq)
{
	period = 1/freq;
	TON=(period*duty)/100;
	TOFF=period-TON;
	TON= 255-((CLOCK_INTERNAL*TON)/Prescaler_256_);
	TOFF= 255-((CLOCK_INTERNAL*TOFF)/Prescaler_256_);
	
	_TIMSK_ |= (1<<_TOIE0_);
	SET_prescaler(Prescaler_256_);
	
}

	// Enable OVF interrupt and global interrupt.
	
void TIM0_PWM_INIT(){
	
	Timer_MODEs(MODE0);
	_TIMSK_ |= (1<<_TOIE0_);
	_SREG_ |= (1<<I);
}

void PWM_STOP()
{
	TIM0_STOP();
	_TIMSK_ &=~(1<<_TOIE0_);
}