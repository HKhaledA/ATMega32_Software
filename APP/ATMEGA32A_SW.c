/*
 * ATMEGA32A_SW.c
 *
 * Created: 6/28/2019 5:27:16 PM
 *  Author: Hamdy
 */ 



#include "ATmega32A_GPIO.h"
#include <ATmega32A_EXT_ISR.h>
#include <Atmega32A_ADC.h>
#include <LCD.h>
int main(void)
{
	 /* Change Req Settings Struct */
	 ADC_ControlBlock.ADC_Enable=1;
	 ADC_ControlBlock.ADC_Mode= SingleConvertion;
	 ADC_ControlBlock.ADC_FreqDiv=ADC_Div_128;
	 ADC_ControlBlock.ADC_Resolution=ADC_10Bit;
	 ADC_ControlBlock.ADC_Interrupt=ADC_Polling;
	 ADC_ControlBlock.ADC_VoltageReferPin=AREF_VoltRef;
	 ADC_ControlBlock.ADC_VolatgeRefer_Value=1.6;
	 ADC_ControlBlock.ADC_Channel=ADC0_Channel;
	 ADC_Init();
	 LCD_init();
	 while(1)
    {
			 ADC_ControlBlock.ADC_Channel=ADC0_Channel;
			ADC_ControlBlock.ADC_StartConvertion=1;
			ADC_Update();	
			LCD_DisplayString("Temp = ");
			LCD_DisplayInt(ADC_ControlBlock.ADC_Output_InVolts*100);
			LCD_DisplayString("C");
			
			ADC_ControlBlock.ADC_Channel=ADC1_Channel;
			ADC_ControlBlock.ADC_StartConvertion=1;
			LCD_Select_RowCol(1,0);
			LCD_DisplayString("Volt = ");
			ADC_Update();	
			LCD_DisplayInt(ADC_ControlBlock.ADC_Output_InVolts);
			LCD_DisplayString(".");
			ADC_ControlBlock.ADC_StartConvertion=1;
			ADC_Update();	
			LCD_DisplayInt(((uint32)(ADC_ControlBlock.ADC_Output_InVolts*10))%10);
			LCD_DisplayString("V");
			_delay_ms(250);
			LCD_Clear();
    }
}


