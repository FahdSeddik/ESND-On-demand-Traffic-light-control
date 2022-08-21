/*
 * button.h
 *
 * Created: 8/12/2022 7:20:54 PM
 *  Author: fahds
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/dio.h"

//Button port and pin
#define BUTTON_1_PORT PORT_D 
#define BUTTON_1_PIN PIN2


//initialize
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);

// button read
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value);



#endif /* BUTTON_H_ */