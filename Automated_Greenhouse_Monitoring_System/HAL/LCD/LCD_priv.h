/**
 ******************************************************************************
 * @file           : LCD_priv.h
 * @author         : Mostafa Edrees
 * @brief          : Private file of LCD.
 * @date           : 11/1/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#include <stdio.h>
#include <stdlib.h>

#define EIGHT_BIT			8
#define FOUR_BIT			4

#define D7_POS				7
#define D6_POS				6
#define D5_POS				5
#define D4_POS				4
#define D3_POS				3
#define D2_POS				2
#define D1_POS				1
#define D0_POS				0

#define MASK_BIT			1

static inline ES_t LCD_inlenuSendCommand(u8 Copy_u8Command);
static ES_t LCD_enuLatch(u8 Copy_u8Data);
static void LCD_vidCheckPosition(void);
static void LCD_vidTrigger_LATCH(void);


/* Function Set */
#define LCD_8Bit_TwoLine_5_7CharFont				0x38
#define LCD_4Bit_TwoLine_5_7CharFont				0x28

/* Display ON/OFF Control */
#define LCD_DisplayOn_CursorOn_Blinking				0x0F
#define LCD_DisplayOn_CursorOn_NoBlinking			0x0E
#define LCD_DisplayOn_CursorOff_NoBlinking			0x0C

/* Display Clear */
#define LCD_Clear_Display							0x01

/* Entry Mode Set */
#define LCD_Increase_NoShift						0x06
#define LCD_Decrease_NoShift						0x04
#define LCD_Increase_ShiftLeft						0x07
#define LCD_Increase_ShiftRight						0x05

/* Lines */
#define LCD_FIRST_LINE								0
#define LCD_SECOND_LINE								1

#define LCD_BEGIN_AT_FIRST_ROW						0x80
#define LCD_BEGIN_AT_SECOND_ROW						0xC0


#endif /* LCD_PRIV_H_ */