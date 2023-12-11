/*
 * KEYPAD_int.h
 *
 *  Created on: Dec 8, 2023
 *      Author: future
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#include "errorStates.h"
#include "stdTypes.h"

ES_t KEYPAD_enuInit(void);
ES_t KEYPAD_u8GetPressedkey(u8 *Local_u8pPressedKey);

#endif /* KEYPAD_INT_H_ */
