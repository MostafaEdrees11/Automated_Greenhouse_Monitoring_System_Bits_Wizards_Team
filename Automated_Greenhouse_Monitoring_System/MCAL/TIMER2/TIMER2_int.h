/*
 * TIMER2_int.h
 *
 *  Created on: Jul 10, 2024
 *      Author: Samar ibrahim
 */

#ifndef MCAL_TIMER2_TIMER2_INT_H_
#define MCAL_TIMER2_TIMER2_INT_H_


ES_t TIMER2_enuInit(void);

ES_t TIMER2_enuDelayMilliSecondSyn(u32 Copy_u32DelayTime_ms);

ES_t TIMER2_enuDelayMilliSecondASyn(u32 Copy_u32DelayTime_ms, void (*Copy_PFunApp)(void *), void *Copy_PParameterApp);

ES_t TIMER2_enuSetPreload(u8 Copy_u8PreloadValue);

ES_t TIMER2_enuSetOutputCompareRegister(u8 Copy_u8OCRValue);

ES_t TIMER2_enuSetCALLBACK_CTC(void (*Copy_PFunApp)(void *), void *Copy_PParameterApp);

ES_t TIMER2_enuGeneratePWM(u8 Copy_u8DutyCycle);

ES_t TIMER2_enuEnableOVFInterrupt(void);

ES_t TIMER2_enuEnableCTCInterrupt(void);


/*Timer0 Mode*/
#define OVF					15
#define PHCO_PWM			16
#define CTC					17
#define FAST_PWM			18

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
#define DISCONNECTED		-1
#define TOGGLE_OC0			1
#define CLEAR_OC0			2
#define SET_OC0				3
#define NON_INVERTED		4
#define INVERTED			5


#endif /* MCAL_TIMER2_TIMER2_INT_H_ */
