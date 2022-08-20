/*
 * dio.c
 *
 * Created: 8/12/2022 6:21:04 PM
 *  Author: fahds
 */ 
#include "dio.h"

// include .h
// global variables
// function definitions

void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
	switch(portNumber){
		case PORT_A:
			if(direction == IN){
				CLEAR_BIT(DDRA,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRA,pinNumber);
			}
			else{
				//error handling
			}
			break;
		case PORT_B:
			if(direction == IN){
				CLEAR_BIT(DDRB,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRB,pinNumber);
			}
			else{
				//error handling
			}
			break;
		case PORT_C:
			if(direction == IN){
				CLEAR_BIT(DDRC,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRC,pinNumber);
			}
			else{
				//error handling
			}
			break;
		case PORT_D:
			if(direction == IN){
				CLEAR_BIT(DDRD,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRD,pinNumber);
			}
			else{
				//error handling
			}
			break;
	}
}
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value)
{
	switch(portNumber){
		case PORT_A:
			if(value == LOW){
				//PORTA &= ~(1<<pinNumber); //write 0
				CLEAR_BIT(PORTA,pinNumber);
			}else if (value == HIGH){
				//PORTA |= (1<<pinNumber); //write 1
				SET_BIT(PORTA,pinNumber);
			}
			else{
				//error handling
			}
		break;
		case PORT_B:
			if(value == LOW){
				//PORTB &= ~(1<<pinNumber); //write 0
				CLEAR_BIT(PORTB,pinNumber);
			}else if (value == HIGH){
				//PORTB |= (1<<pinNumber); //write 1
				SET_BIT(PORTB,pinNumber);
			}
			else{
				//error handling
			}
		break;
		case PORT_C:
			if(value == LOW){
				//PORTC &= ~(1<<pinNumber); //write 0
				CLEAR_BIT(PORTC,pinNumber);
			}else if (value == HIGH){
				//PORTC |= (1<<pinNumber); //write 1
				SET_BIT(PORTC,pinNumber);
			}
			else{
				//error handling
			}
		break;
		case PORT_D:
			if(value == LOW){
				//PORTD &= ~(1<<pinNumber); //write 0
				CLEAR_BIT(PORTD,pinNumber);
			}else if (value == HIGH){
				//PORTD |= (1<<pinNumber); //write 1
				SET_BIT(PORTD,pinNumber);
			}
			else{
				//error handling
			}
		break;
	}
}
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	switch(portNumber){
		case PORT_A:
			//PORTA ^= (1<<pinNumber);
			TOGGLE_BIT(PORTA,pinNumber);
		break;
		case PORT_B:
			//PORTB ^= (1<<pinNumber);
			TOGGLE_BIT(PORTB,pinNumber);
		break;
		case PORT_C:
			//PORTC ^= (1<<pinNumber);
			TOGGLE_BIT(PORTC,pinNumber);
		break;
		case PORT_D:
			//PORTD ^= (1<<pinNumber);
			TOGGLE_BIT(PORTD,pinNumber);
		break;
	}
}
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value)
{
	switch(portNumber){
		case PORT_A:
			//*value = ((PINA&(1<<pinNumber))>>pinNumber);
			*value = READ_BIT(PINA,pinNumber);
		break;
		case PORT_B:
			//*value = ((PINB&(1<<pinNumber))>>pinNumber);
			*value = READ_BIT(PINB,pinNumber);
		break;
		case PORT_C:
			//*value = ((PINC&(1<<pinNumber))>>pinNumber);
			*value = READ_BIT(PINC,pinNumber);
		break;
		case PORT_D:
			//*value = ((PIND&(1<<pinNumber))>>pinNumber);
			*value = READ_BIT(PIND,pinNumber);
		break;
	}
}