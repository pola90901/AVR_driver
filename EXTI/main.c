/*
 * main.c
 *
 *  Created on: Dec 3, 2022
 *      Author: 1
 */

#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include <avr/delay.h>
#include "EXTI_interface.h"
volatile u8 flag;

void Blink_LED(void){
DIO_u8Set_Pin_value(0,7,0);
_delay_ms(1000);


}
// pointer to function synatx :
// return of the function (*name of the pointer to function  )(the input argument of the function)
//void (*ptr)(void);
// ptr()         // calling


//array of  pointers to function synatx :
//void (*ptr[3])(void);
// ptr[0]()			// calling


int main()
{
	DIO_u8Set_Pin_direction(0,7,1);
	DIO_u8Set_Pin_direction(3,2,0);
	DIO_u8Set_Pin_value(3,2,1);

	EXTI_voidSet_CallBackFunction(0,Blink_LED);
	EXTI_VoidSet_level(EXTI_u8_EXTI0,EXTI_u8_EXTI0_FAILING_EDGE);
	EXTI_voidEnable(EXTI_u8_EXTI0);
	EXTI_voidGlobal_En_Dis(EXTI_u8Enable);


	while(1)
	{
		DIO_u8Set_Pin_value(0,7,1);


	}


	return 0;
}
