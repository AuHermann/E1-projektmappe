/*
 * satsammen2.c
 *
 * Created: 16-05-2019 13:20:28
 * Author : einar
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "door2.h"
#include "Switch.h"
#include "isr.h"
#include "MotorDriver.h"
#include "Led.h"
#include "MP3_Driver.h"
#include "uart.h"

int main(void)
{
	initSwitchPort();
	initMotor();
	initDoor();
	initLedPort();
	InitUART(9600, 8);
	_delay_ms(1000);
	initMP3();
	_delay_ms(1000);
	playSound(1);
	_delay_ms(1000);
	start();	

	  /* Replace with your application code */
    while (1) 
    {
		
    }
}

