/*
 * GIE_prog.c
 *
 * Created: 12/13/2023 11:39:33 PM
 *  Author: Mostafa Edrees
 */ 
#include "../../LIB/stdTypes.h"
#include "../../LIB/Error_States.h"

#include "GIE_priv.h"

ES_t GIE_enuGloable_Interrupt_Enable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	SREG &= ~(MASK_BIT << GIE_I);
	SREG |= (MASK_BIT << GIE_I);
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;
}

ES_t GIE_enuGloable_Interrupt_Disable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	SREG &= ~(MASK_BIT << GIE_I);
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;
}