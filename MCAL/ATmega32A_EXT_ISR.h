/*
 * ATmega32A_EXT_ISR.h
 *
 * Created: 7/19/2019 3:46:55 PM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_EXT_ISR_H_
#define ATMEGA32A_EXT_ISR_H_

	#include "Macros.h"
	#include "uc_Config.h"
	#include "StandardTypes.h"
	

typedef enum
{
	EXT_INT0_LOW=0x00,
	EXT_INT0_TOGGLE=0x01,
	EXT_INT0_RISING=0x03,
	EXT_INT0_FALLING=0x02,
	EXT_INT1_LOW=0x00,
	EXT_INT1_TOGGLE=0x04,
	EXT_INT1_RISING=0x0C,
	EXT_INT1_FALLING=0x08,
	EXT_INT2_RISING=0x40,
	EXT_INT2_FALLING=0x00,
}ATmega32A_EXTINT_Modes;

typedef enum
{
	EXT_INT0_CONTROL=0x40,
	EXT_INT1_CONTROL=0x80,
	EXT_INT2_CONTROL=0x20,
}ATmega32A_EXTINT_Control;

void EXT_INT_EnableFunc(
						ATmega32A_EXTINT_Control int_number,
						ATmega32A_EXTINT_Modes  int_Mode
						);
						
void EXT_INT_DisableFunc(
						ATmega32A_EXTINT_Control int_number
						);

extern void ( *volatile ISR0_PTR) (void);
extern void ( *volatile ISR1_PTR) (void);
extern void ( *volatile ISR2_PTR) (void);
#endif /* ATMEGA32A_EXT_ISR_H_ */