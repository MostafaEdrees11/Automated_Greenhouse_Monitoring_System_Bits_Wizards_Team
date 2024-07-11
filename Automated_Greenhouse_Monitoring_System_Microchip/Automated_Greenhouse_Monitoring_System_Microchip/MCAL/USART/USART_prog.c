/*
 * USART_prog.c
 *
 * Created: 6/21/2024 6:35:42 PM
 *  Author: Mostafa Edrees
 */ 

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "USART_priv.h"
#include "USART_config.h"


ES_t USART_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8UCSRAvalue = 0;
	u16 Local_u16UBRRvalue = 0;
	
	#if USART_SPEED == NORMAL_SPEED
	UCSRA &= ~(MASK_BIT << U2X);
	#elif USART_SPEED == DOUBLE_SPEED
	UCSRA |=  (MASK_BIT << U2X);
	#else
	#error "USART SPEED has a wrong configuration"
	#endif
	
	#if USART_MODE == TRANSMITTER
	UCSRB |= (MASK_BIT << TXEN);
	#elif USART_MODE == RECEIVER
	UCSRB |= (MASK_BIT << RXEN);
	#elif USART_MODE == TRANSCEIVER
	UCSRB |= (MASK_BIT << TXEN);
	UCSRB |= (MASK_BIT << RXEN);
	#else
	#error "USART MODE has a wrong configuration"
	#endif
	
	#if USART_DATA_LENGTH == FIVE_DATA_LENGTH
	Local_u8UCSRAvalue &= ~(MASK_BIT << UCSZ0);
	Local_u8UCSRAvalue &= ~(MASK_BIT << UCSZ1);
	UCSRB &= ~(MASK_BIT << UCSZ2);
	#elif USART_DATA_LENGTH == SIX_DATA_LENGTH
	Local_u8UCSRAvalue |=  (MASK_BIT << UCSZ0);
	Local_u8UCSRAvalue &= ~(MASK_BIT << UCSZ1);
	UCSRB &= ~(MASK_BIT << UCSZ2);
	#elif USART_DATA_LENGTH == SEVEN_DATA_LENGTH
	Local_u8UCSRAvalue &= ~(MASK_BIT << UCSZ0);
	Local_u8UCSRAvalue |=  (MASK_BIT << UCSZ1);
	UCSRB &= ~(MASK_BIT << UCSZ2);
	#elif USART_DATA_LENGTH == EIGHT_DATA_LENGTH
	Local_u8UCSRAvalue |=  (MASK_BIT << UCSZ0);
	Local_u8UCSRAvalue |=  (MASK_BIT << UCSZ1);
	UCSRB &= ~(MASK_BIT << UCSZ2);
	#elif USART_DATA_LENGTH == NINE_DATA_LENGTH
	Local_u8UCSRAvalue |=  (MASK_BIT << UCSZ0);
	Local_u8UCSRAvalue |=  (MASK_BIT << UCSZ1);
	UCSRB |= (MASK_BIT << UCSZ2);
	#else
	#error "USART DATA LENGTH has a wrong configuration"
	#endif
	
	#if TRANSMITTION_MODE == ASYNCHRONOUS
	Local_u8UCSRAvalue &= ~(MASK_BIT << UMSEL);
	#elif TRANSMITTION_MODE == SYNCHRONOUS
	Local_u8UCSRAvalue |=  (MASK_BIT << UMSEL);
	#else
	#error "USART TRANSMITTION MODE has a wrong configuration"
	#endif
	
	#if PARITY_STATE == NO_PARITY
	Local_u8UCSRAvalue &= ~(MASK_BIT << UPM0);
	Local_u8UCSRAvalue &= ~(MASK_BIT << UPM1);
	#elif PARITY_STATE == ODD_PARITY
	Local_u8UCSRAvalue |=  (MASK_BIT << UPM0);
	Local_u8UCSRAvalue |=  (MASK_BIT << UPM1);
	#elif PARITY_STATE == EVEN_PARITY
	Local_u8UCSRAvalue &= ~(MASK_BIT << UPM0);
	Local_u8UCSRAvalue |=  (MASK_BIT << UPM1);
	#else
	#error "USART PARITY has a wrong configuration"
	#endif
	
	#if NO_STOP_BITS == ONE_STOP_BITS
	Local_u8UCSRAvalue &= ~(MASK_BIT << USBS);
	#elif NO_STOP_BITS == TWO_STOP_BITS
	Local_u8UCSRAvalue |=  (MASK_BIT << USBS);
	#else
	#error "USART STOP BITS has a wrong configuration"
	#endif
	
	Local_u8UCSRAvalue |= (MASK_BIT << URSEL);
	UCSRC = Local_u8UCSRAvalue;
	
	
	Local_u16UBRRvalue = (u16)CALCULATE_BAUDRATE(USART_BAUD_RATE);
	
	Local_u16UBRRvalue &= ~(MASK_BIT << 15);
	UBRRL = (u8)Local_u16UBRRvalue;
	UBRRH = (Local_u16UBRRvalue >> 8);
	
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;
}

ES_t USART_enuSendCharacter(u8 Copy_u8SendedChar)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	while(!((UCSRA >> UDRE) & 1));
	UDR = Copy_u8SendedChar;
	
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;
}

ES_t USART_enuReceiveCharacter(u8 *Copy_Pu8ReceivedChar)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_Pu8ReceivedChar != NULL)
	{
		while(!((UCSRA >> RXC) & 1));
		*Copy_Pu8ReceivedChar = UDR;
		
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

ES_t USART_enuSendString(u8 *Copy_Pu8SendedString)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_Pu8SendedString != NULL)
	{
		while(*Copy_Pu8SendedString != '\0')
		{
			while(!((UCSRA >> UDRE) & 1));
			UDR = *Copy_Pu8SendedString;
			Copy_Pu8SendedString++;
		}
		
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

/* we will stop receive string (end of string) when we press 'Enter' --> (\r = 13), \n */
ES_t USART_enuReceiveStringUntilEnter(u8 *Copy_Pu8ReceivedString)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	u8 Local_u8String = 0, Local_u8CharIndex = 0;
	
	if(Copy_Pu8ReceivedString != NULL)
	{
		while(1)
		{
			while(!((UCSRA >> RXC) & 1));
			Local_u8String = UDR;
			
			if(Local_u8String == '\r' || Local_u8String == '\n')
			{
				Copy_Pu8ReceivedString[Local_u8CharIndex] = '\0';
				break;
			}
			else
			{
				Copy_Pu8ReceivedString[Local_u8CharIndex++] = Local_u8String;
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


ES_t USART_enuReceiveStringWithKey(u8 *Copy_Pu8ReceivedString)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	u8 Local_u8String = 0, Local_u8CharIndex = 0;
	u8 Local_u8StringKey = 0;
	
	if(Copy_Pu8ReceivedString != NULL)
	{
		while(!((UCSRA >> RXC) & 1));
		Local_u8StringKey = UDR;
		
		while(1)
		{
			while(!((UCSRA >> RXC) & 1));
			Local_u8String = UDR;
			
			if(Local_u8String == Local_u8StringKey)
			{
				Copy_Pu8ReceivedString[Local_u8CharIndex] = '\0';
				break;
			}
			else
			{
				Copy_Pu8ReceivedString[Local_u8CharIndex++] = Local_u8String;
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