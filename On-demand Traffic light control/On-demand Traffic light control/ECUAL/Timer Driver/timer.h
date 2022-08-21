/*
 * timer.h
 *
 * Created: 8/20/2022 9:28:27 PM
 *  Author: fahds
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"


void TIMER_init();//initialize Timer0
void TIMER_delay(uint16_t millisec); //delay of specific amount default uses 256 prescalar


#endif /* TIMER_H_ */