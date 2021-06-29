

/*
 * Keypad.c
 *
 *  Created on: Jan 8, 2018
 *      Author: Mohamed
 */
#include "Keypad.h"

u8 Keypad_GetPressedKey()
{
	u8 Col, Row;
	while (1)
	{
		for (Col = 0; Col < N_Col; Col++)
		{
			Keypad_Port_Dir = (0b00010000 << Col);
			Keypad_Port_Out = ~(0b00010000 << Col);

			for (Row = 0; Row < N_Row; Row++)
			{
				if (Bit_Is_Clear(Keypad_Port_In, Row))
				{
					_delay_ms(4);
					return Keypad_4x3((Row * N_Col) + Col + 1);
				}
			}

		}
	}
}


u8 Keypad_4x3(u8 Num) {
	switch (Num) {
	case 10:
		return 42;
		break;
	case 11:
		return 0;
		break;
	case 12:
		return 35;
	default:
		return Num;
	}
}

/*---------------------------------*/

u32 sorted_num(u8 num[])
{
	u32 i=0,total_value=0;
	for (i=0;i<5;i++)
	{
		if (i==0)
		{
			total_value=total_value+num[i];
		}

		total_value=total_value+num[i]*i*10;
	}
	return total_value;
}

/****-------------------------*/
u32 revers_num (u32 num)
{
	u32 remainder=0,rev=0;
	while (num != 0) {
        remainder = num % 10;
        rev = rev * 10 + remainder;
        num /= 10;
     }
	return rev;
}






