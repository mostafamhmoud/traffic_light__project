/*
 * interrupt.c
 *
 * Created: 09/29/22 9:49:29 PM
 *  Author: LENOVO
 */ 

#include "interrupt.h"
#include "../DIO_Driver/dio.h"

uint8_t INT0_init(uint8_t sense_control) 
{
	switch(sense_control)
	{
		case low_level:
		    clear_bit(MCUCR , ISC00) ; 
			clear_bit(MCUCR , ISC01) ;
			break;
		case Any_logical_change:
			 set_bit(MCUCR , ISC00) ;
			 clear_bit(MCUCR , ISC01) ;
			 break;
		case falling_edge:
		    clear_bit(MCUCR , ISC00) ;
		    set_bit(MCUCR , ISC01) ;
		    break;	
		case rising_edge:
		    set_bit(MCUCR , ISC00) ;
		    set_bit(MCUCR , ISC01) ;
		    break;	 
		default:
		    return ERROR;	
	}
	
	set_bit(GICR , INT0) ;
}
uint8_t INT1_init(uint8_t sense_control) ;
uint8_t INT2_init(uint8_t sense_control) ;