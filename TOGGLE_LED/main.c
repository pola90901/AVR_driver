/*
 * main.c
 *
 *  Created on: 18 Nov 2022
 *      Author: pola
 */
#include<avr/io.h>
#include<avr/delay.h>
#include"types.h"
#include"util.h"
int main()
{
	DDRA=0b11111111;
	while(1)
	{
		for(u8 i=0;i<8;i++)
		{
			set_bit(PORTA,i);

			//PORTA=0b00000001;
			_delay_ms(10);
			clear_bit(PORTA,i);
			//PORTA=0b00000000;
			_delay_ms(10);
		}

	}
	return 0;
}
