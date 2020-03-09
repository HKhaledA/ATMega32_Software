/*
 * ATmega32A_EXT_ISR.c
 *
 * Created: 7/19/2019 3:46:43 PM
 *  Author: Hamdy
 */ 
#include "ATmega32A_EXT_ISR.h"
#include <avr/interrupt.h>

#ifndef NULL
	#define NULL	((void *)0x00)
#endif

 void ( *volatile ISR0_PTR) (void)=NULL;
 void ( *volatile ISR1_PTR) (void)=NULL;
 void ( *volatile ISR2_PTR) (void)=NULL;


ISR(INT0_vect)
{
	if (ISR0_PTR  != NULL)
	{
		ISR0_PTR();
	}	
}

ISR(INT1_vect)
{
		if (ISR1_PTR  != NULL)
		{
			ISR1_PTR();
		}
} 
ISR(INT2_vect)
{
		if (ISR2_PTR  != NULL)
		{
			ISR2_PTR();
		}
}
static void ISR_SettingError(void)
{
	while(1)
	{
		printf("HardWare Fault \n");
		// Stuck Error
	}
}

void EXT_INT_EnableFunc(
						ATmega32A_EXTINT_Control int_number,
						ATmega32A_EXTINT_Modes  int_Mode)
						{
							switch (int_number)
							{
								case EXT_INT0_CONTROL:
									 MCUCR &= (0xFC); /* Clear Prev Selection */
									 MCUCR |= (int_Mode & 0x03);
									 if((int_Mode & 0xFC) != 0)
									 {
										 ISR_SettingError(); /* Int Mode and Int Number arenot Compatible */
									 }
									 GICR |= int_number;
								break;
								case EXT_INT1_CONTROL:
								MCUCR &= (0xF3);
								MCUCR |= (int_Mode & 0x0C);
								 if((int_Mode & 0xF3) != 0)
								 {
									 ISR_SettingError(); /* Int Mode and Int Number are not Compatible */
								 }
								 GICR |= int_number;
								break;
								case EXT_INT2_CONTROL:
									 MCUCSR &= 0xBF;
									 MCUCSR |= (int_Mode & 0x40);
									 if ((int_Mode & 0xBF) != 0)
									 {
								   		ISR_SettingError(); /* Int Mode and Int Number are not Compatible */
								 	 }
									GICR |= int_number;
								break;
								default:
									ISR_SettingError(); // Wrong Int Number
								break;
								
							}
						}

void EXT_INT_DisableFunc(ATmega32A_EXTINT_Control int_number)
{
	GICR &= (~int_number);
}