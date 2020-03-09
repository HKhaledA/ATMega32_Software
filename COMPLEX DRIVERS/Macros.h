/*
 * Macros.h
 *
 * Created: 6/28/2019 6:05:31 PM
 *  Author: Hamdy
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define SETBIT(R,B)			( (R)|= (1<<(B)))
#define CLEARBIT(R,B)		( (R)&=~(1<<(B)))
#define TOGGLEBIT(R,B)		( (R)^= (1<<(B)))
#define IS_BIT_SET(R,B)		(((R) & (1<<(B)))>>(B))
#define IS_BIT_CLEAR(R,B)	(!IS_BIT_SET(R,B))


#endif /* MACROS_H_ */


#if 0
inline static void  SETBIT(uint8 *R ,uint8 B)
{
	( (*R)|= (1<<(B)));
}
#endif