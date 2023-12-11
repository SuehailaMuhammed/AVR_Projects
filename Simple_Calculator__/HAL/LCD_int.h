/*
 * LCD_int.h
 *
 *  Created on: Dec 8, 2023
 *      Author: future
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#define _LCD_CLEAR                      0X01
#define ROW1   1
#define ROW2   2


ES_t LCD_enuInit(void);

ES_t LCD_enuDisplayChar(u8 Copy_u8Data);
ES_t LCD_enuSendCommand(u8 Copy_u8Command);

ES_t LCD_enuDisplayString(u8 *Copy_pu8Str);
ES_t LCD_enuDisplayStringPos(u8 *string,u8 row,u8 column);


ES_t LCD_enuSendCharPos(u8 Copy_u8char,u8 row,u8 column);


ES_t LCD_enuDisplayInt(u32 Copy_s32Number);
ES_t LCD_enuSendIntPos(u32 Copy_s32Number,u8 row,u8 column);



ES_t LCD_enuGoToPosition(u8 Copy_u8Line, u8 Copy_u8Position);



#endif /* LCD_INT_H_ */
