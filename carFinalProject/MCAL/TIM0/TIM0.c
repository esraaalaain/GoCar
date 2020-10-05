/*
 * Timer_driver.c
 *
 * Created: 8/27/2020 4:06:42 PM
 * Author : Esraa

 */ 

#include "../../includes/types.h"
#include "../../MCAL/TIM0/TIM0.h"

/************************************************************************/
/*
max time 0.000256 >> no prescaler
max time 0.002048 >> 8-pre
max time 0.011776 >> 64-pre
max time 0.065536 >> 256-pre
max time 0.262144 >> 1024-pre   
time count = required delay / clock time -1   
clock time = 1/prescaler        
                                                        */
/************************************************************************/



#define  CLOCK_INTERNAL 1000000 // 1MHZ



void SET_prescaler( uint16_t pre)
{
	if(pre == Prescaler_off_)
	{
		_TCCR0_ |=0;
	}
	else if(pre == Prescaler_1_)
	{
		_TCCR0_ |= 1;
		
	}
	else if(pre == Prescaler_8_)
	{
		_TCCR0_ |=2;
	}
	else if(pre == Prescaler_64_)
	{
		_TCCR0_ |=3;
	}
	else if(pre == Prescaler_256_)
	{
		_TCCR0_ |=4;
	}
	else if(pre == Prescaler_1024_)
	{	
		_TCCR0_ |=5;
	}
}


void TIM0_STOP()
{
	_TIFR_ |= (1<<_TOV0_);
	SET_prescaler(Prescaler_off_);
}

void wait_ovf()
{
	while((_TIFR_&(1<<_TOV0_))!=1);
}


void Timer_MODEs(uint8_t T_mode)
{
	if(T_mode==MODE0)
	{
		_TCCR0_ &=~((1<<_WGM00_)|(1<<_WGM01_));
	}
	else if (T_mode==MODE1)
	{
		_TCCR0_ |= (1<<_WGM01_);
		_TCCR0_ &= ~(1<<_WGM00_);
	}
	else if(T_mode==MODE2)
	{
		_TCCR0_ |= (1<<_WGM00_);
		_TCCR0_ &= ~(1<<_WGM01_);		
	}
	else if(T_mode==Fast_PWM)
	{
		_TCCR0_ |=(1<< _WGM00_)|(1<< _WGM01_);
	}

}

void T_COM_non_PWM(uint8_t C_mode)
{
	if (C_mode==COM_NORMAL)
	{
		_TCCR0_ &=~((1<<_COM00_)|(1<<_COM01_));// clear
	}
	else if(C_mode==COM_Toggel)
	{
		_TCCR0_ |=(1<<_COM00_);
		_TCCR0_ &= ~(1<<_COM01_);

	}
	else if (C_mode==COM_Clear)
	{
		_TCCR0_ |= (1<<_COM01_);
		_TCCR0_ &= ~(1<<_COM00_);
	
	}
	else if (C_mode==COM_Set)
	{
		_TCCR0_ |=(1<< _COM01_)|(1<< _COM00_);// set
	
	}
}
