/*
 * timer.h
 *
 * Created: 8/20/2022 9:28:27 PM
 *  Author: fahds
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"


void TIMER_init();
void TIMER_delay(uint32_t millisec);


#endif /* TIMER_H_ */