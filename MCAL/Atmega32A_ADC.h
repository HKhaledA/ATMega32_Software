/*
 * Atmega32A_ADC.h
 *
 * Created: 8/23/2019 5:28:11 PM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_ADC_H_
#define ATMEGA32A_ADC_H_


	#include <uc_Config.h>
	#include <ATmega32A_GPIO.h>
	#include <Macros.h>
	#include <StandardTypes.h>
	

	#define ADMUX	((IO_register*)0x27)
	#define ADCSRA	((IO_register*)0x26)
	#define SFIOR	((IO_register*)0x50)
	#define ADCL	(*(uint8*)0x24)
	#define ADCH	(*(uint8*)0x25)


typedef enum
{
	AREF_VoltRef=0x00,
	AVCC_VoltRef=0x40,
	_2_56V_VoltREF=0xC0,
}ADC_VoltRef;

typedef enum
{
	LEFT_Adjust=0x20,
	RIGHT_Adjust=0x00,
}ADC_DataAdjustment;

typedef enum
{
	ADC0_Channel,
	ADC1_Channel,
	ADC2_Channel,
	ADC3_Channel,
	ADC4_Channel,
	ADC5_Channel,
	ADC6_Channel,
	ADC7_Channel,
	DIFF_PADC0_NADC0_G10x,
	DIFF_PADC1_NADC0_G10x,
}ADC_ChSelect;


typedef enum
{
	SingleConvertion=0x0000,
	AutoTrig_FreeRun=0x0020,
	AutoTrig_AnalogComp=0x2020,
	
}ADC_TrigMode;

typedef enum
{
	ADC_Polling=0x00,
	ADC_InterruptEnable=0x08,
}ADC_WorkMode;

typedef enum
{
	ADC_Div_2=0x01,
	ADC_Div_4,
	ADC_Div_8,
	ADC_Div_16,
	ADC_Div_32,
	ADC_Div_64,
	ADC_Div_128,
}ADC_Prescale;

typedef enum
{
	ADC_8Bit,
	ADC_10Bit,
}ADC_Res;

typedef struct 
{
	uint8			ADC_Enable : 1;	// Set This Bit to 1 To Enable ADC , 0 To Disable
	ADC_TrigMode	ADC_Mode;		// Refer to ADC_TrigMode Enum , Refer to P00 Datasheet	
	ADC_Prescale	ADC_FreqDiv;	// Freq Must Be Between 50 ~ 200Khz 
	ADC_Res			ADC_Resolution;	// Refer to ADC_Res Enum
	ADC_WorkMode	ADC_Interrupt;	// Refer to ADC_WorkMode Enum
	void (*volatile ADC_InterruptFunc) (void * inData); // Call Back Function For ADC Interrupt 
	
	ADC_VoltRef		ADC_VoltageReferPin;	// refer to ADC_VoltRef	
	float32			ADC_VolatgeRefer_Value;	// Please Set Reference Volt value
	
	ADC_ChSelect	ADC_Channel;			// Select ADC Channel
	uint8			ADC_Gain;
	uint8			ADC_StartConvertion;	// Set This Bit to 1 To Start an ADC Conversion , Clears Automatically 
	float32			ADC_Output_InVolts;		// ADC Read Data Converted to Volts
	uint16			ADC_Output;				// ADC Read Data 
}ADC_ControlStruct;

extern ADC_ControlStruct ADC_ControlBlock;


void ADC_Init(void);
void ADC_Update(void);

#endif /* ATMEGA32A_ADC_H_ */