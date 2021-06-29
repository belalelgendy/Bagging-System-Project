/*
 * Servo.motor.c
 *
 *  Created on: 22 Apr 2020
 *      Author: HP
 */

#include "Servo_motor.h"
/*-----------Servo-Motor Data-sheet-----------------------/*
 * Time-period=2ms
 * -90 Degree =1ms
 *  0  Degree =1.5ms
 * -90 Degree =2ms
 */

void void_initservomotor(void)
{
	//   Make it as output singnal
	Set_BIT(Servomotor_DIRECTION,Servo_PIN);
	TCNT1=0;
	/*
	 *   Fpwm=(Fcpu/(N*(1+Top))          Fpwm=50HZ--N=64----Fcpu=8GHZ
	 *   TOP=2499
	 */
	ICR1=2499;
	/*-----init timer-------*/
	Set_BIT(TCCR1A,WGM11);Set_BIT(TCCR1A,COM1A1);         //Fast PWM-Non_Inverting Mode (ICR1)
	Set_BIT(TCCR1B,WGM12);Set_BIT(TCCR1B,WGM13);
	Set_BIT(TCCR1B,CS10);Set_BIT(TCCR1B,CS11);            //Prescaler=64
}

void void_servomotor_Start(u32 Motor_Phase)
{
	if (Motor_Phase==0)
		{
			OCR1A=65;


		}
	else if(Motor_Phase==90)
		{
			OCR1A=175;


		}
	else if(Motor_Phase==180)
		{
			OCR1A=300;


		}

}

void void_servomotor_Stop(void)
{
	void_servomotor_Start(90);
}
