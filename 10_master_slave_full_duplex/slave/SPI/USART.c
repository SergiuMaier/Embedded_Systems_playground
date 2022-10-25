/*
 * main_func.c
 *
 * Created: 9/29/2022 11:46:57 AM
 * Author: Sergiu Maier
 */ 
#define MAX_LENGTH 50

#include "USART.h"

void init_USART(uint16_t ubrr)
{	
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B |= (1 << RXEN0)|(1 << TXEN0);
	UCSR0B |= (1 << RXCIE0)|(1 << TXCIE0);//|(1 << UDRIE0);
	UCSR0C |= (1 << USBS0)|(3 << UCSZ00);
	
	sei();
}

void transmit_data(unsigned char data)
{
	while (!(UCSR0A & (1<<UDRE0)));
	
	UDR0 = data;
}

unsigned char receive_data(void)
{
	while (!(UCSR0A & (1<<RXC0)));

	return UDR0;
}

void send_data(char data[])
{	
	uint8_t i = 0;
	
	while(data[i])
	{
		transmit_data(data[i]);
		i++;
	}
}

void read_data(char data[])
{	
	char caracter_primit;
	uint8_t i = 0;
	
	while (i < (MAX_LENGTH - 1))
	{	
		caracter_primit = receive_data();		
		
		if(caracter_primit != '\r')
		{
			data[i] = caracter_primit;
			i++;
		}
		else{
			break;
		}
	}
	
	data[i] = '\0'; //caracter final
}

ISR(USART_TX_vect)
{
	flag_tx = 1;
}

ISR(USART_RX_vect)
{
	flag_rx = 1;
}

void start_program()
{
	if(flag_tx == 1)
	{
		//read_data(mesaj);
		//switch_data(mesaj);
		send_data(mesaj);
	}
	
	if(flag_rx == 1)
	{
		read_data(mesaj);
		switch_data(mesaj);
	}
}


