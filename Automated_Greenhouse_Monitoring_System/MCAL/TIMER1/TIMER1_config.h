/*
 * TIMER1_config.h
 *
 * Created: 3/22/2024 1:25:20 AM
 *  Author: Mostafa Edrees
 */ 


#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

#define TIMER1_MODE			TIMER1_FAST_PWM_8B

/*
Note:
	Don't use PRES_256 or PRES_1024 if you will use ICU because it's out the frequency = 0
*/
#define TIMER1_PRES			PRES_8

/* You should write F_SYSTEM in KHz */
#define F_SYSTEM			8000UL


#define OC1A_MODE			OCRA_NON_INVERTING
#define OC1B_MODE			OCRB_NON_INVERTING

#endif /* TIMER1_CONFIG_H_ */
