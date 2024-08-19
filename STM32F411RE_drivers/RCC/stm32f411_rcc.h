#ifndef STM32F411_RCC_H
#define STM32F411_RCC_H

#include "stm32f411xe.h"  // Include the device-specific header file

// Define clock sources
typedef enum {
    RCC_SYSCLK_HSI = 0x0, // High-Speed Internal Clock (16 MHz)
    RCC_SYSCLK_HSE = 0x1, // High-Speed External Clock (8 MHz typically)
    RCC_SYSCLK_PLL = 0x2  // Phase-Locked Loop Clock
} RCC_SYSCLK_Source;

// Function Prototypes
void RCC_SetSYSCLKSource(RCC_SYSCLK_Source source);
void RCC_EnablePeripheralClock(GPIO_TypeDef *GPIOx);
void RCC_DisablePeripheralClock(GPIO_TypeDef *GPIOx);

#endif // STM32F411_RCC_H
