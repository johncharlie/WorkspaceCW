/*! **********************************************************************************************
* 2014  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*
*
* @file:      TPM.h
* @author(s):  
* Abner Perez Haro A01224776
* Juan Carlos Perez Castellanos A01225629
* 
* @brief (User's Manual)
**************************************************************************************************/

#ifndef TPM_H_
#define TPM_H_

 
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
void TPM_Init(void);
/*
		Reset TPM module and initialise as default configuration: 
		*Enable flag interrupt
		*No clock source selected
		*Prescale divisor 1/4
*/

void TPM_SetLimitFlags(char u8numFlags);
/*
	Set the number of times timer interrupt flag has to be triggered before the timer stops.
*/
void TPM_SetMicroSecPFlag(unsigned int u16microSec);
/*
	Configure the time in microseconds to launch the interrupt timer flag.
*/
void TPM_Start(void);
/*
	Start timer operation. It will stop when the maximum number of flags is reached.    
*/
void TPM_Stop(void);
/*
	Stop timer operation.
*/
char TMP_isRunning(void);
/*
	It returns 1 if timer is running, and 0 if it is stopped.
*/
/*************************************************************************************************/
#endif /* TPM_H_ */
