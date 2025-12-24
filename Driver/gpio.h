/*
 * gpio.h
 *
 *  Created on: Dec 10, 2025
 *      Author: iman
 */

#include "stm32f401xe.h"

#ifndef GPIO_H_
#define GPIO_H_

#define GPIOAEN (1UL << 0)
#define GPIOBEN (1UL << 1)
#define GPIOCEN (1UL << 2)
#define GPIODEN (1UL << 3)
#define GPIOEEN (1UL << 4)
#define GPIOHEN (1UL << 7)

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15

#define INPUT 0
#define GENERALPURPOSE 1
#define ALTFUNC 2
#define ANALOG 3

void gpio_rcc(GPIO_TypeDef *GPIOx);

void gpio_init(GPIO_TypeDef *GPIOx, uint8_t PIN, uint8_t MODE);


#endif /* GPIO_H_ */
