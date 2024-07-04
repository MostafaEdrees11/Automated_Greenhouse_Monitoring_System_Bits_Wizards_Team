/*
 * USART_int.h
 *
 * Created: 6/21/2024 6:36:03 PM
 *  Author: Mostafa Edrees
 */ 


#ifndef USART_INT_H_
#define USART_INT_H_

ES_t USART_enuInit(void);

ES_t USART_enuSendCharacter(u8 Copy_u8SendedChar);

ES_t USART_enuReceiveCharacter(char *Copy_Pu8ReceivedChar);

ES_t USART_enuSendString(char *Copy_Pu8SendedString);

ES_t USART_enuReceiveStringUntilEnter(char *Copy_Pu8ReceivedString);

ES_t USART_enuReceiveStringWithKey(char *Copy_Pu8ReceivedString);


#endif /* USART_INT_H_ */