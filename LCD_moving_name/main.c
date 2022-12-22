/*Write your name moving in sinusoidal wave on the LCD*/
#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include"LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include <avr/delay.h>
int  main()
{

	LCD_void_inti();
	u8 arr[]={"pola"};
	u8 j=0;
	while(1)
	{
		for(u8 i=0;i<11;i++)
		{
			LCD_void_Display_String(arr,i,j=!j); // writing each time at x increment by 1 and y toggled between 2 lines
			_delay_ms(500);
			LCD_void_wirte_command(0b00000001);//display clear

		}

	}
	return 0;
}

