/**
 ******************************************************************************
 * @file           : EXTI_priv.h
 * @author         : Mostafa Edrees
 * @brief          : Private file of EXTI.
 * @date           : 13/12/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_


#define MCUCR			*((volatile u8 *)0x55)
#define MCUCSR			*((volatile u8 *)0x54)
#define GICR			*((volatile u8 *)0x5B)
#define GIFR			*((volatile u8 *)0x5A)

/*
Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0
The External Interrupt 0 is activated by the external pin INT0 if the SREG I-flag and the corresponding interrupt mask are set.
*/
#define ISC00			0
#define ISC01			1

/*
Bit 3, 2 – ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0
The External Interrupt 1 is activated by the external pin INT1 if the SREG I-bit and the corresponding interrupt mask in the GICR are set.
*/
#define ISC10			2
#define ISC11			3

/*
Bit 6 – ISC2: Interrupt Sense Control 2
The Asynchronous External Interrupt 2 is activated by the external pin INT2 if the SREG I-bit and
the corresponding interrupt mask in GICR are set.
If ISC2 is written to zero, a falling edge onINT2 activates the interrupt.
If ISC2 is written to one, a rising edge on INT2 activates the interrupt.
*/
#define ISC2			6

/*
Bit 6 – INT0: External Interrupt Request 0 Enable
When the INT0 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), the external pin interrupt is enabled
*/
#define INT0			6

/*
Bit 7 – INT1: External Interrupt Request 1 Enable
When the INT1 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), the external pin interrupt is enabled
*/
#define INT1			7

/*
Bit 5 – INT2: External Interrupt Request 2 Enable
When the INT2 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), the external pin interrupt is enabled
*/
#define INT2			5

/*
Bit 6 – INTF0: External Interrupt Flag 0
When an edge or logic change on the INT0 pin triggers an interrupt request, INTF0 becomes set
(one). If the I-bit in SREG and the INT0 bit in GICR are set (one), the MCU will jump to the corresponding interrupt vector. 
The flag is cleared when the interrupt routine is executed.
Alternatively, the flag can be cleared by writing a logical one to it. This flag is always cleared
when INT0 is configured as a level interrupt
*/
#define INTF0			6

/*
Bit 7 – INTF1: External Interrupt Flag 1
When an edge or logic change on the INT1 pin triggers an interrupt request, INTF1 becomes set
(one). If the I-bit in SREG and the INT1 bit in GICR are set (one), the MCU will jump to the corresponding Interrupt Vector. 
The flag is cleared when the interrupt routine is executed.
Alternatively, the flag can be cleared by writing a logical one to it. This flag is always cleared
when INT1 is configured as a level interrupt.
*/
#define INTF1			7

/*
Bit 5 – INTF2: External Interrupt Flag 2
When an event on the INT2 pin triggers an interrupt request, INTF2 becomes set (one). 
If the Ibit in SREG and the INT2 bit in GICR are set (one), the MCU will jump to the corresponding Interrupt Vector. 
The flag is cleared when the interrupt routine is executed. Alternatively, the flag
can be cleared by writing a logical one to it.
*/
#define INTF2			5

typedef enum
{
	EXTI0,
	EXTI1,
	EXTI2
}EXTI_ID_t;


typedef enum
{
	ENABLED,
	DISABLED
}EXTI_STATE_t;

typedef enum
{
	LOW_LEVEL,
	LOGICAL,
	FAILLING,
	RISING
}EXTI_CTL_STATE_t;

#define MAX_NUM_EXTI	3

#define MASK_BIT		1

#endif /* EXTI_PRIV_H_ */
