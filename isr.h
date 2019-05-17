/*
 * isr.h
 *
 * Created: 17-05-2019 21:23:35
 *  Author: einar
 */ 


#ifndef ISR_H_
#define ISR_H_

unsigned char hd = 0;
unsigned char vd = 0;
unsigned char bil = 0;

ISR(INT0_vect)
{
	if (hd == 0)
	{
		openDoorH();
		hd = 1;
	}
	else
	{
		closeDoorH();
		hd = 0;
	}
	EIFR |= (1<<INTF0);
}
ISR(INT1_vect)
{
	if (vd == 0)
	{
		openDoorV();
		vd = 1;
	}
	else
	{
		closeDoorV();
		vd = 0;
	}
	EIFR |= (1<<INTF1);
}
/*ISR(INT2_vect)
{
	if (bil == 0)
	{
		start();
		bil = 1;
	}
	else
	{
		stop();
		bil = 0;
	}
	EIFR |= (1<<INTF1);
}*/



#endif /* ISR_H_ */