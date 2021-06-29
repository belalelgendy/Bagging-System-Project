/*
 * Servomotor.h
 *
 *  Created on: 21 Apr 2020
 *      Author: HP
 */

#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

#include "Main_Library.h"

#define Steppermotor_DIRECTION  DDRD
#define Steppermotor_Data       PORTD
#define Coil_1                    0
#define Coil_2                    1
#define Coil_3                    2
#define Coil_4                    3

/* 1=-180    2=-90   3=+90   4=+180*/

void void_initSteppermotor(void);
void void_motorPhase(u8 Motor_Phase);
void void_Steppermotorstop(void);


#endif /* STEPPERMOTOR_H_ */
