

#ifndef TIM0_PWM_H_
#define TIM0_PWM_H_

#define DUTY_30 30
#define DUTY_60 60
#define DUTY_90 90

	/* PWM Interface */
	void TIM0_PWM_start(float duty, float freq);
	void PWM_STOP();
	void TIM0_PWM_INIT();

#endif