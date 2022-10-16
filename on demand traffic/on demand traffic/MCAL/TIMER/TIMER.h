/*
 * TIMER.h
 *
 * Created: 7/9/2022 6:38:20 PM
 *  Author: ameln
 */ 

#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"

//initialize Timer0
void TIMER_init();
//delay OF timer
void TIMER_delay(uint16_t millisec); 


#endif /* TIMER_H_ */