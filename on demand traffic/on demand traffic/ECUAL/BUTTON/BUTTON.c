/*
 * BUTTON.c
 *
 * Created: 7/9/2022 9:25:55 PM
 *  Author: ameln
 */ 

#include "button.h"

//initialize
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin){
	DIO_init(buttonPort,buttonPin,IN);
}

// button read
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value){
	DIO_read(buttonPort,buttonPin,value);
}