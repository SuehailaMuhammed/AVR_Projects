/*
 * main.c
 *
 *  Created on: Dec 8, 2023
 *      Author: future
 */

#include "stdTypes.h"
#include "util/delay.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "LCD_int.h"



int main (void)
{
	LCD_enuInit();
	LCD_enuDisplayChar('S');
	LCD_enuDisplayChar('u');
	LCD_enuDisplayChar('e');
	LCD_enuDisplayChar('h');
	LCD_enuDisplayChar('a');
	LCD_enuDisplayChar('i');
	LCD_enuDisplayChar('l');
	LCD_enuDisplayChar('a');
	_delay_ms(3000);
	LCD_enuSendCommand(0x01);


	while (1);

	return 0;
}