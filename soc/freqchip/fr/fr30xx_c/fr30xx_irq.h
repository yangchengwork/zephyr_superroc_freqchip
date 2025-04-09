/*
  ******************************************************************************
  * @file    fr30xx.h
  * @author  FreqChip Firmware Team
  * @brief   CMSIS fr30xx Device Peripheral Access Layer Header File.
  *
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Configuration of the Processor and Core Peripherals
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 FreqChip.
  * All rights reserved.
  ******************************************************************************
*/
#ifndef __FR30XX_IRQ_H__
#define __FR30XX_IRQ_H__

#ifdef __cplusplus
extern "C"
{
#endif

/** @group Peripheral_interrupt_number_definition
  * @{
  */
#if defined(__ARMCC_VERSION) || defined(__GNUC__) || defined(__ICCARM__)
// 定义中断编号的宏
#define NonMaskableInt_IRQn          -14               /**< 非可屏蔽中断 */
#define HardFault_IRQn               -13               /**< Cortex-M33 SV 硬故障中断 */
#define MemoryManagement_IRQn        -12               /**< Cortex-M33 内存管理中断 */
#define BusFault_IRQn                -11               /**< Cortex-M33 总线故障中断 */
#define UsageFault_IRQn              -10               /**< Cortex-M33 使用故障中断 */
#define SecureFault_IRQn             -9                /**< Cortex-M33 安全故障中断 */
#define SVCall_IRQn                  -5                /**< Cortex-M33 SV 调用中断 */
#define DebugMonitor_IRQn            -4                /**< Cortex-M33 调试监视器中断 */
#define PendSV_IRQn                  -2                /**< Cortex-M33 挂起 SV 中断 */
#define SysTick_IRQn                 -1                /**< Cortex-M33 系统滴答中断 */
	
// CMSDK 特定中断编号
#define TIMER0_IRQn                     0     /*!< 定时器0中断 */
#define TIMER1_IRQn                     1     /*!< 定时器1中断 */
#define TIMER2_IRQn                     2     /*!< 定时器2中断 */
#define TIMER3_IRQn                     3     /*!< 定时器3中断 */
#define DMA0_IRQn                       4     /*!< DMA0中断 */
#define DMA1_IRQn                       5     /*!< DMA1中断 */
#define SDIOH0_IRQn                     6     /*!< SDIOH0中断 */
#define IPC_MCU_IRQn                    8     /*!< IPC_MCU中断 */
#define USBOTG_IRQn                     9     /*!< USBOTG中断 */
#define GPIOA_IRQn                      16    /*!< GPIOA中断 */
#define GPIOB_IRQn                      17    /*!< GPIOB中断 */
#define GPIOC_IRQn                      18    /*!< GPIOC中断 */
#define GPIOD_IRQn                      19    /*!< GPIOD中断 */
#define UART0_IRQn                      20    /*!< UART0中断 */
#define UART1_IRQn                      21    /*!< UART1中断 */
#define UART2_IRQn                      22    /*!< UART2中断 */
#define UART3_IRQn                      23    /*!< UART3中断 */
#define UART4_IRQn                      24    /*!< UART4中断 */
#define UART5_IRQn                      25    /*!< UART5中断 */
#define I2C0_IRQn                       26    /*!< I2C0中断 */
#define I2C1_IRQn                       28    /*!< I2C1中断 */
#define I2C2_IRQn                       30    /*!< I2C2中断 */
#define SPIM0_IRQn                      32    /*!< SPIM0中断 */
#define SPIM1_IRQn                      33    /*!< SPIM1中断 */
#define SPIS0_IRQn                      35    /*!< SPIS0中断 */
#define SPIS1_IRQn                      36    /*!< SPIS1中断 */
#define SPIMX8_0_IRQn                   37    /*!< SPIMX8_0中断 */
#define SPIMX8_1_IRQn                   38    /*!< SPIMX8_1中断 */
#define I2S0_IRQn                       39    /*!< I2S0中断 */
#define I2S1_IRQn                       40    /*!< I2S1中断 */
#define PDM0_IRQn                       42    /*!< PDM0中断 */
#define PDM1_IRQn                       43    /*!< PDM1中断 */
#define SARADC_IRQn                     45    /*!< SARADC中断 */
#define PSD_DAC_IRQn                    46    /*!< PSD_DAC中断 */
#define SPDIF_IRQn                      47    /*!< SPDIF中断 */
#define DISPLAY_IRQn                    51    /*!< DISPLAY中断 */
#define WDT_IRQn                        52    /*!< WDT中断 */
#define CALI_IRQn                       53    /*!< CALI中断 */
#define TRNG_IRQn                       54    /*!< TRNG中断 */
#define TICK_IRQn                       55    /*!< TICK中断 */
#define DSP_TIMER0_IRQn                 60    /*!< DSP_TIMER0中断 */
#define DSP_TIMER1_IRQn                 61    /*!< DSP_TIMER1中断 */
#define DSP_WDT_IRQn                    62    /*!< DSP_WDT中断 */
#define IPC_DSP_IRQn                    63    /*!< IPC_DSP中断 */
#define YUV2RGB_IRQn                    64    /*!< YUV2RGB中断 */
#define PMU_IRQn                        65    /*!< PMU中断 */
#define PMU_LVD_IRQn                    66    /*!< PMU_LVD中断 */
#define PMU_ACOK_IRQn                   67    /*!< PMU_ACOK中断 */
#define PMU_WDT_IRQn                    68    /*!< PMU_WDT中断 */
#define GPIOE_IRQn                      69    /*!< GPIOE中断 */
#define CAN0_Line0_IRQn                 70    /*!< CAN0-Line0中断 */
#define CAN0_Line1_IRQn                 71    /*!< CAN0-Line1中断 */
#define CAN1_Line0_IRQn                 72    /*!< CAN1-Line0中断 */
#define CAN1_Line1_IRQn                 73    /*!< CAN1-Line1中断 */
#define CAN2_Line0_IRQn                 74    /*!< CAN2-Line0中断 */
#define CAN2_Line1_IRQn                 75    /*!< CAN2-Line1中断 */
#define CAN3_Line0_IRQn                 76    /*!< CAN3-Line0中断 */
#define CAN3_Line1_IRQn                 77    /*!< CAN3-Line1中断 */
#define PWM0_IRQn                       79    /*!< PWM0中断 */
#define PWM1_IRQn                       80    /*!< PWM1中断 */
#define TIMER4_IRQn                     81    /*!< TIMER4中断 */
#define TIMER5_IRQn                     82    /*!< TIMER5中断 */

#endif  // __ARMCC_VERSION

#ifdef __XTENSA__
typedef enum IRQn
{
    DSP_IPC_IRQn                    = 7,
}IRQn_Type;
#endif  // __XTENSA__
/**
  * @}
  */

/** @group Peripheral_memory_map
  * @{
  */
#define FLASH_DAC_BASE       (0x08000000)  

#define DMAC0_BASE           (0x10000000)
#define USB_OTG_BASE         (0x10010000)
#define APB_BASE             (0x10100000)
#define CRC_BASE             (0x10130000)
#define EFUSE_SISO_BASE      (0x10140000)
#define EFUSE_PIPO0_BASE     (0x10150000)
#define EFUSE_PIPO1_BASE     (0x101C0000)
#define SYSTEM_TIMER_BASE    (0x10160000)
#define FREE_COUNTER_BASE    (0x10170000)
#define CAN0_BASE            (0x10180000)
#define CAN1_BASE            (0x10190000)
#define CAN2_BASE            (0x101A0000)
#define CAN3_BASE            (0x101B0000)
#define AES_BASE             (0x502B0000)

#define DSP_FLASH_DAC_BASE   (0x28000000)

#define PSRAM_DAC_BASE       (0x38000000)
#define SDIOH0_BASE          (0x40000000)
#define DMAC1_BASE           (0x40020000)

#define GPIOA_BASE           (0x50000000)
#define GPIOB_BASE           (0x50008000)
#define UART0_BASE           (0x50010000)
#define UART1_BASE           (0x50018000)
#define I2C0_BASE            (0x50020000)
#define SPIM0_BASE           (0x50030000)
#define SPIS0_BASE           (0x50040000)
#define PWM0_BASE            (0x50050000)
#define I2S0_BASE            (0x50060000)
#define PDM0_BASE            (0x50070000)
#define AHBC_CACHE_BASE      (0x500B0000)
#define PSRAM_OSPI_BASE      (0x500B8000)
#define SPIMX8_0_BASE        (0x500C0000)
#define DISPLAY_BASE         (0x500D0000)
#define SARADC_BASE          (0x500E0000)

#define GPIOC_BASE           (0x50100000)       
#define GPIOD_BASE           (0x50108000)
#define UART2_BASE           (0x50110000)
#define UART3_BASE           (0x50118000)
#define I2C1_BASE            (0x50120000)
#define SPIM1_BASE           (0x50130000)
#define SPIS1_BASE           (0x50140000)
#define PWM1_BASE            (0x50150000)
#define I2S1_BASE            (0x50160000)
#define PDM1_BASE            (0x50170000)
#define SPDIF_BASE           (0x50180000)
#define PSD_DAC_BASE         (0x50190000)
#define SPIMX8_1_BASE        (0x501C0000)

#define GPIOE_BASE           (0x50200000)
#define UART4_BASE           (0x50210000)
#define UART5_BASE           (0x50218000)
#define I2C2_BASE            (0x50220000)
#define DSP_TIM0_BASE        (0x50240000)
#define DSP_TIM1_BASE        (0x50240014)
#define DSP_WDT_BASE         (0x50250000)
#define DSP_IPC_BASE         (0x50280000)
#define DSP_QSPI_BASE        (0x50290000)
#define YUV2RGB_BASE         (0x502A0000)

#define SYSTEM_REG_BASE      (0xE0050000)
#define TIM0_BASE            (0xE0060000)
#define TIM1_BASE            (0xE0060014)
#define TIM2_BASE            (0xE0068000)
#define TIM3_BASE            (0xE0068014)
#define TIM4_BASE            (0xE006C000)
#define TIM5_BASE            (0xE006C014)
#define WDT_BASE             (0xE0070000)
#define FRSPIM_BASE          (0xE0080000)
#define IPC_BASE             (0xE0090000)
#define CALIB_BASE           (0xE00A0000)
#define FLASH_CACHE_BASE     (0xE00B0000)
#define FLASH_QSPI_BASE      (0xE00C0000)
#define TRNG_BASE            (0xE00D0000)
#define ADC_BASE             (0xE00E0000)


/**
  * @}
  */

/* ########################## Oscillator Values adaptation ####################*/
/**
  * @brief Adjust the value of External High Speed oscillator (HSE) used in your application.
  *        This value is used by the system clock calculation.
  */
#define HSE_VALUE    24000000U /*!< Value of the External oscillator in Hz */

/**
  * @brief Internal High Speed oscillator (HSI) value.
  *        This value is used by the system clock calculation.
  */
#define HSI_VALUE    24000000U /*!< Value of the Internal oscillator in Hz */

#ifdef __cplusplus
}
#endif

#endif  // __FR30XX_IRQ_H__
