/*
 * TIMER0_int.h
 *
 * Created: 2/11/2024 11:10:57 AM
 *  Author: Mostafa Edrees
 */ 


#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

ES_t TIMER0_enuInit(void);

ES_t TIMER0_enuDelayMilliSecondSyn(u32 Copy_u32DelayTime_ms);

ES_t TIMER0_enuDelayMilliSecondASyn(u32 Copy_u32DelayTime_ms, void (*Copy_PFunApp)(void *), void *Copy_PParameterApp);

ES_t TIMER0_enuSetPreload(u8 Copy_u8PreloadValue);

ES_t TIMER0_enuSetOutputCompareRegister(u8 Copy_u8OCRValue);

ES_t TIMER0_enuSetCALLBACK_CTC(void (*Copy_PFunApp)(void *), void *Copy_PParameterApp);

ES_t TIMER0_enuGeneratePWM(u8 Copy_u8DutyCycle);

ES_t TIMER0_enuEnableOVFInterrupt(void);

ES_t TIMER0_enuEnableCTCInterrupt(void);


/*Timer0 Mode*/
#define OVF					15
#define PHCO_PWM			16
#define CTC					17
#define FAST_PWM			18

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
#define DISCONNECTED		-1
#define TOGGLE_OC0			1
#define CLEAR_OC0			2
#define SET_OC0				3
#define NON_INVERTED		4
#define INVERTED			5




#endif /* TIMER0_INT_H_ */