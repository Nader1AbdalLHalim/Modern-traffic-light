/*
 * timer.h
 *
 * Created: 01/11/2022 09:35:20
 *  Author: Nader
 */ 


#ifndef TIMER_H_
#define TIMER_H_



#include "../INTRUPT DRIVER/intrupt.h"
//to determine wanted mode in this program normal mode
void timer0_mode(void);
//to set timer initial value according to calculations
void timer0_init(int initial_value);
//to determine used prescaler in calculayions
void timer0_start(int prescalling);
//to start counntig till the target time
void timer0_delay(int overflownum );
//to get timer state .
void timer0_state(uint32_t prescalling,uint8_t *value );
//to reset timer.
void timer0_off(void);







#endif /* TIMER_H_ */