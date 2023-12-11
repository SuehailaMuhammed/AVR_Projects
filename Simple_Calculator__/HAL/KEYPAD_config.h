/*
 * KEYPAD_config.h
 *
 *  Created on: Dec 8, 2023
 *      Author: future
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "stdTypes.h"
#include "DIO_priv.h"



#define KPD_Arr_Val  {{'7','8','9','/'},{'4','5','6','*'}, {'1','2','3','-'}, {'C','0','=','+'} }

#define Keypad_R1PORT DIO_PORTC
#define Keypad_R1PIN  DIO_PIN1

#define Keypad_R2PORT DIO_PORTC
#define Keypad_R2PIN  DIO_PIN2

#define Keypad_R3PORT DIO_PORTC
#define Keypad_R3PIN  DIO_PIN3

#define Keypad_R4PORT DIO_PORTC
#define Keypad_R4PIN  DIO_PIN4

#define Keypad_C1PORT DIO_PORTD
#define Keypad_C1PIN  DIO_PIN1

#define Keypad_C2PORT DIO_PORTD
#define Keypad_C2PIN  DIO_PIN2

#define Keypad_C3PORT DIO_PORTD
#define Keypad_C3PIN  DIO_PIN3

#define Keypad_C4PORT DIO_PORTD
#define Keypad_C4PIN  DIO_PIN4

#define NOT_PRESSED 0xFF


#endif /* KEYPAD_CONFIG_H_ */
