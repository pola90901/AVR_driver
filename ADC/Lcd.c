/*
 * Lcd.c
 *
 *  Created on: Jan 11, 2019
 *      Author: user
 */


#include "Lcd.h"
#include <avr/delay.h>
#include "Dio.h"

void Lcd_Init(void)
{
	// Wait 50 ms till LCD VDD reaches 4.5v.
	_delay_ms(50);

	// Set PORTD to output direction contains (DB0 ~ DB7).
	Dio_SetPortDirection(PH_PORTD, OUTPUT_DIRECTION);

	Dio_SetPinDirection(PH_PORTC, PIN_0, OUTPUT_DIRECTION);  // RS pin.

	Dio_SetPinDirection(PH_PORTC, PIN_1, OUTPUT_DIRECTION);  // RW pin.


	Dio_SetPinDirection(PH_PORTC, PIN_2, OUTPUT_DIRECTION);  // E pin.

	Lcd_SendCommand(0x38);  // Function set (8 bit mode , 2 lines , 5x7 format).
	_delay_ms(1);

	Lcd_SendCommand(0x0E); // Display ON/OFF control. (Display ON , cursor ON , blinking off)
	_delay_ms(1);


	Lcd_SendCommand(0x01);   // Clear display.
	_delay_ms(2);


	Lcd_SendCommand(0x06);   // Entry mode. (No display shift , AC increase)
	_delay_ms(1);
}

void Lcd_SendCommand(u8 Command)
{
	// Write 0 on RS pin to select instruction register.
	Dio_WritePin(PH_PORTC, PIN_0, LOW_LEVEL);

	// Write 0 on RW pin to select write command.
	Dio_WritePin(PH_PORTC, PIN_1, LOW_LEVEL);

	// Output
	Dio_WritePort(PH_PORTD, Command);

	// Write 1 on enable pin
	Dio_WritePin(PH_PORTC, PIN_2, HIGH_LEVEL);
	_delay_ms(2);
	// Write 0 on enable pin.
	Dio_WritePin(PH_PORTC, PIN_2, LOW_LEVEL);

}

void Lcd_SendChar(u8 Char)
{
	// Write 1 on RS pin to select data register.
	Dio_WritePin(PH_PORTC, PIN_0, HIGH_LEVEL);

	// Write 0 on RW pin to select write command.
	Dio_WritePin(PH_PORTC, PIN_1, LOW_LEVEL);

	// Output
	Dio_WritePort(PH_PORTD, Char);

	// Write 1 on enable pin
	Dio_WritePin(PH_PORTC, PIN_2, HIGH_LEVEL);
	_delay_ms(2);
	// Write 0 on enable pin.
	Dio_WritePin(PH_PORTC, PIN_2, LOW_LEVEL);

}


void Lcd_SendString(u8 *ptr)
{
	while(*ptr != 0)
	{
		Lcd_SendChar(*ptr);
		ptr++;
	}
}




void Lcd_SetXY(u8 x, u8 y )
{
	switch (y)
	{
	case FIRSTLINE:
	{
		Lcd_SendCommand(0x02);
		for(u8 i=1;i<x;i++)
		{
			Lcd_SendCommand(0x14);
		}

		break;
	}
	case SECONDLINE:
	{
		Lcd_SendCommand(0xA8);

		for(u8 i=1;i<x;i++)
		{
			Lcd_SendCommand(0x14);
		}


		break;
	}


	}
}


