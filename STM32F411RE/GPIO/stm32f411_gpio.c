#include "stm32f411_gpio.h"

// Initialize GPIO pin
void GPIO_Init(GPIO_TypeDef *GPIOx, uint32_t pin, GPIO_Mode mode, GPIO_OutputType outputType, GPIO_Speed speed, GPIO_PuPd pull) {
    // Enable the GPIO Clock
    if (GPIOx == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (GPIOx == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (GPIOx == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if (GPIOx == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    else if (GPIOx == GPIOE) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    else if (GPIOx == GPIOH) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;

    // Configure the GPIO Mode
    GPIOx->MODER &= ~(0x3 << (pin * 2)); // Clear the existing mode
    GPIOx->MODER |= (mode << (pin * 2)); // Set the mode

    // Configure the GPIO Output Type
    GPIOx->OTYPER &= ~(0x1 << pin); // Clear the existing output type
    GPIOx->OTYPER |= (outputType << pin); // Set the output type

    // Configure the GPIO Speed
    GPIOx->OSPEEDR &= ~(0x3 << (pin * 2)); // Clear the existing speed
    GPIOx->OSPEEDR |= (speed << (pin * 2)); // Set the speed

    // Configure the GPIO Pull-up/Pull-down
    GPIOx->PUPDR &= ~(0x3 << (pin * 2)); // Clear the existing pull-up/pull-down
    GPIOx->PUPDR |= (pull << (pin * 2)); // Set the pull-up/pull-down
}

// Write to GPIO pin
void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint32_t pin, uint8_t state) {
    if (state == GPIO_PIN_SET) {
        GPIOx->BSRR = (1 << pin);
    } else {
        GPIOx->BSRR = (1 << (pin + 16));
    }
}

// Read from GPIO pin
uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t pin) {
    return (uint8_t)((GPIOx->IDR >> pin) & 0x1);
}

// Toggle GPIO pin
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t pin) {
    GPIOx->ODR ^= (1 << pin);
}
