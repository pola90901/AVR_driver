/*
 * main.c
 *
 *  Created on: Dec 16, 2022
 *      Author: 1
 */


#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include "Timer1_private.h"
#include "Timer1_config.h"
#include "Timer1_interface.h"
#include "adc_interface.h"
#include "LCD_interface.h"



// 8 MHZ , pre scaller =64 , 16 bit resolution
//tick time =8 micro sec
// 20 msec for the servo = 20,000 micro sec
//ICR1=2499 --to over flow at that time
//OCR=> manpulate Time on
volatile f32 result;
void main()
{
	// mode 14 FAst PWM timer 1
	//Non inverted ->clear on compare set on top
	DIO_u8Set_Pin_direction(GROUP_D,DIO_u8_PIN_5,DIO_u8_OUTPUT);

	TIMER_TCCR1A=0b10100010; 					// clear on compare ,set on over flow , non inverted
												//oc1A , OC1B

	TIMER_TCCR1B=0b00011011;					// prescaler 64
	TIMER_ICR1L=2499; // over flow value
	TIMER_OCR1AL=250;	// t on for angle 180
	while(1)
			{




			}
}
