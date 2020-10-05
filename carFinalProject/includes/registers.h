#include "types.h"

#ifndef _ATMEGA32A_REGISTERS_H_
#define _ATMEGA32A_REGISTERS_H_

#define PA_DIR *((volatile uint8_t*) (0X3A))
#define PA_IN *((volatile uint8_t*) (0X39))
#define PA_OUT *((volatile uint8_t*) (0X3B))

#define PB_DIR *((volatile uint8_t*) (0X37))
#define PB_IN *((volatile uint8_t*) (0X36))
#define PB_OUT *((volatile uint8_t*) (0X38))

#define PC_DIR *((volatile uint8_t*) (0X34))
#define PC_IN *((volatile uint8_t*) (0X33))
#define PC_OUT *((volatile uint8_t*) (0X35))

#define PD_DIR *((volatile uint8_t*) (0X31))
#define PD_IN *((volatile uint8_t*) (0X30))
#define PD_OUT *((volatile uint8_t*) (0X32))

#define TIM_INT_EN *((volatile uint8_t*) (0X59))
#define TIM_FLAGS  *((volatile uint8_t*) (0X58))

#define TIM0_CNT   *((volatile uint8_t*) (0X52))
#define TIM0_CTRL  *((volatile uint8_t*) (0X53))
#define TIM0_OCR   *((volatile uint8_t*) (0X5C))

#endif