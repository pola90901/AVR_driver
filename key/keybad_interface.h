/*
 * keybad_interface.h
 *
 *  Created on: 26 Nov 2022
 *      Author: pola
 */

#ifndef KEYBAD_INTERFACE_H_
#define KEYBAD_INTERFACE_H_


#define KPD_u8_ROWs 4
#define KPD_u8_COLs 4
void KPD_void_Get_Status(u8 *PTR_u8_KPD_Status);
void KPD_Void_INit(void);
#define KPD_u8_KEYS_NUM    KPD_u8_ROWs*KPD_u8_COLs

#define KPD_u8_KEY_PRESSED	    0
#define KPD_u8_KEY_NOT_PRESSED	1



#endif /* KEYBAD_INTERFACE_H_ */
