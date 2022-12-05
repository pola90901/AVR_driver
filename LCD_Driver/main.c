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

	u8 arr[]={"polar"};
	LCD_void_Display_String(arr,2,0);
*/
	u8 ch[]={17, 10, 4, 10, 17, 0, 0, 0};

	LCD_Set_CG_RAM_ADD(0);
	for(u8 i=0;i<8;i++)
	{
		LCD_void_wirte_data(ch[i]);
	}
	LCD_void_Set_DDRam_ADD(0);
	LCD_void_wirte_data(0);



	while(1)
	{

	}
}

