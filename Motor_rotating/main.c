
/*
 * Using two tactile switches, control DC motor direction. One switch
for rotating the motor clockwise and the other one for counter
clockwise. The direction of the rotation shall be written on LCD.
 * */#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include"LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include <avr/delay.h>
 int  main()
 {

	 LCD_void_inti();
	 u8 arr1[]={"clock wise"};
	 u8 arr2[]={"Anticlock wise"};

	 // setting port A pin 0 and 1 as outputs to control the direction of the rotation through 2x transistors and 2x relays
	 DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_0,DIO_u8_OUTPUT);
	 DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_1,DIO_u8_OUTPUT);

	 // setting port B pin 0, 1 as input pull up resistor pn 2x tactile switch
	 DIO_u8Set_Pin_direction(GROUP_B,DIO_u8_PIN_0,DIO_u8_INPUT);
	 DIO_u8Set_Pin_direction(GROUP_B,DIO_u8_PIN_1,DIO_u8_INPUT);
	 DIO_u8Set_Pin_value(GROUP_B,DIO_u8_PIN_0,DIO_u8_HIGH);
	 DIO_u8Set_Pin_value(GROUP_B,DIO_u8_PIN_1,DIO_u8_HIGH);




	 while(1)
	 {
		 u8 switch1_stat,switch2_stat;
		 DIO_u8Get_Pin_value(GROUP_B,DIO_u8_PIN_0,&switch1_stat);
		 DIO_u8Get_Pin_value(GROUP_B,DIO_u8_PIN_1,&switch2_stat);
		 while(switch1_stat==0)
		 {
			 LCD_void_Display_String(arr1,0,0);// writing Rotating clock wise
			 DIO_u8Set_Pin_value(GROUP_A,DIO_u8_PIN_0,DIO_u8_HIGH);
			 DIO_u8Set_Pin_value(GROUP_A,DIO_u8_PIN_1,DIO_u8_LOW);
			 DIO_u8Get_Pin_value(GROUP_B,DIO_u8_PIN_0,&switch1_stat);
		 }
		 LCD_void_wirte_command(0b00000001);//display clear
		 DIO_u8Set_Pin_value(GROUP_A,DIO_u8_PIN_0,DIO_u8_LOW);
		 DIO_u8Set_Pin_value(GROUP_A,DIO_u8_PIN_1,DIO_u8_LOW);

		 while(switch2_stat==0)
		 {
			 LCD_void_Display_String(arr2,0,0);// writing Rotating Anticlock wise
			 DIO_u8Set_Pin_value(GROUP_A,DIO_u8_PIN_0,DIO_u8_LOW);
			 DIO_u8Set_Pin_value(GROUP_A,DIO_u8_PIN_1,DIO_u8_HIGH);
			 DIO_u8Get_Pin_value(GROUP_B,DIO_u8_PIN_1,&switch2_stat);
		 }
		 LCD_void_wirte_command(0b00000001);//display clear

	 }
	 return 0;
 }

