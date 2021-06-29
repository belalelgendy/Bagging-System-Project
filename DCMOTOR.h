/*
 * DCMOTOR.h
 *
 *  Created on: 21 Apr 2020
 *      Author: HP
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "Main_Library.h"

/*--------------Motor Conveyer----------*/
#define INPUT_Direction   DDRA
#define Motor_Data        PORTA
#define IN_MOT1 4
#define IN_MOT2 5
/*---------- Heater------------*/
#define INPUT_Direction_1   DDRA
#define Motor_Data_1        PORTA
#define IN_MOT1_1            6
#define IN_MOT2_1            7

void void_InitDCmotor();
void void_StopDCmotor(u8 Motor_Type);
void void_StartDCmotor(u8 Motor_Type);
#endif /* DCMOTOR_H_ */
