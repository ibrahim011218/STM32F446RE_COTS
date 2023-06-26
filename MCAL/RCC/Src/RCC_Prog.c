/*
 * RCC_Prog.c
 *
 *  Created on: Apr 9, 2023
 *      Author: IBRAHIM MOHAMED
 */

#include <stdint.h>
#include "BIT_MATH.h"
#include "RCC_Reg.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"
#include "ErrType.h"



uint8_t RCC_setCLockStatus(const ClockType a_clockType, const ClockStatus a_status)
{
	/* Initialize Error State Local Variable */
	uint8_t Error_status= OK;

	uint16_t Local_counter_Time=0;

	if(a_clockType == PLL)
	{
		/* check the status */
		if( a_status== ON)
		{
			/* set PLLON bit to enable PLL */
			SET_BIT(RCC_CR, a_clockType);   //PLLON
			/* wait for set the flag */
			while( (GET_BIT(RCC_CR, (a_clockType + 1)) == 0) && (Local_counter_Time < Time_out))
			{
				Local_counter_Time ++;
			}

			if(Local_counter_Time == Time_out)
			{
				Error_status= NOK;
			}
		}
		else if( a_status== OFF)
		{
			/* clear PLLON bit to disable PLL */
			CLR_BIT(RCC_CR, a_clockType);
		}
		else
		{
			Error_status= NOK;
		}
	}

	else if(a_clockType == HSE)
	{
		/* check the status */
		if( a_status== ON)
		{
			/* set HSEON bit to enable HSE */
			SET_BIT(RCC_CR, a_clockType);
			/* wait for set the flag */
			while( (GET_BIT(RCC_CR, (a_clockType + 1)) == 0) && (Local_counter_Time < Time_out))
			{
				Local_counter_Time ++;
			}

			if(Local_counter_Time == Time_out)
			{
				Error_status= NOK;
			}

		}
		else if( a_status== OFF)
		{

			/* clear HSEON bit to disable HSE */
			CLR_BIT(RCC_CR, a_clockType);
		}
		else
		{
			Error_status= NOK;
		}
	}


	else if(a_clockType == HSI)
	{
		/* check the status */
		if( a_status== ON)
		{
			/* set HSION bit to enable HSI */
			SET_BIT(RCC_CR, a_clockType);
			/* wait for set the flag */
			while( (GET_BIT(RCC_CR, (a_clockType + 1)) == 0)&& (Local_counter_Time < Time_out))
			{
				Local_counter_Time ++;
			}

			if(Local_counter_Time == Time_out)
			{
				Error_status= NOK;
			}
		}
		else if( a_status== OFF)
		{

			/* clear HSION bit to disable HSI */
			CLR_BIT(RCC_CR, a_clockType);
		}
		else
		{
			Error_status= NOK;
		}
	}

	else
	{
		Error_status= NOK;
	}
	return Error_status;

}




uint8_t RCC_getClockStatus(const ClockType a_clockType)
{
	/* Return the status of the ready flag of the corresponding clock type.
	 *
	 * Note that the relation between the ready flag and the passed ClockType
	 * of each clock is (ready flag = ClockType + 1)
	 */
	return SET_BIT(RCC_CR, (a_clockType + 1));
}


uint8_t RCC_getCLockSource(void)
{
	/* Return the value of the SWS bits of the RCC_CFGR */
	return (uint8_t)((RCC_CFGR & (RCC_CFGR_SWS)) >> 2);
}


uint8_t RCC_setCLockSource(const SystemClock a_systemClock)
{
	uint8_t Error_status= OK;
	/* Check if the passed clock is OFF */
	if(a_systemClock == SC_HSI)
	{
		if(!(RCC_getClockStatus(HSI)))
		{
			Error_status= NOK;
			return Error_status;
		}
	}
	else if(a_systemClock == SC_HSE)
	{
		if(!(RCC_getClockStatus(HSE)))
		{
			Error_status= NOK;
			return Error_status;
		}
	}
	else
	{
		if(!(RCC_getClockStatus(PLL)))
		{
			Error_status= NOK;
			return Error_status;
		}
	}

	/* Set the passed clock as system clock by putting its
	 * corresponding value in the SW bits of the RCC_CFGR.
	 *
	 * 00: HSI oscillator selected as system clock
	 * 01: HSE oscillator selected as system clock
	 * 10: PLL_P selected as system clock
	 * 11: PLL_R selected as system clock
	 *
	 * The passed argument equals to the required value of
	 * the two SW bits.
	 */

	/* Firstly, clear the two SW bits */
	RCC_CFGR &= ~RCC_CFGR_SW;

	/* Secondly, put the suitable value in the SW bits */
	RCC_CFGR |= a_systemClock;

	/* Return the system clock after changed */
	return Error_status;
}





uint8_t RCC_AHB1_enableClock(const AHB1_Peripheral a_peripheral)
{
	/* Set the bit in the AHB1ENR that corresponds to the desired peripheral */
	SET_BIT(RCC_AHB1ENR, a_peripheral);

	/* Return the value of the bit (Should be 1)*/
	return RCC_AHB1ENR & (1 << a_peripheral);
}


uint8_t RCC_AHB2_enableClock(const AHB2_Peripheral a_peripheral)
{
	/* Set the bit in the AHB2ENR that corresponds to the desired peripheral */
	SET_BIT(RCC_AHB2ENR, a_peripheral);

	/* Return the value of the bit (Should be 1)*/
	return RCC_AHB2ENR & (1 << a_peripheral);
}


uint8_t RCC_AHB3_enableClock(const AHB3_Peripheral a_peripheral)
{
	/* Set the bit in the AHB3ENR that corresponds to the desired peripheral */
	SET_BIT(RCC_AHB3ENR, a_peripheral);

	/* Return the value of the bit (Should be 1)*/
	return RCC_AHB3ENR & (1 << a_peripheral);
}


uint8_t RCC_APB1_enableClock(const APB1_Peripheral a_peripheral)
{
	/* Set the bit in the APB1ENR that corresponds to the desired peripheral */
	SET_BIT(RCC_APB1ENR, a_peripheral);

	/* Return the value of the bit (Should be 1)*/
	return RCC_APB1ENR & (1 << a_peripheral);
}


uint8_t RCC_APB2_enableClock(const APB2_Peripheral a_peripheral)
{
	/* Set the bit in the APB2ENR that corresponds to the desired peripheral */
	SET_BIT(RCC_APB2ENR, a_peripheral);

	/* Return the value of the bit (Should be 1)*/
	return RCC_APB2ENR & (1 << a_peripheral);
}

/*
 * *******************************************************
 */

/* Peripherals disablers */

uint8_t RCC_AHB1_disableClock(const AHB1_Peripheral a_peripheral)
{
	/* Set the bit in the AHB1ENR that corresponds to the desired peripheral */
	CLR_BIT(RCC_AHB1ENR, a_peripheral);

	/* Return the inverse of the value of the bit (Should be 1)*/
	return !(RCC_AHB1ENR & (1 << a_peripheral));
}


uint8_t RCC_AHB2_disableClock(const AHB2_Peripheral a_peripheral)
{
	/* Set the bit in the AHB2ENR that corresponds to the desired peripheral */
	CLR_BIT(RCC_AHB2ENR, a_peripheral);

	/* Return the inverse of the value of the bit (Should be 1)*/
	return !(RCC_AHB2ENR & (1 << a_peripheral));
}


uint8_t RCC_AHB3_disableClock(const AHB3_Peripheral a_peripheral)
{
	/* Set the bit in the AHB3ENR that corresponds to the desired peripheral */
	CLR_BIT(RCC_AHB3ENR, a_peripheral);

	/* Return the inverse of the value of the bit (Should be 1)*/
	return !(RCC_AHB3ENR & (1 << a_peripheral));
}


uint8_t RCC_APB1_disableClock(const APB1_Peripheral a_peripheral)
{
	/* Set the bit in the APB1ENR that corresponds to the desired peripheral */
	CLR_BIT(RCC_APB1ENR, a_peripheral);

	/* Return the inverse of the value of the bit (Should be 1)*/
	return !(RCC_APB1ENR & (1 << a_peripheral));
}

uint8_t RCC_APB2_disableClock(const APB2_Peripheral a_peripheral)
{
	/* Set the bit in the AHB2ENR that corresponds to the desired peripheral */
	CLR_BIT(RCC_APB2ENR, a_peripheral);

	/* Return the inverse of the value of the bit (Should be 1)*/
	return !(RCC_APB2ENR & (1 << a_peripheral));
}




