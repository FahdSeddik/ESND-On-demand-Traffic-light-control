/*
 * application.c
 *
 * Created: 8/12/2022 7:11:14 PM
 *  Author: fahds
 */ 
#include "application.h"
#define NUMBER_OF_OVERFLOWS 2000
void APP_init(void){
	//Car
	LED_init(LED_CAR_PORT,LED_CAR_G_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_Y_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_R_PIN);
	
	LED_init(LED_PED_PORT,LED_PED_G_PIN);
	LED_init(LED_PED_PORT,LED_PED_Y_PIN);
	LED_init(LED_PED_PORT,LED_PED_R_PIN);
	
	BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
}
void APP_start(void){
	unsigned int overflowCounter = 0;
	//LED_on(LED_1_PORT,LED_1_PIN);
	//LED_toggle(PORT_A,4);
	//3. delay 512ms
	//Timer start -> setting the clock source (prescalar)
	SET_BIT(TCCR0,0); //no prescalar
	while(overflowCounter < NUMBER_OF_OVERFLOWS){
		//Will be repeated 2000
		
		//stop after one overflow -> 256 micro second
		//wait until the overflow flag to be set
		while(READ_BIT(TIFR,0) == 0);
		//clear the overflow flag by writing one to flag
		SET_BIT(TIFR,0);
		overflowCounter++;
	}
	// Timer stop
	TCCR0 = 0x00;
	
	
}