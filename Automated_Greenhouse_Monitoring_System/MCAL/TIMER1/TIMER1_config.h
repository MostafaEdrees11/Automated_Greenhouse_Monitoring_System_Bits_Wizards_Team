/*
 * TIMER1_config.h
 *
 * Created: 3/22/2024 1:25:20 AM
 *  Author: Mostafa Edrees
 */ 


#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

#define TIMER1_MODE			RESERVED

/*
Note:
	Don't use PRES_256 or PRES_1024 if you will use ICU because it's out the frequency = 0
*/
#define TIMER1_PRES			PRES_64

/* You should write F_SYSTEM in KHz */
#define F_SYSTEM			1000UL

#define OC1A_MODE			DISCONNECTED
#define OC1B_MODE			DISCONNECTED

#endif /* TIMER1_CONFIG_H_ */