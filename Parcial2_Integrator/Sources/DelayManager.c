/*! **********************************************************************************************
* 2014  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*  
*
* @file:      DelayManager.c
* @author(s):  
* Abner Perez Haro A01224776
* Juan Carlos Perez Castellanos A01225629
* 
* @brief (Theory of Operation)
*
**************************************************************************************************/


/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "TPM.h"
#include "derivative.h"
/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/

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

/*************************************************************************************************/
/*********************				   Exported Functions					**********************/
/*************************************************************************************************/

void DelayManager_Init(void)
{
	TPM_Init();
}

void DelayManager_SetDelay(char u8speed)
{
	TPM_SetLimitFlags(u8speed);
}

void DelayManager_Delay(void)
{
	TPM_Start();
	while(TMP_isRunning())
	{
		__RESET_WATCHDOG();
	}
}

/*************************************************************************************************/
/*********************				    Private Functions					**********************/
/*************************************************************************************************/

