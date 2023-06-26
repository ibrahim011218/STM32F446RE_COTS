/********************************************************/
/*
 * @file GPOI_Interface.h
 * @author Ibrahim Mohamed
 * @brief  include functions decleration and enums
 *
 */

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


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
}Port_t;


typedef enum 
{
	PIN0 =0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}Pin_t;


typedef enum
{
	INPUT =0,
	OUTPUT,
	ALTERNATE_FUNCTION,
	ANALOG
}Mode_t;


typedef enum
{
	LOW =0,
	MEDUIM,
	FAST,
	HIGH
}OutputSpeed_t;


typedef enum
{
	PUSH_PULL =0,
	OPEN_DRAIN
}OutputType_t;


typedef enum
{
	NoPULL =0,
	PULLUP,
	PULLDOWN
}PullUpDown_t;


typedef enum
{
	PIN_LOW =0,
	PIN_HIGH
}PinValue_t;


typedef enum
{
	AF =0, 
	AF1, 
	AF2, 
	AF3, 
	AF4, 
	AF5, 
	AF6, 
	AF7, 
	AF8, 
	AF9, 
	AF10, 
	AF11, 
	AF12, 
	AF13, 
	AF14, 
	AF15, 
}AltFunc_t;


typedef struct
{
	Port_t Port;
	Pin_t PinNum;
	Mode_t Mode;
	OutputSpeed_t speed;
	OutputType_t OutputType;
	PullUpDown_t PullType;
	AltFunc_t  AltFunc;
	PinValue_t PinVal;
}PinConfig_t;


/*==============================================================================================================================================
 * Function Declarations
 *==============================================================================================================================================*/
/***********************************************************
 *@fn GPIO_u8PinInit
 *@brief the function initializes the GPIO pin according to the input paramters
 *@paramter[in] PinConfig : initializaton values of the pin
 *@retval ErrorStatus
 */
uint8_t GPIO_u8PinInit(const PinConfig_t* PinConfig);


/***********************************************************
 *@fn GPIO_u8SetPinValue
 *@brief the function output a certain value on an output pin
 *@paramter[in] Port : the port number , get options @Port_t enum
 *@paramter[in] PinNum : the pin number , get options @PinNum enum
 *@paramter[in] PinVal : the output value , get options @PinVal enum
 *@retval ErrorStatus
 */
uint8_t GPIO_u8SetPinValue(Port_t Port , Pin_t PinNum, PinValue_t PinVal );


/*==========================================================================================================
 *@fn  GPIO_u8TogglePinValue
 *@brief  the function toggles the value of a certain pin
 *@paramter[in] Port : the port number , get options @Port_t enum
 *@paramter[in] PinNum : the pin number , get options @PinNum enum
 *@retval ErrorStatus
*===========================================================================================================*/
uint8_t GPIO_u8TogglePinValue(Port_t Port , Pin_t PinNum );


/*===========================================================================================================
 *@fn  GPIO_u8GetPinValue
 *@brief  the function reads the value of a certain pin
 *@paramter[in] Port : the port number , get options @Port_t enum
 *@paramter[in] PinNum : the pin number , get options @PinNum enum
 *@paramter[out] PinVal : the output value , get options @PinVal enum
 *@retval ErrorStatus
*============================================================================================================*/
uint8_t GPIO_u8GetPinValue(Port_t Port , Pin_t PinNum, PinValue_t* PinVal );



#endif
