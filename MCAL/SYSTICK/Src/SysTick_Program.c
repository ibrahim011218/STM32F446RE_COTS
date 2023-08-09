/*
 ******************************************************************************
 * @file           : SYSTICK_Program.c
 * @Author         : Ibrahim Mohamed
 * @brief          : SYSTICK Main Program File
 * @Date           : May 11, 2023
 ******************************************************************************
 */


/*********************************************************************************
 * INCLUDES SECTION
 ***********************************************************************************/


#include <stdint.h>
#include "BIT_MATH.h"
#include "ErrType.h"
#include "Stm32F446xx.h"
#include "SysTick_Interface.h"




/**
 * @fn     : Systick_Delay_ms
 * @brief  : Fuction That Makes Delay in Software Based on Passed Number of Milliseconds
 * @param  : Copy_Time_Milli -> Time Passed To Delay in Milliseconds
 * @retval : ErrorStatus To Indicate if Function Worked Correctly or Not
 **/

uint8_t Systick_Delay_ms (uint32_t Copy_Time_Milli)
{
	/* Initialize Error State Local Variable */
	uint8_t Error_status= NOK;

	/* Set the value on Load Register ( Reload = time / ( (Freq_sys(HSI=16MHZ) / pres_c(8) )*1000) )   */
	STK_LOAD = Copy_Time_Milli * 2000U;
	/* Selects the clock source : AHHB/8 */
	STK_CTRL &= ~(1 << CTRL_CLKSOURCE);
	/* Enable the counter */
	STK_CTRL |= (1 << CTRL_ENABLE);
	/* Waiting for the flag */
	while( GET_BIT(STK_CTRL,CTRL_COUNTFLAG) == 0);
	/* Disable the counter */
	STK_CTRL &= ~(1 << CTRL_ENABLE);

	Error_status= OK;

	return Error_status;

}
