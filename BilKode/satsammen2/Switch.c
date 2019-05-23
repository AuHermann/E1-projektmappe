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
	DDRD = 0; //SÆtter port D til indgange
	EICRA =0b11101010;
	EICRB = 0b00000000;
	EIMSK = 0b00001111;
	sei();
}

