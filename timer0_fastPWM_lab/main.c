/*
 * main.c
 *
 *  Created on: Dec 16, 2022
 *      Author: 1
 */


#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include "Timer0_private.h"
#include "Timer0_config.h"
#include "Timer0_interface.h"
#include "adc_interface.h"
#include "LCD_interface.h"

#include <avr/delay.h>

/*void __vector_10(void)__attribute((signal)); // vector  based on data sheet vector table for overflow timer0

void __vector_10(void){
	static u8 state=0;
	DIO_u8Set_Pin_value(GROUP_B,DIO_u8_PIN_0,toggle_bit(state,0));

}*/
volatile  f32 result;
extern volatile u32 flag;
void main()
{
	DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_0,DIO_u8_INPUT);
	// for motor pin OC0 pin generate PWM
	DIO_u8Set_Pin_direction(GROUP_B,DIO_u8_PIN_3,DIO_u8_OUTPUT);
	ADC_voidInit();
	LCD_void_inti();

	TIMER_TCCR0=0b01111010;			  	  // FAst pwm bit 3 , 6 = 11
										// inverted mode bit
										//set on compare , clear on top 4, 5 =11
										// pre scaller = 8 bit 2 ,1 ,0 = 010

	set_bit(TIMER_SREG,7);
	set_bit(TIMER_TIMSK,0);
	set_bit(TIMER_TIMSK,1);

	ADC_voidRead_Interput(ADC_u8_CH0);
	while(1)
	{
		// to get variable values from potentiometer to display on lcd the value and change the freq on the buzzer based on the value of resistance
		TIMER_OCR0=(ADC_u16Read_Pulling(ADC_u8_CH0))/4;
		LCD_wirte_number(TIMER_OCR0);
		LCD_void_wirte_command(0b00000001);//display clear

/***************************************************************************************/
/*		//using ADC interrupt reading
			TIMER_OCR0=result/4;
			LCD_wirte_number(TIMER_OCR0);
			LCD_void_wirte_command(0b00000001);//display clear
*/

	}


}
