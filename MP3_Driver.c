/*
 * MP3_Driver.c
 *
 * Created: 15-05-2019 09:48:28
 *  Author: dryos
 */ 
#include <avr/io.h>
#include "uart.h"

void initMP3()
{
	SendChar(0x7E);
	SendChar(0x0C);
	SendChar(0x00);
	SendChar(0x00);
	SendChar(0x00);
	SendChar(0xFF);
	SendChar(0xF4);
	SendChar(0xEF);
}
void playSound(char soundChoice)
{
	unsigned char x = (0xFC - soundChoice) + 1;
	SendChar(0x7E);
	SendChar(0x03);
	SendChar(0x00);
	SendChar(0x00);
	SendChar(soundChoice);
	SendChar(0xFF);
	SendChar(x);			//er forskellig ved forskellige tracks... what do
	SendChar(0xEF);
}
void volumeSet()
{
	//Volume set MAX
	SendChar(0x7E);
	SendChar(0x06);
	SendChar(0x00);
	SendChar(0x00);
	SendChar(0x1E);
	SendChar(0xFF);
	SendChar(0xDC);
	SendChar(0xEF);
}