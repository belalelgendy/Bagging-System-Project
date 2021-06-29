/*
 * Photo_Sensor.h
 *
 *  Created on: 23 Apr 2020
 *      Author: HP
 */

#ifndef PHOTO_SENSOR_H_
#define PHOTO_SENSOR_H_

#include "Main_Library.h"
/******************Photo Sensor******************************/
#define PhotoSensor_Direction     DDRC
#define PhotoSensor_Data          PORTC
#define PhotoSensor_Pin            3
/*********************Metal Detector***************************/
#define MetalDector_Direction     DDRD
#define MetalDector_Data          PIND
#define MetalDector_Pin            4
/*********************Heater***************************/
#define Heater_Direction     DDRD
#define Heater_Data          PORTD
#define Heater_Pin            6
/*********************Gripper***************************/
/************************************************/
void void_InitPhotosensor(void);
void void_Photosensor_detect(void);
void void_photosensor_notdetect(void);
/*-----------------------------------------*/
void void_InitMetalDetector(void);
u8 void_MetalDetecting(void);
/*-------------------------------------*/
void void_InitHeater(void);
void void_HeaterStart(void);
void void_HeaterStop(void);
/*---------Gripper Movement-------------*/
void void_Grippermovement(void);

/********************Latching**************-*/
void voidLatch_Signal(u8 Dir,u8 Port,u8 Signal);

#endif /* PHOTO_SENSOR_H_ */
