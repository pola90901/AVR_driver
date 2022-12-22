/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */

#include "types.h"
#include<avr/delay.h>
#include "Adc.h"
#include "temp.h"
#include "Lcd.h"

#include <stdlib.h>
#include <string.h>

void main()
{
	Temp_init();
	Lcd_Init();
	u32 temp;
	u8 text[20];
	u8 test[]={"The Temp is:"};
	while(1)
	{

		temp=GetTemp();
		itoa(temp,text,10);
		Lcd_SendString(test);
		Lcd_SendString(text);

		_delay_ms(100);
		Lcd_SendCommand(0x01);
	}

}
