/*
 * dio.c
 *
 * Created: 01/11/2022 09:31:36
 *  Author: Nader
 */ 
#include "dio.h"

void DIO_init(uint8_t portnumber , uint8_t pinnumber , uint8_t direction)
{
	switch(portnumber)
	{
		case PORT_A :
		if(direction == IN)
		{
			DDRA &= ~(1<<pinnumber)	; //clear bit
		}
		else if (direction == OUT)
		{
			DDRA |= (1<<pinnumber)   ;  //set bit
		}
		else
		{
			//error handling.
		}
		break;

		case PORT_B :
		if(direction == IN)
		{
			DDRB &= ~(1<<pinnumber)	;
		}
		else if (direction == OUT)
		{
			DDRB|=(1<<pinnumber)    ;
		}
		else
		{
			//error handling.
		}
		break;
		
		case PORT_C :
		if(direction == IN)
		{
			DDRC &= ~(1<<pinnumber)	; //clear bit 0
		}
		else if (direction == OUT)
		{
			DDRC |= (1<<pinnumber)  ; // set bit 1
		}
		else
		{
			//error handling.
		}
		break;
		
		case PORT_D :
		if(direction == IN)
		{
			DDRD &= ~(1<<pinnumber)	;
		}
		else if (direction == OUT)
		{
			DDRD |= (1<<pinnumber)    ;
		}
		else
		{
			//error handling.
		}
		break;

	}

}
void DIO_write( uint8_t portnumber , uint8_t pinnumber , uint8_t value)
{
	switch(portnumber)
	{
		case PORT_A :
		if(value == LOW)
		{
			PORTA &= ~(1<<pinnumber)	;
		}
		else if (value == high )
		{
			PORTA |= (1<<pinnumber)   ;
		}
		else
		{
			//error handling.
		}
		break;

		case PORT_B :
		if(value ==  LOW)
		{
			PORTB &= ~(1<<pinnumber)	;
		}
		else if (value == high )
		{
			PORTB|=(1<<pinnumber)    ;
		}
		else
		{
			//error handling.
		}
		break;
		
		case PORT_C :
		if(value ==  LOW)
		{
			PORTC &= ~(1<<pinnumber)	;
		}
		else if (value == high)
		{
			PORTC |= (1<<pinnumber)    ;
		}
		else
		{
			//error handling.
		}
		break;
		
		case PORT_D :
		if(value ==  LOW)
		{
			PORTD &= ~(1<<pinnumber)	;
		}
		else if (value ==  high)
		{
			PORTD |= (1<<pinnumber)    ;
		}
		else
		{
			//error handling.
		}
		break;

	}
	
}
void DIO_toggle(uint8_t portnumber,uint8_t pinnumber)
{
	/*set direction of pinnumber in portnumber to output*/
	void DIO_init(uint8_t portnumber , uint8_t pinnumber , uint8_t HIGH);

	switch(portnumber)
	{
		case PORT_A:
		PORTA ^= (1<<pinnumber);
		//_delay_ms(50);
		break;
		case PORT_B:
		PORTB ^= (1<<pinnumber);
		break;
		case PORT_C:
		PORTC ^= (1<<pinnumber);
		break;
		case PORT_D:
		PORTD ^= (1<<pinnumber);
		break;
		default:
		//error handling
		break;
	}

}


void DIO_read(uint8_t portnumber,uint8_t pinnumber,uint8_t *value)
{
	switch(portnumber)
	{
		case PORT_A:
		*value= (PINA & (1<<pinnumber))>>pinnumber; //get state read bit 0 or 1
		return value;
		break;
		case PORT_B:
		*value =  ( PINB & (1<<pinnumber))>>pinnumber;//get state read bit 0 or 1
		break;
		case PORT_C:
		*value =  ( PINC & (1<<pinnumber))>>pinnumber;//get state read bit 0 or 1
		break;
		case PORT_D:
		*value =  ( PIND & (1<<pinnumber))>>pinnumber;//get state read bit 0 or 1
		break;
		default:
		//error handling
		break;
	}
	//if pinnumber is connected to vcc result is 1    .
	//if pinnumber is connected to ground result is 0 .
}