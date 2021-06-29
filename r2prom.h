/*
 * r2prom.h
 *
 *  Created on: 29 Apr 2020
 *      Author: HP
 */

#ifndef R2PROM_H_
#define R2PROM_H_


#define FALSE 0
#define TRUE 1

void EEOpen();

u8 EEWriteByte(u32 address,u8 data);
u8 EEReadByte(u32 address);

#endif



