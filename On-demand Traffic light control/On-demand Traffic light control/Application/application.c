/*
 * application.c
 *
 * Created: 8/12/2022 7:11:14 PM
 *  Author: fahds
 */ 
#include "application.h"
uint8_t carLED=0;
uint8_t prevcarLED=1;
uint8_t normalmode = 1;
void APP_init(void){
	
	//Car LED initialization
	LED_init(LED_CAR_PORT,LED_CAR_G_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_Y_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_R_PIN);
	
	//Pedestrian LED initialization
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
void APP_start(void){
	//variable to be used in for loop
	uint8_t i;
	
	//if normal mode or need transition (i.e. car green led or yellow is on)
	if(normalmode || carLED==0 || carLED==1){
		if(!normalmode){
			carLED=1;
		}
		//Configuring Pedestrian LEDs 
		LED_off(LED_PED_PORT,LED_PED_G_PIN);
		LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		LED_on(LED_PED_PORT,LED_PED_R_PIN);
		
		switch(carLED){
			//Green LED
			case 0:
				LED_on(LED_CAR_PORT,LED_CAR_G_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
				for(i=0;i<50;i++){
					TIMER_delay(68);
					if(!normalmode)break;
				}
				carLED=1;
				prevcarLED=0;
				break;
			case 1:
				if(!normalmode){
					if(prevcarLED!=2){
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
				if(prevcarLED==0){
					carLED=2;
					prevcarLED=1;
				}else if(prevcarLED==2){
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
				//nothing
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
		//LED_off(LED_PED_PORT,LED_PED_G_PIN);
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