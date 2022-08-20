/*
 * On-demand Traffic light control.c
 *
 * Created: 8/20/2022 8:57:24 PM
 * Author : fahds
 */ 

#include "Application/application.h"


int main(void)
{
    APP_init();
	
	while(1){
		APP_start();
	}
}

TIMER2_COMP_vect