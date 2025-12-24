/*
 * systick.c
 *
 *  Created on: Dec 10, 2025
 *      Author: iman
 */

#include "systick.h"

void systick_delayS (uint32_t delay){

	SysTick->VAL = 0;
	SysTick->LOAD |= 16000000UL;
	SysTick->CTRL &= ~(SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk);
	SysTick->CTRL |= (SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk);



	for (int i = 0; i < delay ;i++){

		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
	}

	SysTick->CTRL = 0;
}


