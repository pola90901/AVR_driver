/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include"types.h"

u16 GetTemp(void)
{
	u16 AdcValue=Adc_Read();


	u16 volt=(u32) (AdcValue*5000)/1024;
	u8 temp=volt/10;
	return volt;
	}
void Temp_init(void)
{
Adc_Init();
}
