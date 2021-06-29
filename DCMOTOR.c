/*
 * DCMOTOR.c
 *
 *  Created on: 21 Apr 2020
 *      Author: HP
 */

#include "DCMOTOR.h"


void void_InitDCmotor()
{
	Set_BIT(INPUT_Direction,IN_MOT1);
	Set_BIT(INPUT_Direction,IN_MOT2);
	Set_BIT(INPUT_Direction_1,IN_MOT1_1);
	Set_BIT(INPUT_Direction,IN_MOT2_1);
	void_StopDCmotor('C');
	void_StopDCmotor('G');
}
void void_StopDCmotor(u8 Motor_Type)
{
	if (Motor_Type == 'C')
	{
		Clear_BIT(Motor_Data,IN_MOT1);
		Clear_BIT(Motor_Data,IN_MOT2);
	}
	else if (Motor_Type == 'G' )
	{
		Clear_BIT(Motor_Data_1 ,IN_MOT1_1);
		Clear_BIT(Motor_Data_1 ,IN_MOT2_1);
	}

}
void void_StartDCmotor(u8 Motor_Type)
{
	if (Motor_Type == 'C')
	{	Clear_BIT(Motor_Data,IN_MOT1);
		Set_BIT(Motor_Data,IN_MOT2);
	}
	else if (Motor_Type == 'G' )
	{	Clear_BIT(Motor_Data_1,IN_MOT1_1);
		Set_BIT(Motor_Data_1,IN_MOT2_1);
	}
}
