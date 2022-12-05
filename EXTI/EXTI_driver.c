/*
 * EXTI_driver.c
 *
 *  Created on: Dec 3, 2022
 *      Author: 1
 */
#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include <avr/delay.h>
#include "EXTI_private.h"
#include "EXTI_interface.h"

void (*Apvoid_Callback[3])(void)={NULL,NULL,NULL};

void __vector_1(void){  // INT0
	if(Apvoid_Callback[0]!=NULL)
	{
		Apvoid_Callback[0]();
	}
}
void __vector_2(void){// INT1
	Apvoid_Callback[1]();


}
void __vector_3(void){// INT2
	Apvoid_Callback[2]();
}


void EXTI_voidSet_CallBackFunction(u8 Copy_u8INTindex,void (*pvoid_Callback)(void))
{
	Apvoid_Callback[Copy_u8INTindex]=pvoid_Callback;
}



void EXTI_VoidSet_level(u8 copy_u8INT_index,u8 copy_u8INT_Level)
{
	switch(copy_u8INT_index)
	{
	case EXTI_u8_EXTI0 :
		Assign_Bit(EXTI__u8_MCUCR,0,Get_bit(copy_u8INT_Level,0));
		Assign_Bit(EXTI__u8_MCUCR,1,Get_bit(copy_u8INT_Level,1));
		break;

	case EXTI_u8_EXTI1 :
		Assign_Bit(EXTI__u8_MCUCR,2,Get_bit(copy_u8INT_Level,0));
		Assign_Bit(EXTI__u8_MCUCR,3,Get_bit(copy_u8INT_Level,1));
		break;

	case EXTI_u8_EXTI2 :
		Assign_Bit(EXTI__u8_MCUCSR,6,Get_bit(copy_u8INT_Level,0));

		break;

	}
}
void EXTI_voidEnable(u8 copy_u8INT_index)
{
	switch(copy_u8INT_index)
	{
	case EXTI_u8_EXTI0 :
		Assign_Bit(EXTI__u8_GICR,6,EXTI_u8Enable);
		break;
	case EXTI_u8_EXTI1 :
		Assign_Bit(EXTI__u8_GICR,7,EXTI_u8Enable);
		break;
	case EXTI_u8_EXTI2 :
		Assign_Bit(EXTI__u8_GICR,5,EXTI_u8Enable);
		break;
	}
}
void EXTI_voidDisable(u8 copy_u8INT_index)
{
	switch(copy_u8INT_index)
	{
	case EXTI_u8_EXTI0 :
		Assign_Bit(EXTI__u8_GICR,6,EXTI_u8Disable);
		break;
	case EXTI_u8_EXTI1 :
		Assign_Bit(EXTI__u8_GICR,7,EXTI_u8Disable);
		break;
	case EXTI_u8_EXTI2 :
		Assign_Bit(EXTI__u8_GICR,5,EXTI_u8Disable);
		break;
	}
}
void EXTI_voidGlobal_En_Dis(u8 Copy_uEn_Dis)
{
	switch(Copy_uEn_Dis)
	{
	case EXTI_u8Enable:
		set_bit(EXTI__u8_SREG,7);
		break;
	case EXTI_u8Disable:
		clear_bit(EXTI__u8_SREG,7);
		break;
	}
}






