/*
 * Lcd.h
 *
 *  Created on: Jan 11, 2019
 *      Author: user
 */

#ifndef LCD_H_
#define LCD_H_


#include "Types.h"

void Lcd_Init(void);
void Lcd_SendCommand(u8 Command);
void Lcd_SendChar(u8 Char);
void Lcd_SendString(u8 *ptr);
void Lcd_SetXY(u8 x, u8 y );


#define FIRSTLINE 1
#define SECONDLINE 2


#endif /* LCD_H_ */
