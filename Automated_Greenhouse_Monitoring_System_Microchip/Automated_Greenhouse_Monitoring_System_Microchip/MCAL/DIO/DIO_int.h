/**
 ******************************************************************************
 * @file           : DIO_int.h
 * @author         : Mostafa Edrees
 * @brief          : interface file of DIO.
 * @date           : 10/6/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

/* configuration of names of 4 ports */
#define DIO_u8PORTA		0
#define DIO_u8PORTB		1
#define DIO_u8PORTC		2
#define DIO_u8PORTD		3

/* configuration of names of pins */
#define DIO_u8PIN0		0
#define DIO_u8PIN1		1
#define DIO_u8PIN2		2
#define DIO_u8PIN3		3
#define DIO_u8PIN4		4
#define DIO_u8PIN5		5
#define DIO_u8PIN6		6
#define DIO_u8PIN7		7

/* configuration of data direction states */
#define DIO_u8INPUT			0
#define DIO_u8OUTPUT		1

/* configuration of input states */
#define DIO_u8FLOAT			0
#define DIO_u8PULL_UP		1

/* configuration of output states */
#define DIO_u8LOW			0
#define DIO_u8HIGH			1

/* initialize function */
ES_t DIO_enuINIT(void);

/* PORT functions */
ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8Value);
ES_t DIO_enuSetPortVal(u8 Copy_u8PortID, u8 Copy_u8Value);
ES_t DIO_enuGetPortVal(u8 Copy_u8PortID, u8 *Copy_pu8Value);
ES_t DIO_enuTogPortVal(u8 Copy_u8PortID);

/* PIN functions */
ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);
ES_t DIO_enuSetPinVal(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);
ES_t DIO_enuGetPinVal(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 *Copy_pu8Value);
ES_t DIO_enuTogPinVal(u8 Copy_u8PortID, u8 Copy_u8PinID);

#endif /* DIO_INT_H_ */