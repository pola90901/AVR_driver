/*
 * main.c
 *
 *  Created on: 20 Nov 2022
 *      Author: pola
 */


#include<avr/io.h>
#include"types.h"
#include"util.h"

// not completed

void main (void)
{
	DDRD=0b00000001;
	DDRA=255;

	while(1)
	{

		while(Get_bit(PIND,1)==0)
		{

		}
		toggle_bit(PORTA,1);






	}

}

