/*
 * led.c
 *
 * Created: 01/11/2022 09:17:20
 *  Author: Nader
 */ 

#include "led.h"

void LED_init(uint8_t ledport , uint8_t ledpin) //led is an output
{
	DIO_init(ledport,ledpin,OUT);  //set direction of pin 4 to output
}

void LED_on(uint8_t ledport , uint8_t  ledpin)
{
	DIO_write(ledport , ledpin , high );  // pull high pin 4 or write 1 to it .
}

void LED_off(uint8_t ledport , uint8_t ledpin)
{
	DIO_write(ledport,ledpin,LOW);
}

void LED_toggle(uint8_t ledport , uint8_t ledpin)
{
	DIO_toggle( ledport,ledpin);
}

void LED_read(uint8_t ledport,uint8_t ledpin,uint8_t *value)
{
	DIO_read(ledport,ledpin,value);
}

void LED_blink(uint8_t ledport , uint8_t ledpin,uint8_t*MODE)
{
int x = 0;
while(x<=20 && *MODE==0)
{
	DIO_toggle( ledport,ledpin);
	_delay_ms(50);
	x++;
}
}
void LED_double_blink(uint8_t ledport , uint8_t ledpin, uint8_t ledport1 , uint8_t ledpin1)
{
	int x = 0;
	while(x<=20)
	{
	  DIO_toggle( ledport,ledpin);
	  DIO_toggle( ledport1,ledpin1);
	  _delay_ms(250);
	  x++;
	}
}

