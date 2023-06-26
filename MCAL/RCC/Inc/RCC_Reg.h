/*
 * RCC_Reg.h
 *
 *  Created on: Apr 9, 2023
 *      Author: IBRAHIM MOHAMED
 */

#ifndef RCC_REG_H_
#define RCC_REG_H_

#define RCC_CR					(*((volatile uint32_t *)0x40023800))
#define RCC_PLLCFGR				(*((volatile uint32_t *)0x40023804))
#define RCC_CFGR				(*((volatile uint32_t *)0x40023808))
#define RCC_CIR					(*((volatile uint32_t *)0x4002380C))
#define RCC_AHB1RSTR			(*((volatile uint32_t *)0x40023810))
#define RCC_AHB2RSTR			(*((volatile uint32_t *)0x40023814))
#define RCC_AHB3RSTR			(*((volatile uint32_t *)0x40023818))
#define RCC_APB1RSTR			(*((volatile uint32_t *)0x40023820))
#define RCC_APB2RSTR			(*((volatile uint32_t *)0x40023824))
#define RCC_AHB1ENR				(*((volatile uint32_t *)0x40023830))
#define RCC_AHB2ENR				(*((volatile uint32_t *)0x40023834))
#define RCC_AHB3ENR				(*((volatile uint32_t *)0x40023838))
#define RCC_APB1ENR				(*((volatile uint32_t *)0x40023840))
#define RCC_APB2ENR				(*((volatile uint32_t *)0x40023844))
#define RCC_AHB1LPENR			(*((volatile uint32_t *)0x40023850))
#define RCC_AHB2LPENR			(*((volatile uint32_t *)0x40023854))
#define RCC_AHB3LPENR			(*((volatile uint32_t *)0x40023858))
#define RCC_APB1LPENR			(*((volatile uint32_t *)0x40023860))
#define RCC_APB2LPENR			(*((volatile uint32_t *)0x40023864))
#define RCC_BDCR				(*((volatile uint32_t *)0x40023870))
#define RCC_CSR					(*((volatile uint32_t *)0x40023874))
#define RCC_SSCGR				(*((volatile uint32_t *)0x40023880))
#define RCC_PLLI2SCFGR			(*((volatile uint32_t *)0x40023884))
#define RCC_PLLSAICFGR			(*((volatile uint32_t *)0x40023888))
#define RCC_DCKCFGR				(*((volatile uint32_t *)0x4002388C))
#define RCC_CKGATENR			(*((volatile uint32_t *)0x40023890))
#define RCC_DCKCFGR2			(*((volatile uint32_t *)0x40023894))


#define RCC_BASE_ADDRESS		(*((volatile uint32_t *)0x40023800))


/**********************************************
 *			RCC_CR bit fields masks			  *
 **********************************************/
#define RCC_CR_HSION			0x00000001		/* Internal high-speed clock enable */
#define RCC_CR_HSIRDY			0x00000002		/* Internal high-speed clock ready flag */
#define RCC_CR_HSITRIM			0x000000F8		/* Internal high-speed clock trimming */
#define RCC_CR_HSICAL			0x0000FF00		/* Internal high-speed clock calibration */
#define RCC_CR_HSEON			0x00010000		/* HSE clock enable */
#define RCC_CR_HESRDY			0x00020000		/* HSE clock ready flag */
#define RCC_CR_HSEBYP			0x00040000		/* HSE clock bypass */
#define RCC_CR_CSSON			0x00080000		/* Clock security system enable */
#define RCC_CR_PLLON			0x01000000		/* Main PLL (PLL) enable */
#define RCC_CR_PLLRDY			0x02000000		/* Main PLL (PLL) clock ready flag */
#define RCC_CR_PLLI2SON			0x04000000		/* PLLI2S enable */
#define RCC_CR_PLLI2SRDY		0x08000000		/* PLLI2s clock ready fag */
#define RCC_CR_PLLSAION			0x10000000		/* PLLSAI enable */
#define RCC_CR_PLLSAIRDY		0x20000000		/* PLLSAI clock ready flag */



/**********************************************
 *			RCC_CFGR bit fields masks		  *
 **********************************************/
#define RCC_CFGR_SW				0x00000003		/* System clock switch */
#define RCC_CFGR_SWS			0x0000000C		/* System clock switch status */
#define RCC_CFGR_HPRE			0x000000F0		/* AHB prescaler */
#define RCC_CFGR_PPRE1			0x00001C00		/* APB Low speed prescaler (APB1) */
#define RCC_CFGR_PPRE2			0x0000E000		/* APB high-speed prescaler (APB2) */
#define RCC_CFGR_RTCPRE			0x001F0000		/* HSE division factor for RTC clock */
#define RCC_CFGR_MCO1			0x00600000		/* Microcontroller clock output 1 */
#define RCC_CFGR_MCO1PRE		0x07000000		/* MCO1 prescaler */
#define RCC_CFGR_MCO2PRE		0x38000000		/* MCO2 prescaler */
#define RCC_CFGR_MCO2			0xC0000000		/* Microcontroller clock output 2 */




#endif /* RCC_REG_H_ */
