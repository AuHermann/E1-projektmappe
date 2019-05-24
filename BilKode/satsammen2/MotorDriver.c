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
	DDRL =	 0b10001000;
	TCCR5A = 0b10000011;
	TCCR5B = 0b00000101;
	setSpeed(0);
	setDirection(1);
}

void start()
{
	int i;
	for(i = 0; i > 90; i++)
	{
		setSpeed(i);
		_delay_ms(50);
	}
	setSpeed(90);
	turnOn(1);
}

void stop()
{
	setSpeed(0);
	turnOff(1);
	
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