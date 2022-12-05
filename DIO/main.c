/*
 * main.c

 *
 *  Created on: 20 Nov 2022
 *      Author: pola
 */

#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include <avr/delay.h>

int main()
{
	u8 res;
	DIO_u8Set_PORT_direction(GROUP_A,255);
	while(1)
	{

	//	DIO_u8Get_PORT_value(GROUP_C,&res);

		DIO_u8Set_PORT_value(GROUP_A,255);
		_delay_ms(500);
		DIO_u8Set_PORT_value(GROUP_A,0);
		_delay_ms(500);


	}



	return 0;
}






