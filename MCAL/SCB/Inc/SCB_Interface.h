/*
 ******************************************************************************
 * @file           : SCB_Interface.h
 * @Author         : Ibrahim Mohamed
 * @brief          : SCB Interface File
 * @Date           : Jul 16, 2023
 ******************************************************************************
 */

#ifndef SCB_INTERFACE_H_
#define SCB_INTERFACE_H_


/**********************   Macros section *****************************/

/** Options For the User To Choose Number of Groups and Subs**/

#define 	SixteenGroup_0Sub		0X05FA0300UL
#define 	EightoGroup_2Sub		0X05FA0400UL
#define 	FourGroup_4Sub			0X05FA0500
#define 	TWOGroup_8Sub			0X05FA0600UL
#define 	NoneGroup_16Sub			0X05FA0700UL




/**********************   Functions section *****************************/


/**
 * @fn    : SCB_VoidSetPriorityGroup
 * @brief : This Function Set the Priority Group and Sub Priority
 * @param : Copy_U8PriorityGroup
 * @retval: (void)
 */

void SCB_VoidSetPriorityGroup(uint32_t Copy_U8PriorityGroup);



#endif /* SCB_INTERFACE_H_ */
