/*
 * EXTI_interface.h
 *
 *  Created on: Dec 3, 2022
 *      Author: 1
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void __vector_1(void)__attribute__((signal));
void __vector_2(void)__attribute__((signal));
void __vector_3(void)__attribute__((signal));

void EXTI_VoidSet_level(u8 copy_u8INT_index,u8 copy_u8INT_Level);
void EXTI_voidEnable(u8 copy_u8INT_index);
void EXTI_voidDisable(u8 copy_u8INT_index);
void EXTI_voidGlobal_En_Dis(u8 Copy_uEn_Dis);

void EXTI_voidSet_CallBackFunction(u8 Copy_u8INTindex,void (*pvoid_Callback)(void));


#define EXTI_u8_EXTI0    0

#define EXTI_u8_EXTI1    1

#define EXTI_u8_EXTI2    2


#define EXTI_u8_EXTI0_LOW_LVL    	0b00
#define EXTI_u8_EXTI0_IOC    		0b01
#define EXTI_u8_EXTI0_FAILING_EDGE  0b10
#define EXTI_u8_EXTI0_RISING_EDGE   0b11



#define EXTI_u8_EXTI1_LOW_LVL    	0b00
#define EXTI_u8_EXTI1_IOC    		0b01
#define EXTI_u8_EXTI1_FAILING_EDGE  0b10
#define EXTI_u8_EXTI1_RISING_EDGE   0b11




#define EXTI_u8_EXTI2_FAILING_EDGE  0b0
#define EXTI_u8_EXTI2_RISING_EDGE   0b1


#define EXTI_u8Enable   0b1
#define EXTI_u8Disable  0b0

#endif /* EXTI_INTERFACE_H_ */
