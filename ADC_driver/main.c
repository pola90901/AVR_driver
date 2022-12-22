#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include "adc_interface.h"
#include <avr/delay.h>
#include "LCD_interface.h"

volatile f32 result=0;
extern u32 flag;
int main()
{
	/*f32 analog;
	f32 digital;
	DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_0,DIO_u8_INPUT);
	ADC_voidInit();
	LCD_void_inti();
	while(1)
	{
		// reading the converted analog value in digital value
		digital =ADC_u16Read_Pulling(ADC_u8_CH0);

		//displaying on LCD 16x2 the digital value
		LCD_wirte_number(digital);

		//pointing the LCD to write on the second line
		LCD_void_Set_DDRam_ADD(64);

		//calculating the analog value through this math equation
		analog= (digital*5000)/1024;

		//displaying on LCD 16x2 the analog value
		LCD_wirte_number(analog);

		// waiting to see the result displayed on the LCD
		_delay_ms(500);


		//display clear the LCD to enable new value to be written
		LCD_void_wirte_command(0b00000001);


	}
*/
	/*****************************************************************/
	// testing ADC driver with interrupt

	/*******************************************************************/

	f32 analog;
	DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_0,DIO_u8_INPUT);
	DIO_u8Set_Pin_direction(GROUP_A,DIO_u8_PIN_1,DIO_u8_OUTPUT);
	ADC_voidInit();
	LCD_void_inti();
	// inti. ADC via interrupt mode the converted analog value in digital value
		ADC_u16Read_Interput(ADC_u8_CH0);

	while(1)
	{

		if (flag==1){
		//	DIO_u8Set_Pin_value(GROUP_A,DIO_u8_PIN_1 ,DIO_u8_HIGH);
		//displaying on LCD 16x2 the digital value
		LCD_wirte_number(result);

		//pointing the LCD to write on the second line
		LCD_void_Set_DDRam_ADD(64);

		//calculating the analog value through this math equation
		analog= (result*5000)/1024.0;

		//displaying on LCD 16x2 the analog value
		LCD_wirte_number(analog);

		// waiting to see the result displayed on the LCD
		_delay_ms(500);
		//display clear the LCD to enable new value to be written
		LCD_void_wirte_command(0b00000001);
		flag=0;
		}
	}
	return 0;
}
