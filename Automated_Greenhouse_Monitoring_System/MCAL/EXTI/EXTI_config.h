/**
 ******************************************************************************
 * @file           : EXTI_config.h
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of EXTI.
 * @date           : 13/12/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

#include "../../LIB/stdTypes.h"
#include "../../LIB/Error_States.h"

#include "EXTI_priv.h"

typedef struct
{
	/* it is specify the interrupt id
	it must be --> INT0 or INT1 or INT2 */
	EXTI_ID_t			EXTI_id;
	
	/* it is specify the interrupt state
	it must be --> ENABLED or DISABLED */
	EXTI_STATE_t		EXTI_state;
	
	/* it is specify the interrupt control state
	it must be --> LOW_LEVEL or LOGICAL or FAILLING or RISING */
	EXTI_CTL_STATE_t	EXTI_control_state;
}EXTI_Configuration_t;



#endif /* EXTI_CONFIG_H_ */