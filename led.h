/*
 * led.h
 *
 * Created: 01/11/2022 09:16:59
 *  Author: Nader
 */ 


#ifndef LED_H_
#define LED_H_
#include "../BUTTON DRIVER/button.h"

void LED_init(uint8_t ledport , uint8_t ledpin);
void LED_on(uint8_t ledport , uint8_t ledpin);
void LED_off(uint8_t ledport , uint8_t ledpin);
void LED_toggle(uint8_t ledport , uint8_t ledpin);
void LED_blink(uint8_t ledport , uint8_t ledpin, uint8_t *MODE);
void LED_double_blink(uint8_t ledport , uint8_t ledpin, uint8_t ledport1 , uint8_t ledpin1);

//LED read
void LED_read(uint8_t ledport,uint8_t ledpin,uint8_t *value);




#endif /* LED_H_ */