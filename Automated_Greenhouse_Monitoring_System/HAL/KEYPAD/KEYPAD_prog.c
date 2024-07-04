/**
 ******************************************************************************
 * @file           : KEYPAD_prog.c
 * @author         : Mostafa Edrees
 * @brief          : program file of KEYPAD.
 * @date           : 3/11/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "KEYPAD_priv.h"
#include "KEYPAD_config.h"

/**
 ******************************************************************************
 * @Fn			: KEYPAD_enuInit
 * @brief		: it is used to initialize KEYPAD peripheral
 * @param [in]	: none
 * @retval		: ES_t --> it returns the error state of excution of this function
 * @note		: none
 ******************************************************************************
**/
ES_t KEYPAD_enuInit(void)
{
	ES_t Local_u8ErrorState = ES_NOK;
	
	/* Configure Column pins as output high */
	/* Output */
	Local_u8ErrorState = DIO_enuSetPinDirection(KEYPAD_C1_PORT, KEYPAD_C1_PIN, DIO_u8OUTPUT);
	Local_u8ErrorState = DIO_enuSetPinDirection(KEYPAD_C2_PORT, KEYPAD_C2_PIN, DIO_u8OUTPUT);
	Local_u8ErrorState = DIO_enuSetPinDirection(KEYPAD_C3_PORT, KEYPAD_C3_PIN, DIO_u8OUTPUT);
	Local_u8ErrorState = DIO_enuSetPinDirection(KEYPAD_C4_PORT, KEYPAD_C4_PIN, DIO_u8OUTPUT);
	
	/* High */
	Local_u8ErrorState = DIO_enuSetPinVal(KEYPAD_C1_PORT, KEYPAD_C1_PIN, DIO_u8HIGH);
	Local_u8ErrorState = DIO_enuSetPinVal(KEYPAD_C2_PORT, KEYPAD_C2_PIN, DIO_u8HIGH);
	Local_u8ErrorState = DIO_enuSetPinVal(KEYPAD_C3_PORT, KEYPAD_C3_PIN, DIO_u8HIGH);
	Local_u8ErrorState = DIO_enuSetPinVal(KEYPAD_C4_PORT, KEYPAD_C4_PIN, DIO_u8HIGH);
	
	/* Configure Row pins as input pull-up */
	/* Input */
	Local_u8ErrorState = DIO_enuSetPinDirection(KEYPAD_R1_PORT, KEYPAD_R1_PIN, DIO_u8INPUT);
	Local_u8ErrorState = DIO_enuSetPinDirection(KEYPAD_R2_PORT, KEYPAD_R2_PIN, DIO_u8INPUT);
	Local_u8ErrorState = DIO_enuSetPinDirection(KEYPAD_R3_PORT, KEYPAD_R3_PIN, DIO_u8INPUT);
	Local_u8ErrorState = DIO_enuSetPinDirection(KEYPAD_R4_PORT, KEYPAD_R4_PIN, DIO_u8INPUT);
	
	/* Pull-UP */
	Local_u8ErrorState = DIO_enuSetPinVal(KEYPAD_R1_PORT, KEYPAD_R1_PIN, DIO_u8PULL_UP);
	Local_u8ErrorState = DIO_enuSetPinVal(KEYPAD_R2_PORT, KEYPAD_R2_PIN, DIO_u8PULL_UP);
	Local_u8ErrorState = DIO_enuSetPinVal(KEYPAD_R3_PORT, KEYPAD_R3_PIN, DIO_u8PULL_UP);
	Local_u8ErrorState = DIO_enuSetPinVal(KEYPAD_R4_PORT, KEYPAD_R4_PIN, DIO_u8PULL_UP);
	
	return Local_u8ErrorState;
}

/**
 ******************************************************************************
 * @Fn			: KEYPAD_u8GetPressedKey
 * @brief		: it is used to get the key pressed by the user
 * @param [in]	: none
 * @retval		: it returns the Key pressed
 * @note		: none
 ******************************************************************************
**/
u8 KEYPAD_u8GetPressedKey(void)
{
	/* Two arrays --> one for Columns ports & one for Columns pins */
	static u8 Local_Au8ColumnsPorts[COLUMN_NUM] = {KEYPAD_C1_PORT, KEYPAD_C2_PORT, KEYPAD_C3_PORT, KEYPAD_C4_PORT};
	static u8 Local_Au8ColumnsPins[COLUMN_NUM] = {KEYPAD_C1_PIN, KEYPAD_C2_PIN, KEYPAD_C3_PIN, KEYPAD_C4_PIN};
	
	/* Two arrays --> one for Rows ports & one for Rows pins */	
	static u8 Local_Au8RowsPorts[ROW_NUM] = {KEYPAD_R1_PORT, KEYPAD_R2_PORT, KEYPAD_R3_PORT, KEYPAD_R4_PORT};
	static u8 Local_Au8RowsPins[ROW_NUM] = {KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN, KEYPAD_R4_PIN};
	
	/* array for Keypad characters */
	static u8 Local_KEYPAD_CHAR[ROW_NUM][COLUMN_NUM] = KEYPAD_CHARACTERS;
	
	u8 Local_u8ColumnIndex, Local_u8RowIndex, Local_u8PinState;
	u8 Local_u8PressedKey = KEYPAD_No_Key_Pressed;
	
	for(Local_u8ColumnIndex = 0; Local_u8ColumnIndex < COLUMN_NUM; Local_u8ColumnIndex++)
	{
		/* Active the current column */
		DIO_enuSetPinVal(Local_Au8ColumnsPorts[Local_u8ColumnIndex], Local_Au8ColumnsPins[Local_u8ColumnIndex], DIO_u8LOW);
		
		for(Local_u8RowIndex = 0; Local_u8RowIndex < ROW_NUM; Local_u8RowIndex++)
		{
			/* iterate on reading Row pins value */
			DIO_enuGetPinVal(Local_Au8RowsPorts[Local_u8RowIndex], Local_Au8RowsPins[Local_u8RowIndex], &Local_u8PinState);
			
			if(DIO_u8LOW == Local_u8PinState)
			{
				Local_u8PressedKey = Local_KEYPAD_CHAR[Local_u8RowIndex][Local_u8ColumnIndex];
				
				/* single press */
				while(DIO_u8LOW == Local_u8PinState)
				{
					DIO_enuGetPinVal(Local_Au8RowsPorts[Local_u8RowIndex], Local_Au8RowsPins[Local_u8RowIndex], &Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}
		
		/* Deactive the current column */
		DIO_enuSetPinVal(Local_Au8ColumnsPorts[Local_u8ColumnIndex], Local_Au8ColumnsPins[Local_u8ColumnIndex], DIO_u8HIGH);
	}
	
	
	return Local_u8PressedKey;
}
