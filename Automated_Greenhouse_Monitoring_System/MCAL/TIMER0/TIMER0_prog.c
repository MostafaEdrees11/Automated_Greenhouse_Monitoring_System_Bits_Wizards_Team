/*
 * TIMER0_prog.c
 *
 * Created: 2/11/2024 11:11:40 AM
 *  Author: Mostafa Edrees
 */ 

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "TIMER0_priv.h"
#include "TIMER0_config.h"

#include "../interrupt.h"


volatile static void (*TIMER0_PFunISRfun_OVF)(void *) = NULL;
volatile static void *TIMER0_PvidISRparameter_OVF = NULL;

volatile static void (*TIMER0_PFunISRfun_CTC)(void *) = NULL;
volatile static void *TIMER0_PvidISRparameter_CTC = NULL;

u8 TIMER0_PRELOAD = 0;
u32 TIMER0_NUM_OVF = 0;
f32 TIMER0_f32OC0Value = 0;

ES_t TIMER0_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	/* Mask the two bits of Wave Generation Mode */
	TCCR0 &= WGM_MASK;
	
	#if TIMER0_MODE == OVF
	TCCR0 &= ~(MASK_BIT << WGM00);
	TCCR0 &= ~(MASK_BIT << WGM01);
	#elif TIMER0_MODE == PHCO_PWM
	TCCR0 |=  (MASK_BIT << WGM00);
	TCCR0 &= ~(MASK_BIT << WGM01);
	#elif TIMER0_MODE == CTC
	TCCR0 &= ~(MASK_BIT << WGM00);
	TCCR0 |=  (MASK_BIT << WGM01);
	#elif TIMER0_MODE == FAST_PWM
	TCCR0 |=  (MASK_BIT << WGM00);
	TCCR0 |=  (MASK_BIT << WGM01);
	#else
	#error "Timer0 Mode has a wrong configuration"
	#endif
	
	/* Mask the three bits of Timer0 Prescaler */
	TCCR0 &= PRESCALER_MASK;
	
	#if TIMER0_PRES == PRES_TIMER_OFF
	TCCR0 &= ~(MASK_BIT << CS00);
	TCCR0 &= ~(MASK_BIT << CS01);
	TCCR0 &= ~(MASK_BIT << CS02);
	#elif TIMER0_PRES == PRES_NO
	TCCR0 |=  (MASK_BIT << CS00);
	TCCR0 &= ~(MASK_BIT << CS01);
	TCCR0 &= ~(MASK_BIT << CS02);
	#elif TIMER0_PRES == PRES_8
	TCCR0 &= ~(MASK_BIT << CS00);
	TCCR0 |=  (MASK_BIT << CS01);
	TCCR0 &= ~(MASK_BIT << CS02);
	#elif TIMER0_PRES == PRES_64
	TCCR0 |=  (MASK_BIT << CS00);
	TCCR0 |=  (MASK_BIT << CS01);
	TCCR0 &= ~(MASK_BIT << CS02);
	#elif TIMER0_PRES == PRES_256
	TCCR0 &= ~(MASK_BIT << CS00);
	TCCR0 &= ~(MASK_BIT << CS01);
	TCCR0 |=  (MASK_BIT << CS02);
	#elif TIMER0_PRES == PRES_1024
	TCCR0 |=  (MASK_BIT << CS00);
	TCCR0 &= ~(MASK_BIT << CS01);
	TCCR0 |=  (MASK_BIT << CS02);
	#elif TIMER0_PRES == FAILLING_EDGE
	TCCR0 &= ~(MASK_BIT << CS00);
	TCCR0 |=  (MASK_BIT << CS01);
	TCCR0 |=  (MASK_BIT << CS02);
	#elif TIMER0_PRES == RISING_EDGE
	TCCR0 |=  (MASK_BIT << CS00);
	TCCR0 |=  (MASK_BIT << CS01);
	TCCR0 |=  (MASK_BIT << CS02);
	#else
	#error "Timer0 Prescaler has a wrong configuration"
	#endif
	
	/* Mask the two bits of Output Compare Pin (OC0) */
	TCCR0 &= COM_OC0_MASK;
	
	#if OC0_MODE == DISCONNECTED
	TCCR0 &= ~(MASK_BIT << COM00);
	TCCR0 &= ~(MASK_BIT << COM01);
	#elif ((OC0_MODE == TOGGLE_OC0) && (TIMER0_MODE == CTC))
	TCCR0 |=  (MASK_BIT << COM00);
	TCCR0 &= ~(MASK_BIT << COM01);
	#elif ((OC0_MODE == CLEAR_OC0) && (TIMER0_MODE == CTC))
	TCCR0 &= ~(MASK_BIT << COM00);
	TCCR0 |=  (MASK_BIT << COM01);
	#elif (OC0_MODE == SET_OC0 && (TIMER0_MODE == CTC))
	TCCR0 |=  (MASK_BIT << COM00);
	TCCR0 |=  (MASK_BIT << COM01);
	#elif ((OC0_MODE == NON_INVERTED) && (TIMER0_MODE == PHCO_PWM || TIMER0_MODE == FAST_PWM))
	TCCR0 &= ~(MASK_BIT << COM00);
	TCCR0 |=  (MASK_BIT << COM01);
	#elif ((OC0_MODE == INVERTED) && (TIMER0_MODE == PHCO_PWM || TIMER0_MODE == FAST_PWM))
	TCCR0 |=  (MASK_BIT << COM00);
	TCCR0 |=  (MASK_BIT << COM01);
	#else
	#error "OC0 has a wrong configuration"
	#endif
	
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;
}

ES_t TIMER0_enuDelayMilliSecondSyn(u32 Copy_u32DelayTime_ms)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	f32 Local_f32TimeOverFlow = 256.0 * TIMER0_PRES / F_SYSTEM;
	f32 Local_f32Num_OVF_FLOAT = (f32)Copy_u32DelayTime_ms / Local_f32TimeOverFlow;
	
	if((Local_f32Num_OVF_FLOAT - (u32)Local_f32Num_OVF_FLOAT) != 0.0)
	{
		u32 Local_u32Num_OVF_INT = (u32)Local_f32Num_OVF_FLOAT + 1;
		Local_f32Num_OVF_FLOAT = Local_f32Num_OVF_FLOAT - (u32)Local_f32Num_OVF_FLOAT;
		u8 Local_u32PreLoad = 256 - (256 * Local_f32Num_OVF_FLOAT);
		TCNT0 = Local_u32PreLoad;
		while(Local_u32Num_OVF_INT)
		{
			while(!((TIFR >> TOV0) & MASK_BIT));
			TIFR |= (MASK_BIT << TOV0);
			Local_u32Num_OVF_INT--;
		}	
	}
	else
	{
		u32 Local_u32Num_OVF_INT = (u32)Local_f32TimeOverFlow;
		while(Local_u32Num_OVF_INT)
		{
			while(!((TIFR >> TOV0) & MASK_BIT));
			TIFR |= (MASK_BIT << TOV0);
			Local_u32Num_OVF_INT--;
		}
	}
	
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t TIMER0_enuDelayMilliSecondASyn(u32 Copy_u32DelayTime_ms, void (*Copy_PFunApp)(void *), void *Copy_PParameterApp)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	TIMSK &= ~(MASK_BIT << TOIE0);
	
	f32 Local_f32TimeOverFlow = 256.0 * TIMER0_PRES / F_SYSTEM;
	f32 Local_f32Num_OVF_FLOAT = (f32)Copy_u32DelayTime_ms / Local_f32TimeOverFlow;
	
	if((Local_f32Num_OVF_FLOAT - (u32)Local_f32Num_OVF_FLOAT) != 0.0)
	{
		u32 Local_u32Num_OVF_INT = (u32)Local_f32Num_OVF_FLOAT + 1;
		Local_f32Num_OVF_FLOAT = Local_f32Num_OVF_FLOAT - (u32)Local_f32Num_OVF_FLOAT;
		u8 Local_u32PreLoad = 256 - (256 * Local_f32Num_OVF_FLOAT);
		TIMER0_NUM_OVF = Local_u32Num_OVF_INT;
		TIMER0_PRELOAD = Local_u32PreLoad;
		TCNT0 = Local_u32PreLoad;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		TIMER0_NUM_OVF = (u32)Local_f32Num_OVF_FLOAT;
		Local_enuErrorState = ES_OK;
	}
	
	if(Copy_PFunApp != NULL)
	{
		TIMER0_PFunISRfun_OVF = Copy_PFunApp;
		TIMER0_PvidISRparameter_OVF = Copy_PParameterApp;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	TIMSK |= (MASK_BIT << TOIE0);
	
	return Local_enuErrorState;
}

ES_t TIMER0_enuGeneratePWM(u8 Copy_u8DutyCycle)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	#if TIMER0_MODE == PHCO_PWM
	#if OC0_MODE == NON_INVERTED
	TIMER0_f32OC0Value = (Copy_u8DutyCycle * TIMER0_TOP_COUNTS) / (PRESENTAGE_100);
	Local_enuErrorState = ES_OK;
	#elif OC0_MODE == INVERTED
	TIMER0_f32OC0Value = (TIMER0_TOP_COUNTS - ((Copy_u8DutyCycle * TIMER0_TOP_COUNTS) / (PRESENTAGE_100)));
	Local_enuErrorState = ES_OK;
	#else
	#error "OC0 has a wrong configuration"
	#endif	
	
	#elif TIMER0_MODE == FAST_PWM
	#if OC0_MODE == NON_INVERTED
	TIMER0_f32OC0Value = (Copy_u8DutyCycle * TIMER0_NO_OVF_COUNTS) / (PRESENTAGE_100);
	Local_enuErrorState = ES_OK;
	#elif OC0_MODE == INVERTED
	TIMER0_f32OC0Value = (TIMER0_TOP_COUNTS - ((Copy_u8DutyCycle * TIMER0_NO_OVF_COUNTS) / (PRESENTAGE_100)));
	Local_enuErrorState = ES_OK;
	#else
	#error "OC0 has a wrong configuration"
	#endif
	#endif
	
	OCR0 = TIMER0_f32OC0Value;	
	
	return Local_enuErrorState;
}

ES_t TIMER0_enuSetOutputCompareRegister(u8 Copy_u8OCRValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	OCR0 = Copy_u8OCRValue;
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;
}

ES_t TIMER0_enuSetPreload(u8 Copy_u8PreloadValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	TCNT0 = Copy_u8PreloadValue;
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;
}

ES_t TIMER0_enuSetCALLBACK_CTC(void (*Copy_PFunApp)(void *), void *Copy_PParameterApp)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_PFunApp != NULL)
	{
		TIMER0_PFunISRfun_CTC = Copy_PFunApp;
		TIMER0_PvidISRparameter_CTC = Copy_PParameterApp;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

ES_t TIMER0_enuEnableOVFInterrupt(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	TIMSK |= (MASK_BIT << TOIE0);
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;
}

ES_t TIMER0_enuEnableCTCInterrupt(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	TIMSK |= (MASK_BIT << OCIE0);
	Local_enuErrorState = ES_OK;
	
	return Local_enuErrorState;
}

ISR(VECT_TIMER0_OVF)
{
	if(TIMER0_PFunISRfun_OVF != NULL)
	{
		static u32 Local_u32Counter = 0;
		Local_u32Counter++;
		if(Local_u32Counter == TIMER0_NUM_OVF)
		{
			TCNT0 = TIMER0_PRELOAD;
			TIMER0_PFunISRfun_OVF((void *)TIMER0_PvidISRparameter_OVF);
			Local_u32Counter = 0;
		}
	}
}

ISR(VECT_TIMER0_CTC)
{
	if(TIMER0_PFunISRfun_CTC != NULL)
	{
		TIMER0_PFunISRfun_CTC((void *)TIMER0_PvidISRparameter_CTC);
	}
}