/*
 * GIE_priv.h
 *
 * Created: 12/13/2023 11:40:26 PM
 *  Author: Mostafa Edrees
 */ 


#ifndef GIE_PRIV_H_
#define GIE_PRIV_H_

#define SREG				*((volatile u8 *)0x5F)

/*
Bit 7 – I: Global Interrupt Enable
The Global Interrupt Enable bit must be set for the interrupts to be enabled.
The individual interrupt enable control is then performed in separate control registers. If the Global Interrupt Enable
Register is cleared, none of the interrupts are enabled independent of the individual interrupt enable settings.
*/

#define GIE_I				7

#define MASK_BIT			1

#endif /* GIE_PRIV_H_ */