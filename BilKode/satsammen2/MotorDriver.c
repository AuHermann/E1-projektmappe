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
unsigned char currentSpeed = 30;

void initMotor()
{
	DDRL =	 0b10001000;
	TCCR5A = 0b10000011;
	TCCR5B = 0b00000101;
	setSpeed(0);
	setDirection(1);
	currentSpeed = 40;
}

void start()
{
	turnOn();
	speedUp(10, 90);
}

void stop()
{
	_delay_ms(500);
	setSpeed(0);
	brake();
	_delay_ms(500);
	turnOff();
	
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
	int i ,p;
	for(i=currentSpeed; i < speedTarget; i++)
	{
		setSpeed(i);
		for (p = 0; p < delay; p++)
		{
			_delay_ms(1);
		}
	}
}
void slowDown(unsigned char delay, unsigned char speedTarget)
{
	int i,p;
	brake();
	for(i = currentSpeed; i > speedTarget; i--)
	{
		setSpeed(i);
		for (p = 0; p < delay; p++)
			{
				_delay_ms(1);
			}
	}
	
	
}
