
/*
 ******************************************************************************
 * @file           : SYSCFG_Interface.h
 * @Author         : Ibrahim Mohamed
 * @brief          : SYSCFG Interface File
 * @Date           : Jul 17, 2023
 ******************************************************************************
 */

#ifndef SYSCFG_INTERFACE_H_
#define SYSCFG_INTERFACE_H_


/**********************   enum section *****************************/

typedef enum
{
	PortA =0,
	PortB,
	PortC,
	PortD,
	PortE,
	PortF,
	PortG,
	PortH
}SYSCFG_Port_t;


typedef enum
{
	EXTI0=0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	EXTI5,
	EXTI6,
	EXTI7,
	EXTI8,
	EXTI9,
	EXTI10,
	EXTI11,
	EXTI12,
	EXTI13,
	EXTI14,
	EXTI15,

}SYSCFG_EXTI_Line;


/**********************   Macros section *****************************/

#define Max_EXTI_Line         16

#define Max_GPIO_Port         8



/**********************   Function section *****************************/

/**
 * @fn    : SYSCFG_U8SetEXTIPort
 * @brief : This Function Sets A Specific Port for A Specific External Interrupt Line
 * @param : EXTI_Line : Options of All Available EXTI Lines From enum ( @SYSCFG_EXTI_Line )
 * @param : GPIO_PORT : Options of All Available Ports From enum ( @SYSCFG_Port_t )
 * @return: ErrorStatus to Indicate if function Worked Correctly or NOT
 */
uint8_t SYSCFG_U8SetEXTIPort( SYSCFG_EXTI_Line EXTI_Line, SYSCFG_Port_t GPIO_Port);



#endif /* SYSCFG_INTERFACE_H_ */
