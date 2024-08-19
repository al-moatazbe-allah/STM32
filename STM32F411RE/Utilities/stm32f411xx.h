#ifndef STM32F411XE_H
#define STM32F411XE_H

#include <stdint.h>

/* Base addresses of peripherals */
#define PERIPH_BASE           0x40000000U
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000U)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000U)

#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000U)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00U)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800U)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2000U)

/* GPIO Register Definition Structure */
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

/* RCC Register Definition Structure */
typedef struct {
    volatile uint32_t CR;       /*!< RCC clock control register,            Address offset: 0x00 */
    volatile uint32_t PLLCFGR;  /*!< RCC PLL configuration register,        Address offset: 0x04 */
    volatile uint32_t CFGR;     /*!< RCC clock configuration register,      Address offset: 0x08 */
    volatile uint32_t CIR;      /*!< RCC clock interrupt register,          Address offset: 0x0C */
    volatile uint32_t AHB1RSTR; /*!< RCC AHB1 peripheral reset register,    Address offset: 0x10 */
    volatile uint32_t AHB2RSTR; /*!< RCC AHB2 peripheral reset register,    Address offset: 0x14 */
    volatile uint32_t AHB3RSTR; /*!< RCC AHB3 peripheral reset register,    Address offset: 0x18 */
    uint32_t RESERVED0;         /*!< Reserved, 0x1C                          */
    volatile uint32_t APB1RSTR; /*!< RCC APB1 peripheral reset register,    Address offset: 0x20 */
    volatile uint32_t APB2RSTR; /*!< RCC APB2 peripheral reset register,    Address offset: 0x24 */
    uint32_t RESERVED1[2];      /*!< Reserved, 0x28-0x2C                     */
    volatile uint32_t AHB1ENR;  /*!< RCC AHB1 peripheral clock enable register, Address offset: 0x30 */
    volatile uint32_t AHB2ENR;  /*!< RCC AHB2 peripheral clock enable register, Address offset: 0x34 */
    volatile uint32_t AHB3ENR;  /*!< RCC AHB3 peripheral clock enable register, Address offset: 0x38 */
    uint32_t RESERVED2;         /*!< Reserved, 0x3C                          */
    volatile uint32_t APB1ENR;  /*!< RCC APB1 peripheral clock enable register, Address offset: 0x40 */
    volatile uint32_t APB2ENR;  /*!< RCC APB2 peripheral clock enable register, Address offset: 0x44 */
    uint32_t RESERVED3[2];      /*!< Reserved, 0x48-0x4C                     */
    volatile uint32_t AHB1LPENR; /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
    volatile uint32_t AHB2LPENR; /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
    volatile uint32_t AHB3LPENR; /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
    uint32_t RESERVED4;          /*!< Reserved, 0x5C                          */
    volatile uint32_t APB1LPENR; /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
    volatile uint32_t APB2LPENR; /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
    uint32_t RESERVED5[2];       /*!< Reserved, 0x68-0x6C                     */
    volatile uint32_t BDCR;      /*!< RCC Backup domain control register,     Address offset: 0x70 */
    volatile uint32_t CSR;       /*!< RCC clock control & status register,    Address offset: 0x74 */
    uint32_t RESERVED6[2];       /*!< Reserved, 0x78-0x7C                     */
    volatile uint32_t SSCGR;     /*!< RCC spread spectrum clock generation register, Address offset: 0x80 */
    volatile uint32_t PLLI2SCFGR; /*!< RCC PLLI2S configuration register,     Address offset: 0x84 */
    volatile uint32_t PLLSAICFGR; /*!< RCC PLLSAI configuration register,     Address offset: 0x88 */
    volatile uint32_t DCKCFGR;   /*!< RCC dedicated clocks configuration register, Address offset: 0x8C */
} RCC_TypeDef;

/* ADC Register Definition Structure */
typedef struct {
    volatile uint32_t SR;       /*!< ADC status register,                      Address offset: 0x00 */
    volatile uint32_t CR1;      /*!< ADC control register 1,                   Address offset: 0x04 */
    volatile uint32_t CR2;      /*!< ADC control register 2,                   Address offset: 0x08 */
    volatile uint32_t SMPR1;    /*!< ADC sample time register 1,               Address offset: 0x0C */
    volatile uint32_t SMPR2;    /*!< ADC sample time register 2,               Address offset: 0x10 */
    volatile uint32_t JOFR1;    /*!< ADC injected channel data offset register 1, Address offset: 0x14 */
    volatile uint32_t JOFR2;    /*!< ADC injected channel data offset register 2, Address offset: 0x18 */
    volatile uint32_t JOFR3;    /*!< ADC injected channel data offset register 3, Address offset: 0x1C */
    volatile uint32_t JOFR4;    /*!< ADC injected channel data offset register 4, Address offset: 0x20 */
    volatile uint32_t HTR;      /*!< ADC watchdog high threshold register,     Address offset: 0x24 */
    volatile uint32_t LTR;      /*!< ADC watchdog low threshold register,      Address offset: 0x28 */
    volatile uint32_t SQR1;     /*!< ADC regular sequence register 1,          Address offset: 0x2C */
    volatile uint32_t SQR2;     /*!< ADC regular sequence register 2,          Address offset: 0x30 */
    volatile uint32_t SQR3;     /*!< ADC regular sequence register 3,          Address offset: 0x34 */
    volatile uint32_t JSQR;     /*!< ADC injected sequence register,           Address offset: 0x38 */
    volatile uint32_t JDR1;     /*!< ADC injected data register 1,             Address offset: 0x3C */
    volatile uint32_t JDR2;     /*!< ADC injected data register 2,             Address offset: 0x40 */
    volatile uint32_t JDR3;     /*!< ADC injected data register 3,             Address offset: 0x44 */
    volatile uint32_t JDR4;     /*!< ADC injected data register 4,             Address offset: 0x48 */
    volatile uint32_t DR;       /*!< ADC regular data register,                Address offset: 0x4C */
} ADC_TypeDef;

/* Peripheral Definitions */
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define ADC1                ((ADC_TypeDef *) ADC1_BASE)

/* ADC_SR register bit definitions */
#define ADC_SR_EOC_Pos      (1U)
#define ADC_SR_EOC          (1U << ADC_SR_EOC_Pos)   /*!< ADC End of conversion flag */

/* ADC_CR1 register bit definitions */
#define ADC_CR1_RES_Pos     (24U)
#define ADC_CR1_RES         (0x3U << ADC_CR1_RES_Pos) /*!< ADC Resolution */

/* ADC_CR2 register bit definitions */
#define ADC_CR2_ADON_Pos    (0U)
#define ADC_CR2_ADON        (1U << ADC_CR2_ADON_Pos)  /*!< ADC On/Off bit */
#define ADC_CR2_CONT_Pos    (1U)
#define ADC_CR2_CONT        (1U << ADC_CR2_CONT_Pos)  /*!< ADC Continuous conversion mode */
#define ADC_CR2_SWSTART_Pos (30U)
#define ADC_CR2_SWSTART     (1U << ADC_CR2_SWSTART_Pos) /*!< Start conversion of regular channels */

#endif // STM32F411XE_H
