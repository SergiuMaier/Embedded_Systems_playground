/*
 * functii_afisare.c
 *
 * Created: 10/6/2022 10:51:48 AM
 *  Author: Sergiu Maier
 */ 

#include "functii_afisare.h"

void new_line(){
	
	send_data("\n\r>>");
}

void afisare_meniu(){
	
	send_data("\n\rApasa tasta:\n\r 1. Meniu\n\r 2. Afisare timp\n\r 3. Schimbare stare LED\n\r");
}

void switch_data(char data[]){
	
	if(strcmp(data, "meniu") == 0)
	{
		send_data(CLEAR);
		afisare_meniu();
		new_line();
		flag_afisare_timp = 0;
	}
	else if(strcmp(data, "timp") == 0)
		flag_afisare_timp = 1;
	
	else if(strcmp(data, "led on") == 0)
		PORTB |= (1 << PINB0); //functie cu parametrii pin si port

	else if(strcmp(data, "led off") == 0)
		PORTB &= ~(1 << PINB0);
	else
	{
		send_data("Comanda incorecta!\n\r");
		afisare_meniu();
		new_line();
	}
}

void afisare_timp(){
	
	incrementare_minute();
		
	if((flag_timer == 1) && (flag_afisare_timp == 1))
	{	
		//send_data(CLEAR);
		
		send_data("\n\r Timp: ");
		
		itoa(secunde,  ch_sec, 10);
		itoa(minute, ch_min, 10);
		
		//format 00:00
			
		if(minute < 10){
			send_data("0");
			send_data(ch_min);
		}
		else
			send_data(ch_min);
		
		if((secunde >= 0) && (secunde < 10)){
			send_data(":0");
			send_data(ch_sec);
		}
		else{
			send_data(":");
			send_data(ch_sec);
		}
		
		send_data("\n\r\n\r");
		new_line();
		flag_timer = 0;
	}
}

