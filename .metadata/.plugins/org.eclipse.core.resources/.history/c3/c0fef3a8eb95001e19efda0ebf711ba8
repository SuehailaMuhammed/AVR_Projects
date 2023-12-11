/*
 * main.c
 *
 *  Created on: Dec 8, 2023
 *      Author: future
 */


#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"
#include "KEYPAD_int.h"
#include "KEYPAD_config.h"
 void main(void)
 {
	 u8 Local_u8Key;
	 DIO_enuInit();
	 KEYPAD_enuInit();
	 while(1)
	 {
		 do
		 {
			 Local_u8Key = KEYPAD_u8GetPressedkey();
		 }while( Local_u8Key == NOT_PRESSED );
	 }

 }
