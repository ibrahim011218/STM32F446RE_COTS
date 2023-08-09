/*
 ******************************************************************************
 * @file           : SCB_Program.c
 * @Author         : Ibrahim Mohamed
 * @brief          : SCB Program File
 * @Date           : Jul 16, 2023
 ******************************************************************************
 */

/**********************   Includes section *****************************/
#include <stdint.h>
#include "Stm32F446xx.h"
#include "ErrType.h"

#include "SCB_Interface.h"

/**********************************************************************/

/**
 * @fn    : SCB_VoidSetPriorityGroup
 * @brief : This Function Set the Priority Group and Sub Priority
 * @param : Copy_U8PriorityGroup
 * @retval: (void)
 */
void SCB_VoidSetPriorityGroup(uint32_t Copy_U8PriorityGroup)
{
	/* set the Group Priority */
	SCB->AIRCR = Copy_U8PriorityGroup ;
}


