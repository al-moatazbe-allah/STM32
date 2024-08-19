#ifndef STM32F411XX_H
#define STM32F411XX_H

#include <stdint.h>

// Peripheral base addresses
#define PERIPH_BASE           0x40000000UL
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000UL)

// GPIO base addresses
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00)

// RCC base address
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800)

// Timer base addresses
#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00)

// ADC base addresses
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2000)

// Peripheral structures

// GPIO Type Definition
typedef struct {
    volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00 */
    volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04 */
    volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08 */
    volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C */
    volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10 */
    volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14 */
    volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18 */
    volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C */
    volatile uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

// RCC Type Definition
typedef struct {
    volatile uint32_t CR;       /*!< RCC clock control register,            Address offset: 0x00 */
    volatile uint32_t PLLCFGR;  /*!< RCC PLL configuration register,        Address offset: 0x04 */
    volatile uint32_t CFGR;     /*!< RCC clock configuration register,      Address offset: 0x08 */
    volatile uint32_t CIR;      /*!< RCC clock interrupt register,          Address offset: 0x0C */
    volatile uint32_t AHB1RSTR; /*!< RCC AHB1 peripheral reset register,    Address offset: 0x10 */
    volatile uint32_t AHB2RSTR; /*!< RCC AHB2 peripheral reset register,    Address offset: 0x14 */
    volatile uint32_t APB1RSTR; /*!< RCC APB1 peripheral reset register,    Address offset: 0x20 */
    volatile uint32_t APB2RSTR; /*!< RCC APB2 peripheral reset register,    Address offset: 0x24 */
    volatile uint32_t AHB1ENR;  /*!< RCC AHB1 peripheral clock enable register, Address offset: 0x30 */
    volatile uint32_t AHB2ENR;  /*!< RCC AHB2 peripheral clock enable register, Address offset: 0x34 */
    volatile uint32_t APB1ENR;  /*!< RCC APB1 peripheral clock enable register, Address offset: 0x40 */
    volatile uint32_t APB2ENR;  /*!< RCC APB2 peripheral clock enable register, Address offset: 0x44 */
    volatile uint32_t AHB1LPENR; /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
    volatile uint32_t AHB2LPENR; /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
    volatile uint32_t APB1LPENR; /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
    volatile uint32_t APB2LPENR; /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
    volatile uint32_t BDCR;     /*!< RCC Backup domain control register,    Address offset: 0x70 */
    volatile uint32_t CSR;      /*!< RCC clock control & status register,   Address offset: 0x74 */
    volatile uint32_t SSCGR;    /*!< RCC spread spectrum clock generation register, Address offset: 0x80 */
    volatile uint32_t PLLI2SCFGR; /*!< RCC PLLI2S configuration register,     Address offset: 0x84 */
} RCC_TypeDef;

// Timer Type Definition
typedef struct {
    volatile uint32_t CR1;    /*!< TIM control register 1,                 Address offset: 0x00 */
    volatile uint32_t CR2;    /*!< TIM control register 2,                 Address offset: 0x04 */
    volatile uint32_t SMCR;   /*!< TIM slave mode control register,        Address offset: 0x08 */
    volatile uint32_t DIER;   /*!< TIM DMA/interrupt enable register,      Address offset: 0x0C */
    volatile uint32_t SR;     /*!< TIM status register,                    Address offset: 0x10 */
    volatile uint32_t EGR;    /*!< TIM event generation register,          Address offset: 0x14 */
    volatile uint32_t CCMR1;  /*!< TIM capture/compare mode register 1,    Address offset: 0x18 */
    volatile uint32_t CCMR2;  /*!< TIM capture/compare mode register 2,    Address offset: 0x1C */
    volatile uint32_t CCER;   /*!< TIM capture/compare enable register,    Address offset: 0x20 */
    volatile uint32_t CNT;    /*!< TIM counter register,                   Address offset: 0x24 */
    volatile uint32_t PSC;    /*!< TIM prescaler,                          Address offset: 0x28 */
    volatile uint32_t ARR;    /*!< TIM auto-reload register,               Address offset: 0x2C */
    volatile uint32_t CCR1;   /*!< TIM capture/compare register 1,         Address offset: 0x34 */
    volatile uint32_t CCR2;   /*!< TIM capture/compare register 2,         Address offset: 0x38 */
    volatile uint32_t CCR3;   /*!< TIM capture/compare register 3,         Address offset: 0x3C */
    volatile uint32_t CCR4;   /*!< TIM capture/compare register 4,         Address offset: 0x40 */
    volatile uint32_t DCR;    /*!< TIM DMA control register,               Address offset: 0x48 */
    volatile uint32_t DMAR;   /*!< TIM DMA address for full transfer,      Address offset: 0x4C */
} TIM_TypeDef;

// ADC Type Definition
typedef struct {
    volatile uint32_t SR;    /*!< ADC status register,                    Address offset: 0x00 */
    volatile uint32_t CR1;   /*!< ADC control register 1,                 Address offset: 0x04 */
    volatile uint32_t CR2;   /*!< ADC control register 2,                 Address offset: 0x08 */
    volatile uint32_t SMPR1; /*!< ADC sample time register 1,             Address offset: 0x0C */
    volatile uint32_t SMPR2; /*!< ADC sample time register 2,             Address offset: 0x10 */
    volatile uint32_t JOFR1; /*!< ADC injected channel data offset register 1, Address offset: 0x14 */
    volatile uint32_t JOFR2; /*!< ADC injected channel data offset register 2, Address offset: 0x18 */
    volatile uint32_t JOFR3; /*!< ADC injected channel data offset register 3, Address offset: 0x1C */
    volatile uint32_t JOFR4; /*!< ADC injected channel data offset register 4, Address offset: 0x20 */
    volatile uint32_t HTR;   /*!< ADC watchdog high threshold register,   Address offset: 0x24 */
    volatile uint32_t LTR;   /*!< ADC watchdog low threshold register,    Address offset: 0x28 */
    volatile uint32_t SQR1;  /*!< ADC regular sequence register 1,        Address offset: 0x2C */
    volatile uint32_t SQR2;  /*!< ADC regular sequence register 2,        Address offset: 0x30 */
    volatile uint32_t SQR3;  /*!< ADC regular sequence register 3,        Address offset: 0x34 */
    volatile uint32_t JSQR;  /*!< ADC injected sequence register,         Address offset: 0x38 */
    volatile uint32_t JDR1;  /*!< ADC injected data register 1,           Address offset: 0x3C */
    volatile uint32_t JDR2;  /*!< ADC injected data register 2,           Address offset: 0x40 */
    volatile uint32_t JDR3;  /*!< ADC injected data register 3,           Address offset: 0x44 */
    volatile uint32_t JDR4;  /*!< ADC injected data register 4,           Address offset: 0x48 */
    volatile uint32_t DR;    /*!< ADC regular data register,              Address offset: 0x4C */
} ADC_TypeDef;

// Peripheral declarations
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)

#define RCC                 ((RCC_TypeDef *) RCC_BASE)

#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#define TIM4                ((TIM_TypeDef *) TIM4_BASE)
#define TIM5                ((TIM_TypeDef *) TIM5_BASE)

#define ADC1                ((ADC_TypeDef *) ADC1_BASE)

// Bit definitions and macros
#define GPIO_MODER_MODER0_Pos       (0U)
#define GPIO_MODER_MODER0_Msk       (0x3UL << GPIO_MODER_MODER0_Pos)
#define GPIO_MODER_MODER0           GPIO_MODER_MODER0_Msk

#define RCC_CR_HSION_Pos            (0U)
#define RCC_CR_HSION_Msk            (0x1UL << RCC_CR_HSION_Pos)
#define RCC_CR_HSION                RCC_CR_HSION_Msk

#define TIM_CR1_CEN_Pos             (0U)
#define TIM_CR1_CEN_Msk             (0x1UL << TIM_CR1_CEN_Pos)
#define TIM_CR1_CEN                 TIM_CR1_CEN_Msk

#define ADC_SR_EOC_Pos              (1U)
#define ADC_SR_EOC_Msk              (0x1UL << ADC_SR_EOC_Pos)
#define ADC_SR_EOC                  ADC_SR_EOC_Msk

#endif // STM32F411XX_H
