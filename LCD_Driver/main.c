#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include"LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include <avr/delay.h>
void main()
{

	LCD_void_inti();
	/*
	 *
	 LCD_void_Set_DDRam_ADD(64);
	LCD_void_wirte_data('P');
	LCD_void_wirte_data('O');
	LCD_void_wirte_data('L');
	LCD_void_wirte_data('A');
*/
	u8 arr[]={"polar"};
	LCD_void_Display_String(arr,2,0);
	while(1)
	{

	}
}

