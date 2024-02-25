/*
 * LCD_private.h
 *
 *  Created on: Nov 21, 2023
 *      Author: Mohamed Ezzat
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

/******************************************************************/
/************************PRIVATE FUNCTIONS************************/
/***************************************************************/
/* DESCRIPTION : GET POWER OF NUMBER
 * INPUT       : u8Base, Range: 0~255
 *               u8Exp,  Range: 0~255
 *RETURN       : u32,    Range: 0~4294967296
 ****************************************************************/
u32 u32Power(u8 u8Base , u8 u8Exp);


#endif /* LCD_PRIVATE_H_ */
