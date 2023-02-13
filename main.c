/*
 * drivers.c
 *
 * Created: 09/24/22 2:03:06 PM
 * Author : LENOVO
 */ 

//#include <avr/io.h>

//#include <util/delay.h>

#include "ECUAL/BUTTON_Driver/button.h"
#include "ECUAL/LED_Driver/led.h" 
#include "MCAL/TIMER_Driver/timer.h"

#include "MCAL/INTERRUPT_Driver/interrupt.h"

#include "Application/App.h"



int main(void)
{
    app_start();
}


void __vector_1(void) __attribute__((signal)) ;

void __vector_1(void)
{
	pedestrian_mode();
	//timer0_prescaler(8);
	
}

