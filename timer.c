/*
 * timer.c
 *
 * Created: 01/11/2022 09:35:35
 *  Author: Nader
 */ 
#include "timer.h"

void timer0_mode(void)
{
	//CHOSSE TIMER MODE :
	TCCR0 = 0x00;
}


void timer0_init(int initial_value)
{
	//TIMER SET INITIAL VALUE :
	//initial_value = 65536
	TCNT0 = initial_value;
}


void timer0_start(int prescalling)
{
	//START TIMER >>> PRESCALING SITTING
	//TCCR0 |= (1<<2); // no prescaling $$ sit bit CS00 to 1 (256)
	switch(prescalling)
	{
		case 1 :
		TCCR0 |= (1<<0); //set bit0 (cs00) in TCCR0 register to 1  [no prescaler]
		break;
		
		case 8 :
		TCCR0 |= (1<<1); //set bit1 (cs01) in TCCR0 register to 1  [/8]
		break;
		
		case 64 :
		TCCR0 |= (1<<0); //set bit1 (cs00) in TCCR0 register to 1  [/64]
		TCCR0 |= (1<<1); //set bit1 (cs01) in TCCR0 register to 1  [/64]
		break;
		
		case 256 :
		TCCR0 |= (1<<2); //set bit1 (cs02) in TCCR0 register to 1  [/256]
		break;
		
		case 1024 :
		TCCR0 |= (1<<0); //set bit1 (cs00) in TCCR0 register to 1  [/1024]
		TCCR0 |= (1<<2); //set bit1 (cs02) in TCCR0 register to 1  [/1024]
		break;
		
		default:
		//do no thing .
		break;
	}

}


void timer0_delay(int overflownum )
{
	int x;
	while( x < overflownum)
	{
		//stop after one over flow where Tmax= 2 power of 8 = 256 micro second
		//wait till over flag is set using while busy loop
		
		while((TIFR & (1<<0)) == 0 );
		
		//clear over flow flag by set bit to 1
		TIFR |= (1<<0);
		
		x++;
		
	}
	x = 0 ;
	

}



void timer0_off(void)
{
	TCNT0 =65536;
	//if there is initial time well be entered before timer stop
	//TIMER STOP
	TCCR0 = 0x00;
}

void timer0_state(uint32_t prescalling , uint8_t *value )
{
	uint8_t x=0 , y=0 ;
	switch(prescalling)
	{
		case 1 :
		*value= (TCCR0 & (1<<0))>>0; //get state read bit 0 or 1  [no prescaler]
		break;
		
		case 8 :
		*value= (TCCR0 & (1<<1))>>1; //get state read bit 0 or 1  [/8]
		break;
		
		case 64 :
		x= (TCCR0 & (1<<0))>>0; //get state read bit 0 or 1  [/64]
		y= (TCCR0 & (1<<1))>>1; //get state read bit 0 or 1  [/64]
		*value= x && y ;
		break;
		
		case 256 :
		*value= (TCCR0 & (1<<2))>>2; //get state read bit 0 or 1 [/256]
		break;
		
		case 1024 :
		x = (PINA & (1<<0))>>0; //get state read bit 0 or 1 [/1024]
		y = (PINA & (1<<2))>>2; //get state read bit 0 or 1   [/1024]
		*value = x && y ;
		break;
		
		default:
		//do no thing .
		break;
	}

}
