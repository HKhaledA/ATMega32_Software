/*
 * uc_Config.h
 *
 * Created: 6/28/2019 5:38:22 PM
 *  Author: Hamdy
 */ 


#ifndef UC_CONFIG_H_
#define UC_CONFIG_H_

	#include "StandardTypes.h"
	
#define F_CPU (16000000U) 
#include <util/delay.h>


typedef enum
{
 FALSE,
 TRUE,
}bool;


#define MCUCR	(*(vuint8 *)0x55)
#define MCUCSR	(*(vuint8 *)0x54)
#define SREG	(*(vuint8 *)0x5f)
#define GICR	(*(vuint8 *)0x5B)
#define GIFR	(*(vuint8 *)0x5A)

#define GLOBAL_INT_ENABLE()		(SETBIT(SREG,7))
#define GLOBAL_INT_DISABLE()	(CLEARBIT(SREG,7))

#endif /* UC_CONFIG_H_ */