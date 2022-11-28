#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include"keybad_interface.h"
int main()
{
	u8 arr[KPD_u8_KEYS_NUM];
	KPD_Void_INit();

DIO_u8Set_Pin_direction(0,0,1);
	while(1)
	{
		KPD_void_Get_Status(arr);

		if(arr[0]==0)
		{

			DIO_u8Set_Pin_value(0,0,1);
		}else
		{
			DIO_u8Set_Pin_value(0,0,0);

		}
	}
	return 0;
}
