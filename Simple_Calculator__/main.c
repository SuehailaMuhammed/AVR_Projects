/*
 * main.c
 *
 *  Created on: Dec 8, 2023
 *      Author: future
 */

#include "stdTypes.h"
#include <util/delay.h>
#include "errorStates.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"

#define _LCD_CLEAR                      0X01

u16 calc_sum(  u8 a[],u8 b[],u8 n,u8 m);
u16 calc_sub(  u8 a[],u8 b[],u8 n,u8 m);
u16 calc_multi(u8 a[],u8 b[],u8 n,u8 m);
u16 calc_div(  u8 a[],u8 b[],u8 n,u8 m);


u8 counter = 0;
u8 KpValue=255;                       //variable to store the pressed button for Keypad
u8 Reset=1;

u8 FristNum[4];                       //Array to store the first number (Assuming the number of digits 4)
u8 SecondNum[4];                      //Array to store the Second number (Assuming the number of digits 4)


int main()
{


			/*   Loading to Start Calculator    */
	         LCD_enuInit();
	          LCD_enuDisplayString((u8*) "Welcome!");


	          LCD_enuDisplayString((u8*) "Calculator is ready");
	          				_delay_ms(1000);
	          				LCD_enuSendCommand(_LCD_CLEAR);
	          				//KpValue == '\0';
	          				counter=0;

			/*    loop for repeating the calculation    */
		while(1){
			u8 operation=0;
				/*    Getting The First Number    */
				while(1)
				{
					do{
						KpValue =KEYPAD_u8GetPressedKey();
						_delay_ms(200);
					}while(KpValue == '\0');

					if(KpValue == '+' || KpValue == '-' || KpValue == '/' || KpValue == '*'){
						operation = KpValue;
						LCD_enuDisplayChar(KpValue);
						break;
					}
					FristNum[counter]=KpValue;
					counter++;
					LCD_enuDisplayChar(KpValue);

				}
				u8 counter2=counter+1;
				u8 counter3=0;


				/*    Getting The Second Number    */
				while(1)
				{
					do{
						KpValue = KEYPAD_u8GetPressedKey();
						_delay_ms(200);
					}while(KpValue == '\0');
					if(KpValue == '=' ){
						LCD_enuDisplayChar(KpValue);
						break;
					}
					SecondNum[counter3]=KpValue;
					counter2++;
					counter3++;
					LCD_enuDisplayChar(KpValue);
				}


				/*     switch which operation was Selected */
				switch(operation)
				{
					case '+': LCD_enuDisplayChar(calc_sum(FristNum,SecondNum,counter,counter3)); break;
					case '-': LCD_enuDisplayChar(calc_sub(FristNum,SecondNum,counter,counter3)); break;
					case '*': LCD_enuDisplayChar(calc_multi(FristNum,SecondNum,counter,counter3)); break;
					case '/': LCD_enuDisplayChar(calc_div(FristNum,SecondNum,counter,counter3)); break;
				}
				_delay_ms(3000);
				LCD_enuSendCommand(_LCD_CLEAR);


}



u16 calc_sum(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{

		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1+num2);
}

u16 calc_sub(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1-num2);
}

u16 calc_multi(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1*num2);
}

u16 calc_div(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1/num2);
}
return 0;
}

