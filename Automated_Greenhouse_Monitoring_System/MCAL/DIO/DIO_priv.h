/**
 ******************************************************************************
 * @file           : DIO_priv.h
 * @author         : Mostafa Edrees
 * @brief          : Private file of DIO.
 * @date           : 10/6/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

/* mask bit */
#define DIO_MASK_BIT	1

/* PORTs ID */
#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3

/* PINs ID */
#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7

/* Data Direction states */
#define INPUT			0
#define OUTPUT			1

/* Output states */
#define LOW				0
#define HIGH			1

/* Input states */
#define FLOAT			0
#define PULL_UP			1

/* registers addresses of PORTA */
#define PORTA			*((u8 *)0x3B)
#define DDRA			*((u8 *)0x3A)
#define PINA			*((volatile u8 *)0x39)

/* registers addresses of PORTB */
#define PORTB			*((u8 *)0x38)
#define DDRB			*((u8 *)0x37)
#define PINB			*((volatile u8 *)0x36)

/* registers addresses of PORTC */
#define PORTC			*((u8 *)0x35)
#define DDRC			*((u8 *)0x34)
#define PINC			*((volatile u8 *)0x33)

/* registers addresses of PORTD */
#define PORTD			*((u8 *)0x32)
#define DDRD			*((u8 *)0x31)
#define PIND			*((volatile u8 *)0x30)


/* Concatenation function */
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

#endif /* DIO_PRIV_H_ */