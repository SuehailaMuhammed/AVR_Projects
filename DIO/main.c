/*
 * main.c
 *
 *  Created on: Dec 7, 2023
 *      Author: future
 */


#include "stdTypes.h"
#include "errorStates.h"
#include "DIO_int.h"
#include <util/delay.h>

int main(void)
{
	u8 segCthd []= { 0x3f, 0x06, 0x5B,
					 0x4F, 0x66, 0x6D,
					 0x7D, 0x07, 0x7F,
					 0x6F},i,j;
	DIO_enuInit();
	DIO_enuSetPortValue(DIO_u8PORTB , 0x00);
	while(1)
	{
		for(i=0;i<10;i++)
		{
			DIO_enuSetPortValue(DIO_u8PORTB , segCthd[0]);
			DIO_enuSetPortValue(DIO_u8PORTA , segCthd[i]);
			for (j=0;j<10;j++)
			{
				DIO_enuSetPortValue(DIO_u8PORTB , segCthd[j]);
				_delay_ms(500);
			}
		}
	}

}


