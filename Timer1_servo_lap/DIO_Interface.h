/*
 * DIO_Interface.h
 *
 *  Created on: 20 Nov 2022
 *      Author: pola
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_




#define GROUP_A 0
#define GROUP_B 1
#define GROUP_C 2
#define GROUP_D 3

#define DIO_u8PORT_INIT_ERR	0
#define DIO_u8PORT_ID_ERR	1
#define DIO_u8PIN_ID_ERR	2
#define DIO_u8Value_ID_ERR	3

#define DIO_u8_PIN_0 0
#define DIO_u8_PIN_1 1
#define DIO_u8_PIN_2 2
#define DIO_u8_PIN_3 3
#define DIO_u8_PIN_4 4
#define DIO_u8_PIN_5 5
#define DIO_u8_PIN_6 6
#define DIO_u8_PIN_7 7


#define DIO_u8_HIGH 1
#define DIO_u8_LOW  0

#define DIO_u8_OUTPUT 1
#define DIO_u8_INPUT  0

u8 DIO_u8Set_Pin_value(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 Copy_u8_val);
u8 DIO_u8Set_Pin_direction(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID, u8 Copy_u8_direction);
u8 DIO_u8Set_PORT_value(u8 Copy_u8_Port_ID, u8 Copy_u8_PORT_value);
u8 DIO_u8Set_PORT_direction(u8 Copy_u8_Port_ID, u8 Copy_u8_PORT_direction);
u8 DIO_u8Get_Pin_value(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 *Copy_u8_val);
u8 DIO_u8Get_PORT_value(u8 Copy_u8_Port_ID,u8 *Copy_u8_PORT_val);


#endif /* DIO_INTERFACE_H_ */
