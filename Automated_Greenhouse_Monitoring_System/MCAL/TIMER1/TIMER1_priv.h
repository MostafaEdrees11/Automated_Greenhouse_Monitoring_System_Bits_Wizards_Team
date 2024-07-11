/*
 * TIMER1_priv.h
 *
 * Created: 3/22/2024 1:25:31 AM
 *  Author: Mostafa Edrees
 */ 


#ifndef TIMER1_PRIV_H_
#define TIMER1_PRIV_H_


#include "../../LIB/Error_States.h"

// TIMER1 Registers
#define	TCCR1A					*((volatile u8 *)0x4F)
#define TCCR1B					*((volatile u8 *)0x4E)
#define TCNT1H					*((volatile u8 *)0x4D)
#define TCNT1L					*((volatile u8 *)0x4C)

#define OCR1A                   (*(volatile u16*)0x4A)
#define OCR1AH					*((volatile u8 *)0x4B)
#define OCR1AL					*((volatile u8 *)0x4A)

#define OCR1B					(*(volatile u16*)0x48)
#define OCR1BH					*((volatile u8 *)0x49)
#define OCR1BL					*((volatile u8 *)0x48)

#define ICR1					(*(volatile u16*)0x46)
#define ICR1H					*((volatile u8 *)0x47)
#define ICR1L					*((volatile u8 *)0x46)

#define TIMSK					*((volatile u8 *)0x59)
#define TIFR					*((volatile u8 *)0x58)

// TCCR1A Bits
#define COM1A1					7
#define COM1A0					6
#define COM1B1					5
#define COM1B0					4
#define FOC1A					3
#define FOC1B					2
#define WGM11					1
#define WGM10					0

// TCCR1B Bits
#define ICNC1					7
#define ICES1					6
#define RESERVED				5
#define WGM13					4
#define WGM12					3
#define CS12					2
#define CS11					1
#define CS10					0

// TIMSK Bits
#define TICIE1					5
#define OCIE1A					4
#define OCIE1B					3
#define TOIE1					2

// TIFR Bits
#define ICF1					5
#define OCF1A					4
#define OCF1B					3
#define TOV1					2

/*Timer1 Mode*/
#define TIMER1_OVF							0
#define TIMER1_PWM_PHCO_8B					1
#define TIMER1_PWM_PHCO_9B					2
#define TIMER1_PWM_PHCO_10B					3
#define TIMER1_CTC_TOP_OCR1A				4
#define TIMER1_FAST_PWM_8B					5
#define TIMER1_FAST_PWM_9B					6
#define TIMER1_FAST_PWM_10B					7
#define TIMER1_PWM_PH_FRCO_TOP_ICR1			8
#define TIMER1_PWM_PH_FRCO_TOP_OCR1A		9
#define TIMER1_PWM_PHCO_TOP_ICR1			10
#define TIMER1_PWM_PHCO_TOP_OCR1A			11
#define TIMER1_CTC_TOP_ICR1					12
#define TIMER1_RESERVED						13
#define TIMER1_FAST_PWM_TOP_ICR1			14
#define TIMER1_FAST_PWM_TOP_OCR1A			15


/* Timer1 Prescaler */
#define PRES_TIMER_OFF			0
#define PRES_NO					1
#define PRES_8					8
#define PRES_64					64
#define PRES_256				256
#define PRES_1024				1024
#define FAILLING_EDGE			6
#define RISING_EDGE				7

/* OC1A/OC1B Mode */
#define DISCONNECTED			-1
#define TOGGLE_OC1A				1
#define TOGGLE_OC1B				1
#define CLEAR_OC1A				2
#define CLEAR_OC1B				2
#define SET_OC1A				3
#define SET_OC1B				3
#define NON_INVERTED			4
#define INVERTED				5

#define OCRB_DISCONNECTED		1
#define OCRB_TOGGLE				2
#define OCRB_NON_INVERTING		3
#define OCRB_INVERTING			4

#define OCRA_DISCONNECTED		1
#define OCRA_TOGGLE				2
#define OCRA_NON_INVERTING		3
#define OCRA_INVERTING			4


#define MASK_BIT				1

typedef enum
{
	TIMER1_FAILLING_DETECT,
	TIMER1_RISING_DETECT
}TIMER1_EDGE_STATE_t;

typedef enum
{
	TIMER1_DISABLE_NOISE_CANCELER,
	TIMER1_ENABLE_NOISE_CANCELER
}TIMER1_NOISE_CANCELER_STATE_t;

typedef enum
{
	TIMER1_start,
	TIMER1_Ton,
	TIMER1_Ttotal,
	TIMER1_Off
}TIMER1_ICU_STATE_t;


#define CLR_BIT(X,N)     (X)=(X)&(~(1<<(N)))
#define READ_BIT(X,N)          (((X)>>(N))&1)
#define TOG_BIT(X,N)       (X)=(X)^(1<<(N))
#define SET_BIT(X,N)       (X)=(X)|(1<<(N))



#endif /* TIMER1_PRIV_H_ */