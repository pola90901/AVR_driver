/*
 * EXTI_private.h
 *
 *  Created on: Dec 3, 2022
 *      Author: 1
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define EXTI__u8_MCUCR        	  *((volatile u8*)0x55)
#define EXTI__u8_MCUCSR      	  *((volatile u8*)0x54)
#define EXTI__u8_GICR      	  *((volatile u8*)0x5B)
#define EXTI__u8_SREG     	  *((volatile u8*)0x5F)
#define NULL 		((void*)0)

#endif /* EXTI_PRIVATE_H_ */
