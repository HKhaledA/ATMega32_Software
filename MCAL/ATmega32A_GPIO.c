/*
 * ATmega32A_GPIO.c
 *
 * Created: 7/5/2019 2:54:26 PM
 *  Author: Hamdy
 */ 


#include "ATmega32A_GPIO.h"

void		   IO_DirectionConfig( volatile GPIO_Struct * P_Gpio, HW_pins Pin_no, PinMode Mode)
{
	switch (Mode)
	{
		case INPUT_FLOAT:
		     CLEARBIT(P_Gpio->DDR_reg.Reg,Pin_no);
			 CLEARBIT(P_Gpio->PORT_reg.Reg,Pin_no);
		break;
		case INPUT_PULLUP:
			 CLEARBIT(P_Gpio->DDR_reg.Reg,Pin_no);
			 SETBIT(P_Gpio->PORT_reg.Reg,Pin_no);
		break;
		case OUTPUT:
			 SETBIT(P_Gpio->DDR_reg.Reg,Pin_no);
		break;
		default:
			printf("Invalid Parameters in Direction Config\n");
		break;
	}
	
	
}
void		   IO_OutputWrite(volatile GPIO_Struct * P_Gpio,HW_pins Pin_no,DigitalSignals Signal)
{
	switch (Signal)
	{
		case HIGH:
			 SETBIT(P_Gpio->PORT_reg.Reg , Pin_no);	
		break;
		case LOW:
			 CLEARBIT(P_Gpio->PORT_reg.Reg , Pin_no);	
		break;
		default:
			printf("invalid input for Output Write Function\n");
		break;
	}	
}

DigitalSignals IO_InputRead(volatile GPIO_Struct * P_Gpio,HW_pins Pin_no)
{
	 if (IS_BIT_SET(P_Gpio->PIN_reg.Reg, Pin_no))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}