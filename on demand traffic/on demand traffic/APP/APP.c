/*
 * APP.c
 *
 * Created:  9/9/2022 2:42:55 PM
 *  Author: ameln
 */ 


#include "APP.h"
uint8_t carLED=0,prevcarLED=1,normalmode = 1;

void APP_init(void)
{
	
	//Car LED initialization
	LED_init(LED_CAR_PORT,LED_CAR_G_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_Y_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_R_PIN);
	
	//passenger LED initialization
	LED_init(LED_PED_PORT,LED_PED_G_PIN);
	LED_init(LED_PED_PORT,LED_PED_Y_PIN);
	LED_init(LED_PED_PORT,LED_PED_R_PIN);
	
	//Button initialization
	BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
	
	//Timer initialization
	TIMER_init();
	
	//Enable Global interrupts & setup rising edge detection for button
	sei();
	RISING_EDGE_SETUP();
	SETUP_INT0();
}

void APP_start(void)
{	
	uint8_t i=0;
	if(normalmode || carLED==0 || carLED==1)
	{
		if(!normalmode)
		{
			carLED=1;
		} 
		LED_off(LED_PED_PORT,LED_PED_G_PIN);
		LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		LED_off(LED_PED_PORT,LED_PED_R_PIN);
		switch(carLED)
		{
			
			case 0:
				LED_on(LED_CAR_PORT,LED_CAR_G_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
				
				for(i=0;i<50;i++)
				{
					TIMER_delay(68);
					if(!normalmode)break;
				}
				carLED=1;
				prevcarLED=0;
				break; 
			case 1:
				
				if(!normalmode){
					if(prevcarLED!=2){
						LED_on(LED_PED_PORT,LED_PED_R_PIN);
						for(i=0;i<5;i++){
							LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
							LED_on(LED_PED_PORT,LED_PED_Y_PIN);
							TIMER_delay(390);
							LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
							LED_off(LED_PED_PORT,LED_PED_Y_PIN);
							TIMER_delay(190);
							LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
							LED_on(LED_PED_PORT,LED_PED_Y_PIN);
							TIMER_delay(390);
						}
					}
					prevcarLED=1;
					carLED=2;
					LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
				}else{
					for(i=0;i<5;i++){
						LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
						TIMER_delay(380);
						LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
						TIMER_delay(180);
						LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
						TIMER_delay(380);
						if(!normalmode){
							prevcarLED=1;
							break;
						}
					}
				}
				LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_off(LED_PED_PORT,LED_PED_Y_PIN);
				if(prevcarLED==0)
				{
					carLED=2;
					prevcarLED=1;
				}
				else if(prevcarLED==2)
				{
					carLED=0;
					prevcarLED=1;
				}
				break;
			case 2:
				LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
				for(i=0;i<50;i++){
					TIMER_delay(68);
					if(!normalmode)break;
				}
				prevcarLED=2;
				carLED=1;
				break;
			default:
				carLED=2;
				prevcarLED=1;
				break;
		}
		
	}else{
		
		LED_on(LED_PED_PORT,LED_PED_G_PIN);
		LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		LED_off(LED_PED_PORT,LED_PED_R_PIN);
		
		
		LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
		LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
		LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
		TIMER_delay(5000);
		
		
		LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
		
		
		for(i=0;i<5;i++){
			LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_on(LED_PED_PORT,LED_PED_Y_PIN);
			TIMER_delay(390);
			LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_off(LED_PED_PORT,LED_PED_Y_PIN);
			TIMER_delay(190);
			LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_on(LED_PED_PORT,LED_PED_Y_PIN);
			TIMER_delay(390);
		} 
		LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
		LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		LED_on(LED_PED_PORT,LED_PED_R_PIN);
		normalmode=1;
		carLED=0;
		prevcarLED=1;
	}
	
}

ISR(EXT_INT_0){
	normalmode=0;
}