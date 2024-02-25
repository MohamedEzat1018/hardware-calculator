/*
 * CALC_program.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Mohamed Ezzat
 */
#include "LIB/STD_TYPES.h"
#include "CALC_private.h"
#include "CALC_interface.h"



u32 CALC_u32GetResult(u8* ptau8Operand1,u8* ptau8Operand2 , u8 u8Sign , u8 u8Op1NumOfDigits,u8 u8Op2NumOfDigits)
{
	u32 u32Result = 0;
	u32 u32Operand1 = 0;
	u32 u32Operand2 = 0;
	u32 u32multipicand;
	u8 u8Iterator;

	/* Convert Operand 1 From Array Of Character To Integer Number & Reset Operand 1 Array  */
	for(u8Iterator = ITERATOR_BGN ; u8Iterator < u8Op1NumOfDigits ; u8Iterator++)
	{
		u32multipicand = CALC_u32Power(BASE,(u8Op1NumOfDigits-u8Iterator-OFFSET));
		u32Operand1 += ((ptau8Operand1[u8Iterator]-'0') * u32multipicand);
		ptau8Operand1[u8Iterator] = RESET;
	}
	/* Convert Operand 2 From Array Of Character To Integer Number & Reset Operand 2 Array  */
	for(u8Iterator = ITERATOR_BGN ; u8Iterator < u8Op2NumOfDigits ; u8Iterator++)
	{
		u32multipicand = CALC_u32Power(BASE,(u8Op2NumOfDigits-u8Iterator-OFFSET));
		u32Operand2 += ((ptau8Operand2[u8Iterator]-'0') * u32multipicand);
		ptau8Operand2[u8Iterator] = RESET;
	}
	/* Get Operation For Operand 1 & Operand 2 Result */
	switch(u8Sign)
	{
		case '+': u32Result = u32Operand1 + u32Operand2 ; break;
		case '/': u32Result = u32Operand1 / u32Operand2 ; break;
		case '-': u32Result = u32Operand1 - u32Operand2 ; break;
		case 'x': u32Result = u32Operand1 * u32Operand2 ; break;
	}
	return u32Result;
}

u32 CALC_u32Power(u8 u8Base , u8 u8Exp)
{
	u32 u32Result = 1;
	while (u8Exp != 0)
	{
		u32Result *= u8Base;
		u8Exp--;
	}
	return u32Result;
}
