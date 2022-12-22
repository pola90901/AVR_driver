/*
 * main.c
Assignment 1
Write a C code that simulate the traffic lightening system:
1- Turn On Green LED for 10 seconds
2- Turn On Yellow LED for 3 seconds
3- Turn On Red LED for 10 seconds
4- Apply these forever while counting the seconds down on a
two 7-segment displays.
 *
 *  Created on: 20 Nov 2022
 *      Author: pola
 */

#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include "7seg.h"
#define F_CPU 8000000
#include <avr/delay.h>

int main()
{

	// array to represent the numbers to be displayed on 7 segments
	u8 arr[10]={Num0,Num1,Num2,Num3,Num4,Num5,Num6,Num7,Num8,Num9};

	//setting port Band A  as outputs for 2x  7 segment
	DIO_u8Set_PORT_direction(GROUP_B,255);
	DIO_u8Set_PORT_direction(GROUP_A,255);

	// setting 3 pins port C as out for leds
	DIO_u8Set_Pin_direction(GROUP_C,DIO_u8_PIN_5,DIO_u8_OUTPUT);
	DIO_u8Set_Pin_direction(GROUP_C,DIO_u8_PIN_6,DIO_u8_OUTPUT);
	DIO_u8Set_Pin_direction(GROUP_C,DIO_u8_PIN_7,DIO_u8_OUTPUT);
	while(1)
	{
		// green led on
		DIO_u8Set_Pin_value(GROUP_C,DIO_u8_PIN_5,DIO_u8_HIGH);


		// counting 10 sec on 2 7 segments
		for(u8 i=0;i<10;i++)
		{
			DIO_u8Set_PORT_value(GROUP_A,arr[0]);
			DIO_u8Set_PORT_value(GROUP_B,arr[i]);
			_delay_ms(1000);
			if(i==9)
			{
				DIO_u8Set_PORT_value(GROUP_B,arr[0]);
				DIO_u8Set_PORT_value(GROUP_A,arr[1]);
				_delay_ms(1000);
			}
		}
		// led green off
		DIO_u8Set_Pin_value(GROUP_C,DIO_u8_PIN_5,DIO_u8_LOW);
		//led yellow on
		DIO_u8Set_Pin_value(GROUP_C,DIO_u8_PIN_6,DIO_u8_HIGH);
		// counting 3 sec on 2x 7 segments
		for(u8 i=1;i<4;i++)
		{
			DIO_u8Set_PORT_value(GROUP_A,arr[0]);
			DIO_u8Set_PORT_value(GROUP_B,arr[i]);
			_delay_ms(1000);

		}
		//led yellow off
		DIO_u8Set_Pin_value(GROUP_C,DIO_u8_PIN_6,DIO_u8_LOW);
		//led red on
		DIO_u8Set_Pin_value(GROUP_C,DIO_u8_PIN_7,DIO_u8_HIGH);

		// counting 10 sec on 2 7 segments
		for(u8 i=0;i<10;i++)
		{
			DIO_u8Set_PORT_value(GROUP_A,arr[0]);
			DIO_u8Set_PORT_value(GROUP_B,arr[i]);
			_delay_ms(1000);
			if(i==9)
			{
				DIO_u8Set_PORT_value(GROUP_B,arr[0]);
				DIO_u8Set_PORT_value(GROUP_A,arr[1]);
				_delay_ms(1000);
			}
		}

		//led red off
		DIO_u8Set_Pin_value(GROUP_C,DIO_u8_PIN_7,DIO_u8_LOW);


	}



	return 0;
}






