/*
 * Timer0_interface.h
 *
 *  Created on: Dec 16, 2022
 *      Author: 1
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


void TIMER0_INIT(void);

void Timer_voidSetMode(u8 Copy_u8Mode);
void Timer_voidCompare_output_mode_Non_PWM(u8 Copy_u8Operation);
void Timer0_VoidClockSelect(u8 Copy_u8Prescaler);
void Timer0_voidInterruptEnable(u8 Copy_u8Mask);
void Timer0_voidSetpreload(u8 Copy_u8PreloadValue);


#endif /* TIMER0_INTERFACE_H_ */
