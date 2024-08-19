#include "STM32F411_TIM.h"

// Initialize the timer in the specified mode
void Timer_Init(TIM_TypeDef *TIMx, Timer_Mode mode, uint32_t prescaler, uint32_t period) {
    // Reset the timer configuration
    TIMx->CR1 = 0x0000;
    TIMx->CR2 = 0x0000;
    TIMx->SMCR = 0x0000;
    TIMx->DIER = 0x0000;
    
    // Set prescaler and auto-reload value (period)
    TIMx->PSC = prescaler;
    TIMx->ARR = period;

    switch (mode) {
        case TIMER_MODE_BASIC:
            // Basic timer mode (use default settings)
            break;
        case TIMER_MODE_PWM:
            // PWM mode configuration
            TIMx->CCMR1 |= (0x6 << TIM_CCMR1_OC1M_Pos); // PWM mode 1 on channel 1
            TIMx->CCER |= TIM_CCER_CC1E; // Enable channel 1
            break;
        case TIMER_MODE_INPUT_CAPTURE:
            // Input capture mode configuration
            TIMx->CCMR1 |= (0x1 << TIM_CCMR1_CC1S_Pos); // CC1 channel is configured as input, IC1 mapped on TI1
            TIMx->CCER |= TIM_CCER_CC1E; // Enable capture on channel 1
            break;
        case TIMER_MODE_OUTPUT_COMPARE:
            // Output compare mode configuration
            TIMx->CCMR1 |= (0x0 << TIM_CCMR1_OC1M_Pos); // Output Compare mode on channel 1
            TIMx->CCER |= TIM_CCER_CC1E; // Enable channel 1
            break;
    }
}

// Start the timer
void Timer_Start(TIM_TypeDef *TIMx) {
    TIMx->CR1 |= TIM_CR1_CEN;  // Enable the counter
}

// Stop the timer
void Timer_Stop(TIM_TypeDef *TIMx) {
    TIMx->CR1 &= ~TIM_CR1_CEN;  // Disable the counter
}

// Set the duty cycle for PWM mode
void Timer_SetDutyCycle(TIM_TypeDef *TIMx, uint32_t channel, uint32_t dutyCycle) {
    switch (channel) {
        case 1:
            TIMx->CCR1 = dutyCycle;
            break;
        case 2:
            TIMx->CCR2 = dutyCycle;
            break;
        case 3:
            TIMx->CCR3 = dutyCycle;
            break;
        case 4:
            TIMx->CCR4 = dutyCycle;
            break;
    }
}

// Set the period of the timer (auto-reload value)
void Timer_SetPeriod(TIM_TypeDef *TIMx, uint32_t period) {
    TIMx->ARR = period;
}

// Get the captured value in input capture mode
uint32_t Timer_GetCaptureValue(TIM_TypeDef *TIMx, uint32_t channel) {
    switch (channel) {
        case 1:
            return TIMx->CCR1;
        case 2:
            return TIMx->CCR2;
        case 3:
            return TIMx->CCR3;
        case 4:
            return TIMx->CCR4;
        default:
            return 0;
    }
}
