/**
 ******************************************************************************
 * @file           : LCD_prog.c
 * @author         : Mostafa Edrees
 * @brief          : program file of LCD.
 * @date           : 11/1/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LCD_priv.h"
#include "LCD_config.h"

#include <util/delay.h>

static u8 LCD_u8PosCounter = 0;

/**
 ******************************************************************************
 * @Fn			: LCD_enuInit
 * @brief		: it is used to initialize LCD peripheral
 * @param [in]	: none
 * @retval		: ES_t --> it returns the state of excution of this function
 * @note		: none
 ******************************************************************************
**/
ES_t LCD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	/* Set Control Pins as output */
	Local_enuErrorState = DIO_enuSetPinDirection(RS_PORT, RS_PIN, DIO_u8OUTPUT);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	Local_enuErrorState = DIO_enuSetPinDirection(RW_PORT, RW_PIN, DIO_u8OUTPUT);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinDirection(EN_PORT, EN_PIN, DIO_u8OUTPUT);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	/* Set Data Pins as output */
	Local_enuErrorState = DIO_enuSetPinDirection(D7_PORT, D7_PIN, DIO_u8OUTPUT);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinDirection(D6_PORT, D6_PIN, DIO_u8OUTPUT);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinDirection(D5_PORT, D5_PIN, DIO_u8OUTPUT);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	Local_enuErrorState = DIO_enuSetPinDirection(D4_PORT, D4_PIN, DIO_u8OUTPUT);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	_delay_ms(35);
	
	#if LCD_MODE == EIGHT_BIT
	Local_enuErrorState = DIO_enuSetPinDirection(D3_PORT, D3_PIN, DIO_u8OUTPUT);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	Local_enuErrorState = DIO_enuSetPinDirection(D2_PORT, D2_PIN, DIO_u8OUTPUT);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	Local_enuErrorState = DIO_enuSetPinDirection(D1_PORT, D1_PIN, DIO_u8OUTPUT);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	Local_enuErrorState = DIO_enuSetPinDirection(D0_PORT, D0_PIN, DIO_u8OUTPUT);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	/* Function Set */
	Local_enuErrorState = LCD_inlenuSendCommand(LCD_8Bit_TwoLine_5_7CharFont);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	_delay_ms(1);
	
	#elif LCD_MODE == FOUR_BIT
	/* Function Set */
	LCD_inlenuSendCommand(0x33);
	LCD_inlenuSendCommand(0x32);
	
	Local_enuErrorState = LCD_inlenuSendCommand(LCD_4Bit_TwoLine_5_7CharFont);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	_delay_ms(1);
	
	#else
	#error "LCD Mode has a wrong configuration"
	#endif
	
	/* Display ON/OFF Control */
	Local_enuErrorState = LCD_inlenuSendCommand(LCD_DisplayOn_CursorOn_Blinking);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	_delay_ms(1);
	
	/* Display Clear */
	Local_enuErrorState = LCD_inlenuSendCommand(LCD_Clear_Display);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	_delay_ms(2);
	
	/* Entry Mode Set */
	Local_enuErrorState = LCD_inlenuSendCommand(LCD_Increase_NoShift);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	_delay_ms(1);
	
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

/**
 ******************************************************************************
 * @Fn			: LCD_enuDisplayChar
 * @brief		: it is used to display character on LCD
 * @param [in]	: Copy_u8Data --> it is specify character which will display on LCD
 * @retval		: ES_t --> it returns the state of excution of this function
 * @note		: none
 ******************************************************************************
**/
ES_t LCD_enuDisplayChar(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	/* Check position in case of we send data */
	LCD_vidCheckPosition();
	
	/* RS --> High to write Data */
	Local_enuErrorState = DIO_enuSetPinVal(RS_PORT, RS_PIN, DIO_u8HIGH);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	/* Call Latch Function */
	Local_enuErrorState = LCD_enuLatch(Copy_u8Data);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

/**
 ******************************************************************************
 * @Fn			: LCD_enuSendCommand
 * @brief		: it is used to send command to LCD
 * @param [in]	: Copy_u8Command --> it is specify command which send to LCD
 * @retval		: ES_t --> it returns the state of excution of this function
 * @note		: none
 ******************************************************************************
**/
ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	/* RS --> LOW to write Command */
	Local_enuErrorState = DIO_enuSetPinVal(RS_PORT, RS_PIN, DIO_u8LOW);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	/* Call Latch Function */
	Local_enuErrorState = LCD_enuLatch(Copy_u8Command);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

/**
 ******************************************************************************
 * @Fn			: LCD_enuLatch
 * @brief		: it is used to execute the common lines between display char and send command
 * @param [in]	: Copy_u8Data --> it is specify command or data which send to LCD
 * @retval		: ES_t --> it returns the state of excution of this function
 * @note		: none
 ******************************************************************************
**/
static ES_t LCD_enuLatch(u8 Copy_u8Data)
{	
	ES_t Local_enuErrorState = ES_NOK;
	
	/* RW --> LOW to write */
	Local_enuErrorState = DIO_enuSetPinVal(RW_PORT, RW_PIN, DIO_u8LOW);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	/* Enable --> HIGH */
	Local_enuErrorState = DIO_enuSetPinVal(EN_PORT, EN_PIN, DIO_u8HIGH);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	#if LCD_MODE == EIGHT_BIT
	/* Write Command to Data Pins */
	Local_enuErrorState = DIO_enuSetPinVal(D7_PORT, D7_PIN, ((Copy_u8Data >> D7_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinVal(D6_PORT, D6_PIN, ((Copy_u8Data >> D6_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinVal(D5_PORT, D5_PIN, ((Copy_u8Data >> D5_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinVal(D4_PORT, D4_PIN, ((Copy_u8Data >> D4_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinVal(D3_PORT, D3_PIN, ((Copy_u8Data >> D3_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinVal(D2_PORT, D2_PIN, ((Copy_u8Data >> D2_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	Local_enuErrorState = DIO_enuSetPinVal(D1_PORT, D1_PIN, ((Copy_u8Data >> D1_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinVal(D0_PORT, D0_PIN, ((Copy_u8Data >> D0_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	#elif LCD_MODE == FOUR_BIT
	u8 Local_u8FourBitData = 0;
	/* Send Data from D7..D4 */
	Local_u8FourBitData = (Copy_u8Data & 0xF0);
	Local_enuErrorState = DIO_enuSetPinVal(D7_PORT, D7_PIN, ((Local_u8FourBitData >> D7_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinVal(D6_PORT, D6_PIN, ((Local_u8FourBitData >> D6_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinVal(D5_PORT, D5_PIN, ((Local_u8FourBitData >> D5_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinVal(D4_PORT, D4_PIN, ((Local_u8FourBitData >> D4_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	LCD_vidTrigger_LATCH();
	_delay_ms(1);
	
	/* Send Data from D3..D0 */
	Local_u8FourBitData = (Copy_u8Data << FOUR_BIT);
	Local_enuErrorState = DIO_enuSetPinVal(D7_PORT, D7_PIN, ((Local_u8FourBitData >> D7_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinVal(D6_PORT, D6_PIN, ((Local_u8FourBitData >> D6_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinVal(D5_PORT, D5_PIN, ((Local_u8FourBitData >> D5_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	Local_enuErrorState = DIO_enuSetPinVal(D4_PORT, D4_PIN, ((Local_u8FourBitData >> D4_POS) & MASK_BIT));
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
		
	#else
	#error "LCD Mode has a wrong configuration"
	#endif
	
	_delay_ms(1);
	DIO_enuSetPinVal(EN_PORT, EN_PIN, DIO_u8LOW);
	_delay_ms(1);
	
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

static void LCD_vidTrigger_LATCH(void)
{
	/* Enable EN --> it works at Rising Edge */
	DIO_enuSetPinVal(EN_PORT, EN_PIN, DIO_u8LOW);
	_delay_ms(10);
	DIO_enuSetPinVal(EN_PORT, EN_PIN, DIO_u8HIGH);
}

/**
 ******************************************************************************
 * @Fn			: LCD_inlenuSendCommand
 * @brief		: it is used to send command to LCD but this is belong to Developer not user
 * @param [in]	: Copy_u8Command --> it is specify command which send to LCD
 * @retval		: ES_t --> it returns the state of excution of this function
 * @note		: none
 ******************************************************************************
**/
static inline ES_t LCD_inlenuSendCommand(u8 Copy_u8Command)
{
	ES_t Local_enuErrorState = ES_NOK;
		
	/* RS --> LOW to write Command */
	Local_enuErrorState = DIO_enuSetPinVal(RS_PORT, RS_PIN, DIO_u8LOW);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;	

	/* Call Latch Function */
	Local_enuErrorState = LCD_enuLatch(Copy_u8Command);
	if(Local_enuErrorState != ES_OK)
		return Local_enuErrorState;
	
	Local_enuErrorState = ES_OK;	
	return Local_enuErrorState;
}

/**
 ******************************************************************************
 * @Fn			: LCD_enuGoToPosition
 * @brief		: it is used to move cursor to a specific position
 * @param [in]	: Copy_u8Line --> it is specify the line which cursor move to it
 * @param [in]	: Copy_u8Position --> it is specify the position which cursor move to it
 * @retval		: ES_t --> it returns the state of excution of this function
 * @note		: none
 ******************************************************************************
**/
ES_t LCD_enuGoToPosition(u8 Copy_u8Line, u8 Copy_u8Position)
{
    ES_t Local_enuErrorState = ES_NOK;

    if (Copy_u8Position < 20) // Check if position is within the line range
    {
        if (Copy_u8Line == LCD_FIRST_LINE)
        {
            Local_enuErrorState = LCD_inlenuSendCommand(LCD_BEGIN_AT_FIRST_ROW + Copy_u8Position);
            if (Local_enuErrorState != ES_OK)
                return Local_enuErrorState;

            LCD_u8PosCounter = Copy_u8Position;
        }
        else if (Copy_u8Line == LCD_SECOND_LINE)
        {
            Local_enuErrorState = LCD_inlenuSendCommand(LCD_BEGIN_AT_SECOND_ROW + Copy_u8Position);
            if (Local_enuErrorState != ES_OK)
                return Local_enuErrorState;

            LCD_u8PosCounter = Copy_u8Position + 20;
        }
        else if (Copy_u8Line == LCD_THIRD_LINE)
        {
            Local_enuErrorState = LCD_inlenuSendCommand(LCD_BEGIN_AT_THIRD_ROW + Copy_u8Position);
            if (Local_enuErrorState != ES_OK)
                return Local_enuErrorState;

            LCD_u8PosCounter = Copy_u8Position + 40;
        }
        else if (Copy_u8Line == LCD_FOURTH_LINE)
        {
            Local_enuErrorState = LCD_inlenuSendCommand(LCD_BEGIN_AT_FOURTH_ROW + Copy_u8Position);
            if (Local_enuErrorState != ES_OK)
                return Local_enuErrorState;

            LCD_u8PosCounter = Copy_u8Position + 60;
        }
    }

    Local_enuErrorState = ES_OK;
    return Local_enuErrorState;
}
/**
 ******************************************************************************
 * @Fn			: LCD_enuGoToPosition
 * @brief		: it is used to check the position of the cursor
 * @retval		: ES_t --> it returns the state of excution of this function
 * @note		: none
 ******************************************************************************
**/
static void LCD_vidCheckPosition(void)
{
    if (LCD_u8PosCounter == 20)
    {
        LCD_enuGoToPosition(LCD_SECOND_LINE, 0);
        LCD_u8PosCounter++;
    }
    else if (LCD_u8PosCounter == 40)
    {
        LCD_enuGoToPosition(LCD_THIRD_LINE, 0);
        LCD_u8PosCounter++;
    }
    else if (LCD_u8PosCounter == 60)
    {
        LCD_enuGoToPosition(LCD_FOURTH_LINE, 0);
        LCD_u8PosCounter++;
    }
    else if (LCD_u8PosCounter == 80)
    {
        LCD_inlenuSendCommand(LCD_Clear_Display);
        LCD_enuGoToPosition(LCD_FIRST_LINE, 0);
        LCD_u8PosCounter = 0;
    }
    else
    {
        LCD_u8PosCounter++;
    }
}

/**
 ******************************************************************************
 * @Fn			: LCD_vidClearScreen
 * @brief		: it is used to clear the display
 * @retval		: none
 * @note		: none
 ******************************************************************************
**/
void LCD_vidClearScreen(void)
{
	LCD_inlenuSendCommand(LCD_Clear_Display);
	LCD_u8PosCounter = 0;
}

/**
 ******************************************************************************
 * @Fn			: LCD_enuWriteString
 * @brief		: it is used to write a string
 * @param [in]	: Copy_pu8Str --> it is a pointer to the string that we will display it.
 * @retval		: ES_t --> it returns the state of excution of this function
 * @note		: none
 ******************************************************************************
**/
ES_t LCD_enuWriteString(u8 *Copy_pu8Str)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_pu8Str != NULL)
	{
		while(*Copy_pu8Str != '\0')
		{
			Local_enuErrorState = LCD_enuDisplayChar(*Copy_pu8Str);
			if(Local_enuErrorState != ES_OK)
				return Local_enuErrorState;
			Copy_pu8Str++;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		return ES_NULL_POINTER;
	}
	
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

/**
 ******************************************************************************
 * @Fn			: LCD_enuWriteNumber
 * @brief		: it is used to write a number
 * @param [in]	: Copy_s32Number --> it is the number that we will display it.
 * @retval		: ES_t --> it returns the state of excution of this function
 * @note		: none
 ******************************************************************************
**/
ES_t LCD_enuWriteIntNumber(s32 Copy_s32Number)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_As8Container[16];
	u8 Local_u8Iterator;
	
	sprintf(Local_As8Container, "%d", Copy_s32Number);
	
	for(Local_u8Iterator = 0; Local_As8Container[Local_u8Iterator] != '\0'; Local_u8Iterator++)
	{
		Local_enuErrorState = LCD_enuDisplayChar(Local_As8Container[Local_u8Iterator]);
	}
	
	return Local_enuErrorState;
}

ES_t LCD_enuWriteFloatNumber(f32 Copy_f32Number)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	f32 Local_f32FracNum = Copy_f32Number - (u32)Copy_f32Number;
	s32 Local_s32IntNum = Copy_f32Number - Local_f32FracNum;
	LCD_enuWriteIntNumber(Local_s32IntNum);
	LCD_enuDisplayChar('.');
	LCD_enuWriteIntNumber(Local_f32FracNum * 100000);
	
	return Local_enuErrorState;
}

ES_t LCD_enuCustomCharacter(u8 *Copy_ArrCustomChar)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	LCD_inlenuSendCommand(64);
	
	while(*Copy_ArrCustomChar != 0)
	{
		LCD_enuDisplayChar(*Copy_ArrCustomChar);
		Copy_ArrCustomChar++;
	}
	
	LCD_inlenuSendCommand(LCD_BEGIN_AT_FIRST_ROW);
	LCD_enuDisplayChar(0);
	
	return Local_enuErrorState;
}
