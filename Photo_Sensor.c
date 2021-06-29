/*
 * Photo_Sensor.c
 *
 *  Created on: 23 Apr 2020
 *      Author: HP
 */

#include "Photo_Sensor.h"



void void_InitPhotosensor(void)
{
	Set_BIT(PhotoSensor_Direction,PhotoSensor_Pin);
}

void void_Photosensor_detect(void)
{
	void_StartDCmotor('C');
	_delay_ms(100);
	Set_BIT(PhotoSensor_Data ,PhotoSensor_Pin);
	LCD_String_xy(1,0,"Bag detected");
	void_StopDCmotor('C');
	_delay_ms(100);
}

void void_photosensor_notdetect(void)
{
	Clear_BIT(PhotoSensor_Data ,PhotoSensor_Pin);
	_delay_ms(10);
}

void void_InitMetalDetector(void)
{
	Clear_BIT(MetalDector_Direction  ,MetalDector_Pin );
}


u8 void_MetalDetecting(void)
{
	u8 temp=0;
	if (GET_BIT(MetalDector_Data ,MetalDector_Pin)==1)
	{
		temp=1;
	}
	else
		temp=0;
	return temp;
}
/*--------------------------------------------------*/
void void_InitHeater(void)
{
	Set_BIT(Heater_Direction,Heater_Pin);
	Clear_BIT(Heater_Data,Heater_Pin);
}
void void_HeaterStart(void)
{
	Set_BIT(Heater_Data,Heater_Pin);
	_delay_ms(300);
}
void void_HeaterStop(void)
{
	Clear_BIT(Heater_Data,Heater_Pin);
	_delay_ms(200);
}

/*--------------------------------------------*/

void void_Grippermovement(void)
{
	void_StartDCmotor('G');
	_delay_ms(100);
	void_StopDCmotor('G');
	_delay_ms(100);
}















