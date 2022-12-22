/*
 * main.c
 *
 *  Created on: Dec 16, 2022
 *      Author: 1
 */


#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include "Timer0_private.h"
#include "Timer0_config.h"
#include "Timer0_interface.h"

#include <avr/delay.h>
// timer 0 over flow interrupt
void __vector_11(void)__attribute((signal)); // vector  based on data sheet vector table for overflow timer0



u8 volatile LED_COUNTER=0;		// global variable incremented every 1 sec inside the ISR to navigate bet. 3 leds
u8 volatile flag=0;		// global variable incremented every 1 sec inside the ISR avoid changing of the leds more than one time evert 1 sec
						// as the speed of MCU is fast running with 8 MHz	to to avoid toggle the led at wrong times we need this variable

void __vector_11(void){
	static  u16 counter =0;			//a counter used to to incremented every time  the timer overflow call the Vector 11 (ISR)
									//to calculate the times of requested overflows to reach 1 sec
	counter++;
	if (counter==3907)
	{
		flag=1;
		LED_COUNTER++;
		counter =0;
		// preload value to start count from 192 to overflow at 255 to cover the diff. in the equation used to calculate the 1 sec
		TIMER_TCNT0=192;
	}
}

void main()
{
	u8 state_0=0;
	u8 state_1=0;
	u8 state_2=0;
	// to toggle pin
	DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_0,DIO_u8_OUTPUT);
	DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_1,DIO_u8_OUTPUT);
	DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_2,DIO_u8_OUTPUT);
	TIMER_TCCR0=0b00000010;			   // normal mode bit 3,6 ==0
									  //OCO disconnected bits 5,4 ==0
								   	 // pre scaller = 8 bit 2 ,1 ,0 = 010
	set_bit(TIMER_TIMSK,0);			// enable timer0 over flow enable interrupt
	set_bit(TIMER_SREG,7);  	   // enable global interrupt
	TIMER_TCNT0=192;
							// start count from 192 to 255 as a preload value to handle the no. of over flow needed to to work every 1 sec
	while(1)
	{
		if (flag==1)
		{
			if(LED_COUNTER % 1 ==0)
			{
				DIO_u8Set_Pin_value(GROUP_A,DIO_u8_PIN_0,toggle_bit(state_0,0));
			}
			if(LED_COUNTER % 2 ==0)
			{
				DIO_u8Set_Pin_value(GROUP_A,DIO_u8_PIN_1,toggle_bit(state_1,0));
			}
			if(LED_COUNTER % 3 ==0)
			{
				DIO_u8Set_Pin_value(GROUP_A,DIO_u8_PIN_2,toggle_bit(state_2,0));
			}
			flag=0;
		}
	}
}
