/*
 * DIO.h
 *
 * Created: 7/9/2022 4:58:34 PM
 *  Author: ameln
 */ 

#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"

//port macro
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//Direction macro
#define IN 0 
#define OUT 1

//Value macro
#define LOW 0 
#define HIGH 1

//driver prototypes (API)

//initialize the DIO 
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);
//write to DIO
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);
//toggle the DIO 
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber);
//read DIO value 
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value); 

#endif /* DIO_H_ */