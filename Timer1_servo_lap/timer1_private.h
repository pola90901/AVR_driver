/*
 * timer1_private.h
 *
 *  Created on: Dec 17, 2022
 *      Author: 1
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_


#define TIMER_TCCR1A  *((volatile u8*)0x4F)

#define TIMER_TCCR1B  *((volatile u8*)0x4E)

#define TIMER_OCR1AH  *((volatile u8*)0x4B)
#define TIMER_OCR1AL  *((volatile u16*)0x4A)//u16 -->3shan lma agy aktb values kbera ttktb feh we feh el mkan el ba3do

#define TIMER_ICR1H  *((volatile u8*)0x47)
#define TIMER_ICR1L *((volatile u16*)0x46)//u16 -->3shan lma agy aktb values kbera ttktb feh we feh el mkan el ba3do




#endif /* TIMER1_PRIVATE_H_ */
