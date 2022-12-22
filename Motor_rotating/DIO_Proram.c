#include"types.h"
#include"util.h"
#include"DIO_Private.h"
#include"DIO_Config.h"
#include"DIO_Interface.h"

u8 DIO_u8Set_Pin_value(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 Copy_u8_val)
{
	u8 loc_u8Error_State=DIO_u8PORT_INIT_ERR;
	if((Copy_u8_Port_ID>=DIO_MIN_u8_PORT_ID)&&(Copy_u8_Port_ID<=DIO_MAX_u8_PORT_ID))
	{
		if((Copy_u8_Pin_ID>=DIO_MIN_u8_PIN_ID)&&(Copy_u8_Pin_ID<=DIO_MAX_u8_PIN_ID))
		{
			if((Copy_u8_val==DIO_MIN_u8_PIN_Val)||(Copy_u8_val==DIO_MAX_u8_PIN_Val))
			{
				switch(Copy_u8_Port_ID)
				{
				case GROUP_A:
					Assign_Bit(DIO_u8_PORTA,Copy_u8_Pin_ID,Copy_u8_val);
					break;
				case GROUP_B:
					Assign_Bit(DIO_u8_PORTB,Copy_u8_Pin_ID,Copy_u8_val);
					break;
				case GROUP_C:
					Assign_Bit(DIO_u8_PORTC,Copy_u8_Pin_ID,Copy_u8_val);
					break;
				case GROUP_D:
					Assign_Bit(DIO_u8_PORTD,Copy_u8_Pin_ID,Copy_u8_val);
					break;
				}
			}else{
				loc_u8Error_State=DIO_u8Value_ID_ERR;
			}
		}else{
			loc_u8Error_State=DIO_u8PIN_ID_ERR;
		}
	}else{
		loc_u8Error_State=DIO_u8PORT_ID_ERR;
	}
	return loc_u8Error_State;
}
u8 DIO_u8Set_Pin_direction(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID, u8 Copy_u8_direction ){
	u8 loc_u8Error_State=DIO_u8PORT_INIT_ERR;
	if((Copy_u8_Port_ID>=DIO_MIN_u8_PORT_ID)&&(Copy_u8_Port_ID<=DIO_MAX_u8_PORT_ID))
	{
		if((Copy_u8_Pin_ID>=DIO_MIN_u8_PIN_ID)&&(Copy_u8_Pin_ID<=DIO_MAX_u8_PIN_ID))
		{
			if((Copy_u8_direction==DIO_MAX_u8_Direction)||(Copy_u8_direction==DIO_MIN_u8_Direction))
			{
				switch(Copy_u8_Port_ID)
				{
				case GROUP_A:
					Assign_Bit(DIO_u8_DDRA,Copy_u8_Pin_ID,Copy_u8_direction);
					break;
				case GROUP_B:
					Assign_Bit(DIO_u8_DDRB,Copy_u8_Pin_ID,Copy_u8_direction);
					break;
				case GROUP_C:
					Assign_Bit(DIO_u8_DDRC,Copy_u8_Pin_ID,Copy_u8_direction);
					break;
				case GROUP_D:
					Assign_Bit(DIO_u8_DDRD,Copy_u8_Pin_ID,Copy_u8_direction);
					break;
				}

			}else{
				loc_u8Error_State=DIO_u8Value_ID_ERR;
			}

		}else{
			loc_u8Error_State=DIO_u8PIN_ID_ERR;
		}
	}else{
		loc_u8Error_State=DIO_u8PORT_ID_ERR;
	}
	return loc_u8Error_State;
}
u8 DIO_u8Set_PORT_value(u8 Copy_u8_Port_ID, u8 Copy_u8_PORT_value)
{
	u8 loc_u8Error_State=DIO_u8PORT_INIT_ERR;
	if((Copy_u8_Port_ID>=DIO_MIN_u8_PORT_ID)&&(Copy_u8_Port_ID<=DIO_MAX_u8_PORT_ID))
	{
		switch(Copy_u8_Port_ID)
		{
		case GROUP_A:
			DIO_u8_PORTA=Copy_u8_PORT_value;
			break;
		case GROUP_B:
			DIO_u8_PORTB=Copy_u8_PORT_value;
			break;
		case GROUP_C:
			DIO_u8_PORTC=Copy_u8_PORT_value;
			break;
		case GROUP_D:
			DIO_u8_PORTD=Copy_u8_PORT_value;
			break;
		}
	}
	else
	{
		loc_u8Error_State=DIO_u8PORT_ID_ERR;
	}
	return loc_u8Error_State;
}
u8 DIO_u8Set_PORT_direction(u8 Copy_u8_Port_ID, u8 Copy_u8_PORT_direction)
{
	u8 loc_u8Error_State=DIO_u8PORT_INIT_ERR;
	if((Copy_u8_Port_ID>=DIO_MIN_u8_PORT_ID)&&(Copy_u8_Port_ID<=DIO_MAX_u8_PORT_ID))
	{
		switch(Copy_u8_Port_ID)
		{
		case GROUP_A:
			DIO_u8_DDRA=Copy_u8_PORT_direction;
			break;
		case GROUP_B:
			DIO_u8_DDRB=Copy_u8_PORT_direction;
			break;
		case GROUP_C:
			DIO_u8_DDRC=Copy_u8_PORT_direction;
			break;
		case GROUP_D:
			DIO_u8_DDRD=Copy_u8_PORT_direction;
			break;
		}
	}
	else
	{
		loc_u8Error_State=DIO_u8PORT_ID_ERR;
	}
	return loc_u8Error_State;
}
u8 DIO_u8Get_Pin_value(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 *Copy_u8_val)
{
	u8 loc_u8Error_State=DIO_u8PORT_INIT_ERR;
	if((Copy_u8_Port_ID>=DIO_MIN_u8_PORT_ID)&&(Copy_u8_Port_ID<=DIO_MAX_u8_PORT_ID))
	{
		if((Copy_u8_Pin_ID>=DIO_MIN_u8_PIN_ID)&&(Copy_u8_Pin_ID<=DIO_MAX_u8_PIN_ID))
		{
			switch(Copy_u8_Port_ID)
			{
			case GROUP_A:
				*Copy_u8_val=Get_bit(DIO_u8_PINA,Copy_u8_Pin_ID);
				break;
			case GROUP_B:
				*Copy_u8_val=Get_bit(DIO_u8_PINB,Copy_u8_Pin_ID);
				break;
			case GROUP_C:
				*Copy_u8_val=Get_bit(DIO_u8_PINC,Copy_u8_Pin_ID);
				break;
			case GROUP_D:
				*Copy_u8_val=Get_bit(DIO_u8_PIND,Copy_u8_Pin_ID);
				break;
			}

		}else{
			loc_u8Error_State=DIO_u8PIN_ID_ERR;
		}
	}else{
		loc_u8Error_State=DIO_u8PORT_ID_ERR;
	}
	return loc_u8Error_State;
}
u8 DIO_u8Get_PORT_value(u8 Copy_u8_Port_ID,u8 *Copy_u8_PORT_val)
{
	u8 loc_u8Error_State=DIO_u8PORT_INIT_ERR;
		if((Copy_u8_Port_ID>=DIO_MIN_u8_PORT_ID)&&(Copy_u8_Port_ID<=DIO_MAX_u8_PORT_ID))
		{

				switch(Copy_u8_Port_ID)
				{
				case GROUP_A:
					*Copy_u8_PORT_val=DIO_u8_PINA;
					break;
				case GROUP_B:
					*Copy_u8_PORT_val=DIO_u8_PINB;
					break;
				case GROUP_C:
					*Copy_u8_PORT_val=DIO_u8_PINC;
					break;
				case GROUP_D:
					*Copy_u8_PORT_val=DIO_u8_PIND;
					break;
				}


		}else{
			loc_u8Error_State=DIO_u8PORT_ID_ERR;
		}
		return loc_u8Error_State;
}
