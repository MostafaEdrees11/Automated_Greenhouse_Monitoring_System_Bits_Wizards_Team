/**
 ******************************************************************************
 * @file           : ADC_prog.c
 * @author         : Mostafa Edrees
 * @brief          : program file of ADC.
 * @date           : 26/1/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "ADC_priv.h"
#include "ADC_config.h"

#include "../interrupt.h"


static volatile void (*ADC_PFuncISRFunc)(void *) = NULL;
static volatile void *ADC_PvidISRParameter = NULL;

ES_t ADC_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	/* Configure Voltage Reference */
	/* Mask the two bits of voltage reference */
	ADMUX &= VOLT_REF_MASK;
	#if ADC_VOLT_REF == AREF_REF
	ADMUX &= ~(MASK_BIT << REFS0);
	ADMUX &= ~(MASK_BIT << REFS1);
	#elif ADC_VOLT_REF == AVCC_REF
	ADMUX |=  (MASK_BIT << REFS0);
	ADMUX &= ~(MASK_BIT << REFS1);
	#elif ADC_VOLT_REF == INTERNAL_REF
	ADMUX |=  (MASK_BIT << REFS0);
	ADMUX |=  (MASK_BIT << REFS1);
	#else
	#error "ADC Voltage Referance has a wrong configuration"
	#endif
	
	/* Configure Adjustment */
	/* Mask the bit of adjustment */
	ADMUX &= ~(MASK_BIT << ADLAR);
	#if ADC_ADJUST == RIGHT_ADJUST
	ADMUX &= ~(MASK_BIT << ADLAR);
	#elif ADC_ADJUST == LEFT_ADJUST
	ADMUX |=  (MASK_BIT << ADLAR);
	#else
	#error "ADC Adjustment has a wrong configuration"
	#endif
	
	/* Configure ADC Prescaler */
	/* Mask the three bits of Prescaler */
	ADCSRA &= PRESCALER_MASK;
	#if ADC_PRESCALER == DIVISION_FACTOR_2
	ADCSRA |=  (MASK_BIT << ADPS0);
	ADCSRA &= ~(MASK_BIT << ADPS1);
	ADCSRA &= ~(MASK_BIT << ADPS2);
	#elif ADC_PRESCALER == DIVISION_FACTOR_4
	ADCSRA &= ~(MASK_BIT << ADPS0);
	ADCSRA |=  (MASK_BIT << ADPS1);
	ADCSRA &= ~(MASK_BIT << ADPS2);
	#elif ADC_PRESCALER == DIVISION_FACTOR_8
	ADCSRA |=  (MASK_BIT << ADPS0);
	ADCSRA |=  (MASK_BIT << ADPS1);
	ADCSRA &= ~(MASK_BIT << ADPS2);
	#elif ADC_PRESCALER == DIVISION_FACTOR_16
	ADCSRA &= ~(MASK_BIT << ADPS0);
	ADCSRA &= ~(MASK_BIT << ADPS1);
	ADCSRA |=  (MASK_BIT << ADPS2);
	#elif ADC_PRESCALER == DIVISION_FACTOR_32
	ADCSRA |=  (MASK_BIT << ADPS0);
	ADCSRA &= ~(MASK_BIT << ADPS1);
	ADCSRA |=  (MASK_BIT << ADPS2);
	#elif ADC_PRESCALER == DIVISION_FACTOR_64
	ADCSRA &= ~(MASK_BIT << ADPS0);
	ADCSRA |=  (MASK_BIT << ADPS1);
	ADCSRA |=  (MASK_BIT << ADPS2);
	#elif ADC_PRESCALER == DIVISION_FACTOR_128
	ADCSRA |=  (MASK_BIT << ADPS0);
	ADCSRA |=  (MASK_BIT << ADPS1);
	ADCSRA |=  (MASK_BIT << ADPS2);
	#else
	#error "ADC PreScaler has a wrong configuration"
	#endif
	
	return Local_enuErrorState;
}

ES_t ADC_enuEnable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	ADCSRA |= (MASK_BIT << ADEN);
	
	return Local_enuErrorState;
}

ES_t ADC_enuDisable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	ADCSRA &= ~(MASK_BIT << ADEN);
	
	return Local_enuErrorState;
}

ES_t ADC_enuStartConversion(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	ADCSRA |= (MASK_BIT << ADSC);
	
	return Local_enuErrorState;
}

ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	/* Mask the five bits of channels */
	ADMUX &= CHANNALS_MASK;
	
	ADMUX |= Copy_u8ChannelID;
	
	return Local_enuErrorState;
}

ES_t ADC_enuPollingSystem(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	/* Busy Wait until flag is set */
	while(!((ADCSRA >> ADIF) & MASK_BIT));
	
	/* Write one to clear the flag */
	ADCSRA |= (MASK_BIT << ADIF);
	
	return Local_enuErrorState;
}

ES_t ADC_enuEnableInterrupt(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	ADCSRA |= (MASK_BIT << ADIE);
	
	return Local_enuErrorState;
}

ES_t ADC_enuDisableInterrupt(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	ADCSRA &= ~(MASK_BIT << ADIE);
	
	return Local_enuErrorState;
}

ES_t ADC_enuReadHighValue(u8 *Copy_pu8ReadHighValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	#if ADC_ADJUST == RIGHT_ADJUST
	*Copy_pu8ReadHighValue  = (ADCL >> 2);
	*Copy_pu8ReadHighValue |= (ADCH << 6);
	#elif ADC_ADJUST == LEFT_ADJUST
	*Copy_pu8ReadHighValue = ADCH;
	#else
	#error "ADC Adjustment has a wrong configuration"
	#endif
	
	return Local_enuErrorState;
}

ES_t ADC_enuReadADCValue(u16 *Copy_pu16ReadValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	#if ADC_ADJUST == RIGHT_ADJUST
	*Copy_pu16ReadValue  = ((u16)ADCL);
	*Copy_pu16ReadValue |= ((u16)ADCH << 8);
	#elif ADC_ADJUST == LEFT_ADJUST
	*Copy_pu16ReadValue  = ((u16)ADCL >> 6);
	*Copy_pu16ReadValue |= ((u16)ADCH << 2);
	#else
	#error "ADC Adjustment has a wrong configuration"
	#endif
	
	return Local_enuErrorState;
}

ES_t ADC_enuEnableTrigger(u8 Copy_u8TriggerSource)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	ADCSRA &= ~(MASK_BIT << ADATE);
	
	/* Mask the three bits of Auto Trigger Source */
	SFIOR &= AUTO_TRIGGER_MASK;
	switch(Copy_u8TriggerSource)
	{
		case FREE_RUNNING:
		SFIOR &= ~(MASK_BIT << ADTS0);
		SFIOR &= ~(MASK_BIT << ADTS1);
		SFIOR &= ~(MASK_BIT << ADTS2);
		break;
		
		case ANALOG_COMPARATOR:
		SFIOR |=  (MASK_BIT << ADTS0);
		SFIOR &= ~(MASK_BIT << ADTS1);
		SFIOR &= ~(MASK_BIT << ADTS2);
		break;
		
		case EXTI0_TRIG:
		SFIOR &= ~(MASK_BIT << ADTS0);
		SFIOR |=  (MASK_BIT << ADTS1);
		SFIOR &= ~(MASK_BIT << ADTS2);
		break;
		
		case TIMER0_COMPARE_MATCH_TRIG:
		SFIOR |=  (MASK_BIT << ADTS0);
		SFIOR |=  (MASK_BIT << ADTS1);
		SFIOR &= ~(MASK_BIT << ADTS2);
		break;
		
		case TIMER0_OVERFLOW_TRIG:
		SFIOR &= ~(MASK_BIT << ADTS0);
		SFIOR &= ~(MASK_BIT << ADTS1);
		SFIOR |=  (MASK_BIT << ADTS2);
		break;
		
		case TIMER1_COMPARE_MATCH_TRIG:
		SFIOR |=  (MASK_BIT << ADTS0);
		SFIOR &= ~(MASK_BIT << ADTS1);
		SFIOR |=  (MASK_BIT << ADTS2);
		break;
		
		case TIMER1_OVERFLOW_TRIG:
		SFIOR &= ~(MASK_BIT << ADTS0);
		SFIOR |=  (MASK_BIT << ADTS1);
		SFIOR |=  (MASK_BIT << ADTS2);
		break;
		
		case TIMER1_CAPUTRE_TRIG:
		SFIOR |=  (MASK_BIT << ADTS0);
		SFIOR |=  (MASK_BIT << ADTS1);
		SFIOR |=  (MASK_BIT << ADTS2);
		break;
		
		default:
		Local_enuErrorState = ES_OUT_OF_RANGE;
		break;
	}
	
	ADCSRA |= (MASK_BIT << ADATE);
	
	return Local_enuErrorState;
}

ES_t ADC_enuDisableTrigger(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	ADCSRA &= ~(MASK_BIT << ADATE);
	
	return Local_enuErrorState;
}

ES_t ADC_enuCallBack(volatile void (*Copy_PFunc)(void*), volatile void *Copy_PvidAppParameter)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_PFunc != NULL)
	{
		ADC_PFuncISRFunc = Copy_PFunc;
		ADC_PvidISRParameter = Copy_PvidAppParameter;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ES_t ADC_Read_From_Ch(u16 *Copy_pu16ReadValue, u8 Copy_u8ChannelID)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADC_enuEnable();
	ADC_enuDisableTrigger();
	ADC_enuSelectChannel(Copy_u8ChannelID);
	ADC_enuStartConversion();
	ADC_enuDisableInterrupt();
	ADC_enuPollingSystem();
	ADC_enuReadADCValue(Copy_pu16ReadValue);
	ADC_enuDisable();

	return Local_enuErrorState;
}

ISR(VECT_ADC)
{
	if(ADC_PFuncISRFunc != NULL)
	{
		ADC_PFuncISRFunc(ADC_PvidISRParameter);
	}
}
