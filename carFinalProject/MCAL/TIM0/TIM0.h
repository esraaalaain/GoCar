/*
 * Timer_driver.h
 *
 * Created: 8/27/2020 4:18:56 PM
 *  Author: Esraa
 
 1- TCCR0>> CONTROL register >> MODES(WGM00,WGM01), 2-CLOCK SELLECT(CS02,CS01,CS00), 3- Compare Output Mode
 
 *************************************************************
		  bit-6=64   bit-3=8
   mode	  WGM00   WGM01
	0		0		0		Normal 0xFF Immediate MAX
	1		0		1		PWM, Phase Correct 0xFF TOP BOTTOM
	2		1		0		CTC OCR0 Immediate MAX
	3		1		1		Fast PWM 0xFF BOTTOM MAX
 *****************************************************************
 
 non-PWM
  bit-5=32  bit-4=16
  COM01  COM00	Description
  0		 0		Normal port operation, OC0 disconnected.
  0		 1		Toggle OC0 on compare match
  1		 0		Clear OC0 on compare match
  1		 1		Set OC0 on compare match
  ******************************************************************
 Compare Output Mode, Fast PWM Mode
 bit-5=32  bit-4=16 
 COM01 COM00	Description
  0		0		Normal port operation, OC0 disconnected.
  0		1		Reserved
  1		0		Clear OC0 on compare match, set OC0 at BOTTOM,(nin-inverting mode) //
  1		1		Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)
 ********************************************************************************
 #define Norm 0
 #define Reserved 16
 #define NIN_Inverting 32
 #define Inverting 48
 
 Compare Output Mode, Phase Correct PWM Mode 

 COM01 COM00	Description
  0		 0		Normal port operation, OC0 disconnected.
  0		 1		Reserved
  1		 0		Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
  1		 1		Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.
 ********************************************************************************
  clock select (prescaler).
 bit-2,bit-1 and bit-0 in Register TCCR0
   
CS02   CS01 CS00	Description
 0		0	0		No clock source (Timer/Counter stopped).
 0		0	1		clkI/O/(No prescaling)
 0		1	0		clkI/O/8 (From prescaler)
 0		1	1		clkI/O/64 (From prescaler)
 1		0	0		clkI/O/256 (From prescaler)
 1		0	1		clkI/O/1024 (From prescaler)
 1		1	0		External clock source on T0 pin. Clock on falling edge.
 1		1	1		External clock source on T0 pin. Clock on rising edge.
**************************************************************************** 
 
 
 */ 

/************************************************************************/
/* * Timer/Counter0 Compare Match *
#define TIMER0_COMP_vect            _VECTOR(10)
#define TIMER0_COMP_vect_num        10

* Timer/Counter0 Overflow *
#define TIMER0_OVF_vect            _VECTOR(11)
#define TIMER0_OVF_vect_num        11                                                                     */
/************************************************************************/

#include "../../includes/types.h"

#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_

//bits control in mode 
#define  _WGM00_ 6
#define  _WGM01_ 3

// bits clock select 
#define _CS00_ 0
#define _CS01_ 1
#define _CS02_ 2

//bits control in compare mode  
#define _COM00_ 4
#define _COM01_ 5

//compare mode
#define COM_NORMAL 1
#define COM_Toggel 2
#define COM_Clear 3
#define COM_Set 4
//

#define Prescaler_off_ 0
#define Prescaler_1_ 1
#define Prescaler_8_  8
#define Prescaler_64_ 64
#define Prescaler_256_ 256
#define Prescaler_1024_  1024
// fast pwm
 #define Norm 0
 #define Reserved 16
 #define NIN_Inverting 32
 #define Inverting 48
//
#define MODE0 0
#define MODE1 1
#define MODE2 2
#define Fast_PWM 3
// Interrupt
#define I 7
#define _OCIE0_ 1
#define _TOIE0_ 0 

#define _TOV0_ 0 //TIFR 
#define _OCF0_ 1
/*TIMER/COUNTER0 REGISTERS */
#define _TCCR0_ *(volatile uint8_t*)(0x53)
#define _TCNT0_ *(volatile uint8_t*)(0x52)
#define _OCR0_  *(volatile uint8_t*)(0x5C)
#define _TIMSK_ *(volatile uint8_t*)(0x59)
#define _TIFR_  *(volatile uint8_t*)(0x58)
#define _SREG_  *(volatile uint8_t*)(0x5F)

	/*TIMER Interface*/
		 
	void Timer_MODEs(uint8_t T_mode);
	void SET_prescaler( uint16_t pre);
	void TIM0_STOP();
	
	void wait_ovf();


#endif /* TIMER_DRIVER_H_ */