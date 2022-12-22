/*
 * main.c

 *
 *  Created on: 20 Nov 2022
 *      Author: pola
 */
/*
 * Write a C code that
apply 8 different
animations on 8 LED
string based on the
value of 3 way DIP
Switch as following:
DIP value		:LED Action
1                Flashing every 500 ms
2                Shifting Left every 250 ms
3                Shifting Right every 250 ms
4                2-LEDs Converging every 300 ms
5                2-LEDs Diverging every 300 ms
6                Ping Pong effect every 250 ms
7                Incrementing (Snake effect) every 300 ms
8                2-LEDs Converging/Diverging every 300 ms
 *
 * */
#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include <avr/delay.h>

int main()
{

	// setting port A as output to connect leds
	DIO_u8Set_PORT_direction(GROUP_A,255);

	// setting pins 0,1,2 in portB as inputs
	DIO_u8Set_Pin_direction(GROUP_B,DIO_u8_PIN_0,DIO_u8_INPUT);
	DIO_u8Set_Pin_direction(GROUP_B,DIO_u8_PIN_1,DIO_u8_INPUT);
	DIO_u8Set_Pin_direction(GROUP_B,DIO_u8_PIN_2,DIO_u8_INPUT);


	// make the inputs as internal pull up resistor
	DIO_u8Set_Pin_value(GROUP_B,DIO_u8_PIN_0,DIO_u8_HIGH);
	DIO_u8Set_Pin_value(GROUP_B,DIO_u8_PIN_1,DIO_u8_HIGH);
	DIO_u8Set_Pin_value(GROUP_B,DIO_u8_PIN_2,DIO_u8_HIGH);



	while(1)
	{

		u8 stat;
		DIO_u8Get_PORT_value(GROUP_B,&stat);
		switch(stat)
		{

		case 0:
			// flashing every 500 ms
			DIO_u8Set_PORT_value(GROUP_A,255);
			_delay_ms(500);
			DIO_u8Set_PORT_value(GROUP_A,0);
			_delay_ms(500);
			break;
		case 1:
			// led shift left every 250 ms

			for(u8 i=0;i<8;i++)
			{
				DIO_u8Set_PORT_value(GROUP_A,1<<i); //1= 0b 0000 0001
				_delay_ms(250);
			}

			break;
		case 2:
			// led shift right every 250 ms
			for(u8 i=0;i<8;i++)
			{
				DIO_u8Set_PORT_value(GROUP_A,128>>i); // 128= 0b 1000 0000
				_delay_ms(250);
			}

			break;
		case 3:
			// leds converging evey  300ms
			DIO_u8Set_PORT_value(GROUP_A,129); // 129= 0b 1000 0001
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,66); // 66= 0b 0100 0010
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,36); // 128= 0b 0010 0100
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,24); // 128= 0b 0001 1000
			_delay_ms(300);
			break;
		case 4:
			// leds diverging evey  300ms
			DIO_u8Set_PORT_value(GROUP_A,24);// 24= 0b 0001 1000
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,36); // 36= 0b 0010 0100
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,66); // 66= 0b 0100 0010
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,129);  // 129= 0b 1000 0001
			_delay_ms(300);
			break;
		case 5:
			// ping bong effect
			for(u8 i=0;i<8;i++)
			{
				DIO_u8Set_PORT_value(GROUP_A,1<<i); //1= 0b 0000 0001
				_delay_ms(250);
			}
			for(u8 i=0;i<8;i++)
			{
				DIO_u8Set_PORT_value(GROUP_A,128>>i); // 128= 0b 1000 0000
				_delay_ms(250);
			}
			break;
		case 6:
			// increment snake effect
			DIO_u8Set_PORT_value(GROUP_A,0);
			for(u8 i=0;i<8;i++)
			{
				DIO_u8Set_Pin_value(GROUP_A,i,DIO_u8_HIGH);
				_delay_ms(300);
			}

			break;
		case 7:

			//converging then diverging every 300 ms
			DIO_u8Set_PORT_value(GROUP_A,129); // 129= 0b 1000 0001
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,66); // 66= 0b 0100 0010
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,36); // 128= 0b 0010 0100
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,24); // 128= 0b 0001 1000
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,24);// 24= 0b 0001 1000
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,36); // 36= 0b 0010 0100
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,66); // 66= 0b 0100 0010
			_delay_ms(300);
			DIO_u8Set_PORT_value(GROUP_A,129);  // 129= 0b 1000 0001
			_delay_ms(300);

			break;
		}

	}
	return 0;
}






