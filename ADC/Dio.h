/*
 * Dio.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include "types.h"
#ifndef DIO_H_
#define DIO_H_
void Dio_SetPinDirection(u8 PH_PortID,u8 PH_PinID,u8 Direction);
void Dio_WritePin(u8 PH_PortID,u8 PH_PinID,u8 Level);
u8 Dio_ReadPin(u8 PH_PortID,u8 PH_PinID);
void Dio_SetPortDirection(u8 PH_PortID,u8 Direction);
void Dio_WritePort(u8 PH_PortID,u8 Level);
u8 Dio_ReadPort(u8 PH_PortID);
void Dio_ActivatePinPullupResistor(u8 PH_PortID,u8 PH_PinID);
void Dio_ActivatePortPullupResistor(u8 PH_PortID);
void Dio_TogglePin(u8 PH_PortID,u8 PH_PinID);
void Dio_TogglePort(u8 PH_PortID);

#define PH_PORTA 1
#define PH_PORTB 2
#define PH_PORTC 3
#define PH_PORTD 4
#define INPUT_DIRECTION   0
#define OUTPUT_DIRECTION   1
#define LOW_LEVEL    0
#define HIGH_LEVEL   1


#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7



#endif /* DIO_H_ */
