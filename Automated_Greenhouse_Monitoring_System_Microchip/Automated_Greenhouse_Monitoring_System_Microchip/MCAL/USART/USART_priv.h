/*
 * USART_priv.h
 *
 * Created: 6/21/2024 6:36:29 PM
 *  Author: Mostafa Edrees
 */ 


#ifndef USART_PRIV_H_
#define USART_PRIV_H_

#define CALCULATE_BAUDRATE(BaudRate_Value)			(u16)(((F_SYSTEM)/(USART_SPEED * 8 * BaudRate_Value)) - 1)

#define NORMAL_SPEED				2
#define DOUBLE_SPEED				1

#define TRANSMITTER					11
#define RECEIVER					12
#define TRANSCEIVER					13

#define FIVE_DATA_LENGTH			5
#define SIX_DATA_LENGTH				6
#define SEVEN_DATA_LENGTH			7
#define EIGHT_DATA_LENGTH			8
#define NINE_DATA_LENGTH			9

#define ASYNCHRONOUS				33
#define SYNCHRONOUS					34

#define ONE_STOP_BITS				19
#define TWO_STOP_BITS				20

#define NO_PARITY					25
#define ODD_PARITY					26
#define EVEN_PARITY					27


#define UDR							*((volatile u8 *)0x2C)
#define UCSRA						*((volatile u8 *)0x2B)
#define UCSRB						*((volatile u8 *)0x2A)
#define UCSRC						*((volatile u8 *)0x40)
#define UBRRH						*((volatile u8 *)0x40)
#define UBRRL						*((volatile u8 *)0x29)

#define MPCM						0
#define U2X							1
#define PE							2
#define DOR							3
#define FE							4
#define UDRE						5
#define TXC							6
#define RXC							7

#define TXB8						0
#define RXB8						1
#define UCSZ2						2
#define TXEN						3
#define RXEN						4
#define UDRIE						5
#define TXCIE						6
#define RXCIE						7

#define UCPOL						0
#define UCSZ0						1
#define UCSZ1						2
#define USBS						3
#define UPM0						4
#define UPM1						5
#define UMSEL						6
#define URSEL						7

#define MASK_BIT					1

#endif /* USART_PRIV_H_ */