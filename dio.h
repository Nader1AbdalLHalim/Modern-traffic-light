/*
 * dio.h
 *
 * Created: 01/11/2022 09:31:13
 *  Author: Nader
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../UTILITIES/registers.h"
#include "../../UTILITIES/types.h"
#include<util/delay.h>
//#define F_CPU 1000000 u 
//all internal driver typedefs
//all macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//direction defines
#define IN  0
#define OUT 1

//value defines
#define LOW   0
#define high 1


void DIO_init(uint8_t portnumber,uint8_t pinnumber,uint8_t direction);
void DIO_write(uint8_t portnumber,uint8_t pinnumber,uint8_t value);
void DIO_toggle(uint8_t portnumber,uint8_t pinnumber);
void DIO_read(uint8_t portnumber,uint8_t pinnumber,uint8_t *value);



#endif /* DIO_H_ */