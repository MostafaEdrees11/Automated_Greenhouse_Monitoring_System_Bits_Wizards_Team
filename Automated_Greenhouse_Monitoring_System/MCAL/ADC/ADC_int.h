/**
 ******************************************************************************
 * @file           : ADC_int.h
 * @author         : Mostafa Edrees
 * @brief          : interface file of ADC.
 * @date           : 26/1/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef ADC_INT_H_
#define ADC_INT_H_

ES_t ADC_enuInit(void);

ES_t ADC_enuEnable(void);
ES_t ADC_enuDisable(void);

ES_t ADC_enuStartConversion(void);

ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID);

ES_t ADC_enuPollingSystem(void);

ES_t ADC_enuEnableInterrupt(void);
ES_t ADC_enuDisableInterrupt(void);

ES_t ADC_enuReadHighValue(u8 *Copy_pu8ReadHighValue);
ES_t ADC_enuReadADCValue(u16 *Copy_pu16ReadValue);

ES_t ADC_enuEnableTrigger(u8 Copy_u8TriggerSource);
ES_t ADC_enuDisableTrigger(void);

ES_t ADC_Read_From_Ch(u16 *Copy_pu16ReadValue, u8 Copy_u8ChannelID);

ES_t ADC_enuCallBack(volatile void (*Copy_PFunc)(void*), volatile void *Copy_PvidAppParameter);

/* Voltage Reference Selection */
#define AREF_REF					REFERENCE_VOLTAGE
#define AVCC_REF					5000UL
#define INTERNAL_REF				2560UL

/* Left or Right Adjustment */
#define RIGHT_ADJUST				0
#define LEFT_ADJUST					1

/* ADC PreScaler Select */
#define DIVISION_FACTOR_2			2
#define DIVISION_FACTOR_4			4
#define DIVISION_FACTOR_8			8
#define DIVISION_FACTOR_16			16
#define DIVISION_FACTOR_32			32
#define DIVISION_FACTOR_64			64
#define DIVISION_FACTOR_128			128

/* Analog Channels */
#define ADC_CHANNEL_0				0
#define ADC_CHANNEL_1				1
#define ADC_CHANNEL_2				2
#define ADC_CHANNEL_3				3
#define ADC_CHANNEL_4				4
#define ADC_CHANNEL_5				5
#define ADC_CHANNEL_6				6
#define ADC_CHANNEL_7				7


/* ADC Auto Trigger Source Selections */
#define FREE_RUNNING				0
#define ANALOG_COMPARATOR			1
#define EXTI0_TRIG					2
#define TIMER0_COMPARE_MATCH_TRIG	3
#define TIMER0_OVERFLOW_TRIG		4
#define TIMER1_COMPARE_MATCH_TRIG	5
#define TIMER1_OVERFLOW_TRIG		6
#define TIMER1_CAPUTRE_TRIG			7


#endif /* ADC_INT_H_ */
