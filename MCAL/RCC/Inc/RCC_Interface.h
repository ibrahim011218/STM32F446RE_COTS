/*
 * RCC_Interface.h
 *
 *  Created on: Apr 9, 2023
 *      Author: IBRAHIM MOHAMED
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


uint8_t RCC_u8Set_Clk_Sts(uint8_t clk_Type, uint8_t status);


typedef enum
{
	GPIOA = 0,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	GPIOH,

	CRC = 12,

	BKPSRAM = 18,		/* Don't use for RCC_AHB1_resetClock */

	DMA1 = 21,
	DMA2 = 22,

	OTGHS = 29,
	OTGHSULPI = 30		/* Don't use for RCC_AHB1_resetClock */
}AHB1_Peripheral;


/*
 * AHB2_Perigheral enum
 *
 * Gathers all the AHB2 peripherals.
 *
 */
typedef enum
{
	DCMI = 0,
	OTGFS = 7
}AHB2_Peripheral;


/*
 * AHB3_Perigheral enum
 *
 * Gathers all the AHB3 peripherals.
 *
 */
typedef enum
{
	FMC = 0,
	QSPI = 1
}AHB3_Peripheral;


/*
 * APB1_Perigheral enum
 *
 * Gathers all the APB1 peripherals.
 *
 */
typedef enum
{
	TIM2 = 0,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,

	WWDG = 11,

	SPI2 = 13,
	SPI3,

	SPDIFRX = 16,

	USART2 = 17,
	USART3,
	USART4,
	USART5,

	I2C1 = 21,
	I2C2,
	I2C3,

	FMPI2C1 = 24,

	CAN1 = 25,
	CAN2,

	CEC = 27,
	PWR = 28,
	DAC = 29
}APB1_Peripheral;


/*
 * APB1_Perigheral enum
 *
 * Gathers all the APB1 peripherals.
 *
 */
typedef enum
{
	TIM1 = 0,
	TIM8,

	USART1 = 4,
	USART6,

	ADC1 = 8,
	ADC2,
	ADC3,

	SDIO = 11,

	SPI1 = 12,
	SPI4,

	SYSCFG = 14,

	TIM9 = 16,
	TIM10,
	TIM11,

	SAI1 = 22,
	SAI2
}APB2_Peripheral;


/*
 * SystemClock enum
 *
 * Has all 4 available system clock types
 *
 */
typedef enum
{
	SC_HSI = 0,
	SC_HSE,
	SC_PLL_P,
	SC_PLL_R
}SystemClock;


/*
 * ClockType enum
 *
 * Has all clocks of the MCU.
 *
 */
typedef enum
{
	HSI = 0,
	HSE = 16,
	PLL = 24,
	PLLI2S = 26,
	PLLSAI = 28
}ClockType;


/*
 * ClockStatus enum
 *
 * The status of any clock (ON or OFF)
 *
 */
typedef enum
{
	OFF = 0,
	ON = 1
}ClockStatus;


/********************************************
 *			Functions prototypes			*
 ********************************************/

/*
 * RCC_AHB1_enableClock
 *
 * Enables clock for an AHB1 peripheral
 *
 * @Arguments:
 * 		1. enum AHB1_Peripheral enum: peripheral wanted to
 * 				enable its clock.
 *
 * @Return: Returns true if succeeded, false if failed (Should always return true).
 *
 */
uint8_t RCC_AHB1_enableClock(const AHB1_Peripheral a_perigheral);


/*
 * RCC_AHB2_enableClock
 *
 * Enables clock for an AHB2 peripheral
 *
 * @Arguments:
 * 		1. enum AHB2_Peripheral: peripheral wanted to
 * 				enable its clock.
 *
 * @Return: Returns true if succeeded, false if failed (Should always return true).
 *
 */
uint8_t RCC_AHB2_enableClock(const AHB2_Peripheral a_perigheral);


/*
 * RCC_AHB3_enableClock
 *
 * Enables clock for an AHB3 peripheral
 *
 * @Arguments:
 * 		1. enum AHB3_Peripheral: peripheral wanted to
 * 				enable its clock.
 *
 * @Return: Returns true if succeeded, false if failed (Should always return true).
 *
 */
uint8_t RCC_AHB3_enableClock(const AHB3_Peripheral a_perigheral);


/*
 * RCC_APB1_enableClock
 *
 * Enables clock for an APB1 peripheral
 *
 * @Arguments:
 * 		1. enum APB1_Peripheral: peripheral wanted to
 * 				enable its clock.
 *
 * @Return: Returns true if succeeded, false if failed (Should always return true).
 *
 */
uint8_t RCC_APB1_enableClock(const APB1_Peripheral a_perigheral);


/*
 * RCC_APB2_enableClock
 *
 * Enables clock for an APB2 peripheral
 *
 * @Arguments:
 * 		1. enum APB2_Peripheral: peripheral wanted to
 * 				enable its clock.
 *
 * @Return: Returns true if succeeded, false if failed (Should always return true).
 *
 */
uint8_t RCC_APB2_enableClock(const APB2_Peripheral a_perigheral);


/*
 * RCC_AHB1_disableClock
 *
 * disables clock for an AHB1 peripheral
 *
 * @Arguments:
 * 		1. enum AHB1_Peripheral enum: peripheral wanted to
 * 				disable its clock.
 *
 * @Return: Returns true if succeeded, false if failed (Should always return true).
 *
 */
uint8_t RCC_AHB1_disableClock(const AHB1_Peripheral a_perigheral);


/*
 * RCC_AHB2_disableClock
 *
 * disables clock for an AHB2 peripheral
 *
 * @Arguments:
 * 		1. enum AHB2_Peripheral: peripheral wanted to
 * 				disable its clock.
 *
 * @Return: Returns true if succeeded, false if failed (Should always return true).
 *
 */
uint8_t RCC_AHB2_disableClock(const AHB2_Peripheral a_perigheral);


/*
 * RCC_AHB3_disableClock
 *
 * disables clock for an AHB3 peripheral
 *
 * @Arguments:
 * 		1. enum AHB3_Peripheral: peripheral wanted to
 * 				disable its clock.
 *
 * @Return: Returns true if succeeded, false if failed (Should always return true).
 *
 */
uint8_t RCC_AHB3_disableClock(const AHB3_Peripheral a_perigheral);


/*
 * RCC_APB1_disableClock
 *
 * disables clock for an APB1 peripheral
 *
 * @Arguments:
 * 		1. enum APB1_Peripheral: peripheral wanted to
 * 				disable its clock.
 *
 * @Return: Returns true if succeeded, false if failed (Should always return true).
 *
 */
uint8_t RCC_APB1_disbleClock(const APB1_Peripheral a_perigheral);


/*
 * RCC_APB2_disableClock
 *
 * disables clock for an APB2 peripheral
 *
 * @Arguments:
 * 		1. enum APB2_Peripheral: peripheral wanted to
 * 				disable its clock.
 *
 * @Return: Returns true if succeeded, false if failed (Should always return true).
 *
 */
uint8_t RCC_APB2_disableClock(const APB2_Peripheral a_perigheral);


/*
 * RCC_enableHSEBypass
 *
 * Bypass the oscillator with an external clock.
 * Used with an external RC clock.
 *
 * Please note that this function should be called while HSE
 * oscillator is disabled.
 *
 * @Arguments:
 * 		1. boolean value of true to bypass oscillator,
 * 		or false to not bypass oscillator.
 *
 * @Return: Returns true if succeeded, false if failed.
 * 			(Should always return true)
 *
 */
uint8_t RCC_HSEBypass(const uint8_t a_bypass);


/*
 * RCC_setClockStatus
 *
 * Turns any clock on or off.
 *
 *
 * @Arguments:
 * 		1. enum ClockType: choose which clock to turn on or off.
 * 		2. enum ClockStatus: whether to turn the clock on or off.
 *
 * @Return: Returns true if succeeded, false if failed.
 * 			(Should always return true)
 *
 * Note that when turning a clock ON, the functions doesn't return
 * until the selected clock is ON, stable, and ready to use.
 *
 */
uint8_t RCC_setCLockStatus(const ClockType a_clockType, const ClockStatus a_status);


/*
 * RCC_getClockStatus
 *
 * Tells if a clock is ON or OFF
 *
 * @Arguments:
 * 		1. enum ClockType: choose which clock to turn on or off.
 *
 * @Return: A boolean value of TRUE if the passed clock is ON, and
 * 			a value of FALSE if it is OFF.
 *
 */
uint8_t RCC_getClockStatus(const ClockType a_clocktype);


/*
 * RCC_getClockSource
 *
 * Gets the system clock source.
 *
 * @Arguments: (void)
 * 		The function takes no arguments.
 *
 * @Return: sint8 value of:
 * 			0: HSI oscillator used as the system clock.
 * 			1: HSE oscillator used as the system clock.
 * 			2: PLL used as the system clock.
 * 			3: PLL_R used as the system clock.
 *
 */
uint8_t RCC_getCLockSource(void);


/*
 * RCC_setClockSource
 *
 * Selects the system clock source.
 * Note that the selected clock has to be turned on first (RCC_setClockStatus
 * function can be used for this) or the function will return false and exit
 * with no effect (without changing the system clock source).
 *
 * @Arguments:
 * 		1. enum ClockType: choose which clock to set as a source.
 *
 * @Return: sint8 value of:
 * 			-1: The passed clock is OFF. System clock hasn't changed.
 * 			0: HSI oscillator used as the system clock.
 * 			1: HSE oscillator used as the system clock.
 * 			2: PLL used as the system clock.
 * 			3: PLL_R used as the system clock.
 *
 */
uint8_t RCC_setCLockSource(const SystemClock a_systemClock);

/* Define configuration paramaters of                      */
#define ENABLE			        		  	1
#define DISABLE			        			2


#endif /* RCC_INTERFACE_H_ */
