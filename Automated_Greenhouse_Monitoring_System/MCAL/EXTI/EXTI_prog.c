/**
 ******************************************************************************
 * @file           : EXTI_prog.c
 * @author         : Mostafa Edrees
 * @brief          : program file of EXTI.
 * @date           : 13/12/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/
#include "../../LIB/stdTypes.h"
#include "../../LIB/Error_States.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"

#include "../interrupt.h"

/* array of pointers to the function that will be executed when the interrupt is happen */
static volatile void (*EXTI_APFunc[MAX_NUM_EXTI])(void *) = {NULL, NULL, NULL};
	
/* array of pointers to the parameters of the function that will be executed when the interrupt is happen */
static volatile void *EXTI_APvidGenericParameters[MAX_NUM_EXTI] = {NULL, NULL, NULL};
	

ES_t EXTI_enuInit(EXTI_Configuration_t *Copy_PEXTI_Config)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_PEXTI_Config != NULL)
	{
		u8 Local_u8Iterator = 0;
		for(Local_u8Iterator = 0; Local_u8Iterator < MAX_NUM_EXTI; Local_u8Iterator++)
		{
			switch(Copy_PEXTI_Config[Local_u8Iterator].EXTI_id)
			{
				case EXTI0:
				if(Copy_PEXTI_Config[Local_u8Iterator].EXTI_state == ENABLED)
				{
					//Masking the 2 bits --> ISC00, ISC01
					MCUCR &= ~(3 << 0);
					switch(Copy_PEXTI_Config[Local_u8Iterator].EXTI_control_state)
					{
						case LOW_LEVEL:
						MCUCR &= ~(MASK_BIT << ISC00);
						MCUCR &= ~(MASK_BIT << ISC01);
						break;
						
						case LOGICAL:
						MCUCR |= (MASK_BIT << ISC00);
						MCUCR &= ~(MASK_BIT << ISC01);
						break;
						
						case FAILLING:
						MCUCR &= ~(MASK_BIT << ISC00);
						MCUCR |= (MASK_BIT << ISC01);
						break;
						
						case RISING:
						MCUCR |= (MASK_BIT << ISC00);
						MCUCR |= (MASK_BIT << ISC01);
						break;
						
						default:
						Local_enuErrorState = ES_OUT_OF_RANGE;
						break;
					}
				}
				break;
				
				case EXTI1:
				if(Copy_PEXTI_Config[Local_u8Iterator].EXTI_state == ENABLED)
				{
					//Masking the 2 bits --> ISC10, ISC11
					MCUCR &= ~(3 << 2);
					switch(Copy_PEXTI_Config[Local_u8Iterator].EXTI_control_state)
					{
						case LOW_LEVEL:
						MCUCR &= ~(MASK_BIT << ISC10);
						MCUCR &= ~(MASK_BIT << ISC11);
						break;
						
						case LOGICAL:
						MCUCR |= (MASK_BIT << ISC10);
						MCUCR &= ~(MASK_BIT << ISC11);
						break;
						
						case FAILLING:
						MCUCR &= ~(MASK_BIT << ISC10);
						MCUCR |= (MASK_BIT << ISC11);
						break;
						
						case RISING:
						MCUCR |= (MASK_BIT << ISC10);
						MCUCR |= (MASK_BIT << ISC11);
						break;
						
						default:
						Local_enuErrorState = ES_OUT_OF_RANGE;
						break;
					}
				}
				break;
				
				case EXTI2:
				if(Copy_PEXTI_Config[Local_u8Iterator].EXTI_state == ENABLED)
				{
					//Masking the bit --> ISC2
					MCUCSR &= ~(1 << 6);
					switch(Copy_PEXTI_Config[Local_u8Iterator].EXTI_control_state)
					{			
						case FAILLING:
						MCUCSR &= ~(MASK_BIT << ISC2);
						break;
						
						case RISING:
						MCUCSR |= (MASK_BIT << ISC2);
						break;
						
						default:
						Local_enuErrorState = ES_OUT_OF_RANGE;
						break;
					}			
				}
				break;
				
				default:
				Local_enuErrorState = ES_OUT_OF_RANGE;
				break;
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

ES_t EXTI_enuChange_Control_State(EXTI_ID_t Copy_enuEXTI_Id, EXTI_CTL_STATE_t Copy_enuControlState)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_enuEXTI_Id < MAX_NUM_EXTI)
	{
		switch(Copy_enuEXTI_Id)
		{
			case EXTI0:
			//Masking the 2 bits --> ISC00, ISC01
			MCUCR &= ~(3 << 0);
			switch(Copy_enuControlState)
			{
				case LOW_LEVEL:
				MCUCR &= ~(MASK_BIT << ISC00);
				MCUCR &= ~(MASK_BIT << ISC01);
				break;
				
				case LOGICAL:
				MCUCR |= (MASK_BIT << ISC00);
				MCUCR &= ~(MASK_BIT << ISC01);
				break;
				
				case FAILLING:
				MCUCR &= ~(MASK_BIT << ISC00);
				MCUCR |= (MASK_BIT << ISC01);
				break;
				
				case RISING:
				MCUCR |= (MASK_BIT << ISC00);
				MCUCR |= (MASK_BIT << ISC01);
				break;
				
				default:
				Local_enuErrorState = ES_OUT_OF_RANGE;
				break;
			}
			break;
			
			case EXTI1:
			//Masking the 2 bits --> ISC10, ISC11
			MCUCR &= ~(3 << 2);
			switch(Copy_enuControlState)
			{
				case LOW_LEVEL:
				MCUCR &= ~(MASK_BIT << ISC10);
				MCUCR &= ~(MASK_BIT << ISC11);
				break;
				
				case LOGICAL:
				MCUCR |= (MASK_BIT << ISC10);
				MCUCR &= ~(MASK_BIT << ISC11);
				break;
				
				case FAILLING:
				MCUCR &= ~(MASK_BIT << ISC10);
				MCUCR |= (MASK_BIT << ISC11);
				break;
				
				case RISING:
				MCUCR |= (MASK_BIT << ISC10);
				MCUCR |= (MASK_BIT << ISC11);
				break;
				
				default:
				Local_enuErrorState = ES_OUT_OF_RANGE;
				break;
			}
			break;
			
			case EXTI2:
			//Masking the bit --> ISC2
			MCUCSR &= ~(1 << 6);
			switch(Copy_enuControlState)
			{
				case FAILLING:
				MCUCSR &= ~(MASK_BIT << ISC2);
				break;
				
				case RISING:
				MCUCSR |= (MASK_BIT << ISC2);
				break;
				
				default:
				Local_enuErrorState = ES_OUT_OF_RANGE;
				break;
			}
			break;
			
			default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
			break;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t EXTI_enuEnable(EXTI_ID_t Copy_enuEXTI_Id)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_enuEXTI_Id < MAX_NUM_EXTI)
	{
		switch(Copy_enuEXTI_Id)
		{
			case EXTI0:
			GICR &= ~(MASK_BIT << INT0);
			GICR |= (MASK_BIT << INT0);
			break;
			
			case EXTI1:
			GICR &= ~(MASK_BIT << INT1);
			GICR |= (MASK_BIT << INT1);
			break;
			
			case EXTI2:
			GICR &= ~(MASK_BIT << INT2);
			GICR |= (MASK_BIT << INT2);
			break;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t EXTI_enuDisable(EXTI_ID_t Copy_enuEXTI_Id)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_enuEXTI_Id < MAX_NUM_EXTI)
	{
		switch(Copy_enuEXTI_Id)
		{
			case EXTI0:
			GICR &= ~(1 << INT0);
			break;
			
			case EXTI1:
			GICR &= ~(1 << INT1);
			break;
			
			case EXTI2:
			GICR &= ~(1 << INT2);
			break;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t EXTI_enuCallBackFunc(volatile void (*Copy_PFunc)(void*), volatile void *Copy_PvidAppParameter, EXTI_ID_t Copy_enuEXTI_Id)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_PFunc != NULL)
	{
		if(Copy_enuEXTI_Id < MAX_NUM_EXTI)
		{
			EXTI_APFunc[Copy_enuEXTI_Id] = Copy_PFunc;
			EXTI_APvidGenericParameters[Copy_enuEXTI_Id] = Copy_PvidAppParameter;
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

/* ISR for EXTI0 */
ISR(VECT_INT0)
{	
	if(EXTI_APFunc[EXTI0] != NULL)
	{
		EXTI_APFunc[EXTI0](EXTI_APvidGenericParameters[EXTI0]);
	}
}

/* ISR for EXTI1 */
ISR(VECT_INT1)
{
	if(EXTI_APFunc[EXTI1] != NULL)
	{
		EXTI_APFunc[EXTI1](EXTI_APvidGenericParameters[EXTI1]);
	}
}

/* ISR for EXTI2 */
ISR(VECT_INT2)
{	
	if(EXTI_APFunc[EXTI2] != NULL)
	{
		EXTI_APFunc[EXTI2](EXTI_APvidGenericParameters[EXTI2]);
	}
}