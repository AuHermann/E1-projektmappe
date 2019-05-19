/*
 * MotorDriver.c
 *
 * Created: 15-05-2019 08:32:15
 *  Author: Andreas Hermann
 */ 
#include "MotorDriver.h"
#include <avr/io.h>

void initMotor()
{
	DDRL = 0xff;
	TCCR5A = 0b10000011;
	TCCR5B = 0b00000000;
	setSpeed(512);
}

void start()
{
	TCCR5B |= 0b00000011;
}

void stop()
{
	TCCR5B &= 0b00000000;
}

void setSpeed(int speed)
{
	OCR5A = (speed*(1024/100));
}

void setDirection(unsigned char dir)
{
	if(dir == 0)
	{
		PORTL &= 0b01111111;
	}
	else if( dir == 1)
		{
		PORTL |= 0b10000000;
		}
}