/*
 * KPD_config.h
 *
 *  Created on: Nov 24, 2023
 *      Author: Mohamed Ezzat
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

/******************************KPD CONNECTION CONFIG*****************/
/* DESCRIPTION : KPD ROWS & COLUMNS PORT
 * OPTIONS     : DIO_PORTA ~DIO_PORTD
 ***************************************/
#define KPD_ROWS_PORT                       DIO_PORTA
#define KPD_COLUMNS_PORT                    DIO_PORTA

/* DESCRIPTION : KPD NUMBER OF ROWS & COLUMNS &PINS THAT CONNECTION EACH OF THEM
 * OPTIONS     : DIO_PIN0 ~DIO_PIN7
 ***************************************/
/******************KPD NUMBER OF COLUMNS & EACH COULMN PIN**************/
#define KPD_COLUMNS                          4
#define KPD_COLUMN1                          DIO_PIN0
#define KPD_COLUMN2                          DIO_PIN1
#define KPD_COLUMN3                          DIO_PIN2
#define KPD_COLUMN4                          DIO_PIN3


/****************KPD NUMBER OF ROWS & EACH ROW PIN******************/
#define KPD_ROWS                            4
#define KPD_ROW1                            DIO_PIN4
#define KPD_ROW2                            DIO_PIN5
#define KPD_ROW3                            DIO_PIN6
#define KPD_ROW4                            DIO_PIN7

/************************KPD MATRIX CONFIG***********************/
#define KPD_MATRIX                  {{'7','8','9','/'},{'4','5','6','x'},{'1','2','3','-'},{'c','0','=','+'}}



#endif /* KPD_CONFIG_H_ */
