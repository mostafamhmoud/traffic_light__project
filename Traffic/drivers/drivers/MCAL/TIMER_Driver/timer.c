/*
 * timer.c
 *
 * Created: 09/28/22 12:13:28 AM
 *  Author: LENOVO
 */
 
#include "timer.h"

uint8_t timer0_init(EN_mode_t mode)
{
	switch(mode)
	{
		case Normal:
		    clear_bit(TCCR0 , WGM00) ;
			clear_bit(TCCR0 , WGM01) ;
			break;
		
		case CTC:
		    clear_bit(TCCR0 , WGM00) ;
		    set_bit(TCCR0 , WGM01) ;
		    break;
		
		case Fast_Pwm:
		    set_bit(TCCR0 , WGM00) ;
		    set_bit(TCCR0 , WGM01) ;
	     	break;		

		case Phase_Correct:
		    set_bit(TCCR0 , WGM00) ;
		    clear_bit(TCCR0 , WGM01) ;
		    break;			 
		default:                     
		    return ERROR;
		   	
	}
}

uint8_t timer0_prescaler(uint16_t prescaler) 
{
	switch(prescaler)
	{
		case 0:                       // stop timer/counter
		    clear_bit(TCCR0 , CS00) ;
			clear_bit(TCCR0 , CS01) ;
			clear_bit(TCCR0 , CS02) ;
		    break;
		case 1:
		    set_bit(TCCR0 , CS00) ;
			clear_bit(TCCR0 , CS01) ;
			clear_bit(TCCR0 , CS02) ;	
			break;
		case 8:
		    clear_bit(TCCR0 , CS00) ;
			set_bit(TCCR0 , CS01) ;
			clear_bit(TCCR0 , CS02) ;	
			break;
		case 64:
		    set_bit(TCCR0 , CS00) ;
			set_bit(TCCR0 , CS01) ;
			clear_bit(TCCR0 , CS02) ;	
			break;
		case 256:
		    clear_bit(TCCR0 , CS00) ;
			clear_bit(TCCR0 , CS01) ;
			set_bit(TCCR0 , CS02) ;	
			break;
		case 1024:
		    set_bit(TCCR0 , CS00) ;
			clear_bit(TCCR0 , CS01) ;
			set_bit(TCCR0 , CS02) ;	
			break;
		default:                           // stop timer 
		    return ERROR;		
	}
}

// we have 8mhz clock so to facilitate calculation we will make prescaler 8 so one tick is 1us

void timer0_delay_ms(uint16_t delay)   
{
	// init timer 0 
	timer0_init(Normal) ;
	
	uint16_t overflows_counter = 0 ;
	uint16_t num_of_overflows ;
	
	num_of_overflows = (delay/256.0)*1000 ;      // we will convert delay from ms to us
	
	timer0_prescaler(8) ;                        // start timer0
	while(overflows_counter < num_of_overflows)
	{
		// if timer is stopped suddenly for example during interrupt exit delay 
		if(Timer_State == off) break;
		 while((TIFR & (1<<TOV0)) == 0)
		 {
			 if(Timer_State == off) break;
		 }
		 
		 set_bit(TIFR , TOV0);                   // TOV0 is cleared by writing a logic one to the flag. 
		 overflows_counter++;
	}
	
	timer0_prescaler(0) ;                        // stop timer 
}