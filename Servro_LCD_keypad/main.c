#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include "Timer1_private.h"
#include "LCD_interface.h"
#include "keybad_interface.h"
#include <avr/delay.h>

void main()
{
	u8 arr[KPD_u8_KEYS_NUM];
	LCD_void_inti();
	KPD_Void_INit();

	// mode 14 FAst PWM timer 1
	//Non inverted ->clear on compare set on top
	DIO_u8Set_Pin_direction(GROUP_D,DIO_u8_PIN_5,DIO_u8_OUTPUT);

	TIMER_TCCR1A=0b10100010; // clear on compare ,set on over flow , non inverted
	//oc1A , OC1B
	TIMER_TCCR1B=0b00011011;// prescaler 64
	TIMER_ICR1L=2499; // over flow value
	TIMER_OCR1AL=180;	// 180 on for angle 90--based on hardware
	u8 result[3]={'z','z','z'};
	u32 value=0;
	while(1)
	{
		KPD_void_Get_Status(arr);

		if(arr[0]==0)
		{
			LCD_wirte_number(7);
			_delay_ms(500);
			if(result[0]=='z')
			{
				result[0]=7;
			}
			else if(result[1]=='z')
			{
				result[1]=7;
			}
			else if(result[2]=='z')
			{
				result[2]=7;
			}
		}else if(arr[1]==0)
		{
			LCD_wirte_number(8);
			_delay_ms(500);
			if(result[0]=='z')
			{
				result[0]=8;
			}
			if(result[1]=='z')
			{
				result[1]=8;
			}
			else if(result[2]=='z')
			{
				result[2]=8;
			}

		}else if(arr[2]==0)
		{
			LCD_wirte_number(9);
			_delay_ms(500);
			if(result[0]=='z')
			{
				result[0]=9;
			}
			else if(result[1]=='z')
			{
				result[1]=9;
			}
			else if(result[2]=='z')
			{
				result[2]=9;
			}

		}else if(arr[4]==0)
		{
			LCD_wirte_number(4);
			_delay_ms(500);
			if(result[0]=='z')
			{
				result[0]=4;
			}
			else if(result[1]=='z')
			{
				result[1]=4;
			}
			else if(result[2]=='z')
			{
				result[2]=4;
			}

		}
		else if(arr[5]==0)
		{
			LCD_wirte_number(5);
			_delay_ms(500);
			if(result[0]=='z')
			{
				result[0]=5;
			}
			else if(result[1]=='z')
			{
				result[1]=5;
			}
			else if(result[2]=='z')
			{
				result[2]=5;
			}

		}
		else if(arr[6]==0)
		{
			LCD_wirte_number(6);
			_delay_ms(500);
			if(result[0]=='z')
			{
				result[0]=6;
			}
			else if(result[1]=='z')
			{
				result[1]=6;
			}
			else if(result[2]=='z')
			{
				result[2]=6;
			}

		}else if(arr[8]==0)
		{
			LCD_wirte_number(1);
			_delay_ms(500);
			if(result[0]=='z')
			{
				result[0]=1;
			}
			else if(result[1]=='z')
			{
				result[1]=1;
			}
			else if(result[2]=='z')
			{
				result[2]=1;
			}
		}
		else if(arr[9]==0)
		{
			LCD_wirte_number(2);
			_delay_ms(500);
			if(result[0]=='z')
			{
				result[0]=2;
			}
			else if(result[1]=='z')
			{
				result[1]=2;
			}
			else if(result[2]=='z')
			{
				result[2]=2;
			}
		}
		else if(arr[10]==0)
		{
			LCD_wirte_number(3);
			_delay_ms(500);
			if(result[0]=='z')
			{
				result[0]=3;
			}
			else if(result[1]=='z')
			{
				result[1]=3;
			}
			else if(result[2]=='z')
			{
				result[2]=3;
			}
		}
		else if(arr[12]==0)
		{
			LCD_wirte_number(0);
			_delay_ms(500);
			if(result[0]=='z')
			{
				result[0]=0;
			}
			else if(result[1]=='z')
			{
				result[1]=0;
			}
			else if(result[2]=='z')
			{
				result[2]=0;
			}

		}
		else if(arr[15]==0)
		{
			value=(result[0]*100)+(result[1]*10)+result[2];
			LCD_void_wirte_command(0b00000001);//display clear
			if(value<361)
			{
				LCD_wirte_number(value);
				TIMER_OCR1AL=value;
				_delay_ms(1000);

				result[0]='z';
				result[1]='z';
				result[2]='z';
				LCD_void_wirte_command(0b00000001);//display clear

			}else
			{
				LCD_void_wirte_command(0b00000001);//display clear
				_delay_ms(500);
				LCD_wirte_number(value);
				_delay_ms(1000);
				u8 str[100]={"wrong angle \0"};
				LCD_void_Display_String(str,0,0);
				_delay_ms(1000);
				LCD_void_wirte_command(0b00000001);//display clear
				result[0]='z';
				result[1]='z';
				result[2]='z';
			}
		}



	}
}
