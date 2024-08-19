#ifndef STM32F411_ADC_H
#define STM32F411_ADC_H

#include "stm32f411xe.h"  // Include the device-specific header file

// ADC Resolution
typedef enum {
    ADC_RES_12_BIT = 0x0,  // 12-bit resolution
    ADC_RES_10_BIT = 0x1,  // 10-bit resolution
    ADC_RES_8_BIT  = 0x2,  // 8-bit resolution
    ADC_RES_6_BIT  = 0x3   // 6-bit resolution
} ADC_Resolution;

// Function Prototypes
void ADC_Init(ADC_TypeDef *ADCx, ADC_Resolution resolution);
void ADC_StartConversion(ADC_TypeDef *ADCx);
uint16_t ADC_GetConversionValue(ADC_TypeDef *ADCx);
void ADC_Enable(ADC_TypeDef *ADCx);
void ADC_Disable(ADC_TypeDef *ADCx);

#endif // STM32F411_ADC_H
