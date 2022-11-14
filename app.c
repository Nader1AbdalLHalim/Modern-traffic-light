/*
 * app.c
 *
 * Created: 01/11/2022 09:14:10
 *  Author: Nader
 */ 

#include "app.h"
void APP_init(void)
{
///LEDS for cars///
LED_init(PORT_A,PIN0);//green
LED_init(PORT_A,PIN1);//yellow
LED_init(PORT_A,PIN2);//red

///LEDS FOR PEDSTRIAN///
LED_init(PORT_B,PIN0);//green
LED_init(PORT_B,PIN1);//yellow
LED_init(PORT_B,PIN2);//red

///button///
// Set direction for button pin to input 0 //
button_init(PORT_D, PIN2);// where INT0 is located

///INTRUPT///
//3-Enable global interrupts - setting bit 7 in the status register to 1
//4- Choose the external interrupt sense - sense on rising edge.
/*5. Enable External interrupt 0 - INTO */
intrupt_init();
///TIMER///

//choose timer0 mode and set it to normal
timer0_mode();

int initial_value =65536 ;
//set time initial value according to calculations
timer0_init(initial_value);


}
uint8_t MODE = 0;

void APP_start(void)
{

   while(1)
   { 
	  ///NORMAL MODE///
	  ///green for cars///	   
     LED_on(PORT_A,PIN0); //green for cars
      int prescalling = 256;
      int overflownum = 77;  
	   
	    if( MODE == 1 )  		  
		{
					    //pedestrian mode///

		 LED_on(PORT_B,PIN2); // on pedestrian red led
         LED_double_blink( PORT_A, PIN1,  PORT_B, PIN1); // blinking yellow lights for cars and pedestrian for 5 second
		 LED_off(PORT_A,PIN1); // off yellow cars led
		 LED_off(PORT_B,PIN1); // off pedestrian yellow led
		 LED_off(PORT_A,PIN0);//turn off green cars led
		 LED_off(PORT_B,PIN2);//turn off red pedestrian led
		 LED_on(PORT_A,PIN2) ;// on red cars led
		 LED_on(PORT_B,PIN0); // on green led for pedestrian
		  timer0_start( prescalling); // five
		  timer0_delay(overflownum ); // seconds
		  timer0_off();// delay
		
		//////////////////////////////////////////////////////////
		
		 LED_off(PORT_A,PIN2); // off cars red led 
         LED_double_blink( PORT_A, PIN1,  PORT_B, PIN1); // blinking yellow lights for cars and pedestrian for 5 second
		 LED_off(PORT_A,PIN1); // off yellow cars led
		 LED_off(PORT_B,PIN1); // off pedestrian yellow led
		 LED_off(PORT_B,PIN0); // off green led for pedestrian  
		 LED_on(PORT_B,PIN2);  //on pedestrian red led
		 LED_on(PORT_A,PIN0);  //on cars green led
		 MODE = 0 ;
		}
	 //start time
     //set prescaler according to calculations
    timer0_start(prescalling);
		   
    //set number of needed overflows to achieve required time
	timer0_delay(overflownum);
		   
	//timer stop
	timer0_off();
		   
	LED_off(PORT_A,PIN0);//green for cars
	
	/// yellow for cars ///         
	if(MODE == 0)
	{	
	LED_blink(PORT_A,PIN1,&MODE);//yellow for cars blinking for 5 second.
	LED_off(PORT_A,PIN1);//yellow for cars
	}
	if(MODE==1)
	{
	  LED_double_blink( PORT_A, PIN1,  PORT_B, PIN1); // blinking yellow lights for cars and pedestrian for 5 second
	  LED_off(PORT_A,PIN1); // off yellow cars led
	  LED_off(PORT_B,PIN1); // off pedestrian yellow led
	  LED_on(PORT_A,PIN2); //red for cars
      LED_on(PORT_B,PIN0); //turn on pedestrian green light
	  timer0_start( prescalling); // five
	  timer0_delay(overflownum ); // seconds
	  timer0_off();// delay
	   ///////////////////////////////////////////////
	   
	   LED_off(PORT_A,PIN2); // off cars red led
	   LED_double_blink( PORT_A, PIN1,  PORT_B, PIN1); // blinking yellow lights for cars and pedestrian for 5 second
	   LED_off(PORT_A,PIN1); // off yellow cars led
	   LED_off(PORT_B,PIN1); // off pedestrian yellow led
	   LED_off(PORT_B,PIN0); // off green led for pedestrian
	   LED_on(PORT_B,PIN2);  //on pedestrian red led
	   LED_on(PORT_A,PIN0);  //on cars green led
	   timer0_start( prescalling); // five
	   timer0_delay(overflownum ); // seconds
	   timer0_off();// delay
	    LED_off(PORT_B,PIN2);  //off pedestrian red led
	    LED_off(PORT_A,PIN0);  //off cars green led
	   MODE = 0 ;
	}

	///red for cars ////	   
     LED_on(PORT_A,PIN2); //red for cars
        if( MODE == 1 )
		{
		  LED_on(PORT_B,PIN0); //turn on pedestrian green light
		  timer0_start( prescalling);
		  timer0_delay(overflownum );
		  timer0_off();
      
	  /////////////////////////////////////////
	  		  
 	      LED_off(PORT_A,PIN2); // off cars red led
          LED_double_blink( PORT_A, PIN1,  PORT_B, PIN1); // blinking yellow lights for cars and pedestrian for 5 second
 	      LED_off(PORT_A,PIN1); // off yellow cars led
 	      LED_off(PORT_B,PIN1); // off pedestrian yellow led
 	      LED_off(PORT_B,PIN0); // off green led for pedestrian
 	      LED_on(PORT_B,PIN2);  //on pedestrian red led
 	      LED_on(PORT_A,PIN0);  //on cars green led
		   MODE=0;
		}
    timer0_start( prescalling);
    timer0_delay(overflownum );
    timer0_off();
	LED_off(PORT_C,PIN4);//red for cars
	   
   }	

}


ISR(EXT_INT_0)
{
	if(MODE < 2)
	{
		MODE=1;
	}
	else
	{
		MODE = 0;
	}

}

