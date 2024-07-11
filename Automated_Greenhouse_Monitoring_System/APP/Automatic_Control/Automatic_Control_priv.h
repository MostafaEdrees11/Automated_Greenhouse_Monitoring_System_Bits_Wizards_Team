/*
 * Atuomatic_Control_priv.h
 *
 *  Created on: Jul 8, 2024
 *      Author: Fathy Anas
 */

#ifndef APP_AUTOMATIC_CONTROL_AUTOMATIC_CONTROL_PRIV_H_
#define APP_AUTOMATIC_CONTROL_AUTOMATIC_CONTROL_PRIV_H_

extern LED_t LED_AstrLedConfig[LED_NUM];
extern DC_MOTOR_t DC_MOTOR_AstrDcMotorConfig[DC_MOTOR_NUM];
extern BUZZER_t BUZZER_AstrBuzzerConfig[BUZZER_NUM];
extern EXTI_Configuration_t EXTI_AStrEXTI_Config[MAX_NUM_EXTI];

typedef enum
{
	SW_BUZZER_NOT_PRESSED,
	SW_BUZZER_PRESSED
}Buzzer_Forced_stop_t;

static void AC_Buzzer_stvidCallBack(void *);

#endif /* APP_AUTOMATIC_CONTROL_AUTOMATIC_CONTROL_PRIV_H_ */
