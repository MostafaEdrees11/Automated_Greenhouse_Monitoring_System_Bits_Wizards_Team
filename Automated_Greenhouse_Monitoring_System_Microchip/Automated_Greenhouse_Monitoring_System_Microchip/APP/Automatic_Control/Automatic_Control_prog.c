/*
 * Automatic_Control_prog.c
 *
 *  Created on: Jul 8, 2024
 *      Author: Fathy Anas
 */

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../HAL/DC_MOTOR/DC_MOTOR_int.h"

#include "../../HAL/LED/LED_int.h"

#include "../../HAL/BUZZER/BUZZER_int.h"

#include "../Sensors/Sensors_int.h"

#include "../../MCAL/TIMER0/TIMER0_int.h"
#include "../../MCAL/TIMER1/TIMER1_int.h"
#include "../../MCAL/TIMER2/TIMER2_int.h"

#include "../../MCAL/EXTI/EXTI_int.h"
#include "../../MCAL/EXTI/EXTI_config.h"
#include "../../MCAL/GIE/GIE_int.h"

#include "Automatic_Control_int.h"
#include "Automatic_Control_config.h"
#include "Automatic_Control_priv.h"

ES_t AC_enuInitSystem(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* initialize LED System & Lamp of LDR */
	LED_enuINIT(&LED_AstrLedConfig);

	/* initialize DC Motors */
	DC_MOTOR_enuInit(&DC_MOTOR_AstrDcMotorConfig);

	/* initialize Buzzer of System*/
	BUZZER_enuInit(&BUZZER_AstrBuzzerConfig);

	/*
	 * Set Direction of PWM Pins:
	 * OC0  --> PB3
	 * OC1A --> PD5
	 * OC1B --> PD4
	 * OC2  --> PD7
	 */
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN3, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN4, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN5, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN7, DIO_u8OUTPUT);

	/* initialize Timers
	 * Timer0 --> Lamp of LDR --> Fast PWM
	 * Timer1 --> Fan & Heaters --> Fast PWM (Top Not OCR1A or OCR1B)
	 * Timer2 --> Pumb --> Fast PWM*/
	TIMER0_enuInit();
	TIMER1_enuInit();
	TIMER2_enuInit();

	/* initialize EXTI1 for Buzzer */
	EXTI_enuInit(&EXTI_AStrEXTI_Config);
	EXTI_enuCallBackFunc(AC_Buzzer_stvidCallBack, NULL, EXTI1);
	EXTI_enuEnable(EXTI1);

	/* enable GIE */
	GIE_enuGloable_Interrupt_Enable();

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t AC_enuControlHeatSystem(u8 Copy_u8Temp, u8 Copy_u8Hemu)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Heater_u8Duty = 0, Fan_u8Duty;

	if(Copy_u8Temp < TEMP_MIN && Copy_u8Hemu < HUMI_MIN)
	{
		//Heater On
		/*
		 * map the value of temp between 10-->18 to out duty 50-->100 to turn on the heater
		 */
		DC_MOTOR_enuOnCW(HEATER_MOTOR);
		Heater_u8Duty = Math_Mapping(50, 100, TEMP_MIN, TEMP_ERROR_MIN, Copy_u8Temp);
		DC_MOTOR_SetSpeed(HEATER_MOTOR, Heater_u8Duty);
	}
	else if(Copy_u8Temp > (TEMP_MIN+TEMP_HYS) && Copy_u8Hemu > (HUMI_MIN+HUMI_HYS))
	{
		//Heater Off
		DC_MOTOR_enuOff(HEATER_MOTOR);
	}
	else
	{
		/* Do Nothing */
	}
	
	if(Copy_u8Temp > TEMP_MAX && Copy_u8Hemu > HUMI_MAX)
	{
		//Fan On
		/*
		 * map the value of temp between 26-->40 to out duty 50-->100 to turn on the on
		 */
		DC_MOTOR_enuOnCW(FAN_MOTOR);
		Fan_u8Duty = Math_Mapping(50, 100, TEMP_MAX, TEMP_ERROR_MAX, Copy_u8Temp);
		DC_MOTOR_SetSpeed(FAN_MOTOR, Fan_u8Duty);
	}
	else if(Copy_u8Temp < (TEMP_MAX+TEMP_HYS) && Copy_u8Hemu < (HUMI_MAX+HUMI_HYS))
	{
		//Fan Off
		DC_MOTOR_enuOff(FAN_MOTOR);
	}
	else
	{
		/* Do Nothing */
	}

	return Local_enuErrorState;
}

ES_t AC_enuControlIrrigationSystem(u8 Copy_u8SoilMoisture)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Pump_u8Duty = 0;

	if(Copy_u8SoilMoisture < SOIL_MIN && Copy_u8SoilMoisture > SOIL_ERROR_MIN)
	{
		//Pump On
		/*
		 * map the value of soil moisture between 10-->30 to out duty 50-->100 to turn on the pump
		 */
		DC_MOTOR_enuOnCW(PUMP_MOTOR);
		Pump_u8Duty = Math_Mapping(50, 100, SOIL_MIN, SOIL_ERROR_MIN, Copy_u8SoilMoisture);
		DC_MOTOR_SetSpeed(PUMP_MOTOR, Pump_u8Duty);
	}
	else if(Copy_u8SoilMoisture > SOIL_MAX)
	{
		//Pump Off
		DC_MOTOR_enuOff(PUMP_MOTOR);
	}
	else
	{
		/* Do Nothing */
	}

	return Local_enuErrorState;
}

ES_t AC_enuControlLightIntensitySystem(u8 Copy_u8LDR)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 LDRI_u8Duty = 0;

	if(Copy_u8LDR < LDRI_MIN && Copy_u8LDR > LDRI_ERROR_MIN)
	{
		//Lamp On
		/*
		 * map the value of soil moisture between 10-->30 to out duty 50-->100 to turn on the pump
		 */
		LDRI_u8Duty = Math_Mapping(50, 100, LDRI_MIN, LDRI_ERROR_MIN, Copy_u8LDR);
		LED_enuSetIntensity(LAMP_LED, LDRI_u8Duty);
	}
	else if(Copy_u8LDR > LDRI_MAX)
	{
		//Pump Off
		LED_enuSetIntensity(LAMP_LED, 0);
	}
	else
	{
		/* Do Nothing */
	}

	return Local_enuErrorState;
}

Buzzer_Forced_stop_t Buzzer_State = SW_BUZZER_PRESSED;

ES_t AC_enuControlAlertSystem(Data_Reading_t *Copy_PstrSystemReadings)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PstrSystemReadings->Temperture < TEMP_ERROR_MIN || Copy_PstrSystemReadings->Temperture > TEMP_ERROR_MAX
			|| Copy_PstrSystemReadings->Humidity < HUMI_ERROR_MIN || Copy_PstrSystemReadings->Humidity > HUMI_ERROR_MAX
			|| Copy_PstrSystemReadings->Soil_Moisture < SOIL_ERROR_MIN || Copy_PstrSystemReadings->Soil_Moisture > SOIL_ERROR_MAX
			|| Copy_PstrSystemReadings->Light_Intensity < LDRI_ERROR_MIN || Copy_PstrSystemReadings->Light_Intensity > LDRI_ERROR_MAX)
	{
		if(Buzzer_State == SW_BUZZER_PRESSED)
		{
			BUZZER_enuTurnOFF(SYSTEM_BUZZER);
		}
		else
		{
			BUZZER_enuTurnON(SYSTEM_BUZZER);
		}

		Copy_PstrSystemReadings->State = AGMS_ERROR;
		LED_enuTurnOFF(&LED_AstrLedConfig[STATE_LED]);
		LED_enuTurnON(&LED_AstrLedConfig[ERROR_LED]);
	}
	else
	{
		Copy_PstrSystemReadings->State = AGMS_NORMAL;
		Buzzer_State = SW_BUZZER_NOT_PRESSED;
		BUZZER_enuTurnOFF(SYSTEM_BUZZER);
		LED_enuTurnON(&LED_AstrLedConfig[STATE_LED]);
		LED_enuTurnOFF(&LED_AstrLedConfig[ERROR_LED]);
	}

	return Local_enuErrorState;
}

static void AC_Buzzer_stvidCallBack(void *Copy_pvidAppPara)
{
	Buzzer_State = SW_BUZZER_PRESSED;
}
