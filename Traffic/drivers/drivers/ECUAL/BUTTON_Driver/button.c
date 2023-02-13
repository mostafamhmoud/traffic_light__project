/*
 * button.c
 *
 * Created: 09/26/22 3:01:54 PM
 *  Author: LENOVO
 */ 
#include "button.h"

uint8_t BUTTON_init(uint8_t buttonPort , uint8_t buttonPin) 
{
	return DIO_init(buttonPort , buttonPin , IN) ;
}
uint8_t BUTTON_read(uint8_t buttonPort , uint8_t buttonPin , uint8_t *value) 
{
	return DIO_read(buttonPort , buttonPin , value) ;
}