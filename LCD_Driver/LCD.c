
#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include"LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include <avr/delay.h>

void LCD_void_inti()
{
	DIO_u8Set_PORT_direction(LCD_u8_ctrl_PORT,255);
	DIO_u8Set_PORT_direction(LCD_u8_DATA_PORT,255);
	_delay_ms(40);
	LCD_void_wirte_command(0b00111000);//Function set (8 bit mode , 2 lines , 5x7 format).
	_delay_us(50);
	LCD_void_wirte_command(0b00001100);//Display ON/OFF control. (Display ON , cursor ON , blinking off)
	_delay_us(50);
	LCD_void_wirte_command(0b00000001);//display clear
	_delay_ms(2);
	LCD_void_wirte_command(0x06);// Entry mode. (No display shift , AC increase)
	_delay_ms(1);

}
void LCD_void_wirte_command(u8 Copy_u8_cmd)
{
	DIO_u8Set_Pin_value(LCD_u8_ctrl_PORT,LCD_u8_RS_Pin,LCD_u8_RS_CMD);
	LCD_void_write(Copy_u8_cmd);
}
void LCD_void_wirte_data(u8 Copy_u8_data)
{
	DIO_u8Set_Pin_value(LCD_u8_ctrl_PORT,LCD_u8_RS_Pin,LCD_u8_RS_data);
	LCD_void_write(Copy_u8_data);
}

void LCD_void_write(u8 Copy_u8_val)
{

	DIO_u8Set_Pin_value(LCD_u8_ctrl_PORT,LCD_u8_RW_Pin,LCD_u8_RW_write);
	//DIO_u8Set_PORT_value(LCD_u8_DATA_PORT,Copy_u8_val);
	DIO_u8Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_0,Get_bit(Copy_u8_val,0));
	DIO_u8Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_1,Get_bit(Copy_u8_val,1));
	DIO_u8Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_2,Get_bit(Copy_u8_val,2));
	DIO_u8Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_3,Get_bit(Copy_u8_val,3));
	DIO_u8Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_4,Get_bit(Copy_u8_val,4));
	DIO_u8Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_5,Get_bit(Copy_u8_val,5));
	DIO_u8Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_6,Get_bit(Copy_u8_val,6));
	DIO_u8Set_Pin_value(LCD_u8_DATA_PORT,LCD_u8_DATA_PIN_7,Get_bit(Copy_u8_val,7));
	DIO_u8Set_Pin_value(LCD_u8_ctrl_PORT,LCD_u8_ENAble_Pin,LCD_u8_enable_HIGH);
	_delay_ms(2);
	DIO_u8Set_Pin_value(LCD_u8_ctrl_PORT,LCD_u8_ENAble_Pin,LCD_u8_Enable_LOW);
	_delay_ms(2);

}

void LCD_void_Set_DDRam_ADD(u8 Copy_u8DDRAM_ADD)
{
	LCD_void_wirte_command(0b10000000|Copy_u8DDRAM_ADD);

}

void LCD_void_Display_String(u8*Ptr_u8String,u8 Copy_u8X_pos,u8 Copy_u8Y_pos)
{
	u32 Loc_u8_DDramAD=Copy_u8X_pos+(64*Copy_u8Y_pos);
	LCD_void_Set_DDRam_ADD(Loc_u8_DDramAD);
	while(*Ptr_u8String !='\0')

	{	LCD_void_wirte_data(*Ptr_u8String);
	Ptr_u8String++;

	}
}

void LCD_Set_CG_RAM_ADD(u8 Copy_uCGRAM_ADD){

	LCD_void_wirte_command(0b01000000|Copy_uCGRAM_ADD);


}

void LCD_wirte_number(u32 Num)
{
	u8 arr[11];
	u32 temp,i=0,j=0,w=0;
	// filling array with number reversed in order
	while(Num!=0)
	{
		temp=Num%10;
		arr[i]=temp;
		i++;
		Num/=10;
	}
	arr[i]='x';
	i--;
	// re arrange the array
	while(j<i)
	{
		// swap
		temp=arr[j];
		arr[j]=arr[i];
		arr[i]=temp;
		j++;
		i--;
	}
	while(arr[w]!='x')
	{
		LCD_void_wirte_data(arr[w]+'0');
		w++;
	}


}

void LCD_wirte_number_float(f32 Num)
{
	u8 arr_Dec[3];
	u8 arr_int[11];
	u32 temp,temp2,i=0,j=0,w=0;
	// storing floating numbs in arr_Dec
	temp=Num*100;
	arr_Dec[1]=temp%10;
	temp/=10;
	arr_Dec[0]=temp%10;
	temp/=10;
	arr_Dec[2]='x';
	while(temp!=0)
	{
		temp2=temp%10;
		arr_int[i]=temp2;
		i++;
		temp/=10;
	}
	arr_int[i]='x';
	i--;
	// re arrange the array
	while(j<i)
	{
		// swap
		temp2=arr_int[j];
		arr_int[j]=arr_int[i];
		arr_int[i]=temp2;
		j++;
		i--;
	}
	while(arr_int[w]!='x')
	{
		LCD_void_wirte_data(arr_int[w]+'0');

		w++;
	}
	LCD_void_wirte_data('.');

	w=0;
	while(arr_Dec[w]!='x')
	{
		LCD_void_wirte_data(arr_Dec[w]+'0');
		w++;
	}




}
