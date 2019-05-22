#include <avr/io.h>
#include <stdlib.h>
#include "uart.h"

// Target CPU frequency
#define XTAL 16000000

void InitUART(unsigned long BaudRate, unsigned char DataBit)
{
	if(BaudRate < 300 || BaudRate > 115200 || DataBit < 5 || DataBit > 8){
		exit(1);
	}
	UCSR1B = 0b00011000;								//ingen interrupts d7d6d5, RX-TX enable d4d3, databits = 8 d2, xx d1d0
	UCSR1C = 0b00000110;								//asynkron d7d6, No parity d5d4, stopbits = 1 d3, databits = 8 d2d1, 
	UBRR1 = ((16000000/(16*BaudRate))-1);				//Baud rate udregning
}

unsigned char CharReady()
{
   if((UCSR1A & (1<<7)) != 0){
	   return 1;
   }
	   return 0;
}

char ReadChar()
{
	while ((UCSR1A & (1<<7)) == 0)
	{}
	char x = UDR1;
	return x;
}

void SendChar(char Tegn)
{
	while ((UCSR1A & (1<<5)) == 0)
	{}
	UDR1 = Tegn;
}

