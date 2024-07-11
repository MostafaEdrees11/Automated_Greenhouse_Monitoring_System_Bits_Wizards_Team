/*
 * TIMER2_Prog.c
 *
 *  Created on: Jul 10, 2024
 *      Author: Samar ibrahim
 */


#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "TIMER2_priv.h"
#include "TIMER2_config.h"

#include "../interrupt.h"

volatile static void (*TIMER0_PFunISRfun_OVF)(void *) = NULL;
volatile static void *TIMER0_PvidISRparameter_OVF = NULL;

volatile static void (*TIMER0_PFunISRfun_CTC)(void *) = NULL;
volatile static void *TIMER0_PvidISRparameter_CTC = NULL;

u8 TIMER2_PRELOAD = 0;
u32 TIMER2_NUM_OVF = 0;
f32 TIMER2_f32OC2Value = 0;

ES_t TIMER2_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Mask the two bits of Wave Generation Mode */
	TCCR2 &= WGM_MASK;

	#if TIMER2_MODE == OVF
	TCCR2 &= ~(MASK_BIT << TCCR2_WGM20);
	TCCR2 &= ~(MASK_BIT <<TCCR2_WGM21	);
	#elif TIMER2_MODE == PHCO_PWM
	TCCR2 |=  (MASK_BIT << TCCR2_WGM20);
	TCCR2 &= ~(MASK_BIT << TCCR2_WGM21	);
	#elif TIMER2_MODE == CTC
	TCCR2 &= ~(MASK_BIT << TCCR2_WGM20);
	TCCR2 |=  (MASK_BIT <<TCCR2_WGM21	);
	#elif TIMER2_MODE== FAST_PWM
	TCCR2 |=  (MASK_BIT << TCCR2_WGM20);
	TCCR2 |=  (MASK_BIT << TCCR2_WGM21	);
	#else
	#error "Timer2 Mode has a wrong configuration"
	#endif

	/* Mask the three bits of Timer0 Prescaler */
	TCCR2 &= PRESCALER_MASK;

	#if TIMER2_PRES == PRES_TIMER_OFF
	TCCR2 &= ~(MASK_BIT << TCCR2_CS20	);
	TCCR2 &= ~(MASK_BIT << TCCR2_CS21	);
	TCCR2 &= ~(MASK_BIT << TCCR2_CS22	);
	#elif TIMER2_PRES == PRES_NO
	TCCR2 |=  (MASK_BIT << TCCR2_CS20	);
	TCCR2 &= ~(MASK_BIT << TCCR2_CS21	);
	TCCR2 &= ~(MASK_BIT << TCCR2_CS22	);
	#elif TIMER2_PRES == PRES_8
	TCCR2 &= ~(MASK_BIT <<TCCR2_CS20	);
	TCCR2 |=  (MASK_BIT <<TCCR2_CS21	);
	TCCR2 &= ~(MASK_BIT <<TCCR2_CS22	);
	#elif TIMER2_PRES == PRES_32
	TCCR2 |=  (MASK_BIT <<TCCR2_CS20	);
	TCCR2 |=  (MASK_BIT <<TCCR2_CS21	);
	TCCR2 &= ~(MASK_BIT <<TCCR2_CS22	);
	#elif TIMER2_PRES == PRES_64
	TCCR2 &= ~(MASK_BIT << TCCR2_CS20	);
	TCCR2 &= ~(MASK_BIT << TCCR2_CS21	);
	TCCR2 |=  (MASK_BIT << TCCR2_CS22	);
	#elif TIMER2_PRES == PRES_128
	TCCR2 |=  (MASK_BIT << TCCR2_CS20	);
	TCCR2 &= ~(MASK_BIT << TCCR2_CS21	);
	TCCR2 |=  (MASK_BIT << TCCR2_CS22	);
	#elif TIMER2_PRES == PRES_256
	TCCR2 &= ~(MASK_BIT << TCCR2_CS20	);
	TCCR2 |=  (MASK_BIT << TCCR2_CS21	);
	TCCR2 |=  (MASK_BIT << TCCR2_CS22	);
	#elif TIMER2_PRES == PRES_1024
	TCCR2 |=  (MASK_BIT <<TCCR2_CS20	);
	TCCR2 |=  (MASK_BIT <<TCCR2_CS21	);
	TCCR2 |=  (MASK_BIT <<TCCR2_CS22	);
	#else
	#error "Timer2 Prescaler has a wrong configuration"
	#endif

	/* Mask the two bits of Output Compare Pin (OC2) */
	TCCR2 &= COM_OC2_MASK;

	#if OC2_MODE == DISCONNECTED
	TCCR2 &= ~(MASK_BIT << TCCR2_COM20);
	TCCR2 &= ~(MASK_BIT << TCCR2_COM21);
	#elif ((OC2_MODE == TOGGLE_OC2) && (TIMER2_MODE == CTC))
	TCCR2 |=  (MASK_BIT << TCCR2_COM20);
	TCCR2 &= ~(MASK_BIT << TCCR2_COM21);
	#elif ((OC2_MODE == CLEAR_OC2) && (TIMER2_MODE == CTC))
	TCCR2 &= ~(MASK_BIT << TCCR2_COM20);
	TCCR2 |=  (MASK_BIT << TCCR2_COM21);
	#elif (OC2_MODE == SET_OC2 && (TIMER2_MODE == CTC))
	TCCR2 |=  (MASK_BIT << TCCR2_COM20);
	TCCR2 |=  (MASK_BIT << TCCR2_COM21);
	#elif ((OC2_MODE == NON_INVERTED) && (TIMER2_MODE == PHCO_PWM || TIMER2_MODE == FAST_PWM))
	TCCR2 &= ~(MASK_BIT << TCCR2_COM20);
	TCCR2 |=  (MASK_BIT << TCCR2_COM21);
	#elif ((OC2_MODE == INVERTED) && (TIMER2_MODE == PHCO_PWM || TIMER2_MODE == FAST_PWM))
	TCCR2 |=  (MASK_BIT << TCCR2_COM20);
	TCCR2 |=  (MASK_BIT << TCCR2_COM21);
	#else
	#error "OC2 has a wrong configuration"
	#endif

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t TIMER2_enuGeneratePWM(u8 Copy_u8DutyCycle)
{
	ES_t Local_enuErrorState = ES_NOK;

	#if TIMER2_MODE == PHCO_PWM
	#if OC2_MODE == NON_INVERTED
	TIMER2_f32OC2Value = (Copy_u8DutyCycle * TIMER2_TOP_COUNTS) / (PRESENTAGE_100);
	Local_enuErrorState = ES_OK;
	#elif OC2_MODE == INVERTED
	TIMER2_f32OC2Value = (TIMER2_TOP_COUNTS - ((Copy_u8DutyCycle * TIMER0_TOP_COUNTS) / (PRESENTAGE_100)));
	Local_enuErrorState = ES_OK;
	#else
	#error "OC2 has a wrong configuration"
	#endif

	#elif TIMER2_MODE == FAST_PWM
	#if OC2_MODE == NON_INVERTED
	TIMER2_f32OC2Value = (Copy_u8DutyCycle * TIMER2_NO_OVF_COUNTS) / (PRESENTAGE_100);
	Local_enuErrorState = ES_OK;
	#elif OC2_MODE == INVERTED
	TIMER2_f32OC2Value = (TIMER2_TOP_COUNTS - ((Copy_u8DutyCycle * TIMER2_NO_OVF_COUNTS) / (PRESENTAGE_100)));
	Local_enuErrorState = ES_OK;
	#else
	#error "OC2 has a wrong configuration"
	#endif
	#endif

	OCR2 = TIMER2_f32OC2Value;

	return Local_enuErrorState;
}

