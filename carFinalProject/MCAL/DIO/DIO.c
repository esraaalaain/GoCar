
#include "../../includes/registers.h"
#include "../../includes/definitions.h"
	
void DIO_INIT_BIT(int /*PORTX (i.e. PORT_A, PORT_B..)*/ PORT_NAME, int /*PIN_NO (i.e. 0, 1, 2..)*/ PIN_NO, int /*Direction (i.e. INPUT, OUTPUT)*/ DIR){
	switch (PORT_NAME){
		case PORT_A:
		switch (DIR){
			case INPUT:
			PA_DIR &= ~(1<<PIN_NO);
			break;
			case OUTPUT:
			PA_DIR |= (1<<PIN_NO);
		break;}
		break;
		
		case PORT_B:
		switch (DIR){
			case INPUT:
			PB_DIR &= ~(1<<PIN_NO);
			break;
			case OUTPUT:
			PB_DIR |= (1<<PIN_NO);
		break;}
		
		break;
		
		case PORT_C:
		switch (DIR){
			case INPUT:
			PC_DIR &= ~(1<<PIN_NO);
			break;
			case OUTPUT:
			PC_DIR |= (1<<PIN_NO);
		break;}
		
		break;
		
		case PORT_D:
		switch (DIR){
			case INPUT:
			PD_DIR &= ~(1<<PIN_NO);
			break;
			case OUTPUT:
			PD_DIR |= (1<<PIN_NO);
		break;}
		
		break;
		
	}
}

void DIO_WRITE_BIT(int /*PORTX (i.e. PORT_A, PORT_B..)*/ PORT_NAME, int /*PIN_NO (i.e. 0, 1, 2..)*/ PIN_NO, int /*LEVEL (i.e. LOW, HIGH)*/ LEVEL){
	switch (PORT_NAME){
		case PORT_A:
		switch (LEVEL){
			case LOW:
			PA_OUT &= ~(1<<PIN_NO);
			break;
			case HIGH:
			PA_OUT |= (1<<PIN_NO);
		break;}
		break;
		
		case PORT_B:
		switch (LEVEL){
			case LOW:
			PB_OUT &= ~(1<<PIN_NO);
			break;
			case HIGH:
			PB_OUT |= (1<<PIN_NO);
		break;}
		
		break;
		
		case PORT_C:
		switch (LEVEL){
			case LOW:
			PC_OUT &= ~(1<<PIN_NO);
			break;
			case HIGH:
			PC_OUT |= (1<<PIN_NO);
		break;}
		
		break;
		
		case PORT_D:
		switch (LEVEL){
			case LOW:
			PD_OUT &= ~(1<<PIN_NO);
			break;
			case HIGH:
			PD_OUT |= (1<<PIN_NO);
		break;}
		
		break;
		
	}
}

uint8_t DIO_READ_BIT(int /*PORTX (i.e. PORT_A, PORT_B..)*/ PORT_NAME, int /*PIN_NO (i.e. 0, 1, 2..)*/ PIN_NO){
	uint8_t read_data = 0;
	switch (PORT_NAME){
		case PORT_A:
		read_data = PA_IN;
		read_data = read_data>>PIN_NO;
		read_data &= 0X01;
		break;
		
		case PORT_B:
		read_data = PB_IN;
		read_data = read_data>>PIN_NO;
		read_data &= 0X01;
		break;
		
		case PORT_C:
		read_data = PC_IN;
		read_data = read_data>>PIN_NO;
		read_data &= 0X01;
		break;
		
		case PORT_D:
		read_data = PD_IN;
		read_data = read_data>>PIN_NO;
		read_data &= 0X01;
		break;
		
	}
	
	return read_data;
}

void DIO_TOGGLE_BIT(int PORT_NAME, int PIN_NO){
	
	if(DIO_READ_BIT(PORT_NAME, PIN_NO)){
		DIO_WRITE_BIT(PORT_NAME, PIN_NO, LOW);
	}
	else{
		DIO_WRITE_BIT(PORT_NAME, PIN_NO, HIGH);
	}
	return;
}

void DIO_INIT(int /*PORTX (i.e. PORT_A, PORT_B..)*/ PORT_NAME, uint8_t value){
	switch (PORT_NAME){
		case PORT_A:
		PA_DIR = value;
		break;
		
		case PORT_B:
		PB_DIR = value;
		break;
		
		case PORT_C:
		PC_DIR = value;
		break;
		
		case PORT_D:
		PD_DIR = value;
		break;
		
	}

}

void DIO_WRITE(int /*PORTX (i.e. PORT_A, PORT_B..)*/ PORT_NAME, uint8_t value){
	switch (PORT_NAME){
		case PORT_A:
		PA_OUT = value;
		break;
		
		case PORT_B:
		PB_OUT = value;
		break;
		
		case PORT_C:
		PC_OUT = value;
		break;
		
		case PORT_D:
		PD_OUT = value;
		break;
		
	}
}

uint8_t DIO_READ(int /*PORTX (i.e. PORT_A, PORT_B..)*/ PORT_NAME){
	switch (PORT_NAME){
		case PORT_A:
		return PA_IN;
		break;
		
		case PORT_B:
		return PB_IN;
		break;
		
		case PORT_C:
		return PC_IN;
		break;
		
		case PORT_D:
		return PD_IN;
		break;
		
	}
	return -1;
}