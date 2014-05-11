/*! **********************************************************************************************
* 2014  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*
*
* @file:      DelayManager.h
* @author(s):
* Abner Perez Haro A01224776
* Juan Carlos Perez Castellanos A01225629  
*
* @brief (User's Manual)
*
**************************************************************************************************/

#ifndef DELAYMANAGER_H_
#define DELAYMANAGER_H_

 
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
void DelayManager_Init(void);
void DelayManager_SetDelay(char u8speed);
void DelayManager_Delay(void);
/*************************************************************************************************/
#endif /* DELAYMANAGER_H_ */
