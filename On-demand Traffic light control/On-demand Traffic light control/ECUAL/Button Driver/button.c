/*
 * button.c
 *
 * Created: 8/12/2022 7:21:00 PM
 *  Author: fahds
 */ 
#include "button.h"

//initialize
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin){
	DIO_init(buttonPort,buttonPin,IN);
}

// button read
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value){
	DIO_read(buttonPort,buttonPin,value);
}
