
/*
 * button.h
 *
 * Created: 09/26/22 3:01:34 PM
 *  Author: LENOVO
 */ 

#ifndef BUTTON_H
#define BUTTON_H

#include "../../MCAL/DIO_Driver/dio.h"

uint8_t BUTTON_init(uint8_t buttonPort , uint8_t buttonPin) ;
uint8_t BUTTON_read(uint8_t buttonPort , uint8_t buttonPin , uint8_t *value) ;

#endif