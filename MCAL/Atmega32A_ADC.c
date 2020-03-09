/*
 * Atmega32A_ADC.c
 *
 * Created: 8/23/2019 5:28:01 PM
 *  Author: Hamdy
 */ 


#include <Atmega32A_ADC.h>


#ifdef _AVR_ATMEGA32A_H_INCLUDED
	#error "ASYOD"
#endif

ADC_ControlStruct ADC_ControlBlock;


void	ADC_Init(void)
{
		if		(ADC_ControlBlock.ADC_Enable == 1)
		{
				ADMUX->Reg =  ADC_ControlBlock.ADC_VoltageReferPin;
				
				
				SFIOR->Reg &= 0x0f;
				SFIOR->Reg |= (ADC_ControlBlock.ADC_Mode >> 8); 
				ADCSRA->Reg = (1<<7)
						|(ADC_ControlBlock.ADC_Mode&(0x00ff))
						| ADC_ControlBlock.ADC_Interrupt
						| ADC_ControlBlock.ADC_FreqDiv;
		}
		else
		{
				ADCSRA->Reg = 0;
		}
}

void ADC_Update(void)
{
	uint16 Temp_data=0;
	ADMUX->Reg &= 0xC0;
	ADMUX->Reg |= ADC_ControlBlock.ADC_Channel;
	if		(ADC_ControlBlock.ADC_Resolution == ADC_10Bit)
	{
		ADMUX->Reg |= RIGHT_Adjust;
	}
	else
	{
		ADMUX->Reg |= LEFT_Adjust;
	}
	
	if		(ADC_ControlBlock.ADC_StartConvertion == 1)
	{
			ADC_ControlBlock.ADC_StartConvertion=0;
			ADCSRA->Reg |= (1<<6); // start Conversion 
			if		(ADC_ControlBlock.ADC_Interrupt == ADC_InterruptEnable)
			{
				return;
			}
			else
			{
				// Polling Code
				while	(IS_BIT_CLEAR(ADCSRA->Reg,4)){}
				if		(ADC_ControlBlock.ADC_Resolution == ADC_10Bit)
				{
					Temp_data = ADCL;
					Temp_data |= ADCH<<8;
					
					ADC_ControlBlock.ADC_Output = Temp_data;
					if		(ADC_ControlBlock.ADC_Channel > 7 && ADC_ControlBlock.ADC_Channel < 30 )
					{
							if (ADC_ControlBlock.ADC_Resolution == ADC_10Bit)
							{
								ADC_ControlBlock.ADC_Output_InVolts = ((float)Temp_data*ADC_ControlBlock.ADC_VolatgeRefer_Value)/(512.0 * ADC_ControlBlock.ADC_Gain);
							}
							else
							{
								ADC_ControlBlock.ADC_Output_InVolts = ((float)Temp_data*ADC_ControlBlock.ADC_VolatgeRefer_Value)/(128.0 * ADC_ControlBlock.ADC_Gain);
							}
					}
					else
					{
							if (ADC_ControlBlock.ADC_Resolution == ADC_10Bit)
							{
								ADC_ControlBlock.ADC_Output_InVolts = ((float)Temp_data*ADC_ControlBlock.ADC_VolatgeRefer_Value)/1024.0;
							}
							else
							{
								ADC_ControlBlock.ADC_Output_InVolts = ((float)Temp_data*ADC_ControlBlock.ADC_VolatgeRefer_Value)/256.0;
							}
					}
					
				}
				SETBIT(ADCSRA->Reg,4);	
			}
	}
		return;
}