/*
 * Switch.c
 *
 * Created: 15-05-2019 10:21:12
 *  Author: einar
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "door2.h"
#include "Switch.h"


void initSwitchPort()
{
	DDRD &= 0b11111100; //Sætter port d 0 - 1 som indgange 
	//DDRE &= 0b11101111; // Sætter port e 4 som indgang
	EICRA = 0x0F;
	EICRB = 0b00000000;
	EIMSK = 0b00000011;
	
}

