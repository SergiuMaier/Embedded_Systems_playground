/*
 * main_func.c
 *
 * Created: 9/26/2022 11:12:11 AM
 *  Author: Sergiu Maier
 */ 
#include "main_func.h"
#include "main_defines.h"
#include "USART_func.h"

void timer_init(){
	
	TCCR0A |= (1 << WGM01)|(0 << WGM00);
	OCR0A = 0xF9;
	TCCR0B |= (0 << CS02)|(1 << CS01)|(1 << CS00); //64
	TIMSK0 |= (1 << OCIE0A);
}

void init_devices(){
	
	cli();
	
	timer_init();
	
	sei();
}

ISR(TIMER0_COMPA_vect){
	
	cli();
	
	contor++;
	
	if(contor >= 1000){
		secunde++;
		contor = 0;
	}
	
	sei();
}
