/*
 * ADC.h
 *
 *  Created on: 22 Mar 2020
 *      Author: HP
 */

#include"Main_Library.h"


/*----------------------PRESCALER Options-----------------------
 1 = CLK/2    2=CLK/4    3=CLK/8     4=CLK/16
 5=CLK/32    6=CLK/64    7=CLK/128                       */
#define PRESCALER  7
/*------------------- --Voltage Reference---- -----------------*/
#define Vref       1      // 1=5V----2=2.5V
#define  no_channel 3
/*-------------------------------------------------------------*/
#define Enable_Intrrupt  OFF
#define Range_sensor     125
/*--------------------------Function --------------------------*/
void void_INITADC(void);
u32 void_StartConversion_Readvoltage(void);
u32 u32_ConvertAdcDate(void);
/*--------------------------------------------------------------*/
