/*
 * main.c
 *
 *  Created on: 18 Nov 2022
 *      Author: pola
 */

#include<avr/io.h>
#include <avr/delay.h>
#include"types.h"
#include"util.h"

#define  Num9 0x6f
#define  Num8 0x7F
#define  Num7 0x07
#define  Num6 0b11111101
#define  Num5 0x6D
#define  Num4 0x66
#define  Num3 0x4F
#define  Num2 0x5B
#define  Num1 0x06
#define  Num0 0x3F


int main(void)
{//	1x 7 segment count 0 to 9

	DDRD=255;
	DDRA=255;
	DDRB=255;
	DDRC=255;
	PORTA=255;
	PORTB=0;
	PORTC=255;
	u8 arr[10]={Num0,Num1,Num2,Num3,Num4,Num5,Num6,Num7,Num8,Num9};
	while(1)
	{
		for(u8 i=0;i<10;i++)
		{
			PORTD=arr[i];
			_delay_ms(100);
		}
	}





	return 0;
}
