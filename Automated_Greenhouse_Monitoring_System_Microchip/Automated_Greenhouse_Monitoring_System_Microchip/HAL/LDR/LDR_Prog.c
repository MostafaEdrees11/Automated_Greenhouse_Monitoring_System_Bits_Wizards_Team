/*
 * LDR_Prog.c
 *
 *  Created on: Jul 4, 2024
 *      Author: Samar Ibrahim
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/Error_States.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/ADC/ADC_Config.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "../../MCAL/GIE/GIE_int.h"
#include "LDR_config.h"
#include "LDR_priv.h"
#include "../LCD/LCD_int.h"


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : LDR_enuInit.                                          **/
/** Return Type     : ES_t enum.                                            **/
/** Arguments       : LDR_t* Copy_PstrLDRconfig.                            **/
/** Brief           : Initializing LDR configuration (Config of pin)        **/
/*****************************************************************************/
/*****************************************************************************/
ES_t LDR_enuInit(LDR_t* Copy_PstrLDRconfig) {
    ES_t Local_enuErrorState = ES_NOK;

    // Iterate through each LDR configuration
    for (u8 Local_u8Iterator = 0; Local_u8Iterator < LDRNUM; Local_u8Iterator++) {
        if (Copy_PstrLDRconfig[Local_u8Iterator].LDR_Channel != NOTCONNECTED) {
            // Set pin direction
            Local_enuErrorState=DIO_enuSetPinDirection(DIO_u8PORTA, Copy_PstrLDRconfig[Local_u8Iterator].LDR_Channel, DIO_u8INPUT);

        }
    }


    return Local_enuErrorState;
}

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : LDR_enuGetValue.                                         **/
/** Return Type     : ES_t enum.                                            **/
/** Arguments       : u16 *Copy_pu16ReadValue, u8 Copy_u8ChannelID.         **/
/** Brief           : Get the value from the specified ADC channel.         **/
/*****************************************************************************/
/*****************************************************************************/
ES_t LDR_enuGetValue(u16 *Copy_pu16ReadValue, u8 Copy_u8ChannelID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pu16ReadValue != NULL)
	{
		ADC_Read_From_Ch(Copy_pu16ReadValue,Copy_u8ChannelID);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}
