/*
 * Dio.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: pola
 */
#include"util.h"
#include"types.h"
#include "regiester.h"
#include "Dio.h"


void Dio_SetPinDirection(u8 PH_PortID,u8 PH_PinID,u8 Direction)
{
	switch(PH_PortID)
	{
	case PH_PORTA://physical port A
		if(Direction == INPUT_DIRECTION) // input
		{
			clear_bit(reg_DDRA,PH_PinID);

		}
		else if (Direction == OUTPUT_DIRECTION)// output
		{
			set_bit(reg_DDRA,PH_PinID);

		}
		break;
	case PH_PORTB: //physical port b
		if(Direction == INPUT_DIRECTION) // input
		{
			clear_bit(reg_DDRB,PH_PinID);

		}
		else if (Direction == OUTPUT_DIRECTION)// output
		{
			set_bit(reg_DDRB,PH_PinID);

		}



		break;
	case PH_PORTC://physical port c
		if(Direction == INPUT_DIRECTION) // input
		{
			clear_bit(reg_DDRC,PH_PinID);

		}
		else if (Direction == OUTPUT_DIRECTION)// output
		{
			set_bit(reg_DDRC,PH_PinID);

		}


		break;
	case PH_PORTD://physical port d
		if(Direction == INPUT_DIRECTION) // input
		{
			clear_bit(reg_DDRD,PH_PinID);

		}
		else if (Direction == OUTPUT_DIRECTION)// output
		{
			set_bit(reg_DDRD,PH_PinID);

		}

		break;

		/* default:error code to return
		   break;*/
	}
}

void Dio_WritePin(u8 PH_PortID,u8 PH_PinID,u8 Level)
{

	switch(PH_PortID)
	{
	case PH_PORTA://physical port A
		if(Level == LOW_LEVEL) // input
		{
			clear_bit(reg_PORTA,PH_PinID);

		}
		else if (Level == HIGH_LEVEL)// output
		{
			set_bit(reg_PORTA,PH_PinID);

		}
		break;
	case PH_PORTB: //physical port b
		if(Level == LOW_LEVEL) // input
		{
			clear_bit(reg_PORTB,PH_PinID);

		}
		else if (Level == HIGH_LEVEL)// output
		{
			set_bit(reg_PORTB,PH_PinID);

		}



		break;
	case PH_PORTC://physical port c
		if(Level == LOW_LEVEL) // input
		{
			clear_bit(reg_PORTC,PH_PinID);

		}
		else if (Level == HIGH_LEVEL)// output
		{
			set_bit(reg_PORTC,PH_PinID);

		}


		break;
	case PH_PORTD://physical port d
		if(Level == LOW_LEVEL) // input
		{
			clear_bit(reg_PORTD,PH_PinID);

		}
		else if (Level == HIGH_LEVEL)// output
		{
			set_bit(reg_PORTD,PH_PinID);

		}

		break;

		/* default:error code to return
		   break;*/
	}



}

u8 Dio_ReadPin(u8 PH_PortID,u8 PH_PinID)
{
	u8 PinLevel;
  switch(PH_PortID)
   {
  case PH_PORTA:
	  PinLevel=Get_bit(reg_PINA,PH_PinID);
	  break;
  case PH_PORTB:
	  PinLevel=Get_bit(reg_PINB,PH_PinID);
	  break;
  case PH_PORTC:
	  PinLevel=Get_bit(reg_PINC,PH_PinID);
	  break;
  case PH_PORTD:
	  PinLevel=Get_bit(reg_PIND,PH_PinID);
	  break;
   }
  return PinLevel;

}
/*********************************************************/
void Dio_SetPortDirection(u8 PH_PortID,u8 Direction)
{
  switch (PH_PortID)
  {
  case PH_PORTA:

		if(Direction == INPUT_DIRECTION) // input
		{
			write_byte(reg_DDRA,0);

		}
		else if (Direction == OUTPUT_DIRECTION)// output
		{
			write_byte(reg_DDRA,255);

		}


	  break;
  case PH_PORTB:
		if(Direction == INPUT_DIRECTION) // input
		{
			write_byte(reg_DDRB,0);

		}
		else if (Direction == OUTPUT_DIRECTION)// output
		{
			write_byte(reg_DDRB,255);

		}


	  break;
  case PH_PORTC:
		if(Direction == INPUT_DIRECTION) // input
		{
			write_byte(reg_DDRC,0);

		}
		else if (Direction == OUTPUT_DIRECTION)// output
		{
			write_byte(reg_DDRC,255);

		}


	  break;
  case PH_PORTD:
		if(Direction == INPUT_DIRECTION) // input
		{
			write_byte(reg_DDRD,0);

		}
		else if (Direction == OUTPUT_DIRECTION)// output
		{
			write_byte(reg_DDRD,255);

		}


	  break;

  }

}

void Dio_WritePort(u8 PH_PortID,u8 data)
 {
	switch (PH_PortID)
	  {
	  case PH_PORTA:


			    write_byte(reg_PORTA,data);


		  break;
	  case PH_PORTB:


		    write_byte(reg_PORTB,data);


		  break;
	  case PH_PORTC:


		    write_byte(reg_PORTC,data);


		  break;
	  case PH_PORTD:


		    write_byte(reg_PORTD,data);


		  break;
	  }
 }

u8 Dio_ReadPort(u8 PH_PortID)
 {
	 u8 PortLevel;
	   switch(PH_PortID)
	    {
	   case PH_PORTA:
	 	  PortLevel=read_byte(reg_PINA);
	 	  break;
	   case PH_PORTB:
		   PortLevel=read_byte(reg_PINB);
	 	  break;
	   case PH_PORTC:
		   PortLevel=read_byte(reg_PINC);
	 	  break;
	   case PH_PORTD:
		   PortLevel=read_byte(reg_PIND);
	 	  break;
	    }
	   return PortLevel;

 }

void Dio_ActivatePinPullupResistor(u8 PH_PortID,u8 PH_PinID)
{
	  switch(PH_PortID)
		    {
		   case PH_PORTA:
                 clear_bit(reg_DDRA,PH_PinID);
                 clear_bit(reg_SFIOR,2);
                 set_bit(reg_PORTA,PH_PinID);

		 	  break;
		   case PH_PORTB:
               clear_bit(reg_DDRB,PH_PinID);
               clear_bit(reg_SFIOR,2);
               set_bit(reg_PORTB,PH_PinID);

			   break;
		   case PH_PORTC:
               clear_bit(reg_DDRC,PH_PinID);
               clear_bit(reg_SFIOR,2);
               set_bit(reg_PORTC,PH_PinID);
			   break;
		   case PH_PORTD:
               clear_bit(reg_DDRD,PH_PinID);
               clear_bit(reg_SFIOR,2);
               set_bit(reg_PORTD,PH_PinID);

			   break;
		    }
}

void Dio_ActivatePortPullupResistor(u8 PH_PortID)
{
	switch(PH_PortID)
			    {
			   case PH_PORTA:
				   write_byte(reg_DDRA,0);
	                clear_bit(reg_SFIOR,2);
	                write_byte(reg_PORTA,0);

			 	  break;
			   case PH_PORTB:
				   write_byte(reg_DDRB,0);
	                clear_bit(reg_SFIOR,2);
	                write_byte(reg_PORTB,0);

				   break;
			   case PH_PORTC:
				   write_byte(reg_DDRC,0);
	                clear_bit(reg_SFIOR,2);
	                write_byte(reg_PORTC,0);
				   break;
			   case PH_PORTD:
				   write_byte(reg_DDRD,0);
	                clear_bit(reg_SFIOR,2);
	                write_byte(reg_PORTD,0);

				   break;
			    }

	}

void Dio_TogglePin(u8 PH_PortID,u8 PH_PinID)
{
	switch(PH_PortID)
			    {
			   case PH_PORTA:
				    set_bit(reg_DDRA,PH_PinID);
					toggle_bit(reg_PORTA,PH_PinID);

			 	  break;
			   case PH_PORTB:
				    set_bit(reg_DDRB,PH_PinID);
					toggle_bit(reg_PORTB,PH_PinID);
				   break;
			   case PH_PORTC:
				    set_bit(reg_DDRC,PH_PinID);
					toggle_bit(reg_PORTC,PH_PinID);
				   break;
			   case PH_PORTD:
				    set_bit(reg_DDRD,PH_PinID);
					toggle_bit(reg_PORTD,PH_PinID);

				   break;
			    }

}

void Dio_TogglePort(u8 PH_PortID)
{
	switch(PH_PortID)
				    {
				   case PH_PORTA:
					   write_byte(reg_DDRA,255);
						toggle_byte(reg_PORTA);

				 	  break;
				   case PH_PORTB:
					   write_byte(reg_DDRB,255);
						toggle_byte(reg_PORTB);
					   break;
				   case PH_PORTC:
					   write_byte(reg_DDRC,255);
						toggle_byte(reg_PORTC);
					   break;
				   case PH_PORTD:
					   write_byte(reg_DDRD,255);
						toggle_byte(reg_PORTD);

					   break;
				    }


}

// need to write port function as binary number
