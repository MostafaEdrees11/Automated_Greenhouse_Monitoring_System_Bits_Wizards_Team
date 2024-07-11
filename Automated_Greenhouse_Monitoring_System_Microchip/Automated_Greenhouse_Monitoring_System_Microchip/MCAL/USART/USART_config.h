/*
 * USART_config.h
 *
 * Created: 6/21/2024 6:36:14 PM
 *  Author: Mostafa Edrees
 */ 


#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

#define F_SYSTEM				8000000UL

/*
Options for USART SPEED:
	--> NORMAL_SPEED
	--> DOUBLE_SPEED
*/
#define USART_SPEED				NORMAL_SPEED

/*
Options for USART MODE:
	--> TRANSMITTER
	--> RECEIVER
	--> TRANSCEIVER
*/
#define USART_MODE				TRANSCEIVER

/*
Options for USART DATA LENGTH:
	--> FIVE_DATA_LENGTH
	--> SIX_DATA_LENGTH
	--> SEVEN_DATA_LENGTH
	--> EIGHT_DATA_LENGTH
	--> NINE_DATA_LENGTH
*/
#define USART_DATA_LENGTH		EIGHT_DATA_LENGTH

/*
Options for TRANSMITTION MODE:
	--> ASYNCHRONOUS
	--> SYNCHRONOUS
*/
#define TRANSMITTION_MODE		ASYNCHRONOUS

/*
~~~~~~~~~~~~~~~~
Important Note: 
~~~~~~~~~~~~~~~~
-----------------------------------------------------------------------------------------------------------------------------------
	Check the table of the BaudRate in the Data Sheet before you choose it
	check the percentage of the error with the CPU clock that you choose if its large so don't use it or work with anthor clock
	ex: if we need to work with 1000000 Hz as CPU clock and we choose 9600 BaudRate and we work in Normal mode so this will have
	error (7%) and if we work in Double speed mode the error will decrease to (0.2%) so take careeeeeeeeee !!!!!!!
-----------------------------------------------------------------------------------------------------------------------------------
*/
#define USART_BAUD_RATE			9600UL

/*
Options for PARITY STATE:
	--> NO_PARITY
	--> ODD_PARITY
	--> EVEN_PARITY
*/
#define PARITY_STATE			NO_PARITY

/*
Options for NO STOP BITS:
	--> ONE_STOP_BITS
	--> TWO_STOP_BITS
*/
#define NO_STOP_BITS			ONE_STOP_BITS

#endif /* USART_CONFIG_H_ */