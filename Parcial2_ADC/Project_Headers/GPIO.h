/*! **********************************************************************************************
* 2014  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*
*
* @file:      GPIO.h
* @author(s):  
* Abner Perez Haro
* Juan Carlos Perez Castellanos
*
* @brief (User's Manual)
*
**************************************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

 
/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************						Typedefs						**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************			 	 Functions Like Macros					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Extern Variables					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Extern Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Function Prototypes					**********************/
/*************************************************************************************************/
void GPIO_ConfigPinDirection(char port, char pin, char dir);
void GPIO_ConfigPortDirection(char port, char dir);
void GPIO_ConfigPortDirection_Mask(char port, char mask);
char GPIO_ReadPort(char port);
char GPIO_ReadPin(char port,char pin);
void GPIO_WritePin(char port, char pin, char value);
void GPIO_WritePort(char port, char value);
/*************************************************************************************************/
#endif /* GPIO_H_ */
