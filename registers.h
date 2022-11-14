/*
 * registers.h
 *
 * Created: 01/11/2022 09:36:28
 *  Author: Nader
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

//PORT A REGISTERS :
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)

//PORT B  REGISTERS:
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

//PORT C  REGISTERS :
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

//PORT D REGISTERS :
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)

//TIMER 0 REGISTERS :
#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)
#define TIFR *((volatile uint8_t*)0x58)

// External Interrupts registers
#define MCUCR *((volatile uint8_t*)0x55) //8-bit register
#define MCUCSR *((volatile uint8_t*)0x54) //8-bit register
#define GICR *((volatile uint8_t*)0x5B) //8-bit register
#define GIFR *((volatile uint8_t*)0xSA) //8-bit register

// statues register
#define SREG *((volatile uint8_t*)0x5F) //8-bit register


//pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7



#endif /* REGISTERS_H_ */