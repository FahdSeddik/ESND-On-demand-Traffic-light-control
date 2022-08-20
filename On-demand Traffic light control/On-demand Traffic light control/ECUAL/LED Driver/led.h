/*
 * led.h
 *
 * Created: 8/12/2022 6:19:40 PM
 *  Author: fahds
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO Driver/dio.h"

// Car port and pins
#define LED_CAR_PORT PORT_A
#define LED_CAR_G_PIN PIN0
#define LED_CAR_Y_PIN PIN1
#define LED_CAR_R_PIN PIN2

// Pedestrian port and pins
#define LED_PED_PORT PORT_B
#define LED_PED_G_PIN PIN0
#define LED_PED_Y_PIN PIN1
#define LED_PED_R_PIN PIN2

void LED_init(uint8_t ledPort,uint8_t ledPin);
void LED_on(uint8_t ledPort,uint8_t ledPin);
void LED_off(uint8_t ledPort,uint8_t ledPin);
void LED_toggle(uint8_t ledPort,uint8_t ledPin);
//void LED_blink(uint8_t ledPort,uint8_t ledPin,uint8_t delay);


#endif /* LED_H_ */