/*
 * intrupt.c
 *
 * Created: 13/11/2022 17:49:27
 *  Author: Nader
 */ 
#include "intrupt.h"
void intrupt_init(void)
{
	//Enable global interrupts - setting bit 7 in the status register to 1
	SREG |=(1<<7);
	//4- Choose the external interrupt sense - sense on rising edge.
	MCUCR |= (1<<0) | (1<<1);
	/*5. Enable External interrupt 0 - INTO */
	GICR |= (1<<6);

}