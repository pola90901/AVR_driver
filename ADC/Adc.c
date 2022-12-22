/*
 * Adc.c
 *
 *  Created on: Feb 1, 2019
 *      Author: user
 */
#include "util.h"
#include "types.h"
#include "regiester.h"
#include "Adc.h"


void Adc_Init(void)
{
	// Set PA0 to input direction.(ADC0)
	clear_bit(reg_DDRA, 0);

	// Select AREF.
	clear_bit(reg_ADMUX, 6);
	clear_bit(reg_ADMUX, 7);

	// Select right adjustment.
	clear_bit(reg_ADMUX, 5);

	// Select ADC0 channel(single ended).
	clear_bit(reg_ADMUX, 0);
	clear_bit(reg_ADMUX, 1);
	clear_bit(reg_ADMUX, 2);
	clear_bit(reg_ADMUX, 3);
	clear_bit(reg_ADMUX, 4);

	// Enable ADC module.000
	set_bit(reg_ADCSRA, 7);

	// Disable auto trigger feature (select single shot mode).
	clear_bit(reg_ADCSRA, 5);

	// Disable Adc conversion completion interrupt (i.e. Disable PIE of ADC).
	clear_bit(reg_ADCSRA,3);

	// Select prescaler 128.
	set_bit(reg_ADCSRA, 0);
	set_bit(reg_ADCSRA, 1);
	set_bit(reg_ADCSRA, 2);


}

u16 Adc_Read(void)
{

	u16 AdcValue = 0;
	u16 AdcLowValue =0;
	u16 AdcHighValue = 0;
	// Start Adc conversion.
	set_bit(reg_ADCSRA, 6);

	// Wait till adc conversion is completed (i.e. Check Adc conversion completed flag)
	while(Get_bit(reg_ADCSRA, 4) == 0);

	// Clear adc conversion completion flag.
	set_bit(reg_ADCSRA, 4);

	AdcLowValue = reg_ADCL;
	AdcHighValue = reg_ADCH;


	AdcValue = AdcLowValue | ((u16)(AdcHighValue << 8));

	return AdcValue;


}

