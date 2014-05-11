/*! **********************************************************************************************
* 2014  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*
*
* @file:      SpeedManager.h
* @author(s):  
* Abner Perez Haro A01224776
* Juan Carlos Perez Castellanos A01225629
* 
* @brief (User's Manual)
*
**************************************************************************************************/

#ifndef SPEEDMANAGER_H_
#define SPEEDMANAGER_H_

 
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
void SpeedManager_Init(void);
/*
	Initialise the ADC module (ADC_Init()), 8-bit conversion, ADC channel 0 as default input.
	Set gu8AdcValue (ADC conversion result) initial value to 0.
	Set gu8speed (read speed) initial value to 0 .
*/
char SpeedManager_ReadSpeed(void);
/*
	It returns the current level speed (0-28).
*/
/*************************************************************************************************/
#endif /* SPEEDMANAGER_H_ */
