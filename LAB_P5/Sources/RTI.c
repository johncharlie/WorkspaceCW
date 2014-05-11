/*! **********************************************************************************************
* 2014  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
*  
*
* @file:      RTI.c
* @author(s):  
*
* @brief (Theory of Operation)
*
**************************************************************************************************/


/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "derivative.h"
/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/
#define ONE_SEC_MASK 0x07
#define START_MASK 0x17
#define STOP_MASK 0x07
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
static char sgu8isRunning = 0;
static char sgu8flagCounter = 0;
/*************************************************************************************************/
/*********************                  Static Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Global Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************				   Exported Functions					**********************/
/*************************************************************************************************/
void RTI_Init(void)
{
	//Configure time out of 1.024s
	SRTISC = ONE_SEC_MASK;
}

void RTI_Start(void)
{
	SRTISC = START_MASK;
	sgu8isRunning = 1;
	sgu8flagCounter = 0;
}
void RTI_Stop(void)
{
	SRTISC = STOP_MASK;
	sgu8isRunning = 0;
}
char RTI_isRunning(void)
{
	return sgu8isRunning;
}
/*************************************************************************************************/
/*********************				    Private Functions					**********************/
/*************************************************************************************************/
interrupt 23 void RTI_interrupt(void)
{
	//Clear flag
	SRTISC_RTIACK = 1;
	sgu8flagCounter++;
	if(10 == sgu8flagCounter)
	{
		RTI_Stop();
	}
}
