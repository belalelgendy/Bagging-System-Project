/*
 * Servomotor.c
 *
 *  Created on: 21 Apr 2020
 *      Author: HP
 */


#include "Steppermotor.h"

void void_initSteppermotor(void)
{
	Set_BIT(Steppermotor_DIRECTION,Coil_1);Set_BIT(Steppermotor_DIRECTION,Coil_1);
	Set_BIT(Steppermotor_DIRECTION,Coil_1);Set_BIT(Steppermotor_DIRECTION,Coil_1);
	void_Steppermotorstop();
}

void void_Steppermotorstop(void)
{
	Clear_BIT(Steppermotor_Data,Coil_1);Clear_BIT(Steppermotor_Data,Coil_2);
	Clear_BIT(Steppermotor_Data,Coil_3); Clear_BIT(Steppermotor_Data,Coil_4);
}

void void_motorPhase(u8 Motor_Phase)
{
	if(Motor_Phase ==1)
	{
		Set_BIT(Steppermotor_Data,Coil_1);
		Set_BIT(Steppermotor_Data,Coil_2);
		Clear_BIT(Steppermotor_Data,Coil_3); Clear_BIT(Steppermotor_Data,Coil_4);
	}
	else if(Motor_Phase ==2)
	{
		Set_BIT(Steppermotor_Data,Coil_2);
		Set_BIT(Steppermotor_Data,Coil_3);
		Clear_BIT(Steppermotor_Data,Coil_1); Clear_BIT(Steppermotor_Data,Coil_4);
	}
	else if (Motor_Phase ==3)
	{
		Set_BIT(Steppermotor_Data,Coil_3);
		Set_BIT(Steppermotor_Data,Coil_4);
		Clear_BIT(Steppermotor_Data,Coil_1); Clear_BIT(Steppermotor_Data,Coil_2);
	}
	else if(Motor_Phase ==4)
	{
		Set_BIT(Steppermotor_Data,Coil_4);
		Set_BIT(Steppermotor_Data,Coil_1);
		Clear_BIT(Steppermotor_Data,Coil_3); Clear_BIT(Steppermotor_Data,Coil_2);
	}


}
