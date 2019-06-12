/*
* Led.c
*
* Created: 15-05-2019 08:33:42
*  Author: einar
*/
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
void initLedPort()
{
	DDRB |= 0b00010000;
	DDRH |= 0b01000000;
	TCCR2A = 0b10100001;
	TCCR2B = 0b00000001;
	OCR2A = 0;
	OCR2B = 0;
	
}
void turnOn()
{
		OCR2A = 255;
		OCR2B = 51;
}

void brake()
{
		OCR2B = 255;
}
void turnOff()
{
		OCR2A = 0;
		OCR2B = 0;
}