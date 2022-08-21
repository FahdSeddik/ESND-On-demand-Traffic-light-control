/*
 * application.h
 *
 * Created: 8/12/2022 7:11:06 PM
 *  Author: fahds
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"
#include "../ECUAL/Timer Driver/timer.h"
#include "../Utilities/interrupts.h"


void APP_init(void);
void APP_start(void);




#endif /* APPLICATION_H_ */