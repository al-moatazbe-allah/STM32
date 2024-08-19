#ifndef STM32F411_TIMER_H
#define STM32F411_TIMER_H

#include "STM32F411_TIM.h"  // Include the device-specific header file

// Timer Modes Enumeration
typedef enum {
    TIMER_MODE_BASIC,   // Basic Timer Mode
    TIMER_MODE_PWM,     // PWM Mode
    TIMER_MODE_INPUT_CAPTURE,  // Input Capture Mode
    TIMER_MODE_OUTPUT_COMPARE  // Output Compare Mode
} Timer_Mode;

// Function Prototypes
void Timer_Init(TIM_TypeDef *TIMx, Timer_Mode mode, uint32_t prescaler, uint32_t period);
void Timer_Start(TIM_TypeDef *TIMx);
void Timer_Stop(TIM_TypeDef *TIMx);
void Timer_SetDutyCycle(TIM_TypeDef *TIMx, uint32_t channel, uint32_t dutyCycle);
void Timer_SetPeriod(TIM_TypeDef *TIMx, uint32_t period);
uint32_t Timer_GetCaptureValue(TIM_TypeDef *TIMx, uint32_t channel);

#endif // STM32F411_TIMER_H
