/*
 * LCD_interface.h
 *
 *  Created on: 25 Nov 2022
 *      Author: pola
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_void_write(u8 Copy_u8_val);
void LCD_void_wirte_data(u8 Copy_u8_data);
void LCD_void_wirte_command(u8 Copy_u8_cmd);
void LCD_void_inti(void);
void LCD_void_Set_DDRam_ADD(u8 Copy_u8DDRAM_ADD);
void LCD_void_Display_String(u8*Ptr_u8String,u8 Copy_u8X_pos,u8 Copy_u8Y_pos);
void LCD_Set_CG_RAM_ADD(u8 Copy_uCGRAM_ADD);

#endif /* LCD_INTERFACE_H_ */
