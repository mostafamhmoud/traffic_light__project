/*
 * interrupt.h
 *
 * Created: 09/29/22 9:49:13 PM
 *  Author: LENOVO
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../registers.h"

//#define ISR(vector , ...)             \
    void vector (void) __attribute__ ((signal , __INTR_ATTRS)) __VA_ARGS__; \
	void vector(void)
	
//#define ISR(vector , ...)             \
void vector(void) __attribute__((signal)) ; \
void vector(void)	
	
	
// EXTERNAL interrupt vectors
	
#define INT0_vect _VECTOR_1
#define INT1_vect _VECTOR_2
#define INT2_vect _VECTOR_3



// declaring functions 
#define  low_level             0
#define  Any_logical_change    1
#define  falling_edge          2
#define  rising_edge           3


uint8_t INT0_init(uint8_t sense_control) ;
uint8_t INT1_init(uint8_t sense_control) ;
uint8_t INT2_init(uint8_t sense_control) ; 

#define GLIEN() (SREG |= (1<<7))       // global interrupt enable 



#endif /* INTERRUPT_H_ */