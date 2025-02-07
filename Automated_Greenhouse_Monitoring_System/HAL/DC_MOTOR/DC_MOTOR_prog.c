/*
 * DC_MOTOR_prog.c
 *
 *  Created on: Jul 5, 2024
 *      Author: Fathy Anas
 */


#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "../../MCAL/TIMER0/TIMER0_int.h"
#include "../../MCAL/TIMER1/TIMER1_int.h"
#include "../../MCAL/TIMER2/TIMER2_int.h"

#include "DC_MOTOR_priv.h"
#include "DC_MOTOR_config.h"

extern DC_MOTOR_t DC_MOTOR_AstrDcMotorConfig[DC_MOTOR_NUM];

ES_t DC_MOTOR_enuInit(DC_MOTOR_t *Copy_pAstrDcMotorConfig)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pAstrDcMotorConfig != NULL)
	{
		u8 Local_u8Iterator;
		for(Local_u8Iterator = 0; Local_u8Iterator < DC_MOTOR_NUM; Local_u8Iterator++)
		{
			DIO_enuSetPinDirection(Copy_pAstrDcMotorConfig[Local_u8Iterator].DC_MOTOR_u8In1PortID,Copy_pAstrDcMotorConfig[Local_u8Iterator].DC_MOTOR_u8In1PinID,DIO_u8OUTPUT);
			DIO_enuSetPinDirection(Copy_pAstrDcMotorConfig[Local_u8Iterator].DC_MOTOR_u8In2PortID,Copy_pAstrDcMotorConfig[Local_u8Iterator].DC_MOTOR_u8In2PinID,DIO_u8OUTPUT);
		}

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}


ES_t DC_MOTOR_enuOnCW(u8 Copy_u8DcMotorID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8DcMotorID < DC_MOTOR_NUM)
	{
		DIO_enuSetPinVal(DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_u8In1PortID,DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_u8In1PinID,DIO_u8HIGH);
		DIO_enuSetPinVal(DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_u8In2PortID,DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_u8In2PinID,DIO_u8LOW);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t DC_MOTOR_enuOnCCW(u8 Copy_u8DcMotorID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8DcMotorID < DC_MOTOR_NUM)
	{
		DIO_enuSetPinVal(DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_u8In1PortID,DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_u8In1PinID,DIO_u8LOW);
		DIO_enuSetPinVal(DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_u8In2PortID,DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_u8In2PinID,DIO_u8HIGH);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t DC_MOTOR_enuOff(u8 Copy_u8DcMotorID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8DcMotorID < DC_MOTOR_NUM)
	{
		DIO_enuSetPinVal(DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_u8In1PortID,DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_u8In1PinID,DIO_u8LOW);
		DIO_enuSetPinVal(DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_u8In2PortID,DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_u8In2PinID,DIO_u8LOW);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

/*Speed 0:100*/
ES_t DC_MOTOR_SetSpeed(u8 Copy_u8DcMotorID, u8 Copy_u8DcMotorSpeed)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8DcMotorID < DC_MOTOR_NUM && Copy_u8DcMotorSpeed <= 100)
	{
		switch(DC_MOTOR_AstrDcMotorConfig[Copy_u8DcMotorID].DC_MOTOR_enuEnPin)
		{
		case PWM_NONE:
			Local_enuErrorState = ES_NOK;
			break;

		case PWM_OC0:
			TIMER0_enuGeneratePWM(Copy_u8DcMotorSpeed);
			Local_enuErrorState = ES_OK;
			break;

		case PWM_OC1A:
			TIMER1_enuGeneratePWM_OCR1A(Copy_u8DcMotorSpeed);
			Local_enuErrorState = ES_OK;
			break;

		case PWM_OC1B:
			TIMER1_enuGeneratePWM_OCR1B(Copy_u8DcMotorSpeed);
			Local_enuErrorState = ES_OK;
			break;

		case PWM_OC2:
			TIMER2_enuGeneratePWM(Copy_u8DcMotorSpeed);
			Local_enuErrorState = ES_OK;
			break;

		default:
			Local_enuErrorState = ES_NOK;
			break;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
