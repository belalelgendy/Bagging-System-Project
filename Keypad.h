/*
 * Keypad.h
 *
 *  Created on: Jan 8, 2018
 *      Author: Mohamed
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "Main_Library.h"

#define Keypad_Port_Dir DDRD
#define Keypad_Port_Out PORTD
#define Keypad_Port_In PIND
#define N_Col 3
#define N_Row 4

u8 Keypad_GetPressedKey();
u8 Keypad_4x3(u8 Num);
u32 sorted_num(u8 num[]);
u32 revers_num (u32 num);


#endif /* KEYPAD_H_ */
