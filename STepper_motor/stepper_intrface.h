/*
 * stepper_intrface.h
 *
 *  Created on: Dec 3, 2022
 *      Author: 1
 */

#ifndef STEPPER_INTRFACE_H_
#define STEPPER_INTRFACE_H_



void Stepper_voidInit(void);
void Stepper_voidRotate_clockwise_FullStep(void);

void Stepper_voidRotate_Anticlockwise_FullStep(void);

void Stepper_voidRotate_Anticlockwise_HalfStep(void);

void Stepper_void_Set_angle(u32 Copy_u32Angle,u8 Copy_u8Direction );





#endif /* STEPPER_INTRFACE_H_ */
