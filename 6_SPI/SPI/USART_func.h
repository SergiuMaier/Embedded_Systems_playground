/*
 * main_func.h
 *
 * Created: 9/21/2022 11:46:43 AM
 *  Author: Sergiu Maier
 */ 

#ifndef MAIN_FUNC_H_
#define MAIN_FUNC_H_

#include "main_defines.h"

void USART_Init(unsigned int ubrr);

void USART_Transmit(unsigned char data);

unsigned char USART_Receive(void);

void SendData(char *ptr);

#endif /* MAIN_FUNC_H_ */