/*
 * door2.c
 *
 * Created: 16-05-2019 13:02:23
 *  Author: einar
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "door2.h"
#include "Switch.h"
int pos = 0;

void initDoor(void)
{
	closeDoorH();
	closeDoorV();
}
void openDoorH(void)
{
	DDRH = 0xFF;
	ICR4 = 2500;
	TCCR4A = 0b11000000;
	TCCR4B = 0b00010011;
	for (pos=0; pos <=150; pos++)
	{
		OCR4A = (1*pos)+2250;
		_delay_ms(10);
	}
}
void closeDoorH(void)
{
	DDRH = 0xFF;
	ICR4 = 2500;
	TCCR4A = 0b11000000;
	TCCR4B = 0b00010011;
	for (pos=150; pos >=0; pos--)
	{
		OCR4A = (1*pos)+2250;
		_delay_ms(10);
	}
}
void openDoorV(void)
{
	DDRH = 0xFF;
	ICR4 = 2500;
	TCCR4A = 0b00110000;
	TCCR4B = 0b00010011;
	for (pos=0; pos <=150; pos++)
	{
		OCR4B = (1*pos)+2250;
		_delay_ms(10);
	}
}
void closeDoorV(void)
{
	DDRH = 0xFF;
	ICR4 = 2500;
	TCCR4A = 0b00110000;
	TCCR4B = 0b00010011;
	for (pos=150; pos >=0; pos--)
	{
		OCR4B = (1*pos)+2250;
		_delay_ms(10);
	}
}
