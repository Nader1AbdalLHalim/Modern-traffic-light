/*
 * button.h
 *
 * Created: 01/11/2022 09:17:51
 *  Author: Nader
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/TIMER DRIVER/timer.h"


//initializing
void button_init(uint8_t buttonport,uint8_t buttonpin);

//button read
void button_read(uint8_t buttonport,uint8_t buttonpin,uint8_t *value);




#endif /* BUTTON_H_ */