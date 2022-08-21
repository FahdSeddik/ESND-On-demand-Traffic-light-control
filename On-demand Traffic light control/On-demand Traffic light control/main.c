/*
 * On-demand Traffic light control.c
 *
 * Created: 8/20/2022 8:57:24 PM
 * Author : fahds
 */ 

#include "Application/application.h"


int main(void)
{
	//Initialize
    APP_init();
	
	//Main loop
	while(1){
		APP_start();
	}
}



//testing main function
//int main(void){
	//BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
	//LED_init(LED_CAR_PORT,LED_CAR_G_PIN);
	//LED_init(LED_PED_PORT,LED_PED_G_PIN);
	//TIMER_init();
	//uint8_t value;
	//while(1){
		//BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&value);
		//if(value==HIGH){
			//LED_toggle(LED_CAR_PORT,LED_CAR_G_PIN);
			//LED_on(LED_PED_PORT,LED_PED_G_PIN);
			//TIMER_delay(500);
			//LED_off(LED_PED_PORT,LED_PED_G_PIN);
			//TIMER_delay(500);
			//
		//}else{
			//LED_on(LED_CAR_PORT,LED_CAR_G_PIN);
		//}
		//
	//}
//}