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
volatile f32 result;
extern  volatile u32 flag;
#include <avr/delay.h>
// timer 0 over compare match interrupt
void __vector_10(void)__attribute((signal)); // vector  based on data sheet vector table for overflow timer0

void __vector_10(void){
	static u8 state=0;
	DIO_u8Set_Pin_value(GROUP_B,DIO_u8_PIN_0,toggle_bit(state,0));

}

void main()
{
	DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_0,DIO_u8_INPUT);

	// for buzzer to put wanted freq square wave on it
	DIO_u8Set_Pin_direction(GROUP_B,DIO_u8_PIN_0,DIO_u8_OUTPUT);
	DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_1,DIO_u8_OUTPUT);

	set_bit(TIMER_TIMSK,1);			// enable timer0 on compare  interrupt
	set_bit(TIMER_SREG,7);  	   // enable global interrupt

	TIMER_TCCR0=0b00001010;			   // normal mode bit 3,6 ==> bit 6 =0 , bit 3 =1
										//OCO disconnected bits 5,4 ==00
											// pre scaller = 8 bit 2 ,1 ,0 = 010
	ADC_voidInit();
	LCD_void_inti();


	while(1)
	{
		// to get variable values from potentiometer to display on lcd the value and change the freq on the buzzer based on the value of resistance

		TIMER_OCR0=(ADC_u16Read_Pulling(ADC_u8_CH0))/4;
		LCD_wirte_number(TIMER_OCR0);
		LCD_void_wirte_command(0b00000001);//display clear




	}
}
