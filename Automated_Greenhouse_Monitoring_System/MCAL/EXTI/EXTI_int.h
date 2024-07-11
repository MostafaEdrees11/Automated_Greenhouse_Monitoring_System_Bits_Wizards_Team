/**
 ******************************************************************************
 * @file           : EXTI_int.h
 * @author         : Mostafa Edrees
 * @brief          : interface file of EXTI.
 * @date           : 13/12/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

#include "EXTI_priv.h"
#include "EXTI_config.h"

ES_t EXTI_enuInit(EXTI_Configuration_t *Copy_PEXTI_Config);
ES_t EXTI_enuChange_Control_State(EXTI_ID_t Copy_enuEXTI_Id, EXTI_CTL_STATE_t Copy_enuControlState);
ES_t EXTI_enuEnable(EXTI_ID_t Copy_enuEXTI_Id);
ES_t EXTI_enuDisable(EXTI_ID_t Copy_enuEXTI_Id);
ES_t EXTI_enuCallBackFunc(volatile void (*Copy_PFunc)(void*), volatile void *Copy_PvidAppParameter, EXTI_ID_t Copy_enuEXTI_Id);



#endif /* EXTI_INT_H_ */
