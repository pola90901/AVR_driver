/*
 * adc_interface.h
 *
 *  Created on: Dec 9, 2022
 *      Author: 1
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



#define ADC_u8_CH0 0
#define ADC_u8_CH1 1
#define ADC_u8_CH2 2
#define ADC_u8_CH3 3
#define ADC_u8_CH4 4
#define ADC_u8_CH5 5
#define ADC_u8_CH6 6
#define ADC_u8_CH7 7


void ADC_voidInit(void);

u16 ADC_u16Read_Pulling(u8 Copy_u8Channel);

void ADC_voidRead_Interput(u8 Copy_u8Channel);

void ADC_VoidSetPreScaler(u8 Copy_u8Setpre_scaler);

void ADC_voidSelectReferenceVolatge(u8 Copy_u8Vref);

void ADC_voidSetAdjustment(u8 Copy_u8Adjustment);
#endif /* ADC_INTERFACE_H_ */
