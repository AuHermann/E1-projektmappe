/*
 * MotorDriver.c
 *
 * Created: 15-05-2019 08:32:15
 *  Author: Andreas Hermann
 */ 
#include "MotorDriver.h"
#include "Led.h"
#include <avr/io.h>

void initMotor()
{
	DDRL =	 0b10000000;
	TCCR5A = 0b10000011;
	TCCR5B = 0b00000101;
	setSpeed(99);
	setDirection(1);
}

void start()
{
	DDRL |=   0b00001000;
	turnOn(1);
}

void stop()
{
	DDRL = 0;
	turnOff(1);
	OCR5A = 0;
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