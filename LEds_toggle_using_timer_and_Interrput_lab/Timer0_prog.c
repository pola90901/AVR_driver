/*
 * Timer0_prog.c

 *
 *  Created on: Dec 16, 2022
 *      Author: 1
 */
#include "types.h"
#include "util.h"
#include "DIO_Interface.h"
#include "Timer0_private.h"
#include "Timer0_config.h"
#include "Timer0_interface.h"
void TIMER0_INIT(void)
{
	// normal mode timer0
	Timer_voidSetMode(Normal_mode);

	//Normal port operation, OC0 disconnected.
	Timer_voidCompare_output_mode_Non_PWM(Normal_mode_OCO_disconnected);

	//selecting clock
	Timer0_VoidClockSelect(clock_prescal_8);

	// enable overflow interrupt
	Timer0_voidInterruptEnable(Over_flow_Interrupt_Enable);

	// enable global interrupt
	set_bit(TIMER_SREG,7);
}
void Timer_voidSetMode(u8 Copy_u8Mode){
	//Timer/Counter Control Register – TCCR0
	// Bit 6, 3 – WGM01:0: Waveform Generation Mode
	switch(Copy_u8Mode)
	{
	case Normal_mode :
		clear_bit(TIMER_TCCR0,WGM01);
		clear_bit(TIMER_TCCR0,WGM00);
		break;
	case PWM_Phase_Correct :
		clear_bit(TIMER_TCCR0,WGM01);
		set_bit(TIMER_TCCR0,WGM00);
		break;
	case CTC:
		set_bit(TIMER_TCCR0,WGM01);
		clear_bit(TIMER_TCCR0,WGM00);
		break;
	case Fast_PWM:
		set_bit(TIMER_TCCR0,WGM01);
		set_bit(TIMER_TCCR0,WGM00);
		break;

	}
}
void Timer_voidCompare_output_mode_Non_PWM(u8 Copy_u8Operation){
	//Timer/Counter Control Register – TCCR0
	//Compare Output Mode, non-PWM Mode
	// Bit 5:4 – COM01:0: Compare Match Output Mode
	switch(Copy_u8Operation)
	{
	case Normal_mode_OCO_disconnected :
		clear_bit(TIMER_TCCR0,COM00);
		clear_bit(TIMER_TCCR0,COM01);
		break;
	case Clear_OCO_onCompare :
		clear_bit(TIMER_TCCR0,COM00);
		set_bit(TIMER_TCCR0,COM01);
		break;
	case toggle_OCO_onCompare:
		set_bit(TIMER_TCCR0,COM00);
		clear_bit(TIMER_TCCR0,COM01);
		break;
	case set_OCO_onCompare:
		set_bit(TIMER_TCCR0,COM00);
		set_bit(TIMER_TCCR0,COM01);
		break;

	}
}
void Timer0_VoidClockSelect(u8 Copy_u8Prescaler){

	switch(Copy_u8Prescaler)
	{
	case No_clock_source :
		clear_bit(TIMER_TCCR0,CS00);
		clear_bit(TIMER_TCCR0,CS01);
		clear_bit(TIMER_TCCR0,CS02);
		break;
	case clock_no_prescalling :
		set_bit(TIMER_TCCR0,CS00);
		clear_bit(TIMER_TCCR0,CS01);
		clear_bit(TIMER_TCCR0,CS02);
		break;
	case clock_prescal_8:
		clear_bit(TIMER_TCCR0,CS00);
		set_bit(TIMER_TCCR0,CS01);
		clear_bit(TIMER_TCCR0,CS02);
		break;
	case clock_prescal_64:
		set_bit(TIMER_TCCR0,CS00);
		set_bit(TIMER_TCCR0,CS01);
		clear_bit(TIMER_TCCR0,CS02);
		break;
	case clock_prescal_256:
		clear_bit(TIMER_TCCR0,CS00);
		clear_bit(TIMER_TCCR0,CS01);
		set_bit(TIMER_TCCR0,CS02);
		break;
	case clock_prescal_1024:
		set_bit(TIMER_TCCR0,CS00);
		clear_bit(TIMER_TCCR0,CS01);
		set_bit(TIMER_TCCR0,CS02);
		break;
	case External_clock_on_falling_edge:
		clear_bit(TIMER_TCCR0,CS00);
		set_bit(TIMER_TCCR0,CS01);
		set_bit(TIMER_TCCR0,CS02);
		break;
	case External_clock_on_rising_edge:
		set_bit(TIMER_TCCR0,CS00);
		set_bit(TIMER_TCCR0,CS01);
		set_bit(TIMER_TCCR0,CS02);
		break;
	}


}
void Timer0_voidInterruptEnable(u8 Copy_u8Mask)
{
	switch(Copy_u8Mask)
	{
	case Compare_Match_Interrupt_Enable:
		set_bit(TIMER_TIMSK,OCIE0);
		break;
	case Over_flow_Interrupt_Enable:
		set_bit(TIMER_TIMSK,TOIE0);
		break;
	}
}
void Timer0_voidSetpreload(u8 Copy_u8PreloadValue){
	TIMER_TCNT0=Copy_u8PreloadValue;
}
