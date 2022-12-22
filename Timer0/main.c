/*
 * main.c
 *
 *  Created on: Dec 16, 2022
 *      Author: 1
 */

#include "types.h"
#include "util.h"
#include "DIO_Interface.h"
#include "Timer0_private.h"
#include "Timer0_config.h"
#include "Timer0_interface.h"

u8 volatile LED_COUNTER=0;		// global variable incremented every 1 sec inside the ISR to navigate bet. 3 leds
u8 volatile flag=0;
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

int main()
{
	u8 state_0=0;
	u8 state_1=0;
	u8 state_2=0;
	/**********************************************************************/
	//setting  leds as outputs to test the Timer0 driver working with overflow interput
	DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_0,DIO_u8_OUTPUT);
	DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_1,DIO_u8_OUTPUT);
	DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_2,DIO_u8_OUTPUT);
	/*************************************************************************/
	TIMER0_INIT();
	Timer0_voidSetpreload(192); // pre-load value calculated upon event triggered every 1 sec

	while(1)
	{if (flag==1)
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
	return 0;
}
