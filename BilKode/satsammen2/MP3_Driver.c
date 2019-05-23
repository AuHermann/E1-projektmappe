/*
 * MP3_Driver.c
 *
 * Created: 15-05-2019 09:48:28
 *  Author: Bastian
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

void initMP3()
{
	SendChar(0x7E);
	SendChar(0x06);
	SendChar(0x00);
	SendChar(0x00);
	SendChar(0x1E);
	SendChar(0xFF);
	SendChar(0xDC);
	SendChar(0xEF);
	_delay_ms(1000);
}
void playSound(char soundChoice)
{
	// udregning af 16bit checksum, der senere deles op i to
	//  0xFFFF - (CMD + feedback + para1 + para2) + 1
	//	Vi bruger ikke sange nok til at de 8 MSB ændres. Derfor bruges blot 0xFF for de 8 LSB
	
	unsigned char x = 0xFF - (0x03 + 0x00 + 0x00 + soundChoice) + 1;
	
	SendChar(0x7E);
	SendChar(0x03);			//CMD
	SendChar(0x00);			//FeedBack
	SendChar(0x00);			//para1
	SendChar(soundChoice);	//para2
	SendChar(0xFF);
	SendChar(x);			//8 LSB af Checksum (x)
	SendChar(0xEF);
}