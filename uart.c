/*
 * uart.c
 *
 *  Created on: 25 Mar 2020
 *      Author: HP
 */

#include "uart.h"
/*---------------------------------------------------------------------*/
void void_INITuart(void)
{
	UBRRH=(BAUT_RATUE>>8);   UBRRL=BAUT_RATUE;  //Value of baud rate
	Set_BIT(UCSRB,RXEN);
	Set_BIT(UCSRB,TXEN);
	Set_BIT(UCSRC,UCSZ0); Set_BIT(UCSRC,UCSZ1); // Date=8bit
	Set_BIT(UCSRC,URSEL);
	Set_BIT(UCSRB,RXCIE); //to acess UCSRC NOT UBRRH
	Clear_BIT(UCSRC,UMSEL);                     //Asynchronous mode of operation.
}
/*-----------------------------------------------*/
void void_UARTTransmitData(u8 Data)
{
	while (!( UCSRA & (1<<UDRE)));
 UDR=Data;
}
/*-----------------------------------------------*/
u8 usart_getch(void){
	while (!(UCSRA & (1 << RXC)));
	return UDR;
}

/*---------------------------------*/
void void_UARTTransmitString(u8 *str)
{
	while(*str !='/0')
	{
		void_UARTTransmitData(*str);
		str++;
	}
}
/*----------------------------------*/
u8 u8_UARTReceiveString(void){
	u8 str[9999],i=0;
	while(!(UCSRA) & (1<<RXC));
	while (UDR !='#')
	{
		str[i]=usart_getch();
		i++;
	}
	str[i]='\0';
	return str;
}






