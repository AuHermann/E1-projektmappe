/*
 * isr.h
 *
 * Created: 17-05-2019 21:23:35
 *  Author: einar
 */ 


#ifndef ISR_H_
#define ISR_H_
#include "MotorDriver.h"
#include "door2.h"
#include "Switch.h"
#include "MP3_Driver.h"
#include "Led.h"
#include "uart.h"
unsigned char hd = 0;
unsigned char vd = 0;
unsigned char bil = 0;
unsigned char refleksTaeller = 0;

ISR(INT3_vect)
{
	if (hd == 0)
	{
		openDoor('h');
		hd = 1;
	}
	else
	{
		closeDoor('h');
		hd = 0;
	}
	EIFR |= (1<<INTF3);
}
ISR(INT4_vect)
{
	if (vd == 0)
	{
		openDoor('v');
		vd = 1;
	}
	else
	{
		closeDoor('v');
		vd = 0;
	}
	EIFR |= (1<<INTF4);
}
ISR(INT5_vect)
{
	if (bil == 0)
	{
		refleksTaeller = 0;
		start();
		bil = 1;
	}
	else
	{
		stop();
		bil = 0;
	}
	EIFR |= (1<<INTF5);
}
ISR(INT0_vect)
{
	cli();
	refleksTaeller ++;
	SendChar2('h');
	if(refleksTaeller == 1)
	{
		
		playSound(2);
	}
	
	else if(refleksTaeller == 2)
	{
		playSound(2);
		setSpeed(85);
		
	}
	
	else if(refleksTaeller == 3)
	{
		playSound(2);
		setSpeed(55);
		
	}
	
	else if(refleksTaeller == 4)
	
	{
		playSound(2);
		setSpeed(90);
		
	}
	
	else if(refleksTaeller == 5)
	
	{
		playSound(2);
		slowDown(5,50);
		
	}
	else if(refleksTaeller == 6)
	{
		playSound(2);
		slowDown(5,0);
		setDirection(0);
		setSpeed(68);
		
	}
	
	else if(refleksTaeller == 7)
	{
		playSound(2);
	}
	
	else if(refleksTaeller == 8)
	{
		playSound(2);
		slowDown(5,0);
		setDirection(1);
		setSpeed(90);
		
	}
	
	else if(refleksTaeller == 9)
	
	{
		playSound(2);
	}
	
	else if(refleksTaeller == 10)
	
	{
		playSound(2);
	}
	else if(refleksTaeller == 11)
	
	{
		playSound(2);
		stop();
		playSound(3);
	}
	_delay_ms(500);
	if (refleksTaeller != 11 )
	{
		turnOn();
	}
	_delay_ms(500);
	EIFR |= (1<<INTF0);
	sei();
}

ISR(INT2_vect)
{
	cli();
	refleksTaeller ++;
	SendChar2('v');
	if(refleksTaeller == 1)
	{
		
		playSound(2);
	}
	
	else if(refleksTaeller == 2)
	{
		playSound(2);
		setSpeed(85);
		
	}
	
	else if(refleksTaeller == 3)
	{
		playSound(2);
		setSpeed(55);
		
	}
	
	else if(refleksTaeller == 4)
	
	{
		playSound(2);
		setSpeed(90);
		
	}
	
	else if(refleksTaeller == 5)
	
	{
		playSound(2);
		slowDown(5,50);
		
	}
	else if(refleksTaeller == 6)
	{
		playSound(2);
		slowDown(5,0);
		setDirection(0);
		setSpeed(68);
		
	}
	
	else if(refleksTaeller == 7)
	{
		playSound(2);
	}
	
	else if(refleksTaeller == 8)
	{
		playSound(2);
		slowDown(5,0);
		setDirection(1);
		setSpeed(90);
		
	}
	
	else if(refleksTaeller == 9)
	
	{
		playSound(2);
	}
	
	else if(refleksTaeller == 10)
	
	{
		playSound(2);
	}
	else if(refleksTaeller == 11)
	
	{
		playSound(2);
		stop();
		playSound(3);
	}
	_delay_ms(500);
	if (refleksTaeller != 11 )
	{
		turnOn();
	}
	_delay_ms(500);
	EIFR |= (1<<INTF2);
	sei();
}

#endif /* ISR_H_ */