/*
 * TIMER0_priv.h
 *
 * Created: 2/11/2024 11:11:23 AM
 *  Author: Mostafa Edrees
 */ 


#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_

// TIMER0 Registers
#define TCCR0					*((volatile u8 *)0x53)
#define TCNT0					*((volatile u8 *)0x52)
#define OCR0					*((volatile u8 *)0x5C)
#define TIMSK					*((volatile u8 *)0x59)
#define TIFR					*((volatile u8 *)0x58)


// TCCR0 Bits
#define FOC0					7
#define WGM00					6
#define COM01					5
#define COM00					4
#define WGM01					3
#define CS02					2
#define CS01					1
#define CS00					0

// TIMSK Bits
#define OCIE0					1
#define TOIE0					0

// TIFR Bits
#define OCF0					1
#define TOV0					0

/*Timer0 Mode*/
#define OVF						15
#define PHCO_PWM				16
#define CTC						17
#define FAST_PWM				18

/*Timer0 Prescaler*/
#define PRES_TIMER_OFF			0
#define PRES_NO					1
#define PRES_8					8
#define PRES_64					64
#define PRES_256				256
#define PRES_1024				1024
#define FAILLING_EDGE			6
#define RISING_EDGE				7

/*OC0 Mode*/
#define DISCONNECTED			-1
#define TOGGLE_OC0				1
#define CLEAR_OC0				2
#define SET_OC0					3
#define NON_INVERTED			4
#define INVERTED				5


#define TIMER0_NO_OVF_COUNTS	256UL
#define TIMER0_TOP_COUNTS		255UL
#define PRESENTAGE_100			100.0

#define PRESCALER_MASK			0xF8
#define COM_OC0_MASK			0xCF
#define WGM_MASK				0xB7	

#define MASK_BIT				1

#endif /* TIMER0_PRIV_H_ */