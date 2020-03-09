/*
 * ATmega32A_GPIO.h
 *
 * Created: 7/5/2019 2:54:43 PM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_GPIO_H_
#define ATMEGA32A_GPIO_H_

	#include "Macros.h"
	#include "StandardTypes.h"
	#include "uc_Config.h"
	

#define GPIOA	((volatile GPIO_Struct *)0x39)
#define GPIOB	((volatile GPIO_Struct *)0x36)
#define GPIOC	((volatile GPIO_Struct *)0x33)
#define GPIOD	((volatile GPIO_Struct *)0x30)

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
}HW_pins;

typedef enum
{
	INPUT_FLOAT,
	INPUT_PULLUP,
	OUTPUT,
}PinMode;

typedef enum
{
	LOW,
	HIGH,
}DigitalSignals;


typedef union
{
	vuint8 Reg;
	struct  
	{
		// Bit Fields
		vuint8 B0:1;
		vuint8 B1:1;
		vuint8 B2:1;
		vuint8 B3:1;
		vuint8 B4:1;
		vuint8 B5:1;
		vuint8 B6:1;
		vuint8 B7:1;
	}Bits;
}IO_register;


typedef struct 
{
	IO_register PIN_reg;
	IO_register DDR_reg;
	IO_register PORT_reg;
}GPIO_Struct;

void		   IO_DirectionConfig(
									volatile GPIO_Struct * P_Gpio,
									HW_pins Pin_no,
									PinMode Mode
								  );
void		   IO_OutputWrite(
								volatile GPIO_Struct * P_Gpio,
								HW_pins Pin_no,
								DigitalSignals Signal
							  );
DigitalSignals IO_InputRead(
							volatile GPIO_Struct * P_Gpio,
							HW_pins Pin_no
							);
#endif /* ATMEGA32A_GPIO_H_ */