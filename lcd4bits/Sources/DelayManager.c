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
* Generates a delay according to the speed selected. It sets up a base delay in MTIM (1920us), 
* the enough one to guarantee the maximum motor speed. It can generate longer delays with multiples
* of the base time.

**************************************************************************************************/


/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "derivative.h"
#include "MTIM.h"
/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/
#define BUS_CLK 0
#define DIVIDED_BY_32 5
#define MODULO_VAL 240
#define FLAGS_FOR_DEBOUNCING 131
#define MAX_LEVEL_SPEED 28
#define MIN_LEVEL_SPEED 0
#define MIN_DELAY_VAL 1920

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
	//Set up default TMP configuration
	//MTIM_Init();
	//(void)MTIM_SelectClkSource(BUS_CLK);
	//(void)MTIM_SelectPrescaler(DIVIDED_BY_32);
	//MTIM_SetTimerModulo(MODULO_VAL);
	//MTIM_InterruptOn();
}

char DelayManager_SetDelayBySpeed(char u8speed)
{
	char u8extraFlags = 0;
	if(u8speed >= MIN_LEVEL_SPEED && u8speed <= MAX_LEVEL_SPEED)
	{
		//Calculate the extra flags requires for this speed
		u8extraFlags = MAX_LEVEL_SPEED - u8speed;
		(void)MTIM_SetExtraFlags(u8extraFlags);
		return 1;
	}
	return 0;
}

void DelayManager_SetDelayByMicroSeg(unsigned int u16motorDelay){
	MTIM_SetExtraFlags(u16motorDelay/100-1);
	MTIM_Start();
	while(MTIM_IsRunning())
	{
		__RESET_WATCHDOG();
	}
}

void DelayManager_SetDebouncingDelay()
{
	//((MODULO_VAL)*(32 prescaler)/(4MHz CLK))*FLAGS_FOR_DEBOUNCING = 250 ms delay aprox. 
	(void)MTIM_SetExtraFlags(FLAGS_FOR_DEBOUNCING);
}

void DelayManager_Delay(void)
{
	MTIM_Start();
	while(MTIM_IsRunning())
	{
		__RESET_WATCHDOG();
	}
}

int DelayManager_SpeedtoMicroSeg(char u8speed)
{
	return MIN_DELAY_VAL * u8speed;
}

/*************************************************************************************************/
/*********************				    Private Functions					**********************/
/*************************************************************************************************/


