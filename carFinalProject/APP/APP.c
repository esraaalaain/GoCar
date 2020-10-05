

#include "../MCAL/TIM0_PWM/TIM0_PWM.h"
#include "../ECUAL/CAR/CAR.h"
#include "../ECUAL/REMOTE/REMOTE.h"


void APP_INIT(){
	
	TIM0_PWM_INIT();
	
	REMOTE_INIT();
	
	CAR_INIT();
	
}

void APP_UPDATE(){
	
	while(REMOTE_MOVE_PRESSED()){
		REMOTE_MOVE();
	}
	
	CAR_STOP();
	
	while(REMOTE_LEFT_PRESSED()){
		REMOTE_LEFT();
	}
	
	CAR_STOP();
	
	while(REMOTE_RIGHT_PRESSED()){
		REMOTE_RIGHT();
	}
	
	CAR_STOP();
	
	if(REMOTE_G_PRESSED()){
		REMOTE_G();
	}
}