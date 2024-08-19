#include "stm32f411_rcc.h"

// Set the system clock source
void RCC_SetSYSCLKSource(RCC_SYSCLK_Source source) {
    // Clear the current system clock source bits
    RCC->CFGR &= ~RCC_CFGR_SW;

    // Set the new system clock source
    RCC->CFGR |= (source << RCC_CFGR_SW_Pos);

    // Wait until the new clock source is set
    while ((RCC->CFGR & RCC_CFGR_SWS) != (source << RCC_CFGR_SWS_Pos));
}

// Enable the peripheral clock for a given GPIO port
void RCC_EnablePeripheralClock(GPIO_TypeDef *GPIOx) {
    if (GPIOx == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (GPIOx == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (GPIOx == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if (GPIOx == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    else if (GPIOx == GPIOE) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    else if (GPIOx == GPIOH) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
}

// Disable the peripheral clock for a given GPIO port
void RCC_DisablePeripheralClock(GPIO_TypeDef *GPIOx) {
    if (GPIOx == GPIOA) RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN;
    else if (GPIOx == GPIOB) RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN;
    else if (GPIOx == GPIOC) RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN;
    else if (GPIOx == GPIOD) RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN;
    else if (GPIOx == GPIOE) RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOEEN;
    else if (GPIOx == GPIOH) RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOHEN;
}
