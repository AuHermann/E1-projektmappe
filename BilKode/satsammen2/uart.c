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
	UCSR3B = 0b00011000;								//ingen interrupts d7d6d5, RX-TX enable d4d3, databits = 8 d2, xx d1d0
	UCSR3C = 0b00000110;								//asynkron d7d6, No parity d5d4, stopbits = 1 d3, databits = 8 d2d1, 
	UBRR3 = ((16000000/(16*BaudRate))-1);				//Baud rate udregning
}
void InitUART2(unsigned long BaudRate, unsigned char DataBit)
{
	if(BaudRate < 300 || BaudRate > 115200 || DataBit < 5 || DataBit > 8){
		exit(1);
	}
	UCSR0B = 0b00011000;								//ingen interrupts d7d6d5, RX-TX enable d4d3, databits = 8 d2, xx d1d0
	UCSR0C = 0b00000110;								//asynkron d7d6, No parity d5d4, stopbits = 1 d3, databits = 8 d2d1,
	UBRR0 = ((16000000/(16*BaudRate))-1);				//Baud rate udregning
}

unsigned char CharReady()
{
   if((UCSR3A & (1<<7)) != 0){
	   return 1;
   }
	   return 0;
}

char ReadChar()
{
	while ((UCSR3A & (1<<7)) == 0)
	{}
	char x = UDR3;
	return x;
}

void SendChar(char Tegn)
{
	while ((UCSR3A & (1<<5)) == 0)
	{}
	UDR3 = Tegn;
}

void SendChar2(char Tegn)
{
	while ((UCSR0A & (1<<5)) == 0)
	{}
	UDR0 = Tegn;
}