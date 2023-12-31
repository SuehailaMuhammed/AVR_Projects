/*
 * main.c
 *
 *  Created on: Oct 21, 2023
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

int main(){

	DDRA = 0;
		DDRA |= (1<<0);
		DDRA |= (1<<1);

		PORTB = 0b00001110;

		while(1) {

			if( ( (PINB >> 3) & 1) == 0  && ( ( (PINB >> 1) & 1) == 1 && ( (PINB >> 2) & 1) == 1 )) {
				PORTA |= (1<<0);
				PORTA |= (1<<1);
			}
			else if(( (PINB >> 2) & 1) == 0 ) {
				PORTA |= (1<<1);
				PORTA &= ~(1<<0);
			}
			else if(( (PINB >> 1) & 1) == 0) {
				PORTA |= (1<<0);
				PORTA &= ~(1<<1);
			}
			else {
				PORTA &= ~(1<<0);
				PORTA &= ~(1<<1);
			}
		}



	return 0;
}
