/*
 * timer.c
 *
 * Created: 8/20/2022 9:28:19 PM
 *  Author: fahds
 */ 
#include "timer.h"
#include <math.h>
#include "../../Utilities/bit_manipulation.h"

void TIMER_init(){
	TCCR0 = 0x00; //normal mode
}
void TIMER_delay(uint16_t millisec){
	uint16_t Noverflows,TimerInitial;
	double Tmaxdelay,Ttick;
	uint32_t overFlowcnt=0;
	//max delay 256 micro second
	//at 1MHz no prescalar
	// 256 prescalar 
	Ttick = 256.0/1000.0; //ms
	Tmaxdelay= 65.536; //ms
	if(millisec<Tmaxdelay){
		TimerInitial = (Tmaxdelay-millisec)/Ttick;
		Noverflows = 1;
		
	}else if(millisec == (int)Tmaxdelay){
		TimerInitial=0;
		Noverflows=1;
	}else{
		Noverflows = ceil((double)millisec/Tmaxdelay);
		TimerInitial = (1<<8) - ((double)millisec/Ttick)/Noverflows;
		
	}
	TCNT0 = TimerInitial;
	TCCR0 |= (1<<2); //256 prescalar
	while(overFlowcnt<Noverflows){
		//busy wait
		while(READ_BIT(TIFR,0)==0);
		//clear overflow flag
		SET_BIT(TIFR,0);
		//increment counter
		overFlowcnt++;
	}
	//Timer stop
	TCCR0 = 0x00;
}