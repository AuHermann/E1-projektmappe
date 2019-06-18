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
	DDRD &= 0b11110000; //S�tter port d 0 -3 som indgange 
	DDRE &= 0b11101111; // S�tter port e 4 som indgang
	EICRA = 0xAF;
	EICRB = 0b00000010;
	EIMSK = 0b00011111;
	
}

