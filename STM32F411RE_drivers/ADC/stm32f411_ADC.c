#include "stm32f411_ADC.h"

// Initialize the ADC peripheral with the specified resolution
void ADC_Init(ADC_TypeDef *ADCx, ADC_Resolution resolution) {
    // Ensure ADC is disabled before configuration
    ADC_Disable(ADCx);

    // Set the resolution
    ADCx->CR1 &= ~ADC_CR1_RES;
    ADCx->CR1 |= (resolution << ADC_CR1_RES_Pos);

    // Set the ADC to scan mode (if needed), single conversion mode, etc.
    // For simplicity, this example assumes single conversion mode.
    ADCx->CR2 &= ~ADC_CR2_CONT;  // Disable continuous mode
}

// Start the ADC conversion
void ADC_StartConversion(ADC_TypeDef *ADCx) {
    // Start the conversion by setting the SWSTART bit
    ADCx->CR2 |= ADC_CR2_SWSTART;
}

// Get the ADC conversion result
uint16_t ADC_GetConversionValue(ADC_TypeDef *ADCx) {
    // Wait until the conversion is complete
    while (!(ADCx->SR & ADC_SR_EOC));

    // Return the converted value
    return (uint16_t)ADCx->DR;
}

// Enable the ADC peripheral
void ADC_Enable(ADC_TypeDef *ADCx) {
    ADCx->CR2 |= ADC_CR2_ADON;
}

// Disable the ADC peripheral
void ADC_Disable(ADC_TypeDef *ADCx) {
    ADCx->CR2 &= ~ADC_CR2_ADON;
}
