/*
 * TIMER1_prog.c
 *
 * Created: 3/22/2024 1:24:53 AM
 *  Author: Mostafa Edrees
 */ 

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "TIMER1_int.h"
#include "TIMER1_priv.h"
#include "TIMER1_config.h"

#include "../interrupt.h"

ES_t TIMER1_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	/* Mask the four bits of Waveform Generation Mode */
	TCCR1A &= 0xFC;
	TCCR1B &= 0xE7;

	#if TIMER1_MODE == TIMER1_OVF
	TCCR1A &= ~(MASK_BIT << WGM10);
	TCCR1A &= ~(MASK_BIT << WGM11);
	TCCR1B &= ~(MASK_BIT << WGM12);
	TCCR1B &= ~(MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_PWM_PHCO_8B
	TCCR1A |=  (MASK_BIT << WGM10);
	TCCR1A &= ~(MASK_BIT << WGM11);
	TCCR1B &= ~(MASK_BIT << WGM12);
	TCCR1B &= ~(MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_PWM_PHCO_9B
	TCCR1A &= ~(MASK_BIT << WGM10);
	TCCR1A |=  (MASK_BIT << WGM11);
	TCCR1B &= ~(MASK_BIT << WGM12);
	TCCR1B &= ~(MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_PWM_PHCO_10B
	TCCR1A |=  (MASK_BIT << WGM10);
	TCCR1A |=  (MASK_BIT << WGM11);
	TCCR1B &= ~(MASK_BIT << WGM12);
	TCCR1B &= ~(MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_CTC_TOP_OCR1A
	TCCR1A &= ~(MASK_BIT << WGM10);
	TCCR1A &= ~(MASK_BIT << WGM11);
	TCCR1B |=  (MASK_BIT << WGM12);
	TCCR1B &= ~(MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_FAST_PWM_8B
	TCCR1A |=  (MASK_BIT << WGM10);
	TCCR1A &= ~(MASK_BIT << WGM11);
	TCCR1B |=  (MASK_BIT << WGM12);
	TCCR1B &= ~(MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_FAST_PWM_9B
	TCCR1A &= ~(MASK_BIT << WGM10);
	TCCR1A |=  (MASK_BIT << WGM11);
	TCCR1B |=  (MASK_BIT << WGM12);
	TCCR1B &= ~(MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_FAST_PWM_10B
	TCCR1A |=  (MASK_BIT << WGM10);
	TCCR1A |=  (MASK_BIT << WGM11);
	TCCR1B |=  (MASK_BIT << WGM12);
	TCCR1B &= ~(MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_PWM_PH_FRCO_TOP_ICR1
	TCCR1A &= ~(MASK_BIT << WGM10);
	TCCR1A &= ~(MASK_BIT << WGM11);
	TCCR1B &= ~(MASK_BIT << WGM12);
	TCCR1B |=  (MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_PWM_PH_FRCO_TOP_OCR1A
	TCCR1A |=  (MASK_BIT << WGM10);
	TCCR1A &= ~(MASK_BIT << WGM11);
	TCCR1B &= ~(MASK_BIT << WGM12);
	TCCR1B |=  (MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_PWM_PHCO_TOP_ICR1
	TCCR1A &= ~(MASK_BIT << WGM10);
	TCCR1A |=  (MASK_BIT << WGM11);
	TCCR1B &= ~(MASK_BIT << WGM12);
	TCCR1B |=  (MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_PWM_PHCO_TOP_OCR1A
	TCCR1A |=  (MASK_BIT << WGM10);
	TCCR1A |=  (MASK_BIT << WGM11);
	TCCR1B &= ~(MASK_BIT << WGM12);
	TCCR1B |=  (MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_CTC_TOP_ICR1
	TCCR1A &= ~(MASK_BIT << WGM10);
	TCCR1A &= ~(MASK_BIT << WGM11);
	TCCR1B |=  (MASK_BIT << WGM12);
	TCCR1B |=  (MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_RESERVED
	TCCR1A |=  (MASK_BIT << WGM10);
	TCCR1A &= ~(MASK_BIT << WGM11);
	TCCR1B |=  (MASK_BIT << WGM12);
	TCCR1B |=  (MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_FAST_PWM_TOP_ICR1
	TCCR1A &= ~(MASK_BIT << WGM10);
	TCCR1A |=  (MASK_BIT << WGM11);
	TCCR1B |=  (MASK_BIT << WGM12);
	TCCR1B |=  (MASK_BIT << WGM13);
	#elif TIMER1_MODE == TIMER1_FAST_PWM_TOP_OCR1A
	TCCR1A |=  (MASK_BIT << WGM10);
	TCCR1A |=  (MASK_BIT << WGM11);
	TCCR1B |=  (MASK_BIT << WGM12);
	TCCR1B |=  (MASK_BIT << WGM13);
	#else
	#error "Timer1 Mode has a wrong configuration"
	#endif
	
	/* Mask the three bits of Timer1 Prescaler */
	TCCR1B &= 0xF8;
	
	#if TIMER1_PRES == PRES_TIMER_OFF
	TCCR1B &= ~(MASK_BIT << CS10);
	TCCR1B &= ~(MASK_BIT << CS11);
	TCCR1B &= ~(MASK_BIT << CS12);
	#elif TIMER1_PRES == PRES_NO
	TCCR1B |=  (MASK_BIT << CS10);
	TCCR1B &= ~(MASK_BIT << CS11);
	TCCR1B &= ~(MASK_BIT << CS12);
	#elif TIMER1_PRES == PRES_8
	TCCR1B &= ~(MASK_BIT << CS10);
	TCCR1B |=  (MASK_BIT << CS11);
	TCCR1B &= ~(MASK_BIT << CS12);
	#elif TIMER1_PRES == PRES_64
	TCCR1B |=  (MASK_BIT << CS10);
	TCCR1B |=  (MASK_BIT << CS11);
	TCCR1B &= ~(MASK_BIT << CS12);
	#elif TIMER1_PRES == PRES_256
	TCCR1B &= ~(MASK_BIT << CS10);
	TCCR1B &= ~(MASK_BIT << CS11);
	TCCR1B |=  (MASK_BIT << CS12);
	#elif TIMER1_PRES == PRES_1024
	TCCR1B |=  (MASK_BIT << CS10);
	TCCR1B &= ~(MASK_BIT << CS11);
	TCCR1B |=  (MASK_BIT << CS12);
	#elif TIMER1_PRES == FAILLING_EDGE
	TCCR1B &= ~(MASK_BIT << CS10);
	TCCR1B |=  (MASK_BIT << CS11);
	TCCR1B |=  (MASK_BIT << CS12);
	#elif TIMER1_PRES == RISING_EDGE
	TCCR1B |=  (MASK_BIT << CS10);
	TCCR1B |=  (MASK_BIT << CS11);
	TCCR1B |=  (MASK_BIT << CS12);
	#else
	#error "Timer1 Prescaler has a wrong configuration"
	#endif
	
	/* Initialize OC1A Mode*/
	#if   OC1A_MODE == OCRB_DISCONNECTED
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	
	#elif OC1A_MODE == OCRB_TOGGLE
	SET_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	
	#elif OC1A_MODE == OCRB_NON_INVERTING
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	
	#elif OC1A_MODE == OCRB_INVERTING
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	
	#else
	#error "Timer1 OCRA mode wrong cmofigration"
	#endif
	
	/* Initialize OC1A Mode*/
	#if   OC1B_MODE == OCRB_DISCONNECTED
	CLR_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
	
	#elif OC1B_MODE == OCRB_TOGGLE
	SET_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
	
	#elif OC1B_MODE == OCRB_NON_INVERTING
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	
	#elif OC1B_MODE == OCRB_INVERTING
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	
	#else
	#error "Timer1 OCRB mode wrong cmofigration"
	#endif

	return Local_enuErrorState;	
}

ES_t TIMER1_enuDelayMilliSecondSyn(u32 Copy_u32DelayTime_ms)
{
	ES_t Local_enuErrorState = ES_NOK;



	return Local_enuErrorState;
}

ES_t TIMER1_enuDelayMilliSecondASyn(u32 Copy_u32DelayTime_ms, void (*Copy_PFunApp)(void *), void *Copy_PParameterApp)
{
	ES_t Local_enuErrorState = ES_NOK;



	return Local_enuErrorState;
}

ES_t TIMER1_enuSetPreload(u8 Copy_u8PreloadValue)
{
	ES_t Local_enuErrorState = ES_NOK;



	return Local_enuErrorState;
}

ES_t TIMER1_enuSetOutputCompareRegisterChannelA(u16 Copy_u8OCRValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	OCR1A = Copy_u8OCRValue;
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t TIMER1_enuSetOutputCompareRegisterChannelB(u16 Copy_u8OCRValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	OCR1B = Copy_u8OCRValue;
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;
}

ES_t TIMER1_enuSetCALLBACK_OVF(void (*Copy_PFunApp)(void *), void *Copy_PParameterApp)
{
	ES_t Local_enuErrorState = ES_NOK;



	return Local_enuErrorState;
}

ES_t TIMER1_enuSetCALLBACK_CTC_ChannelA(void (*Copy_PFunApp)(void *), void *Copy_PParameterApp)
{
	ES_t Local_enuErrorState = ES_NOK;



	return Local_enuErrorState;
}

ES_t TIMER1_enuSetCALLBACK_CTC_ChannelB(void (*Copy_PFunApp)(void *), void *Copy_PParameterApp)
{
	ES_t Local_enuErrorState = ES_NOK;



	return Local_enuErrorState;
}

ES_t TIMER1_enuSetCALLBACK_ICU(void (*Copy_PFunApp)(void *), void *Copy_PParameterApp)
{
	ES_t Local_enuErrorState = ES_NOK;



	return Local_enuErrorState;
}

ES_t TIMER1_enuEnableOVFInterrupt(void)
{
	ES_t Local_enuErrorState = ES_NOK;



	return Local_enuErrorState;
}

ES_t TIMER1_enuEnableCTCInterruptChannelA(void)
{
	ES_t Local_enuErrorState = ES_NOK;



	return Local_enuErrorState;
}

ES_t TIMER1_enuEnableCTCInterruptChannelB(void)
{
	ES_t Local_enuErrorState = ES_NOK;



	return Local_enuErrorState;
}

EDGE_STATE_t ICU_enuEdgeDetect = FAILLING_DETECT;
ICU_STATE_t ICU_enuState = start;
u16 TimeOn = 0, TimeTotal = 0;

ES_t TIMER1_enuPrepareICU(EDGE_STATE_t Copy_enuEdgeState, NOISE_CANCELER_STATE_t Copy_enuNoiseCancelerState)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Mask the three bits of Timer1 Prescaler */
	TCCR1B &= 0xF8;
	
	#if TIMER1_PRES == PRES_TIMER_OFF
	TCCR1B &= ~(MASK_BIT << CS10);
	TCCR1B &= ~(MASK_BIT << CS11);
	TCCR1B &= ~(MASK_BIT << CS12);
	#elif TIMER1_PRES == PRES_NO
	TCCR1B |=  (MASK_BIT << CS10);
	TCCR1B &= ~(MASK_BIT << CS11);
	TCCR1B &= ~(MASK_BIT << CS12);
	#elif TIMER1_PRES == PRES_8
	TCCR1B &= ~(MASK_BIT << CS10);
	TCCR1B |=  (MASK_BIT << CS11);
	TCCR1B &= ~(MASK_BIT << CS12);
	#elif TIMER1_PRES == PRES_64
	TCCR1B |=  (MASK_BIT << CS10);
	TCCR1B |=  (MASK_BIT << CS11);
	TCCR1B &= ~(MASK_BIT << CS12);
	#elif TIMER1_PRES == PRES_256
	TCCR1B &= ~(MASK_BIT << CS10);
	TCCR1B &= ~(MASK_BIT << CS11);
	TCCR1B |=  (MASK_BIT << CS12);
	#elif TIMER1_PRES == PRES_1024
	TCCR1B |=  (MASK_BIT << CS10);
	TCCR1B &= ~(MASK_BIT << CS11);
	TCCR1B |=  (MASK_BIT << CS12);
	#elif TIMER1_PRES == FAILLING_EDGE
	TCCR1B &= ~(MASK_BIT << CS10);
	TCCR1B |=  (MASK_BIT << CS11);
	TCCR1B |=  (MASK_BIT << CS12);
	#elif TIMER1_PRES == RISING_EDGE
	TCCR1B |=  (MASK_BIT << CS10);
	TCCR1B |=  (MASK_BIT << CS11);
	TCCR1B |=  (MASK_BIT << CS12);
	#else
	#error "Timer1 Prescaler has a wrong configuration"
	#endif
	
	ICU_enuEdgeDetect = Copy_enuEdgeState;
	if(Copy_enuEdgeState == FAILLING_DETECT)
	{
		TCCR1B &= ~(MASK_BIT << ICES1);
	}
	else if (Copy_enuEdgeState == RISING_DETECT)
	{
		TCCR1B |=  (MASK_BIT << ICES1);
	}
	
	if(Copy_enuNoiseCancelerState == DISABLE_NOISE_CANCELER)
	{
		TCCR1B &= ~(MASK_BIT << ICNC1);
	}
	else if (Copy_enuNoiseCancelerState == ENABLE_NOISE_CANCELER)
	{
		TCCR1B |=  (MASK_BIT << ICNC1);
	}

	/* put 0 at the registers as initial value */
	ICR1H = 0;
	ICR1L = 0;
	TCNT1H = 0;
	TCNT1L = 0;
	
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t TIMER1_enuCalculateICUResults(f32 *Copy_Pf32Frequency, f32 *Copy_Pf32DutyCycle)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	f32 Local_f32Time = 0;

	if(Copy_Pf32DutyCycle != NULL && Copy_Pf32Frequency != NULL)
	{
		if(ICU_enuState == Off)
		{
			*Copy_Pf32DutyCycle = (f32)(TimeOn * 100.0 / TimeTotal);
			Local_f32Time = ((f32)((TimeTotal * TIMER1_PRES) / (F_SYSTEM * 1000.0)));
			*Copy_Pf32Frequency = ((f32)(1.0 / Local_f32Time));
			
			ICU_enuState = start;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}


ES_t TIMER1_enuEnableInputCaptureUnitInterrupt(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	TIMSK |= (MASK_BIT << TICIE1);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}



ES_t TIMER1_enuGeneratePWM_OCR1A(u8 Copy_u8DutyCycle)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	#if OC1A_MODE == OCRA_NON_INVERTING
		#if TIMER1_MODE == TIMER1_FAST_PWM_8B || TIMER1_MODE == TIMER1_PWM_PHCO_8B
		OCR1A = ((u32)Copy_u8DutyCycle*256)/100;
		Local_enuErrorState = ES_OK;

		#elif TIMER1_MODE == TIMER1_FAST_PWM_9B || TIMER1_MODE == TIMER1_PWM_PHCO_9B
		OCR1A = ((u32)Copy_u8DutyCycle*512)/100;
		Local_enuErrorState = ES_OK;
		
		#elif TIMER1_MODE == TIMER1_FAST_PWM_10B || TIMER1_MODE == TIMER1_PWM_PHCO_10B
		OCR1A = ((u32)Copy_u8DutyCycle*1024)/100;
		Local_enuErrorState = ES_OK;
		
		#elif TIMER1_MODE == TIMER1_FAST_PWM_TOP_ICR1 || TIMER1_MODE == TIMER1_PWM_PHCO_TOP_ICR1  
		OCR1A = ((u32)Copy_u8DutyCycle*ICR1)/100;
		Local_enuErrorState = ES_OK;
		
		#else
		#error "Timer 1 generate PWM Mode error "
		Local_enuErrorState = ES_OK;
		#endif
		
	#elif OC1A_MODE == OCRA_INVERTING
		#if TIMER1_MODE == TIMER1_FAST_PWM_8B || TIMER1_MODE == TIMER1_PWM_PHCO_8B
		OCR1A = (256 - (((u32)Copy_u8DutyCycle * 256)/(100)));
		Local_enuErrorState = ES_OK;

		#elif TIMER1_MODE == TIMER1_FAST_PWM_9B || TIMER1_MODE == TIMER1_PWM_PHCO_9B
		OCR1A = (512 - (((u32)Copy_u8DutyCycle * 512)/(100)));
		Local_enuErrorState = ES_OK;
		
		#elif TIMER1_MODE == TIMER1_FAST_PWM_10B || TIMER1_MODE == TIMER1_PWM_PHCO_10B
		OCR1A = (1024 - (((u32)Copy_u8DutyCycle * 1024)/(100)));
		Local_enuErrorState = ES_OK;
		
		#elif TIMER1_MODE == TIMER1_FAST_PWM_TOP_ICR1 || TIMER1_MODE == TIMER1_PWM_PHCO_TOP_ICR1
		OCR1A = (ICR1 - (((u32)Copy_u8DutyCycle * ICR1)/(100)));
		Local_enuErrorState = ES_OK;
		
		#else
		#error "Timer 1 generate PWM Mode error "
		Local_enuErrorState = ES_OK;
		#endif
		
	#else
	#error "Timer 1 OCRA Mode error For PWM"
	Local_enuErrorState = ES_OK;
	#endif
	
	return Local_enuErrorState;
}

ES_t TIMER1_enuGeneratePWM_OCR1B(u8 Copy_u8DutyCycle)
{
	ES_t Local_enuErrorState = ES_NOK;
	#if OC1B_MODE == OCRB_NON_INVERTING
		#if TIMER1_MODE == TIMER1_FAST_PWM_8B || TIMER1_MODE == TIMER1_PWM_PHCO_8B
		OCR1B = ((u32)Copy_u8DutyCycle*256)/100;
		Local_enuErrorState = ES_OK;

		#elif TIMER1_MODE == TIMER1_FAST_PWM_9B || TIMER1_MODE == TIMER1_PWM_PHCO_9B
		OCR1B = ((u32)Copy_u8DutyCycle*512)/100;
		Local_enuErrorState = ES_OK;
		
		#elif TIMER1_MODE == TIMER1_FAST_PWM_10B || TIMER1_MODE == TIMER1_PWM_PHCO_10B
		OCR1B = ((u32)Copy_u8DutyCycle*1024)/100;
		Local_enuErrorState = ES_OK;
		
		#elif TIMER1_MODE == TIMER1_FAST_PWM_TOP_ICR1 || TIMER1_MODE == TIMER1_PWM_PHCO_TOP_ICR1
		OCR1B = ((u32)Copy_u8DutyCycle*ICR1)/100;
		Local_enuErrorState = ES_OK;
		
		#elif TIMER1_MODE == TIMER1_FAST_PWM_TOP_OCR1A || TIMER1_MODE == TIMER1_PWM_PHCO_TOP_OCR1A
		OCR1B = ((u32)Copy_u8DutyCycle*OCR1A)/100;
		Local_enuErrorState = ES_OK;
		
		#else
		#error "Timer 1 generate PWM Mode error "
		Local_enuErrorState = ES_OK;
		#endif
		
	#elif OC1B_MODE == OCRB_INVERTING
		#if TIMER1_MODE == TIMER1_FAST_PWM_8B || TIMER1_MODE == TIMER1_PWM_PHCO_8B
		OCR1B = (256 - (((u32)Copy_u8DutyCycle * 256)/(100)));
		Local_enuErrorState = ES_OK;

		#elif TIMER1_MODE == TIMER1_FAST_PWM_9B || TIMER1_MODE == TIMER1_PWM_PHCO_9B
		OCR1B = (512 - (((u32)Copy_u8DutyCycle * 512)/(100)));
		Local_enuErrorState = ES_OK;
		
		#elif TIMER1_MODE == TIMER1_FAST_PWM_10B || TIMER1_MODE == TIMER1_PWM_PHCO_10B
		OCR1B = (1024 - (((u32)Copy_u8DutyCycle * 1024)/(100)));
		Local_enuErrorState = ES_OK;
		
		#elif TIMER1_MODE == TIMER1_FAST_PWM_TOP_ICR1 || TIMER1_MODE == TIMER1_PWM_PHCO_TOP_ICR1
		OCR1B = (ICR1 - (((u32)Copy_u8DutyCycle * ICR1)/(100)));
		Local_enuErrorState = ES_OK;
		
		#elif TIMER1_MODE == TIMER1_FAST_PWM_TOP_OCR1A || TIMER1_MODE == TIMER1_PWM_PHCO_TOP_OCR1A
		OCR1B = (OCR1A - (((u32)Copy_u8DutyCycle * OCR1A)/(100)));
		Local_enuErrorState = ES_OK;
		
		#else
		#error "Timer 1 generate PWM Mode error "
		Local_enuErrorState = ES_OK;
		#endif
		
	#else
	#error "Timer 1 OCRB Mode error For PWM"
	Local_enuErrorState = ES_OK;
	#endif
		
	return Local_enuErrorState;
}




ISR(VECT_TIMER1_ICU)
{
	if(ICU_enuState == start)
	{
		/* put 0 at the registers as initial value */
		ICR1H = 0;
		ICR1L = 0;
		TCNT1H = 0;
		TCNT1L = 0;
		
		ICU_enuEdgeDetect = !ICU_enuEdgeDetect;
		if(ICU_enuEdgeDetect == FAILLING_DETECT)
		{
			TCCR1B &= ~(MASK_BIT << ICES1);
		}
		else if (ICU_enuEdgeDetect == RISING_DETECT)
		{
			TCCR1B |=  (MASK_BIT << ICES1);
		}
		
		ICU_enuState = Ton;
	}
	else if(ICU_enuState == Ton)
	{
		TimeOn = ICR1L;
		TimeOn |= ((u16)(ICR1H << 8));
		
		ICU_enuEdgeDetect = !ICU_enuEdgeDetect;
		if(ICU_enuEdgeDetect == FAILLING_DETECT)
		{
			TCCR1B &= ~(MASK_BIT << ICES1);
		}
		else if (ICU_enuEdgeDetect == RISING_DETECT)
		{
			TCCR1B |=  (MASK_BIT << ICES1);
		}
		
		ICU_enuState = Ttotal;
	}
	else if(ICU_enuState == Ttotal)
	{
		TimeTotal = ICR1L;
		TimeTotal |= ((u16)(ICR1H << 8));
		
		ICU_enuState = Off;
	}
}