
/*
 ******************************************************************************
 * @file           : SYSCFG_Program.c
 * @Author         : Ibrahim Mohamed
 * @brief          : SYSCFG Program File
 * @Date           : Jul 17, 2023
 ******************************************************************************
 */


/**********************   Includes section *****************************/
#include "stdint.h"
#include "Stm32F446xx.h"
#include "ErrType.h"
#include "SYSCFG_Interface.h"



/**********************   Function Implementation section *****************************/

/**
 * @fn    : SYSCFG_U8SetEXTIPort
 * @brief : This Function Sets A Specific Port for A Specific External Interrupt Line
 * @param : EXTI_Line : Options of All Available EXTI Lines From enum ( @SYSCFG_EXTI_Line )
 * @param : GPIO_PORT : Options of All Available Ports From enum ( @SYSCFG_Port_t )
 * @return: ErrorStatus to Indicate if function Worked Correctly or NOT
 */
uint8_t SYSCFG_U8SetEXTIPort( SYSCFG_EXTI_Line EXTI_Line, SYSCFG_Port_t GPIO_Port)
{
	uint8_t Error_State = OK;

	if ( (EXTI_Line < Max_EXTI_Line) && (GPIO_Port < Max_GPIO_Port) )
	{
		/* Variable To Hold The Required Register to Access */
		uint8_t REG_Number = EXTI_Line /4 ;

		/* Variable to Hold The Required Bits to Access */
		uint8_t Bits_Number = (EXTI_Line %4 ) *4 ;

		/*Clear the Required 4 Bits*/
		SYSCOFG->EXTICR[REG_Number] &=(~(0b1111 << Bits_Number));

		/* Set The Required Port for the Required External Interrupt Line */
		SYSCOFG->EXTICR[REG_Number]= ( GPIO_Port << Bits_Number ) ;
	}
	else
	{
		Error_State = NOK;
	}
	return Error_State;
}

