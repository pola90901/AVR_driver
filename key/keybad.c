/*
 * keybad.c
 *
 *  Created on: 26 Nov 2022
 *      Author: pola
 */


#include"types.h"
#include"util.h"
#include"DIO_Interface.h"
#include"keypad_private.h"
#include"keypad_config.h"
#include"keybad_interface.h"


u8 KPD_Au_Rows_Pins[KPD_u8_ROWs]={KPD_u8_ROW_0_Pin,KPD_u8_ROW_1_Pin,KPD_u8_ROW_2_Pin,KPD_u8_ROW_3_Pin};
u8 KPD_Au_Cols_Pins[KPD_u8_COLs]={KPD_u8_COL_0_Pin,KPD_u8_COL_1_Pin,KPD_u8_COL_2_Pin,KPD_u8_COL_3_Pin};



void KPD_Void_INit(void)
{
DIO_u8Set_Pin_direction(KPD_u8_ROWS_PORT,KPD_u8_ROW_0_Pin,DIO_u8_INPUT);
DIO_u8Set_Pin_direction(KPD_u8_ROWS_PORT,KPD_u8_ROW_1_Pin,DIO_u8_INPUT);
DIO_u8Set_Pin_direction(KPD_u8_ROWS_PORT,KPD_u8_ROW_2_Pin,DIO_u8_INPUT);
DIO_u8Set_Pin_direction(KPD_u8_ROWS_PORT,KPD_u8_ROW_3_Pin,DIO_u8_INPUT);

DIO_u8Set_Pin_value(KPD_u8_ROWS_PORT,KPD_u8_ROW_0_Pin,DIO_u8_HIGH);
DIO_u8Set_Pin_value(KPD_u8_ROWS_PORT,KPD_u8_ROW_1_Pin,DIO_u8_HIGH);
DIO_u8Set_Pin_value(KPD_u8_ROWS_PORT,KPD_u8_ROW_2_Pin,DIO_u8_HIGH);
DIO_u8Set_Pin_value(KPD_u8_ROWS_PORT,KPD_u8_ROW_3_Pin,DIO_u8_HIGH);

DIO_u8Set_Pin_direction(KPD_u8_COL_PORT,KPD_u8_COL_0_Pin,DIO_u8_OUTPUT);
DIO_u8Set_Pin_direction(KPD_u8_COL_PORT,KPD_u8_COL_1_Pin,DIO_u8_OUTPUT);
DIO_u8Set_Pin_direction(KPD_u8_COL_PORT,KPD_u8_COL_2_Pin,DIO_u8_OUTPUT);
DIO_u8Set_Pin_direction(KPD_u8_COL_PORT,KPD_u8_COL_3_Pin,DIO_u8_OUTPUT);

	}

void KPD_void_Get_Status(u8 *PTR_u8_KPD_Status){
	u8 LOC_u8_COL_Index;
	u8 LOC_u8_ROW_Index;
	u8 LOC_U8Key_Num ;
	for(LOC_u8_COL_Index=0;LOC_u8_COL_Index<KPD_u8_COLs;LOC_u8_COL_Index++){

		DIO_u8Set_Pin_value(KPD_u8_COL_PORT,KPD_Au_Cols_Pins[LOC_u8_COL_Index],DIO_u8_LOW);

		for(LOC_u8_ROW_Index=0;LOC_u8_ROW_Index<KPD_u8_ROWs;LOC_u8_ROW_Index++){
			LOC_U8Key_Num = LOC_u8_COL_Index+LOC_u8_ROW_Index*4;
			DIO_u8Get_Pin_value(KPD_u8_ROWS_PORT,KPD_Au_Rows_Pins[LOC_u8_ROW_Index],&PTR_u8_KPD_Status[LOC_U8Key_Num]);

		}
		DIO_u8Set_Pin_value(KPD_u8_COL_PORT,KPD_Au_Cols_Pins[LOC_u8_COL_Index],DIO_u8_HIGH);

	}


}




