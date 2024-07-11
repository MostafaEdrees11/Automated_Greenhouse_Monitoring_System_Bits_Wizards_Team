/**
 ******************************************************************************
 * @file           : EXTI_config.c
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of EXTI.
 * @date           : 13/12/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/
#include "EXTI_config.h"
#include "EXTI_priv.h"

EXTI_Configuration_t EXTI_AStrEXTI_Config[MAX_NUM_EXTI] = 
{
	{EXTI0, DISABLED},
	{EXTI1, ENABLED, RISING},
	{EXTI2, DISABLED}
};
