/*
 * TIMER1_int.h
 *
 * Created: 3/22/2024 1:25:03 AM
 *  Author: Mostafa Edrees
 */ 


#ifndef TIMER1_INT_H_
#define TIMER1_INT_H_

typedef enum
{
	FAILLING_DETECT,
	RISING_DETECT
}EDGE_STATE_t;

typedef enum
{
	DISABLE_NOISE_CANCELER,
	ENABLE_NOISE_CANCELER
}NOISE_CANCELER_STATE_t;

typedef enum
{
	start,
	Ton,
	Ttotal,
	Off
}ICU_STATE_t;

ES_t TIMER1_enuInit(void);

ES_t TIMER1_enuDelayMilliSecondSyn(u32 Copy_u32DelayTime_ms);

ES_t TIMER1_enuDelayMilliSecondASyn(u32 Copy_u32DelayTime_ms, void (*Copy_PFunApp)(void *), void *Copy_PParameterApp);

ES_t TIMER1_enuSetPreload(u8 Copy_u8PreloadValue);

ES_t TIMER1_enuSetOutputCompareRegisterChannelA(u16 Copy_u8OCRValue);

ES_t TIMER1_enuSetOutputCompareRegisterChannelB(u16 Copy_u8OCRValue);

ES_t TIMER1_enuPrepareICU(EDGE_STATE_t Copy_enuEdgeState, NOISE_CANCELER_STATE_t Copy_enuNoiseCancelerState);

ES_t TIMER1_enuCalculateICUResults(f32 *Copy_Pf32Frequency, f32 *Copy_Pf32DutyCycle);

ES_t TIMER1_enuSetCALLBACK_OVF(void (*Copy_PFunApp)(void *), void *Copy_PParameterApp);

ES_t TIMER1_enuSetCALLBACK_CTC_ChannelA(void (*Copy_PFunApp)(void *), void *Copy_PParameterApp);

ES_t TIMER1_enuSetCALLBACK_CTC_ChannelB(void (*Copy_PFunApp)(void *), void *Copy_PParameterApp);

ES_t TIMER1_enuSetCALLBACK_ICU(void (*Copy_PFunApp)(void *), void *Copy_PParameterApp);

ES_t TIMER1_enuEnableOVFInterrupt(void);

ES_t TIMER1_enuEnableCTCInterruptChannelA(void);

ES_t TIMER1_enuEnableCTCInterruptChannelB(void);

ES_t TIMER1_enuEnableInputCaptureUnitInterrupt(void);

ES_t TIMER1_enuGeneratePWM_OCR1A(u8 Copy_u8DutyCycle);

ES_t TIMER1_enuGeneratePWM_OCR1B(u8 Copy_u8DutyCycle);


#endif /* TIMER1_INT_H_ */