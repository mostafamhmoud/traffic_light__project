/*
 * led.h
 *
 * Created: 09/26/22 2:09:53 PM
 *  Author: LENOVO
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_Driver/dio.h"

uint8_t LED_init(uint8_t ledPort , uint8_t ledPin) ;
uint8_t LED_on(uint8_t ledPort , uint8_t ledPin) ;
uint8_t LED_off(uint8_t ledPort , uint8_t ledPin) ;
uint8_t LED_toggle(uint8_t ledPort , uint8_t ledPin) ;



#endif /* LED_H_ */