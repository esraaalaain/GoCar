/*
 * Interrupt.h
 *
 * Created: 9/24/2020 6:39:48 AM
 *  Author: Esraa
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

void __vector_12 (void) __attribute__((signal,used));//Compare Interrupt 
void __vector_11 (void) __attribute__((signal,used));// Timer Interrupt

#endif /* INTERRUPT_H_ */