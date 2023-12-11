/*
 * KEYPAD_prog.c
 *
 *  Created on: Dec 8, 2023
 *      Author: future
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "KEYPAD_config.h"
#include "KEYPAD_priv.h"



ES_t KEYPAD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	/*set Columns pins Direction as OUTPUT*/
	Local_enuErrorState = DIO_enuSetPinDirection(Keypad_C1PORT,Keypad_C1PIN,DIO_u8OUTPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(Keypad_C2PORT,Keypad_C2PIN,DIO_u8OUTPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(Keypad_C3PORT,Keypad_C3PIN,DIO_u8OUTPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(Keypad_C4PORT,Keypad_C4PIN,DIO_u8OUTPUT);

	/*Set Rows Pins Direction as INPUT*/
	Local_enuErrorState = DIO_enuSetPinDirection(Keypad_R1PORT,Keypad_R1PIN,DIO_u8INPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(Keypad_R2PORT,Keypad_R2PIN,DIO_u8INPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(Keypad_R3PORT,Keypad_R3PIN,DIO_u8INPUT);
	Local_enuErrorState = DIO_enuSetPinDirection(Keypad_R4PORT,Keypad_R4PIN,DIO_u8INPUT);

	/*Set Raws value As Pull up*/
	Local_enuErrorState = DIO_enuSetPinValue(Keypad_R1PORT,Keypad_R1PIN,DIO_u8PULL_UP);
	Local_enuErrorState = DIO_enuSetPinValue(Keypad_R2PORT,Keypad_R2PIN,DIO_u8PULL_UP);
	Local_enuErrorState = DIO_enuSetPinValue(Keypad_R3PORT,Keypad_R3PIN,DIO_u8PULL_UP);
	Local_enuErrorState = DIO_enuSetPinValue(Keypad_R4PORT,Keypad_R4PIN,DIO_u8PULL_UP);

	/*Set Columns Value as High*/
		Local_enuErrorState = DIO_enuSetPinValue(Keypad_C1PORT,Keypad_C1PIN,DIO_u8HIGH);
		Local_enuErrorState = DIO_enuSetPinValue(Keypad_C2PORT,Keypad_C2PIN,DIO_u8HIGH);
		Local_enuErrorState = DIO_enuSetPinValue(Keypad_C3PORT,Keypad_C3PIN,DIO_u8HIGH);
		Local_enuErrorState = DIO_enuSetPinValue(Keypad_C4PORT,Keypad_C4PIN,DIO_u8HIGH);

	return Local_enuErrorState;
}

u8 KEYPAD_u8GetPressedKey(void)
{
	/* Two arrays --> one for Columns ports & one for Columns pins */
	static u8 Local_Au8ColumnsPorts[COLUMN_NUM] = {Keypad_C1PORT, Keypad_C2PORT, Keypad_C3PORT, Keypad_C4PORT};
	static u8 Local_Au8ColumnsPins[COLUMN_NUM] = {Keypad_C1PIN, Keypad_C2PIN, Keypad_C3PIN, Keypad_C4PIN};

	/* Two arrays --> one for Rows ports & one for Rows pins */
	static u8 Local_Au8RowsPorts[ROW_NUM] = {Keypad_R1PORT, Keypad_R2PORT, Keypad_R3PORT, Keypad_R4PORT};
	static u8 Local_Au8RowsPins[ROW_NUM] = {Keypad_R1PIN, Keypad_R2PIN, Keypad_R3PIN, Keypad_R4PIN};

	/* array for Keypad characters */
	static u8 Local_KEYPAD_CHAR[ROW_NUM][COLUMN_NUM] = KPD_Arr_Val;

	u8 Local_u8ColumnIndex, Local_u8RowIndex, Local_u8PinState;
	u8 Local_u8PressedKey = NOT_PRESSED;

	for(Local_u8ColumnIndex = 0; Local_u8ColumnIndex < COLUMN_NUM; Local_u8ColumnIndex++)
	{
		/* Activate the current column */
		DIO_enuSetPinVal(Local_Au8ColumnsPorts[Local_u8ColumnIndex], Local_Au8ColumnsPins[Local_u8ColumnIndex], DIO_u8LOW);

		for(Local_u8RowIndex = 0; Local_u8RowIndex < ROW_NUM; Local_u8RowIndex++)
		{
			/* iterate on reading Row pins value */
			DIO_enuGetPinVal(Local_Au8RowsPorts[Local_u8RowIndex], Local_Au8RowsPins[Local_u8RowIndex], &Local_u8PinState);

			if(DIO_u8LOW == Local_u8PinState)
			{
				Local_u8PressedKey = Local_KEYPAD_CHAR[Local_u8RowIndex][Local_u8ColumnIndex];

				/* single press */
				while(DIO_u8LOW == Local_u8PinState)
				{
					DIO_enuGetPinVal(Local_Au8RowsPorts[Local_u8RowIndex], Local_Au8RowsPins[Local_u8RowIndex], &Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}

		/* Deactivate the current column */
		DIO_enuSetPinVal(Local_Au8ColumnsPorts[Local_u8ColumnIndex], Local_Au8ColumnsPins[Local_u8ColumnIndex], DIO_u8HIGH);
	}


	return Local_u8PressedKey;
}
