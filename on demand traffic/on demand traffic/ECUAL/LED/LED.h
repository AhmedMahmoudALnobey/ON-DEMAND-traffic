/*
 * LED.h
 *
 * Created: 8/9/2022 5:13:55 PM
 *  Author: ameln
 */ 



#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER/TIMER.h"



void LED_init(uint8_t ledPort,uint8_t ledPin);
void LED_on(uint8_t ledPort,uint8_t ledPin);
void LED_off(uint8_t ledPort,uint8_t ledPin);
void LED_toggle(uint8_t ledPort,uint8_t ledPin);



#endif /* LED_H_ */