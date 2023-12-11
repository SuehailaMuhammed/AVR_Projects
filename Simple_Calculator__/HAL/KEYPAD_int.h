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
u8 KEYPAD_u8GetPressedKey(void);

#endif /* KEYPAD_INT_H_ */
