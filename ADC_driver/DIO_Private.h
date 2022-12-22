/*
 * DIO_Private.h
 *
 *  Created on: 20 Nov 2022
 *      Author: pola
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


#define DIO_u8_DDRA *((volatile u8* )0x3A)
#define DIO_u8_DDRB *((volatile u8* )0x37)
#define DIO_u8_DDRC *((volatile u8* )0x34)
#define DIO_u8_DDRD *((volatile u8* )0x31)

#define DIO_u8_PORTA *((volatile u8 *)0x3B)
#define DIO_u8_PORTB *((volatile u8* ) 0x38)
#define DIO_u8_PORTC *((volatile u8*) 0x35)
#define DIO_u8_PORTD *((volatile u8* )0x32)

#define DIO_u8_PINA *((volatile u8* )0x39)
#define DIO_u8_PINB *((volatile u8* )0x36)
#define DIO_u8_PINC *((volatile u8* )0x33)
#define DIO_u8_PIND *((volatile u8* )0x30)


#define DIO_MIN_u8_PORT_ID   0
#define DIO_MAX_u8_PORT_ID   3

#define DIO_MIN_u8_PIN_ID   0
#define DIO_MAX_u8_PIN_ID   7

#define DIO_MIN_u8_PIN_Val  0
#define DIO_MAX_u8_PIN_Val  1

#define DIO_MAX_u8_Direction 1
#define DIO_MIN_u8_Direction 0




#endif /* DIO_PRIVATE_H_ */
