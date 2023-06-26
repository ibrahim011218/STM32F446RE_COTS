/********************************************************/
/*
 * @file GPOI_Program.c
 * @author Ibrahim Mohamed
 * @brief the GPIO main source file, include functions definitions
 *
 */



#include <stdint.h>
#include "Stm32F446xx.h"
#include "ErrType.h"

#include "GPIO_Interface.h"
#include "GPIO_priv.h"



static GPIO_RegDef_t* GPIO_PORT[GPIO_PERIPHERAL_NUM]= {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH};


/*******************************************************
 * @func GPIO_u8PinInit
 * @brief the function initializes the GPIO pin according to the input parameters
 * @parameter[in] PinConfig : the initialization values of the pin
 * @retval ErrorStatus
 */

uint8_t GPIO_u8PinInit(const PinConfig_t* PinConfig)
{
	uint8_t Local_u8ErrorStatus = OK;
	if(PinConfig != NULL)
	{
		if( ((PinConfig->Port) <= PortH) && ((PinConfig->PinNum) <= PIN15) )
		{
			/* select GPIO Mode : Input, Output, Analog, Alternate func*/
			(GPIO_PORT[PinConfig->Port]->MODER) &= ~(MODER_MASK << ((PinConfig-> PinNum) *MODER_PIN_ACCESS));         /* clear the mode bits*/
			(GPIO_PORT[PinConfig->Port]->MODER) |= ((PinConfig-> Mode) << ((PinConfig-> PinNum) *MODER_PIN_ACCESS));

			/* Select GPIO state : pull up ,Pull down , NoPull*/
			(GPIO_PORT[PinConfig->Port]->PUPDR) &= ~(PUPDR_MASK << ((PinConfig-> PinNum) *PUPDR_PIN_ACCESS));
			(GPIO_PORT[PinConfig->Port]->PUPDR) |= ((PinConfig-> PullType) << ((PinConfig-> PinNum) *PUPDR_PIN_ACCESS));

			/* Select Output type & Output speed in case of general purpose output or alternate function*/
			if((PinConfig->Mode == OUTPUT) || (PinConfig->Mode == ALTERNATE_FUNCTION))
			{
				/* Select Output type : PushPull or open drain */
				(GPIO_PORT[PinConfig->Port]->OTYPER) &= ~(OTYPER_MASK << (PinConfig-> PinNum) );
				(GPIO_PORT[PinConfig->Port]->OTYPER) |= ( (PinConfig-> OutputType) << (PinConfig-> PinNum) );

				/* Select output speed : Low, Medium, High, Fast */
				(GPIO_PORT[PinConfig->Port]->OSPEEDR) &= ~(OSPEEDR_MASK << (PinConfig-> PinNum)*OSPEEDR_PIN_ACCESS );
				(GPIO_PORT[PinConfig->Port]->OSPEEDR) |= ((PinConfig-> speed) << ((PinConfig-> PinNum) *OSPEEDR_PIN_ACCESS));

				/* Select the pin ALTERNATE_FUNCTION */
				if(PinConfig->Mode == ALTERNATE_FUNCTION)
				{
					uint8_t Local_u8RegNum = (PinConfig->PinNum)/ AFR_PIN_SHIFTING;
					uint8_t Local_u8BitNum = (PinConfig->PinNum)% AFR_PIN_SHIFTING;

					(GPIO_PORT[PinConfig->Port]->AFR[Local_u8RegNum]) &= ~(AITFUNC_MASK << Local_u8BitNum * AITFUNC_PIN_ACCESS );
					(GPIO_PORT[PinConfig->Port]->AFR[Local_u8RegNum]) |= ((PinConfig-> AltFunc) << (Local_u8BitNum * AITFUNC_PIN_ACCESS));

				}
			}
		}
		else
		{
			Local_u8ErrorStatus = NOK;
		}
	}
	else
	{
		Local_u8ErrorStatus = NULL_PTR_ERR;
	}

	return Local_u8ErrorStatus;
}

/****************************************************************************
 *@fn GPIO_u8SetPinValue
 *@brief the function output a certain value on an output pin
 *@paramter[in] Port : the port number , get options @Port_t enum
 *@paramter[in] PinNum : the pin number , get options @PinNum enum
 *@paramter[in] PinVal : the output value , get options @PinVal enum
 *@retval ErrorStatus
 */

uint8_t GPIO_u8SetPinValue(Port_t Port , Pin_t PinNum, PinValue_t PinVal )
{
	uint8_t Local_u8ErrorStatus = OK;
	if((Port <= PortH) && (PinNum <= PIN15))
	{
		if(PinVal == PIN_LOW)
		{
			GPIO_PORT[Port]->ODR &=~ (1<< PinNum);
			/* GPIO_PORT[Port]->BSRR = (1 << (16+PinNum)) */
		}
		else if(PinVal == PIN_HIGH)
		{
			GPIO_PORT[Port]->ODR |= (1<< PinNum);
			/* GPIO_PORT[Port]->BSRR = (1 << (PinNum)) */
		}
		else
		{
			Local_u8ErrorStatus = NOK;
		}
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}
	return Local_u8ErrorStatus;
}


/****************************************************************************
 * @fn GPIO_u8SetPortValue
 * @brief the function outputs a certain value on an output Port
 * @param[in] Port , Value
 * @retval void
 */

void GPIO_u8SetPortValue(Port_t Port , uint16_t value)
{
	/* Write the Value on Port*/
	GPIO_PORT[Port]->ODR = value;
}


/****************************************************************************
 *@fn  GPIO_u8TogglePinValue
 *@brief  the function toggles the value of a certain pin
 *@paramter[in] Port : the port number , get options @Port_t enum
 *@paramter[in] PinNum : the pin number , get options @PinNum enum
 *@retval ErrorStatus
 */
uint8_t GPIO_u8TogglePinValue(Port_t Port , Pin_t PinNum )
{
	uint8_t Local_u8ErrorStatus = OK;
	if((Port <= PortH) && (PinNum <= PIN15))
	{
		(GPIO_PORT[Port]->ODR) ^= (0x01 << PinNum)  ;
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}
	return Local_u8ErrorStatus;
}


/****************************************************************************
 *@fn  GPIO_u8GetPinValue
 *@brief  the function reads the value of a certain pin
 *@paramter[in] Port : the port number , get options @Port_t enum
 *@paramter[in] PinNum : the pin number , get options @PinNum enum
 *@paramter[out] PinVal : the output value , get options @PinVal enum
 *@retval ErrorStatus
 */
uint8_t GPIO_u8GetPinValue(Port_t Port , Pin_t PinNum, PinValue_t* PinVal )
{
	uint8_t Local_u8ErrorStatus = OK;
	if((Port <= PortH) && (PinNum <= PIN15))
	{
		if(PinVal != NULL)
		{
			*PinVal = (((GPIO_PORT[Port]->IDR) >> PinNum) & 0x01) ;
		}
		else
		{
			Local_u8ErrorStatus = NULL_PTR_ERR;
		}
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}
	return Local_u8ErrorStatus;
}

