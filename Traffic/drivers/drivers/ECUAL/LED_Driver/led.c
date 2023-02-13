/*
 * led.c
 *
 * Created: 09/26/22 2:10:08 PM
 *  Author: LENOVO
 */ 

#include "led.h"

uint8_t LED_init(uint8_t ledPort , uint8_t ledPin) 
{
	uint8_t state ;
	state = DIO_init(ledPort , ledPin , OUT) ;
	if (state == ERROR)
	{
		return ERROR ;
	}
}
uint8_t LED_on(uint8_t ledPort , uint8_t ledPin) 
{
	uint8_t state ;
	state = DIO_write(ledPort , ledPin , HIGH) ;
	if (state == ERROR)
	{
		return ERROR ;
	}	
}
uint8_t LED_off(uint8_t ledPort , uint8_t ledPin) 
{
	uint8_t state ;
	state = DIO_write(ledPort , ledPin , LOW) ;

	if (state == ERROR)
	{
		return ERROR ;
	}	
}
uint8_t LED_toggle(uint8_t ledPort , uint8_t ledPin) 
{
	uint8_t state ;
	
	state = DIO_toggle(ledPort , ledPin) ;

	if (state == ERROR)
	{
		return ERROR ;
	}	
}
