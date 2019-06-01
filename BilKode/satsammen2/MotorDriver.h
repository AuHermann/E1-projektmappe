/*
 * MotorDriver.h
 *
 * Created: 15-05-2019 08:32:47
 *  Author: Andreas Hermann
 */ 



void initMotor();
void start();
void stop();
void setSpeed(int speed);
void setDirection(unsigned char dir);
void speedUp(unsigned char delay, unsigned char speedTarget);
void slowDown(unsigned char delay, unsigned char speedTarget);


