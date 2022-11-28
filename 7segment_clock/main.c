

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
{

	//DDRD=255;
	DDRA=255;
	DDRB=255;
	//DDRC=255;
	PORTA=255;
	PORTA=0b1110011
	PORTB=255;
	int x=PINA;
	u8 arr[10]={Num0,Num1,Num2,Num3,Num4,Num5,Num6,Num7,Num8,Num9};
	//u8 sec=0,min=0,hrs=0;
	while(1)
	{
			//seconds counter

		{
			for(u8 j=0;j<6;j++)
			{
				for(u8 i=0;i<10;i++)
				{
					for(u8 w=0;w<50;w++)
					{
					PORTA=arr[i];
					clear_bit(PORTB,2);
					_delay_ms(10);
					set_bit(PORTB,2);
					PORTA=arr[j];
					clear_bit(PORTB,3);
					_delay_ms(10);
					set_bit(PORTB,3);
				}
					}

		}

		_delay_ms(1000);
		}


	}
	return 0;
}

