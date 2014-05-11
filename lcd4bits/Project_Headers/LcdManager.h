/*! **********************************************************************************************
* 2014  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*
*
* @file:      LcdManager.h
* @author(s):  
*
* @brief (User's Manual)
*
**************************************************************************************************/

#ifndef LCDMANAGER_H_
#define LCDMANAGER_H_

 
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
void LcdManager_Init(void);
unsigned int LcdManager_RemainderTask(void);
unsigned int LcdManager_Write(char u8speedCurrent, char u8adcValue, char u8dir, char u16motorDelay);

/*************************************************************************************************/
#endif /* LCDMANAGER_H_ */
