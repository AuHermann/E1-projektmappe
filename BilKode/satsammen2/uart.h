// Uart.h
void InitUART(unsigned long BaudRate, unsigned char DataBit);
unsigned char CharReady();
char ReadChar();
void SendChar(char Tegn);

void InitUART2(unsigned long BaudRate, unsigned char DataBit);
void SendChar2(char Tegn);