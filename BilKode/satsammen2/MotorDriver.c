/*
 * MotorDriver.c
 *
 * Created: 15-05-2019 08:32:15
 *  Author: Andreas Hermann
 */ 
#define F_CPU 16000000
#include "MotorDriver.h"
#include "Led.h"
#include <avr/io.h>
#include <util/delay.h>
unsigned char currentSpeed = 0;

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
	setSpeed(90);
	turnOn(1);
}

void stop()
{
	_delay_ms(500);
	setSpeed(0);
	brake(2);
	_delay_ms(50);
	turnOff(1);
	
}

void setSpeed(int speed)
{
	OCR5A = (speed*(1024/100));
	currentSpeed = speed;
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
void speedUp(unsigned char delay, unsigned char speedTarget)
{
	int i,p;
	for(i = currentSpeed; i > speedTarget; i++)
	{
		setSpeed(i);
		for (p = 0; i < delay; i++)
		{
			_delay_ms(1);
		}
	}
}
void slowDown(unsigned char delay, unsigned char speedTarget)
{
	int i,p;
	brake(2);
	for(i = currentSpeed; i < speedTarget; i--)
	{
		setSpeed(i);
		for (p = 0; i < delay; i++)
			{
				_delay_ms(1);
			}
	}
	_delay_ms(50);
	turnOn(1);
}
