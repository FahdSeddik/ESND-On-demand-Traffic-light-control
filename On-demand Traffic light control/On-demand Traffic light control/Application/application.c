/*
 * application.c
 *
 * Created: 8/12/2022 7:11:14 PM
 *  Author: fahds
 */ 
#include "application.h"
uint8_t carLED=0; //0 green 1 yellow 2 red
uint8_t prevcarLED=1;
uint8_t normalmode = 1; //1 normal 0 pedestrian
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
			//Case GREEN LED
			case 0:
				LED_on(LED_CAR_PORT,LED_CAR_G_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
				for(i=0;i<50;i++){
					TIMER_delay(68);
					if(!normalmode)break;//check if ISR was called
				}
				carLED=1;
				prevcarLED=0;
				break;
			//Case YELLOW LED 
			case 1:
				//if not normalmode then we need to blink both
				if(!normalmode){
					if(prevcarLED!=2){
						//blink both yellow leds
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
					prevcarLED=1;//to go to Ped lights logic
					carLED=2;
					LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
				}else{
					//blink car yellow led
					for(i=0;i<5;i++){
						LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
						TIMER_delay(380);
						LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
						TIMER_delay(180);
						LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
						TIMER_delay(380);
						if(!normalmode){//check if ISR was called
							prevcarLED=1;
							break;
						}
					}
				}
				LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_off(LED_PED_PORT,LED_PED_Y_PIN);
				//Configure variables for correct switching
				if(prevcarLED==0){
					carLED=2;
					prevcarLED=1;
				}else if(prevcarLED==2){
					carLED=0;
					prevcarLED=1;
				}
				break;
			//Case RED LED
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
		//Configure PED LEDs
		LED_on(LED_PED_PORT,LED_PED_G_PIN);
		LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		LED_off(LED_PED_PORT,LED_PED_R_PIN);
		
		//Configure CAR LEDs
		LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
		LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
		LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
		TIMER_delay(5000);//5 sec delay
		
		//make sure car red light is off
		LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
		
		//blink both yellow while ped green is on
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
		//Turn off yellow LEDs 
		LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
		LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		//turn on PED red LED
		LED_on(LED_PED_PORT,LED_PED_R_PIN);
		//reset normalmode
		normalmode=1;
		//Configure carLED variables
		carLED=0;
		prevcarLED=1;
	}
	
}

ISR(EXT_INT_0){
	normalmode=0;
}