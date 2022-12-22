/*
 * Timer0_private.h
 *
 *  Created on: Dec 16, 2022
 *      Author: 1
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_


#define TIMER_TCCR0  *((volatile u8*)0x53)

#define TIMER_TCNT0  *((volatile u8*)0x52)

#define TIMER_TIMSK  *((volatile u8*)0x59)

#define TIMER_SREG  *((volatile u8*)0x5F)



#define WGM01  3
#define WGM00  6


#define COM00 4
#define COM01 5

#define CS00 0
#define CS01 1
#define CS02 2


#define TOIE0 0
#define OCIE0 1



#endif /* TIMER0_PRIVATE_H_ */
