/*
 * LCD.c
 *
 *  Created on: 29 Oct 2019
 *      Author: HP
 */


#include"LCD.h"


void voidClear_LCD()
{

	u8SEND_COMMAND(Clear_DISPLAY);
	u8SEND_COMMAND (0x80);
}
/*------------------------------------------------*/
void void_LCD_INIT(void)
{
	Set_BIT(LCD_CONTROL_Direction,LCD_Read_Write_PIN);      // R/W_OUTPUT
	Set_BIT(LCD_CONTROL_Direction,LCD_ENABLE_PIN);          // E_OUTPUT
	Set_BIT(LCD_CONTROL_Direction,LCD_Data_Command_PIN);    // RS_OUTPUT
	#if (LCD_BITMODE ==8)
		{
			LCD_Direction_PINS=0xff;                // LCD_DATA_PINS OUTPUT
			u8SEND_COMMAND (EIGHT_BIT_TWO_LINE );   /* Initialize 16X2 LCD in 8bit mode */
		}
	#elif(LCD_BITMODE ==4)
		{
			LCD_Direction_PINS=0xff;               // LCD_DATA_PINS OUTPUT
			u8SEND_COMMAND (Four_BIT_TWO_LINE);   /* Initialize 16X2 LCD in 8bit mode */
		}
	#endif
	/*-----------------------------------------------------------------------*/
	_delay_ms(20);
	voidClear_LCD();/* LCD power up time to get things ready, it should always >15ms */
	u8SEND_COMMAND (DISPLAY_ON_CURSOR_ON);								/* Display ON, Cursor OFF command */
	u8SEND_COMMAND (ENTRY_MODE);								/* Auto Increment cursor */
}
/*---------------------------------------------------*/
void voidENABLE_TRANSMIT(void)
{
	Set_BIT(LCD_CONTROL_value,LCD_ENABLE_PIN);
	_delay_us(1);
	Clear_BIT(LCD_CONTROL_value,LCD_ENABLE_PIN);
	_delay_ms(3);
}
/*---------------------------------------------------*/
void u8SEND_COMMAND(u8 command)
{
	#if (LCD_BITMODE ==8)
		{
		LCD_PORT_DATA= command;
		Clear_BIT(LCD_CONTROL_value,LCD_Read_Write_PIN);       // WRITE_MODE
		Clear_BIT(LCD_CONTROL_value,LCD_Data_Command_PIN);     // SEND_COMMAND
		voidENABLE_TRANSMIT();                                 // ENABLE TRANSMITT
		}
	#elif(LCD_BITMODE ==4)
		{
			LCD_PORT_DATA=(LCD_PORT_DATA &0x0F) | (command & 0xf0);
			Clear_BIT(LCD_CONTROL_value,LCD_Read_Write_PIN);       // WRITE_MODE
			Clear_BIT(LCD_CONTROL_value,LCD_Data_Command_PIN);     // SEND_COMMAND
			voidENABLE_TRANSMIT();                                 // ENABLE TRANSMITT
			_delay_us(20);
			LCD_PORT_DATA=((LCD_PORT_DATA & 0xF0) | (command<<4));
			Clear_BIT(LCD_CONTROL_value,LCD_Read_Write_PIN);       // WRITE_MODE
			Clear_BIT(LCD_CONTROL_value,LCD_Data_Command_PIN);     // SEND_COMMAND
			voidENABLE_TRANSMIT();
		}
	#endif

}
/*---------------------------------------------------*/
void u8SEND_DATA(u8 data)
{
	#if (LCD_BITMODE ==8)
		{
		LCD_PORT_DATA= data;
		Clear_BIT(LCD_CONTROL_value,LCD_Read_Write_PIN);       // WRITE_MODE
		Set_BIT(LCD_CONTROL_value,LCD_Data_Command_PIN);       // SEND_DATA
		voidENABLE_TRANSMIT();                                 // ENABLE TRANSMITT
		}
	#elif(LCD_BITMODE ==4)
		{
			LCD_PORT_DATA=(LCD_PORT_DATA & 0x0F) | (data & 0xf0);
			Clear_BIT(LCD_CONTROL_value,LCD_Read_Write_PIN);       // WRITE_MODE
			Set_BIT(LCD_CONTROL_value,LCD_Data_Command_PIN);       // SEND_DATA
			voidENABLE_TRANSMIT();
			_delay_us(200);
			LCD_PORT_DATA=((LCD_PORT_DATA &0xF0) | ((data<<4)));
			Clear_BIT(LCD_CONTROL_value,LCD_Read_Write_PIN);       // WRITE_MODE
			Set_BIT(LCD_CONTROL_value,LCD_Data_Command_PIN);       // SEND_DATA
			voidENABLE_TRANSMIT();
		}
	#endif
}
/*---------------------------------------------------*/
void u8SEND_STRING(u8* str)
{
	while (*str != '\0')
	{
		u8SEND_DATA(*str);
		str++;
	}
}
/*-------------------------------------------------------*/

void u8Diplay_NUMBER(u32 num)
{
	/*u8 arr[5];
	u8 i;
	for (i=1;i<5;i++)
	{
		arr[i]=num%10;
		num=num/10;
     }

		for (i=4;i>0;i--)
		{
			u8SEND_DATA(arr[i]+'0');
      	}*/
	char str[100];
	itoa(num,str,10);
	u8SEND_STRING(str);

}
/*********************************************************-*/
void u8Diplay_NUMBERXY(char row, char pos,u32 num)
{
	char str[10];
	itoa(num,str,10);
	LCD_String_xy(row,pos,str);
}
/*----------------------------------------------------------*/
void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD function */
{
	if (row == 1)
		u8SEND_COMMAND((pos & 0x0F)|0x80);				/* Command of first row and required position<16 */
	else if (row == 2)
		u8SEND_COMMAND((pos & 0x0F)|0xC0);				/* Command of Second row and required position<16 */
	else if (row == 3)
		u8SEND_COMMAND((pos & 0x0F)|0x90);				/* Command of Third row and required position<16 */
	else if (row == 4)
		u8SEND_COMMAND((pos & 0x0F)|0xD0);				/* Command of Fourth row and required position<16 */
	u8SEND_STRING(str);								/* Call LCD string function */
}
