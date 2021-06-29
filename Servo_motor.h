/*
 * Servo_motor.h
 *
 *  Created on: 22 Apr 2020
 *      Author: HP
 */

#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#include "Main_Library.h"

#define Servomotor_DIRECTION  DDRD
#define Servomotor_Data       PORTD
#define Servo_PIN               5



void void_initservomotor(void);
void void_servomotor_Start(u32 Motor_Phase);
void void_servomotor_Stop(void);


#endif /* SERVO_MOTOR_H_ */
