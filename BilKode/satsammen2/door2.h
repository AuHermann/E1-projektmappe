/*
 * door2.h
 *
 * Created: 16-05-2019 13:02:41
 *  Author: einar
 */ 


#ifndef DOOR2_H_
#define DOOR2_H_

#include <avr/io.h>
void initDoor(void);
void openDoor(unsigned char Side);
void closeDoor(unsigned char side);



#endif /* DOOR2_H_ */