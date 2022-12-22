/*
 * adc_private.h
 *
 *  Created on: Dec 9, 2022
 *      Author: 1
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_



#define ADC_u8_ADMUX 	*((volatile u8* )0x27)
#define ADC_u8_ADCSRA 	*((volatile u8* )0x26)
#define ADC_u8_ADCH 	*((volatile u8* )0x25)
#define ADC_u8_ADCL 	*((volatile u8* )0x24)
#define ADC_u8_SFIOR 	*((volatile u8* )0x50)

#define EXTI__u8_SREG     	  *((volatile u8*)0x5F)
#define Bit_I 7


#define REFS1 7
#define REFS0 6


// ADCSRA bits:

#define ADC_ADPS0 0
#define ADC_ADPS1 1
#define ADC_ADPS2 2

#define ADSC    6
#define ADATE	5
#define ADIE    3

void __vector_16(void)__attribute__((signal));

#endif /* ADC_PRIVATE_H_ */
