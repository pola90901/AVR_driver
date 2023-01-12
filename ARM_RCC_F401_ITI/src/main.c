
#include "../include/LIB/types.h"
#include "../include/LIB/util.h"
#include "../include/MCAL/RCC/RCC_interface.h"
#include "../include/MCAL/GPIO/GPIO_Interface.h"


int main()
{
	MRCC_voidInit();
	MRCC_voidPeripheralEnable(AHB1,GPIOAEN);
	MGPIO_SetPinDirection(GPIO_PORTA,GPIO_Pin0,OUTPUT_PUSH_PULL,2);
	MCAL_voidSetPinValue(GPIO_PORTA,GPIO_Pin0,1);
	while(1)
	{

	}
return 0;
}
