/*
 * SPI.c
 *
 * Created: 9/29/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

#include "USART.h"
#include "timer.h"

extern uint8_t flag_afisare_timp;

int main(void)
{	
	init_devices();	
	init_USART(MYUBRR);
	
	while(1) 
    {
		afisare_timp();
    }
}

