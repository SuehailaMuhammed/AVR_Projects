/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: future
 */


#include <util/delay.h>
#include "stdTypes.h"

#define PORTA *((u8*)0x3B)
#define DDRA  *((u8*)0x3A)
#define PINA  *((volatile u8*)0x39)

#define PORTB *((u8*)0x38)
#define DDRB  *((u8*)0x37)
#define PINB  *((volatile u8*)0x36)

#define PORTC *((u8*)0x35)
#define DDRC  *((u8*)0x34)
#define PINC  *((volatile u8*)0x33)

#define PORTD *((u8*)0x32)
#define DDRD  *((u8*)0x31)
#define PIND  *((volatile u8*)0x30)

int main(void)
{
	DDRA=0;

	while (1){
		for(int i=0;i<8;i++){
		DDRA |=(1<<i);
		PORTA |=(1<<i);

		}


		for(int i=0;i<8;i++)
		{
			PORTA &=~(1<<i);

		}

	}


}
