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

	LCD_void_wirte_data('P');
	LCD_void_wirte_data('O');
	LCD_void_wirte_data('L');
	LCD_void_wirte_data('A');


	while(1)
	{

	}
}

