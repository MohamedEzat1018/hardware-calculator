/*
 * CALC_private.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Mohamed Ezzat
 */

#ifndef CALC_PRIVATE_H_
#define CALC_PRIVATE_H_

/*********************************************************/
/*********************PRIVATE MACROS*********************/
/*******************************************************/
#define BASE          10
#define OFFSET        1
#define ITERATOR_BGN  0
#define RESET         0

/******************************************************/
/*******************PRIVATE FUNCTIONS*****************/
/****************************************************/
/* DESCRIPION : CALCULATE POWER OF NUMBER
 * INPUT      : u8Base, Range: 0~255 [10]
 *              u8Exp , Range: 0~255
 *RETURN      : u32   , Range: 0~4294967296
 ************************************************/
u32 CALC_u32Power(u8 u8Base , u8 u8Exp);

#endif /* CALC_PRIVATE_H_ */
