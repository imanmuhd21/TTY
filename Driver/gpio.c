/*
 * gpio.c
 *
 *  Created on: Dec 10, 2025
 *      Author: iman
 */

#include "gpio.h"

void gpio_rcc(GPIO_TypeDef *GPIOx){

	if (GPIOx == GPIOA){
		RCC->AHB1ENR |= GPIOAEN;
	}
	else if (GPIOx == GPIOB){

		RCC->AHB1ENR |= GPIOBEN;
	}
	else if (GPIOx == GPIOC){
		RCC->AHB1ENR |= GPIOCEN;

	}
	else if (GPIOx == GPIOD){
		RCC->AHB1ENR |= GPIODEN;

	}
	else if (GPIOx == GPIOE){
		RCC->AHB1ENR |= GPIOEEN;

	}
	else {
		RCC->AHB1ENR = GPIOHEN;

	}
}

void gpio_init(GPIO_TypeDef *GPIOx, uint8_t PIN, uint8_t MODE){

	switch (MODE){
	case INPUT:
		GPIOx->MODER &= ~(3UL << (PIN*2));
		break;

	case GENERALPURPOSE:
		GPIOx->MODER &= ~(3UL << (PIN*2));
		GPIOx->MODER |= (1UL << (PIN*2));
		break;

	case ALTFUNC:
		GPIOx->MODER &= ~(3UL << (PIN*2));
		GPIOx->MODER |= (2UL << (PIN*2));
		break;

	case ANALOG:
		GPIOx->MODER &= ~(3UL << (PIN*2));
		GPIOx->MODER |= (3UL << (PIN*2));
		break;
	}

}
