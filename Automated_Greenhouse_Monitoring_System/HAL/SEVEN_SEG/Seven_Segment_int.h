/**
 ******************************************************************************
 * @file           : Seven_Segment_int.h
 * @author         : Mostafa Edrees
 * @brief          : interface file of Seven Segment.
 * @date           : 10/20/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef SEVEN_SEGMENT_INT_H_
#define SEVEN_SEGMENT_INT_H_

ES_t Seven_Segment_enuInit(SEG_t *Copy_pAstrSEG_Config);

ES_t Seven_Segment_enuDisplayNumber(u8 Copy_SEG_ID, u8 Copy_u8Number);

ES_t Seven_Segment_enuEnableCommon(u8 Copy_SEG_ID);

ES_t Seven_Segment_enuDisableCommon(u8 Copy_SEG_ID);

ES_t Seven_Segment_enuEnableDot(u8 Copy_SEG_ID);

ES_t Seven_Segment_enuDisableDot(u8 Copy_SEG_ID);

ES_t Seven_Sement_enuTurnOFF(u8 Copy_SEG_ID);


#endif /* SEVEN_SEGMENT_INT_H_ */