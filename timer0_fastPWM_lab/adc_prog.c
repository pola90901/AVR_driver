/*
 * adc_prog.c
 *
 *  Created on: Dec 9, 2022
 *      Author: pola
 */
#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include "adc_private.h"
#include "adc_config.h"
#include "adc_interface.h"
#include <avr/delay.h>

extern  f32 result;
volatile u32 flag=0;

void ADC_voidInit(void)
{
	// ADC enable
	set_bit(ADC_u8_ADCSRA,7);

	// pre-scaler: 128
	ADC_VoidSetPreScaler(Pre_Scaler_128);

	// reference voltage : AVCC 5v
	ADC_voidSelectReferenceVolatge(AVCC);

	// Left adjustment
	ADC_voidSetAdjustment(LEFT_Adjustment);
}

void ADC_voidSetAdjustment(u8 Copy_u8Adjustment)
{
	switch(Copy_u8Adjustment)
	{
	case LEFT_Adjustment:
		set_bit(ADC_u8_ADMUX,5);
		break;
	case RIGHT_Adjustment:
		clear_bit(ADC_u8_ADMUX,5);
		break;
	}
}

void ADC_voidSelectReferenceVolatge(u8 Copy_u8Vref){
	switch(Copy_u8Vref){
	case AREF:
		clear_bit(ADC_u8_ADMUX,REFS0);
		clear_bit(ADC_u8_ADMUX,REFS1);
		break;
	case AVCC:
		set_bit(ADC_u8_ADMUX,REFS0);
		clear_bit(ADC_u8_ADMUX,REFS1);
		break;
	case Internal_V:
		set_bit(ADC_u8_ADMUX,REFS0);
		set_bit(ADC_u8_ADMUX,REFS1);
		break;
	}
}

void ADC_VoidSetPreScaler(u8 Copy_u8Setpre_scaler){
	switch(Copy_u8Setpre_scaler)
	{
	case Pre_Scaler_02:

		clear_bit(ADC_u8_ADCSRA,ADC_ADPS0);
		clear_bit(ADC_u8_ADCSRA,ADC_ADPS1);
		clear_bit(ADC_u8_ADCSRA,ADC_ADPS2);
		break;
	case Pre_Scaler_04:

		clear_bit(ADC_u8_ADCSRA,ADC_ADPS0);
		set_bit(ADC_u8_ADCSRA,ADC_ADPS1);
		clear_bit(ADC_u8_ADCSRA,ADC_ADPS2);
		break;
	case Pre_Scaler_08:
		set_bit(ADC_u8_ADCSRA,ADC_ADPS0);
		set_bit(ADC_u8_ADCSRA,ADC_ADPS1);
		clear_bit(ADC_u8_ADCSRA,ADC_ADPS2);
		break;
	case Pre_Scaler_16:
		clear_bit(ADC_u8_ADCSRA,ADC_ADPS0);
		clear_bit(ADC_u8_ADCSRA,ADC_ADPS1);
		set_bit(ADC_u8_ADCSRA,ADC_ADPS2);
		break;
	case Pre_Scaler_32:
		set_bit(ADC_u8_ADCSRA,ADC_ADPS0);
		clear_bit(ADC_u8_ADCSRA,ADC_ADPS1);
		set_bit(ADC_u8_ADCSRA,ADC_ADPS2);
		break;
	case Pre_Scaler_64:
		clear_bit(ADC_u8_ADCSRA,ADC_ADPS0);
		set_bit(ADC_u8_ADCSRA,ADC_ADPS1);
		set_bit(ADC_u8_ADCSRA,ADC_ADPS2);
		break;
	case Pre_Scaler_128:
		set_bit(ADC_u8_ADCSRA,ADC_ADPS0);
		set_bit(ADC_u8_ADCSRA,ADC_ADPS1);
		set_bit(ADC_u8_ADCSRA,ADC_ADPS2);
		break;
	}
}
u16 ADC_u16Read_Pulling(u8 Copy_u8Channel)
{
	u16 res;

	// set the wanted channel based on input without losing the origin value
	ADC_u8_ADMUX &= 0b11100000;
	ADC_u8_ADMUX |=Copy_u8Channel;
	// start single conversion
	set_bit(ADC_u8_ADCSRA,6);
	while(Get_bit(ADC_u8_ADCSRA,4)!= 1) // pulling on a flag ..waiting tell conversion is done
	{
	}
	set_bit(ADC_u8_ADCSRA,4); // setting the flag back to idle


	// merging the two register ADCL and ADCH in one variable u16

	if(Get_bit(ADC_u8_ADMUX,5)==1) // working as Left adjustment
	{
		res =( ADC_u8_ADCL >> 6);
		res |= (( (u16)ADC_u8_ADCH) << (2) );
	}else{							// working as Right adjustment
		res |=ADC_u8_ADCL ;
		res |= (( (u16)ADC_u8_ADCH) << (8) );
	}

	return res;
}

void ADC_voidRead_Interput(u8 Copy_u8Channel){

	// set the wanted channel based on input without losing the origin value
	ADC_u8_ADMUX &= 0b11100000;
	ADC_u8_ADMUX |=Copy_u8Channel;

	// ADC Interrupt Enable
	set_bit(ADC_u8_ADCSRA,ADIE);

	// Enable global Interrupt
	set_bit(EXTI__u8_SREG,Bit_I);

	// start  conversion
	set_bit(ADC_u8_ADCSRA,ADSC);

	//ADC Auto Trigger Enable
	set_bit(ADC_u8_ADCSRA,ADATE);


}

void __vector_16(void)

{
u16 resu;

	flag=1;
	if(Get_bit(ADC_u8_ADMUX,5)==1) // working as Left adjustment
	{
		resu =( ADC_u8_ADCL >> 6);
		resu|= (( (u16)ADC_u8_ADCH) << (2) );
	}else{							// working as Right adjustment
		resu |=ADC_u8_ADCL ;
		resu|= (( (u16)ADC_u8_ADCH) << (8) );
	}
	result=resu;

}


