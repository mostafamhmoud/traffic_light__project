/*
 * App_Start.c
 *
 * Created: 10/05/22 6:25:16 PM
 *  Author: LENOVO
 */ 

#include "App.h"

#define time 5000  // 5 seconds delay

/**************************************************/
/* this functions initializes leds and buttons                              */
/**************************************************/
uint8_t leds_init(void)
{
	if(BUTTON_init(PORT_D , PIN2) == ERROR) return ERROR ;
	
	if(LED_init(PORT_A , PIN0) == ERROR ) return ERROR;   // car_green init
	if(LED_init(PORT_A , PIN1) == ERROR ) return ERROR;   // car_yellow init
	if(LED_init(PORT_A , PIN2) == ERROR ) return ERROR;   // car_red init
	
	if(LED_init(PORT_B , PIN0) == ERROR ) return ERROR;   // pedestrian_green init
	if(LED_init(PORT_B , PIN1) == ERROR ) return ERROR;   // pedestrian_yellow init
	if(LED_init(PORT_B , PIN2) == ERROR ) return ERROR;   // pedestrian_red init
}

/**************************************************/
/* this function makes yellow blinking for 5s in car mode                             */
/**************************************************/
uint8_t car_yellow_blink(void)  // blink for 5s
{
	uint8_t num_time = 0 ;
	while(num_time < 25)       // (5000ms / 100ms) = 50
	{
		if(pedestrian_state == finished) break;  // if you just finish pedestrian mode breek any current delay
		if(car_yellow_on() == ERROR) return ERROR ;
		timer0_delay_ms(100) ;
		if(car_yellow_off() == ERROR ) return ERROR;
		timer0_delay_ms(100) ;
		
		num_time++ ;
	}
}

/**************************************************/
/* this function makes yellow blinking for 5s pedestrian mode                            */
/**************************************************/
uint8_t pedestrian_yellow_blink(void)  // blink for 5s
{
	uint8_t num_time = 0 ;
	while(num_time < 25)       // (5000ms / 200ms) = 25
	{
		if(car_yellow_on() == ERROR ) return ERROR ;
		timer0_delay_ms(100) ;
		if(car_yellow_off() == ERROR ) return ERROR;
		timer0_delay_ms(100) ;
		
		num_time++ ;
	}
}

/**************************************************/
/* this function makes green ON for 5s                             */
/**************************************************/
uint8_t car_traffic_green(void)
{
	car_color_state = green_on;
	if(car_green_on() == ERROR ) return ERROR ;
	timer0_delay_ms(time);
	if(car_green_off() == ERROR ) return ERROR ;
}
/**************************************************/
/* this function makes yellow blinking for 5s in car mode                             */
/**************************************************/
uint8_t car_traffic_yellow(void)
{
	car_color_state = yellow_on;
	if(car_yellow_blink() == ERROR ) return ERROR;
}
/**************************************************/
/* this function makes Red ON for 5s                             */
/**************************************************/
uint8_t car_traffic_red(void)
{
	car_color_state = red_on;
	if(car_red_on() == ERROR ) return ERROR;
	timer0_delay_ms(time);
	if(car_red_off() == ERROR ) return ERROR;
}
/**************************************************/
/* this function makes Green ON for 5s pedestrian mode                            */
/**************************************************/
uint8_t pedestrian_traffic_green(void)
{
	if(pedestrian_green_on() == ERROR ) return ERROR;
	timer0_delay_ms(time);
	if(pedestrian_green_off() == ERROR ) return ERROR;
}
/**************************************************/
/* this function makes Yellow Blinking for 5s pedestrian mode                            */
/**************************************************/
uint8_t pedestrian_traffic_yellow(void)
{
	if(pedestrian_yellow_blink() == ERROR) return ERROR ;
}
/**************************************************/
/* this function makes Red ON for 5s pedestrian mode                            */
/**************************************************/
uint8_t pedestrian_traffic_red(void)
{
	if(pedestrian_red_on() == ERROR ) return ERROR ;
	timer0_delay_ms(time);
	if(pedestrian_red_off() == ERROR ) return ERROR;
}
/**************************************************/
/* this function makes Yellow blinking for 5s in both pedestrian and car                           */
/**************************************************/
uint8_t CarPedestrian_yellow_blink(void)
{
	uint8_t num_time = 0 ;
	while(num_time < 25)       // (5000ms / 200ms) = 25
	{
		if(car_yellow_on() == ERROR ) return ERROR ;
		if(pedestrian_yellow_on() == ERROR ) return ERROR;
		//_delay_ms(100);
		timer0_delay_ms(100) ;
		car_yellow_off();
		pedestrian_yellow_off();
		//_delay_ms(100);
		timer0_delay_ms(100) ;
		
		num_time++ ;
	}
}
/**************************************************/
/* this function makes Green ON for 5s pedestrian in the same time Red on in Car                             */
/**************************************************/
uint8_t Car_red_Pedestrian_green_on(void)
{
	
	if(car_red_on() == ERROR ) return ERROR;
	if(pedestrian_green_on() == ERROR ) return ERROR;
	//_delay_ms(5000);
	timer0_delay_ms(time) ;
}
/**************************************************/
/* this function makes Red ON for 5s pedestrian in the same time Green on in Car                             */
/**************************************************/
uint8_t Car_green_Pedestrian_red_on(void)
{
	if(car_green_on() == ERROR ) return ERROR;
	if(pedestrian_red_on() == ERROR ) return ERROR;
	timer0_delay_ms(time) ;
	car_green_off();
	pedestrian_red_off();
}

/**************************************************/
/* this function describes what happen in normal mode                             */
/**************************************************/
uint8_t normal_mode(void)
{
	//leds_init();
	//timer0_init(Normal);
	normal_mode_start:
	if(car_traffic_green() == ERROR ) return ERROR ;
	if(pedestrian_state == finished)
	{
		pedestrian_state = reset;
		goto normal_mode_start ;
	}
	if(car_traffic_yellow() == ERROR ) return ERROR;
	if(pedestrian_state == 1)
	{
		pedestrian_state = reset ;
		goto normal_mode_start ;
	}
	if(car_traffic_red() == ERROR ) return ERROR;
	if(pedestrian_state == 1)
	{
		pedestrian_state = reset ;
		goto normal_mode_start ;
	}
	car_traffic_yellow();
	if(pedestrian_state == 1)
	{
		pedestrian_state = reset ;
		goto normal_mode_start ;
	}
}
/**************************************************/
/* this function describes what happen when someone press Button                       */
/**************************************************/
uint8_t pedestrian_mode(void)
{
	if(car_color_state == red_on)
	{
		if(Car_red_Pedestrian_green_on() == ERROR ) return ERROR;
		if(car_red_off() == ERROR ) return ERROR;
		CarPedestrian_yellow_blink();
		pedestrian_green_off();
		Car_green_Pedestrian_red_on();
		
		pedestrian_state = finished ;   // finished pedestrian mode
	}
	
	else if((car_color_state == green_on)|(car_color_state == yellow_on))
	{
		if(pedestrian_red_on() == ERROR ) return ERROR;
		if(car_green_off() == ERROR ) return ERROR ;
		CarPedestrian_yellow_blink();
		pedestrian_red_off();
		Car_red_Pedestrian_green_on() ;
		// At the end of the two states,
		// the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
		car_red_off();
		CarPedestrian_yellow_blink();
		pedestrian_green_off();
		Car_green_Pedestrian_red_on();
		
		pedestrian_state = finished ;   // finished pedestrian mode
	}
}

uint8_t app_start(void)
{
	GLIEN();
    INT0_init(rising_edge);
	
    if(leds_init() == ERROR) ERROR;
 
		 
	while(1)
    {
	    if(normal_mode() == ERROR ) return ERROR ;
	}
}