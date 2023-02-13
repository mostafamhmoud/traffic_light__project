/*
 * registers.h
 *
 * Created: 09/24/22 4:50:23 PM
 *  Author: LENOVO
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "std_header.h"

/**************************************************/
/* DIO PINS                                */
/**************************************************/

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9

/**************************************************/
/* DIO registers                                  */
/**************************************************/

// define all registers related to PORTA 

#define PORTA *((volatile uint8_t*)(0x3B))
#define DDRA *((volatile uint8_t*)(0x3A))
#define PINA *((volatile uint8_t*)(0x39))

// define all registers related to PORTB

#define PORTB *((volatile uint8_t*)(0x38))
#define DDRB *((volatile uint8_t*)(0x37))
#define PINB *((volatile uint8_t*)(0x36))

// define all registers related to PORTC

#define PORTC *((volatile uint8_t*)(0x35))
#define DDRC *((volatile uint8_t*)(0x34))
#define PINC *((volatile uint8_t*)(0x33)) 
 
// define all registers related to PORTD

#define PORTD *((volatile uint8_t*)(0x32))
#define DDRD *((volatile uint8_t*)(0x31))
#define PIND *((volatile uint8_t*)(0x30))


/**************************************************/
/* TIMER registers                                  */
/**************************************************/

// TIMER0 registers

// TIMER0 configuration register
#define TCCR0 *((volatile uint8_t*)(0x53))

#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7

// TIMER0 data register 
#define TCNT0 *((volatile uint8_t*)(0x52))


#define OCR0 *((volatile uint8_t*)(0x5C))

// Interrupt Flag Register
#define TIFR *((volatile uint8_t*)(0x58))

#define TOV0 0
#define OCF0 1
#define TOV1 2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5
#define TOV2 6
#define OCF2 7

#define TIMSK *((volatile uint8_t*)(0x59))


/**************************************************/
/* INTERRUPTS registers                                  */
/**************************************************/

//  External Interrupts

#define MCUCR *((volatile uint8_t*)(0x55))
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define SREG *((volatile uint8_t*)(0x5F))
#define GLIE 7

#define MCUCSR *((volatile uint8_t*)(0x54))
#define ISC2 6

#define GICR *((volatile uint8_t*)(0x5B))

#define INT0 6
#define INT1 7
#define INT2 5

#define GIFR *((volatile uint8_t*)(0x5A))

#define INTF0 6
#define INTF1 7
#define INTF2 5




#endif /* REGISTERS_H_ */