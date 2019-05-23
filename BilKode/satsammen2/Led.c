/*
* Led.c
*
* Created: 15-05-2019 08:33:42
*  Author: einar
*/
#include <avr/io.h>
void initLedPort()
{
	DDRH |= 0b01000010;
	DDRE |= 0b00001000;
	DDRB |= 0xFF; //Sætter alle benen på port B til udgange
	PORTB &= ~(0b11111111); //Slukker alle led'erne
	TCCR2A = 0b00100011;
	TCCR2B = 0b00000001;
	TCCR3A = 0b10000011;
	TCCR3B = 0b00000001;
	OCR2B = 0;
	OCR3A = 0;
	
}
void turnOn(unsigned char ledPort)
{
	if (ledPort == 1)
	{
		PORTB |= (0b11111111); //Tænder Forlys og baglys
		OCR2B = 255;
		OCR3A = 500;
	}
}
void turnOff(unsigned char ledPort)
{
	if (ledPort == 1)
	{
		PORTB &= ~(0b11111111); //Slukker Forlys og baglys
	}
}
void brake(unsigned char ledPort)
{
	if (ledPort == 1)
	{
		OCR3A = 255;
	}
}