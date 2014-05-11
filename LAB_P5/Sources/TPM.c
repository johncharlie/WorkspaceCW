/*! **********************************************************************************************
* 2014  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*  
*
* @file:      TPM.c
* @author(s):  
* Abner P�rez Haro A01224776
* Juan Carlos P�rez Castellanos A01225629
* 
* @brief (Theory of Operation)
* This driver set this initial configuration for TPM:
*	-> Enable flag interrupt
*	-> No clock source selected
*	-> Prescale divisor 1/4
* It allows to configure the interrupt flag time in us, and set extra interrupt flags to obtain longer
* delays. It is possible to start, stop and know whether the timer is running or not. 
**************************************************************************************************/


/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "derivative.h"
/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/
#define INITIAL_CONFIG 0b01000010
#define START_MASK 0x08
#define STOP_MASK 0x0F7
#define MAX_NUM_OF_FLAGS 200
/*************************************************************************************************/
/*********************						Typedefs						**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Function Prototypes					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Static Variables                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Global Variables					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Static Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Global Constants                    **********************/
/*************************************************************************************************/
char gu8flagCounter = 0;
char gu8extraFlagsPDelay = 0;
char gu8running = 0;
/*************************************************************************************************/
/*********************				   Exported Functions					**********************/
/*************************************************************************************************/

void TPM_Init(void)
{
	//Set initial configuration:
	//*Enable flag interrupt
	//*No clock source selected
	//*Prescale divisor 1/4
	TPMSC = INITIAL_CONFIG;
	
	//Reset Timer Module
	TPMMODH = 0;
	TPMMODL = 0;
	
	//Reset flag counters
	gu8flagCounter = 0;
	gu8extraFlagsPDelay = 0;
	
	//Timer is stopped
	gu8running = 0;
}

void TPM_SetExtraFlags(char u8numFlags)
{
	if(!gu8running)
	{
		gu8extraFlagsPDelay = u8numFlags;
	}
}

void TPM_SetMicroSecPFlag(unsigned int u16microSec)
{
	//Store u16microSec in timer module
	TPMMODL = (char)u16microSec;
	TPMMODH = (char)(u16microSec >> 8);
}

void TPM_Start(void)
{
	if(!gu8running)
	{
		//Bus clock as source selected
		TPMSC |= START_MASK;
		//Toggle running flag
		gu8running = (~gu8running)&0x01;
	}	
}

void TPM_Stop(void)
{
	if(gu8running)
	{
		//No clock source selected
		TPMSC &= STOP_MASK;
		//Toggle running flag
		gu8running = (~gu8running)&0x01;
	}
}

char TMP_IsRunning(void)
{
	return gu8running;
}

/*************************************************************************************************/
/*********************				    Private Functions					**********************/
/*************************************************************************************************/

interrupt 7 void TMP_ISR(void)
{
	TPMSC_TOF = 0;
	if(gu8flagCounter < gu8extraFlagsPDelay)
	{
		gu8flagCounter++;
	}
	else
	{
		gu8flagCounter = 0;
		TPM_Stop();
	}
}
