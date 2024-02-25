/*
 * main.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Mohamed Ezzat
 */
#include "LIB/STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"
#include "CALC_interface.h"


void main()
{
	//INITIALIZATION
	/* Local Variable Initialization */
	u8 au8Operand1[OPERANDS_SIZE];             //ArrayOfOperand 1
	u8 au8Operand2[OPERANDS_SIZE];             //ArrayOfOperand 2
	u8 u8Sign;                                 //Operation Sign
	u8 u8NumberOfDigits1 = 0;                  //Number Of Digits For Operand1
	u8 u8NumberOfDigits2 = 0;                  //Number Of Digits For Operand1
	u8 u8EqFlag  = 0;                          //Flag To avoid Write On LCDScreen After Press '=' Before press 'c'
 	u8 u8ConFlag = 0;                          //Flag To Choose Write KeyPressed Value In Op1 Or OP2 Array
	u8 u8KeyPressed;                           //KeyPad Key Pressed
	u32 u32Result;                             //Result Of Operation

	/* DIO Initialization */
	/******************LCD*********************/
	/* LCD DATA PORT */
	DIO_voidSetPortDir(DIO_PORTC , DIO_PORT_OUTPUT);
	/* LCD CONTROL PORT */
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN0,DIO_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN2,DIO_OUTPUT);
	/****************KEYPAD******************/
	/* KPD ROWS & COLUMNS PORT */
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN4,DIO_INPUT);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN5,DIO_INPUT);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN6,DIO_INPUT);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN7,DIO_INPUT);
	DIO_voidSetPortVal(DIO_PORTA , DIO_PORT_HIGH);  // set pull up */

	/* LCD Initialization */
	LCD_voidInit();
	LCD_voidClearDisplay();

	/* LOOP */
	while(1)
	{
		u8KeyPressed = KPD_u8GetKeyPressed();
		if(u8KeyPressed !=NULL)
		{
			/*print key pressed on LCD until Press '=' */
			if(u8EqFlag == 0)
			{
				LCD_voidSendData(u8KeyPressed);
			}
			if((u8KeyPressed == '=')||(u8KeyPressed == 'c'))
			{
				switch(u8KeyPressed)
				{
				case '=':
					u8EqFlag = 1;
					/* Special cases */
					/* Division by 0 */
					if ((u8Sign == '/') && (u8ConFlag == 1) && (u8NumberOfDigits2 == 1) && (au8Operand2[0] == '0'))
					{
						LCD_voidSetPosition(LCD_LINE2,LCD_COLUM1);
						LCD_voidSendString("Math Error");
					}
					/* If the second operand  don't exist */
					else if((u8ConFlag == 1) && (u8NumberOfDigits2 == 0))
					{
						LCD_voidSetPosition(LCD_LINE2,LCD_COLUM1);
						LCD_voidSendString("Syntax Error");
					}
					/* Normal case */
					else
					{
						u32Result = CALC_u32GetResult(au8Operand1,au8Operand2,u8Sign,u8NumberOfDigits1,u8NumberOfDigits2);
						LCD_voidSetPosition(LCD_LINE2,LCD_COLUM1);
						LCD_voidSendIntager(u32Result);
						u8EqFlag = 1;
					}
					break;
				case 'c':
					LCD_voidClearDisplay();
					LCD_voidSetPosition(LCD_LINE1,LCD_COLUM1);
					u8ConFlag = 0;
					u8NumberOfDigits1 = 0;
					u8NumberOfDigits2 = 0;
					u8EqFlag = 0;
					break;
				}
			}
			else if((u8KeyPressed == '+')||(u8KeyPressed == '/')||(u8KeyPressed == '-')||(u8KeyPressed == 'x'))
			{
				u8Sign = u8KeyPressed;
				u8ConFlag = 1;
			}
			else
			{
				switch(u8ConFlag)
				{
				case 0: au8Operand1[u8NumberOfDigits1] = u8KeyPressed; u8NumberOfDigits1 ++; break;
				case 1: au8Operand2[u8NumberOfDigits2] = u8KeyPressed; u8NumberOfDigits2 ++; break;
				}
			}
		}
	}
}







