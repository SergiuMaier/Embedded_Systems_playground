/*
 * main_defines.h
 *
 * Created: 9/21/2022 11:46:26 AM
 *  Author: sergiu
 */ 


#ifndef MAIN_DEFINES_H_
#define MAIN_DEFINES_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define FOSC 16000000UL
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#endif /* MAIN_DEFINES_H_ */