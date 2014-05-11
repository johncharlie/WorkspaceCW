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
/*
	Initialise the timer module (MTIM).
	It sets the base time for the fast motor speed.
*/
char DelayManager_SetDelayBySpeed(char u8speed);
/*
	Set the required delay for the speed selected (u8speed), from 0 to 28 level.
	If u8speed is out of range, it returns 0, otherwise 1.
*/
void DelayManager_SetDebouncingDelay(void);
/*
 	 Set a de-bouncing delay for a push button. 
 */
void DelayManager_Delay(void);
/*
	Starts the set up delay. 
*/
/*************************************************************************************************/
#endif /* DELAYMANAGER_H_ */
