/*
 * timer.h
 *
 * Created: 09/28/22 12:13:44 AM
 *  Author: LENOVO
 */ 



#ifndef TIMER_H_
#define TIMER_H_

#include "../../registers.h"
#include "../DIO_Driver/dio.h"

#define off 0 

#define Timer_State (TCCR0 & 0b00000111) // TCCR0 & 0b00000111 // checking if last 3 bits is zero or not 
// if zero timer off else timer on 

typedef enum modes
{
    Normal , CTC , Fast_Pwm , Phase_Correct
}EN_mode_t;

uint8_t timer0_init(EN_mode_t mode) ;
uint8_t timer0_prescaler(uint16_t prescaler) ;
void timer0_delay_ms(uint16_t delay) ;




#endif /* TIMER_H_ */