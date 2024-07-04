/*
 * SPI_prog.c
 *
 * Created: 7/2/2024 6:56:52 PM
 *  Author: Mostafa Edrees
 */ 

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../interrupt.h"

#include "SPI_priv.h"
#include "SPI_config.h"

volatile static void (* SPI_PappFunc)(void *) = NULL;
volatile static void *SPI_PappParameter = NULL;

ES_t SPI_enuInit()
{
	ES_t Local_enuErrorState = ES_NOK;
	
	#if SPI_STATE == ENABLE_SPI
	SPCR |=  (MASK_BIT << SPE);
	#elif SPI_STATE == DISABLE_SPI
	SPCR &= ~(MASK_BIT << SPE);
	#else
	#error "SPI STATE has a wrong configuration"
	#endif
	
	#if SPI_DORD == LSB_FIRST
	SPCR |=  (MASK_BIT << DORD);
	#elif SPI_DORD == MSB_FIRST
	SPCR &= ~(MASK_BIT << DORD);
	#else
	#error "SPI DATA ORDER has a wrong configuration"
	#endif
	
	#if SPI_MODE == MASTER
	SPCR |=  (MASK_BIT << MSTR);
	#elif SPI_MODE == SLAVE
	SPCR &= ~(MASK_BIT << MSTR);
	#else
	#error "SPI MODE has a wrong configuration"
	#endif
	
	#if SPI_CPOL == IDLE_HIGH
	SPCR |=  (MASK_BIT << CPOL);
	#elif SPI_CPOL == IDLE_LOW
	SPCR &= ~(MASK_BIT << CPOL);
	#else
	#error "SPI CLOCK POLARITY has a wrong configuration"
	#endif
	
	#if SPI_CPHA == READ_FIRST
	SPCR &= ~(MASK_BIT << CPHA);
	#elif SPI_CPHA == WRITE_FIRST
	SPCR |=  (MASK_BIT << CPHA);
	#else
	#error "SPI CLOCK PHASE has a wrong configuration"
	#endif
	
	#if SPI_SPEED == NORMAL_SPEED
	SPSR &= ~(MASK_BIT << SPI2X);
	#elif SPI_SPEED == DOUBLE_SPEED
	SPSR |=  (MASK_BIT << SPI2X);
	#else
	#error "SPI SPEED has a wrong configuration"
	#endif
	
	#if ((SPI_FREQUENCY == F_DIVIDED_4) && (SPI_SPEED == NORMAL_SPEED))
	SPCR &= ~(MASK_BIT << SPR0);
	SPCR &= ~(MASK_BIT << SPR1);
	#elif ((SPI_FREQUENCY == F_DIVIDED_16) && (SPI_SPEED == NORMAL_SPEED))
	SPCR |=  (MASK_BIT << SPR0);
	SPCR &= ~(MASK_BIT << SPR1);
	#elif (SPI_FREQUENCY == F_DIVIDED_64)
		#if (SPI_SPEED == NORMAL_SPEED)
		SPCR &= ~(MASK_BIT << SPR0);
		SPCR |=  (MASK_BIT << SPR1);
		#elif (SPI_SPEED == DOUBLE_SPEED)
		SPCR |=  (MASK_BIT << SPR0);
		SPCR |=  (MASK_BIT << SPR1);
		#else
		#error "SPI FREQUENCY at 64 Prescaler has a wrong configuration"
		#endif
	#elif ((SPI_FREQUENCY == F_DIVIDED_128) && (SPI_SPEED == NORMAL_SPEED))
	SPCR |=  (MASK_BIT << SPR0);
	SPCR |=  (MASK_BIT << SPR1);
	#elif ((SPI_FREQUENCY == F_DIVIDED_2) && (SPI_SPEED == DOUBLE_SPEED))
	SPCR &= ~(MASK_BIT << SPR0);
	SPCR &= ~(MASK_BIT << SPR1);
	#elif ((SPI_FREQUENCY == F_DIVIDED_8) && (SPI_SPEED == DOUBLE_SPEED))
	SPCR |=  (MASK_BIT << SPR0);
	SPCR &= ~(MASK_BIT << SPR1);
	#elif ((SPI_FREQUENCY == F_DIVIDED_32) && (SPI_SPEED == DOUBLE_SPEED))
	SPCR &= ~(MASK_BIT << SPR0);
	SPCR |=  (MASK_BIT << SPR1);
	#else
	#error "SPI FREQUENCY has a wrong configuration"
	#endif
	
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}


ES_t SPI_enuSendData_Master(u8 Copy_u8MasterData, u8 *Copy_pu8SlaveData)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_pu8SlaveData != NULL)
	{
		SPDR = Copy_u8MasterData;
		while(!((SPSR >> SPIF) & 1));
		*Copy_pu8SlaveData = SPDR;
		
		Local_enuErrorState = ES_OK;	
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

ES_t SPI_enuReceiveData_Master(u8 *Copy_pu8MasterData, u8 Copy_u8SlaveData)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_pu8MasterData != NULL)
	{
		SPDR = Copy_u8SlaveData;
		while(!((SPSR >> SPIF) & 1));
		*Copy_pu8MasterData = SPDR;
		
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

ES_t SPI_enuEnableInterrupt()
{
	ES_t Local_enuErrorState = ES_NOK;
	
	SPCR |= (MASK_BIT << SPIE);
	
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;
}


ES_t SPI_enuCallBackFunc(void (* Copy_pAppFunc)(void *), void *Copy_pAppParameter)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_pAppFunc != NULL)
	{
		SPI_PappFunc = Copy_pAppFunc;
		SPI_PappParameter = Copy_pAppParameter;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

ISR(VECT_SPI)
{
	if(SPI_PappFunc != NULL)
	{
		SPI_PappFunc((void *)SPI_PappParameter);
	}
}