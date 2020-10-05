
#include "../../includes/types.h"

#ifndef _DIO_H_
#define _DIO_H_
	
	/*DIO Interface*/
	
	void DIO_INIT_BIT(int PORT_NAME, int PIN_NO, int DIR);
	void DIO_WRITE_BIT(int PORT_NAME, int PIN_NO, int LEVEL);
	uint8_t DIO_READ_BIT(int PORT_NAME, int PIN_NO);
	void DIO_TOGGLE_BIT(int PORT_NAME, int PIN_NO);

	void DIO_INIT(int PORT_NAME, uint8_t value);
	void DIO_WRITE(int PORT_NAME, uint8_t value);
	uint8_t DIO_READ(int  PORT_NAME);


#endif