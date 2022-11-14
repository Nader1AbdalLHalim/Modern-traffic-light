/*
 * button.c
 *
 * Created: 01/11/2022 09:18:10
 *  Author: Nader
 */ 

#include "button.h"

void button_init(uint8_t buttonport,uint8_t buttonpin) //button is an input
{
	DIO_init( buttonport , buttonpin ,IN); //set direction of pin  to input 0
}

//button read
void button_read(uint8_t buttonport,uint8_t buttonpin,uint8_t *value)
{
	DIO_read(buttonport,buttonpin,value);
}