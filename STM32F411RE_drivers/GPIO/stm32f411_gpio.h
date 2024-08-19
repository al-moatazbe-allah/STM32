#ifndef STM32F411_GPIO_H
#define STM32F411_GPIO_H

#include "stm32f411xe.h"  // Include the device-specific header file

// Define GPIO Pin States
#define GPIO_PIN_SET   1
#define GPIO_PIN_RESET 0

// Define GPIO Modes
typedef enum {
    GPIO_MODE_INPUT = 0x0,
    GPIO_MODE_OUTPUT = 0x1,
    GPIO_MODE_ALTFN = 0x2,
    GPIO_MODE_ANALOG = 0x3
} GPIO_Mode;

// Define GPIO Output Types
typedef enum {
    GPIO_OUTPUT_TYPE_PP = 0x0, // Push-Pull
    GPIO_OUTPUT_TYPE_OD = 0x1  // Open-Drain
} GPIO_OutputType;

// Define GPIO Speeds
typedef enum {
    GPIO_SPEED_LOW = 0x0,
    GPIO_SPEED_MEDIUM = 0x1,
    GPIO_SPEED_FAST = 0x2,
    GPIO_SPEED_HIGH = 0x3
} GPIO_Speed;

// Define GPIO Pull-Up/Pull-Down configurations
typedef enum {
    GPIO_PUPD_NOPULL = 0x0,
    GPIO_PUPD_PULLUP = 0x1,
    GPIO_PUPD_PULLDOWN = 0x2
} GPIO_PuPd;

// Function Prototypes
void GPIO_Init(GPIO_TypeDef *GPIOx, uint32_t pin, GPIO_Mode mode, GPIO_OutputType outputType, GPIO_Speed speed, GPIO_PuPd pull);
void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint32_t pin, uint8_t state);
uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t pin);
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t pin);

#endif // STM32F411_GPIO_H
