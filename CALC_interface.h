/*
 * CALC_interface.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Mohamed Ezzat
 */

#ifndef CALC_INTERFACE_H_
#define CALC_INTERFACE_H_
/*********************************************************/
/***********************PUBLIC MACROS********************/
/*******************************************************/
#define OPERANDS_SIZE     9

/******************************************************/
/**********************PUBLIC FUNCTIONS***************/
/****************************************************/
/* DESCRIPTION : GET RESULT OF SIMPLE OPRATION FOR 2 OPERANDS (+,-,/,*)
 * INPUT       : ptau8Operand1 POINTER TO ARRAY FOR OPERAND 1
 *               ptau8Operand2 POINTER TO ARRAY FOR OPERAND 2
 *               u8Sign SIGN OPERATION [+,-,*,/]
 *               u8Op1NumOfDigits NUMBER OF OPERAND 1 DIGITS,Range:0~255
 *               u8Op2NumOfDigits NUMBER OF OPERAND 2 DIGITS,Range:0~255
 *RETURN       : u32, Range: 0~4294967296
 ***********************************************************************/
u32 CALC_u32GetResult(u8* ptau8Operand1,u8* ptau8Operand2 , u8 u8Sign , u8 u8Op1NumOfDigits,u8 u8Op2NumOfDigits);


#endif /* CALC_INTERFACE_H_ */
