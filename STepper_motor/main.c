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
#include "Stepper_config.h"
#include"stepper_intrface.h"

void main()
{
	Stepper_voidInit();


	while(1)
	{

		//Stepper_voidRotate_clockwise_FullStep();
		Stepper_void_Set_angle(90,0);
		_delay_ms(1000);


	}

}
