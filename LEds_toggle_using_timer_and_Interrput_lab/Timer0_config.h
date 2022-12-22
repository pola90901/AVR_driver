/*
 * Timer0_config.h
 *
 *  Created on: Dec 16, 2022
 *      Author: 1
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#define Normal_mode			 0
#define PWM_Phase_Correct	 1
#define CTC 				 2
#define Fast_PWM 			 3





#define Normal_mode_OCO_disconnected	 0
#define Clear_OCO_onCompare	   			 1
#define set_OCO_onCompare 				 2
#define toggle_OCO_onCompare 			 3



#define No_clock_source			 		0
#define clock_no_prescalling	 		1
#define clock_prescal_8		 	 		2
#define clock_prescal_64		 		3
#define clock_prescal_256		 		4
#define clock_prescal_1024		 		5
#define External_clock_on_falling_edge  6
#define External_clock_on_rising_edge   7


#define Compare_Match_Interrupt_Enable 	0
#define Over_flow_Interrupt_Enable 		1

#endif /* TIMER0_CONFIG_H_ */
