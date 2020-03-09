/*
 * SLEEDP_MODULE_ATMEGA32A.h
 *
 * Created: 4/20/2019 5:08:38 PM
 *  Author: Hamdy
 */ 


#ifndef SLEEDP_MODULE_ATMEGA32A_H_
#define SLEEDP_MODULE_ATMEGA32A_H_

	#include "uc_Config.h"
	
	
	typedef enum
	{
		IDLE = 0,
		ADC_NOISE_REDUCTION=0x10,
		POWER_DOWN=0x20,
		POWER_SAVE=0x30,
		STANDBY = 0x60,
		EXTEND_STANDBY=0x70,
	}SleepModes;
#define SLEEP_MODULE_ENABLE()	(MCUCR |= (1<<7))
#define SLEEP_MODULE_DISABLE()	(MCUCR &=~(1<<7))
#define SLEEP_MODE_SELECT(Mode) do{MCUCR &= 0x8F; MCUCR |= Mode; }while(0)
#define SLEEP_NOW()		  __asm__ __volatile__("SLEEP""\n\t"::);


#endif /* SLEEDP_MODULE_ATMEGA32A_H_ */