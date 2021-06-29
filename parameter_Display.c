/*
 * parameter_Display.c
 *
 *  Created on: 04 Jun 2020
 *      Author: HP
 */


#include "parameter_Display.h"


void void_Sortingparameter(void)
{
	height=EEReadByte(0x00);
	weight=EEReadByte(0x01);
	Coars_Flow=EEReadByte(0x02);
	Fine_Flow=EEReadByte(0x03);
	Corner_SealingTime=EEReadByte(0x04);
	Corner_DelayedTime=EEReadByte(0x05);
	Down_Sealtemp=EEReadByte(0x06);
	Down_CoolingTime=EEReadByte(0x07);
	Top_Sealtemp=EEReadByte(0x08);
	Top_CoolingTime=EEReadByte(0x09);
}
