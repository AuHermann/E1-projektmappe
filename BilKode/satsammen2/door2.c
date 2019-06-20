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
	DDRH |= 0b00011000;
	TCCR4A = 0b11110000;
	TCCR4B = 0b00010011;
	ICR4 = 2500;
	OCR4A = 2250;
	OCR4B = 2405;
}

void openDoor(unsigned char side)
{
	if (side == 'h')
	{
		for (pos=0; pos <=155; pos++)
		{
			OCR4A = (1*pos)+2250;
			_delay_ms(10);
		}
	}
	else if (side == 'v')
	{
		for (pos=155; pos >0; pos--)
		{
			OCR4B = (1*pos) + 2250;
			_delay_ms(10);
		}
	}
	
}

void closeDoor(unsigned char side)
{
	if (side == 'h')
	{
			OCR4A = 2250;
			_delay_ms(1000);
	}
	else if (side == 'v')
	{
		OCR4B = 2405;
		_delay_ms(1000);
	}
}




