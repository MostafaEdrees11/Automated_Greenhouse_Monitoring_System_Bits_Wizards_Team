/*
 * TIMER2_Priv.h
 *
 *  Created on: Jul 10, 2024
 *      Author: Samar ibrahim
 */

#ifndef MCAL_TIMER2_TIMER2_PRIV_H_
#define MCAL_TIMER2_TIMER2_PRIV_H_

#define TCCR2			*((volatile u8*)0x45)			/*Timer/Counter2 Control Register A*/
#define TCCR2_CS20		0                               /* Prescaler bit 0 */
#define TCCR2_CS21		1                               /* Prescaler bit 1 */
#define TCCR2_CS22		2                               /* Prescaler bit 2 */

#define TCCR2_WGM21		3                               /* Waveform generation mode 1 */

#define TCCR2_COM20		4                               /* Compare Output Mode, Phase Correct, fast and non-PWM Mod0 */
#define TCCR2_COM21		5                               /* Compare Output Mode, Phase Correct, fast and non-PWM Mod1 */

#define TCCR2_WGM20		6                               /* Waveform generation mode 0 */

#define TCCR2_FOC2		7                               /*Force Output Compare, must be set to 0 at PWM mode*/


#define TCNT2			*((volatile u8*)0x44)			/*Timer/Counter2 Control Register*/


#define OCR2			*((volatile u8*)0x43)  			/* Output compare register */


#define TIMSK_OCIE2		7								/* Timer/Counter2 Output Compare Match Interrupt Enable */
#define TIMSK_TOIE2		6

/*Timer0 Mode*/
#define OVF						15
#define PHCO_PWM				16
#define CTC						17
#define FAST_PWM				18

/*Timer0 Prescaler*/
#define PRES_TIMER_OFF			0
#define PRES_NO					1
#define PRES_8					8
#define PRES_32					32
#define PRES_64					64
#define PRES_128				128
#define PRES_256				256
#define PRES_1024				1024

#define FAILLING_EDGE			6
#define RISING_EDGE				7

/*OC0 Mode*/
#define DISCONNECTED			-1
#define TOGGLE_OC2				1
#define CLEAR_OC2				2
#define SET_OC2  				3
#define NON_INVERTED			4
#define INVERTED				5


#define TIMER2_NO_OVF_COUNTS	256UL
#define TIMER2_TOP_COUNTS		255UL
#define PRESENTAGE_100			100.0

#define PRESCALER_MASK			0xF8
#define COM_OC2_MASK			0xCF
#define WGM_MASK				0xB7

#define MASK_BIT				1

#endif /* MCAL_TIMER2_TIMER2_PRIV_H_ */
