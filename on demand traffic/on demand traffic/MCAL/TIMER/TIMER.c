/*
 * TIMER.c
 *
 * Created: 7/9/2022 7:34:06 PM
 *  Author: ameln
 */ 
 
#include "timer.h"
#include "../../Utilities/bit_manipulation.h"
#include <math.h>

void TIMER_init()
{
	TCCR0 = 0x00;
}
void TIMER_delay(uint16_t millisec)
{
	uint16_t Noverflows,TimerInitial,overFlown=0;
	float Tmaxdelay,Ttick;
	Ttick = 256.0/1000.0; 
	Tmaxdelay= 65.536;
	if(millisec<Tmaxdelay)
	{
		TimerInitial = (Tmaxdelay-millisec)/Ttick;
		Noverflows = 1;	
	}
	else if(millisec == (int)Tmaxdelay)
	{
		TimerInitial=0;
		Noverflows=1;
	}
	else
	{
		Noverflows = ceil((double)millisec/Tmaxdelay);
		TimerInitial = (1<<8) - ((double)millisec/Ttick)/Noverflows;	
	}
	TCNT0 = TimerInitial;
	TCCR0 |= (1<<2);
	while(overFlown<Noverflows)
	{
		while(READ_BIT(TIFR,0)==0);
		SET_BIT(TIFR,0);
		overFlown++;
	}
	
	TCCR0 = 0x00;
}