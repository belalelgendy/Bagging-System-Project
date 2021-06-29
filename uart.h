/*
 * uart.h
 *
 *  Created on: 25 Mar 2020
 *      Author: HP
 */

#ifndef UART_H_
#define UART_H_

#include "Main_Library.h"

#define BAUT 230400
#define BAUT_RATUE  ((F_CPU/(16UL*BAUT))-1) // set baud rate value for UBRR



void void_INITuart(void);
void void_UARTTransmitData(u8 Data);
void void_UARTTransmitString(u8 *str);
u8 usart_getch(void);
u8 u8_UARTReceiveString(void);
#endif /* UART_H_ */
