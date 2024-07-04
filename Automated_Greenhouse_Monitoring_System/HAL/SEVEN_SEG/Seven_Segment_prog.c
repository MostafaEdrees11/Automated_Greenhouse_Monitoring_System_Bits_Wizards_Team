/**
 ******************************************************************************
 * @file           : Seven_Segment_prog.c
 * @author         : Mostafa Edrees
 * @brief          : program file of Seven Segment.
 * @date           : 10/20/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Seven_Segment_config.h"
#include "Seven_Segment_priv.h"

extern SEG_t SEV_SEG_AstrSEGConfig[SEG_NUM];

ES_t Seven_Segment_enuInit(SEG_t *Copy_pAstrSEG_Config)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	u8 Local_u8Iterator = 0;
	
	u8 Local_u8Iterator_Error = 0;
	u32 Local_u32CheckError = 0;
	
	if(Copy_pAstrSEG_Config != NULL)
	{
		for(Local_u8Iterator = 0; Local_u8Iterator < SEG_NUM; Local_u8Iterator++)
		{
			Local_u8Iterator_Error = 0;
			Local_u32CheckError |= (DIO_enuSetPinDirection(Copy_pAstrSEG_Config[Local_u8Iterator].SEG_APORT, Copy_pAstrSEG_Config[Local_u8Iterator].SEG_APIN, DIO_u8OUTPUT) << Local_u8Iterator_Error);
			Local_u32CheckError |= (DIO_enuSetPinDirection(Copy_pAstrSEG_Config[Local_u8Iterator].SEG_BPORT, Copy_pAstrSEG_Config[Local_u8Iterator].SEG_BPIN, DIO_u8OUTPUT) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinDirection(Copy_pAstrSEG_Config[Local_u8Iterator].SEG_CPORT, Copy_pAstrSEG_Config[Local_u8Iterator].SEG_CPIN, DIO_u8OUTPUT) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinDirection(Copy_pAstrSEG_Config[Local_u8Iterator].SEG_DPORT, Copy_pAstrSEG_Config[Local_u8Iterator].SEG_DPIN, DIO_u8OUTPUT) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinDirection(Copy_pAstrSEG_Config[Local_u8Iterator].SEG_EPORT, Copy_pAstrSEG_Config[Local_u8Iterator].SEG_EPIN, DIO_u8OUTPUT) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinDirection(Copy_pAstrSEG_Config[Local_u8Iterator].SEG_FPORT, Copy_pAstrSEG_Config[Local_u8Iterator].SEG_FPIN, DIO_u8OUTPUT) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinDirection(Copy_pAstrSEG_Config[Local_u8Iterator].SEG_GPORT, Copy_pAstrSEG_Config[Local_u8Iterator].SEG_GPIN, DIO_u8OUTPUT) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			
			if(Copy_pAstrSEG_Config[Local_u8Iterator].SEG_CMN_PORT != NOT_CONNECTED && Copy_pAstrSEG_Config[Local_u8Iterator].SEG_CMN_PIN != NOT_CONNECTED)
			{
				Local_u32CheckError |= (DIO_enuSetPinDirection(Copy_pAstrSEG_Config[Local_u8Iterator].SEG_CMN_PORT, Copy_pAstrSEG_Config[Local_u8Iterator].SEG_CMN_PIN, DIO_u8OUTPUT) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			}
			
			if(Copy_pAstrSEG_Config[Local_u8Iterator].SEG_DOT_PORT != NOT_CONNECTED && Copy_pAstrSEG_Config[Local_u8Iterator].SEG_DOT_PIN != NOT_CONNECTED)
			{
				Local_u32CheckError |= (DIO_enuSetPinDirection(Copy_pAstrSEG_Config[Local_u8Iterator].SEG_DOT_PORT, Copy_pAstrSEG_Config[Local_u8Iterator].SEG_DOT_PIN, DIO_u8OUTPUT) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			}
		}
		
		for(Local_u8Iterator = 0; Local_u8Iterator < SEG_NUM; Local_u8Iterator++)
		{
			for(Local_u8Iterator_Error = 0; Local_u8Iterator_Error < sizeof(Local_u32CheckError)*8; Local_u8Iterator_Error += ERROR_STATE_SIZE)
			{
				if(((Local_u32CheckError >> Local_u8Iterator_Error) & ERROR_STATE_MASK) != ES_OK)
				{
					return ES_NOK;
				}
			}
			Local_enuErrorState = ES_OK;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

ES_t Seven_Segment_enuDisplayNumber(u8 Copy_SEG_ID, u8 Copy_u8Number)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	u8 Local_u8Iterator_Error = 0;
	u32 Local_u32CheckError = 0;
	 
	if(Copy_SEG_ID < SEG_NUM && Copy_u8Number < 10)
	{
		if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_TYPE == COMMON_ANODE)
		{
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_APORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_APIN, !((SEGCth_Numbers[Copy_u8Number] >> APIN_POS) & MASK_BIT)) << Local_u8Iterator_Error);
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_BPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_BPIN, !((SEGCth_Numbers[Copy_u8Number] >> BPIN_POS) & MASK_BIT)) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CPIN, !((SEGCth_Numbers[Copy_u8Number] >> CPIN_POS) & MASK_BIT)) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DPIN, !((SEGCth_Numbers[Copy_u8Number] >> DPIN_POS) & MASK_BIT)) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_EPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_EPIN, !((SEGCth_Numbers[Copy_u8Number] >> EPIN_POS) & MASK_BIT)) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_FPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_FPIN, !((SEGCth_Numbers[Copy_u8Number] >> FPIN_POS) & MASK_BIT)) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_GPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_GPIN, !((SEGCth_Numbers[Copy_u8Number] >> GPIN_POS) & MASK_BIT)) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
		}
		else if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_TYPE == COMMON_CATHODE)
		{
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_APORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_APIN, ((SEGCth_Numbers[Copy_u8Number] >> APIN_POS) & MASK_BIT)) << Local_u8Iterator_Error);
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_BPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_BPIN, ((SEGCth_Numbers[Copy_u8Number] >> BPIN_POS) & MASK_BIT)) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CPIN, ((SEGCth_Numbers[Copy_u8Number] >> CPIN_POS) & MASK_BIT)) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DPIN, ((SEGCth_Numbers[Copy_u8Number] >> DPIN_POS) & MASK_BIT)) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_EPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_EPIN, ((SEGCth_Numbers[Copy_u8Number] >> EPIN_POS) & MASK_BIT)) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_FPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_FPIN, ((SEGCth_Numbers[Copy_u8Number] >> FPIN_POS) & MASK_BIT)) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_GPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_GPIN, ((SEGCth_Numbers[Copy_u8Number] >> GPIN_POS) & MASK_BIT)) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
		}
		
		for(Local_u8Iterator_Error = 0; Local_u8Iterator_Error < sizeof(Local_u32CheckError)*8; Local_u8Iterator_Error += ERROR_STATE_SIZE)
		{
			if(((Local_u32CheckError >> Local_u8Iterator_Error) & ERROR_STATE_MASK) != ES_OK)
			{
				return ES_NOK;
			}
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t Seven_Segment_enuEnableCommon(u8 Copy_SEG_ID)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_SEG_ID < SEG_NUM)
	{
		if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_TYPE == COMMON_ANODE)
		{
			Local_enuErrorState = DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CMN_PORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CMN_PIN, DIO_u8HIGH);
		}
		else if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_TYPE == COMMON_CATHODE)
		{
			Local_enuErrorState = DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CMN_PORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CMN_PIN, DIO_u8LOW);
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t Seven_Segment_enuDisableCommon(u8 Copy_SEG_ID)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_SEG_ID < SEG_NUM)
	{
		if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_TYPE == COMMON_ANODE)
		{
			Local_enuErrorState = DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CMN_PORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CMN_PIN, DIO_u8LOW);
		}
		else if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_TYPE == COMMON_CATHODE)
		{
			Local_enuErrorState = DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CMN_PORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CMN_PIN, DIO_u8HIGH);
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t Seven_Segment_enuEnableDot(u8 Copy_SEG_ID)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_SEG_ID < SEG_NUM)
	{
		if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_TYPE == COMMON_ANODE)
		{
			Local_enuErrorState = DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PIN, DIO_u8LOW);
		}
		else if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_TYPE == COMMON_CATHODE)
		{
			Local_enuErrorState = DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PIN, DIO_u8HIGH);
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}

ES_t Seven_Segment_enuDisableDot(u8 Copy_SEG_ID)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_SEG_ID < SEG_NUM)
	{
		if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_TYPE == COMMON_ANODE)
		{
			Local_enuErrorState = DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PIN, DIO_u8HIGH);
		}
		else if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_TYPE == COMMON_CATHODE)
		{
			Local_enuErrorState = DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PIN, DIO_u8LOW);
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
		
	return Local_enuErrorState;
}

ES_t Seven_Sement_enuTurnOFF(u8 Copy_SEG_ID)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	u8 Local_u8Iterator_Error = 0;
	u32 Local_u32CheckError = 0;
	
	if(Copy_SEG_ID < SEG_NUM)
	{
		if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_TYPE == COMMON_ANODE)
		{
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_APORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_APIN, DIO_u8HIGH) << Local_u8Iterator_Error);
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_BPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_BPIN, DIO_u8HIGH) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CPIN, DIO_u8HIGH) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DPIN, DIO_u8HIGH) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_EPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_EPIN, DIO_u8HIGH) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_FPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_FPIN, DIO_u8HIGH) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_GPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_GPIN, DIO_u8HIGH) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			
			if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PORT != NOT_CONNECTED && SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PIN != NOT_CONNECTED)
			{
				Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PIN, DIO_u8HIGH) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			}
		}
		else if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_TYPE == COMMON_CATHODE)
		{
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_APORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_APIN, DIO_u8LOW) << Local_u8Iterator_Error);
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_BPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_BPIN, DIO_u8LOW) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_CPIN, DIO_u8LOW) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DPIN, DIO_u8LOW) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_EPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_EPIN, DIO_u8LOW) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_FPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_FPIN, DIO_u8LOW) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_GPORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_GPIN, DIO_u8LOW) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			
			if(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PORT != NOT_CONNECTED && SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PIN != NOT_CONNECTED)
			{
				Local_u32CheckError |= (DIO_enuSetPinVal(SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PORT, SEV_SEG_AstrSEGConfig[Copy_SEG_ID].SEG_DOT_PIN, DIO_u8LOW) << (Local_u8Iterator_Error += ERROR_STATE_SIZE));
			}
		}
		
		for(Local_u8Iterator_Error = 0; Local_u8Iterator_Error < sizeof(Local_u32CheckError)*8; Local_u8Iterator_Error += ERROR_STATE_SIZE)
		{
			if(((Local_u32CheckError >> Local_u8Iterator_Error) & ERROR_STATE_MASK) != ES_OK)
			{
				return ES_NOK;
			}
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	return Local_enuErrorState;
}