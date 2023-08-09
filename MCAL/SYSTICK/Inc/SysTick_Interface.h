/*
 ******************************************************************************
 * @file           : SYSTICK_Interface.h
 * @Author         : Ibrahim Mohamed
 * @brief          : SYSTICK Interface File
 * @Date           : May 11, 2023
 ******************************************************************************
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_




/**
 * @fn     : Systick_Delay_ms
 * @brief  : Fuction That Makes Delay in Software Based on Passed Number of Milliseconds
 * @param  : Copy_Time_Milli -> Time Passed To Delay in Milliseconds
 * @retval : ErrorStatus To Indicate if Function Worked Correctly or Not
 **/

uint8_t Systick_Delay_ms (uint32_t Copy_Time_Milli);





#endif /* SYSTICK_INTERFACE_H_ */
