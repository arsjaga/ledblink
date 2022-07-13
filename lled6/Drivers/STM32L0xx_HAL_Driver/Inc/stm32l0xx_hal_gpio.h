#ifndef __STM32L0xx_HAL_GPIO_H
#define __STM32L0xx_HAL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif
#include "stm32l0xx_hal_def.h"

typedef struct
{
  uint32_t Pin;

  uint32_t Mode;

  uint32_t Pull;

  uint32_t Speed;

  uint32_t Alternate;

} GPIO_InitTypeDef;

typedef enum
{
  GPIO_PIN_RESET = 0U,
  GPIO_PIN_SET
} GPIO_PinState;

#define IS_GPIO_PIN_ACTION(__ACTION__) (((__ACTION__) == GPIO_PIN_RESET) || ((__ACTION__) == GPIO_PIN_SET))

#define GPIO_PIN_0                 (0x0001U)  /* Pin 0 selected    */
#define GPIO_PIN_1                 (0x0002U)  /* Pin 1 selected    */
#define GPIO_PIN_2                 (0x0004U)  /* Pin 2 selected    */
#define LED3	                   (0x0008U)  /* Pin 3 selected    */
#define GPIO_PIN_4                 (0x0010U)  /* Pin 4 selected    */
#define GPIO_PIN_5                 (0x0020U)  /* Pin 5 selected    */
#define GPIO_PIN_6                 (0x0040U)  /* Pin 6 selected    */
#define GPIO_PIN_7                 (0x0080U)  /* Pin 7 selected    */
#define GPIO_PIN_8                 (0x0100U)  /* Pin 8 selected    */
#define GPIO_PIN_9                 (0x0200U)  /* Pin 9 selected    */
#define GPIO_PIN_10                (0x0400U)  /* Pin 10 selected   */
#define GPIO_PIN_11                (0x0800U)  /* Pin 11 selected   */
#define GPIO_PIN_12                (0x1000U)  /* Pin 12 selected   */
#define GPIO_PIN_13                (0x2000U)  /* Pin 13 selected   */
#define GPIO_PIN_14                (0x4000U)  /* Pin 14 selected   */
#define GPIO_PIN_15                (0x8000U)  /* Pin 15 selected   */
#define GPIO_PIN_All               (0xFFFFU)  /* All pins selected */
/**
  * @}
  */

#define GPIO_PIN_MASK              (0x0000FFFFU) /* PIN mask for assert test */
#define IS_GPIO_PIN(__PIN__)        ((((uint32_t)(__PIN__) & GPIO_PIN_MASK) != 0x00U) &&\
                                     (((uint32_t)(__PIN__) & ~GPIO_PIN_MASK) == 0x00U))

#define  GPIO_MODE_INPUT                        MODE_INPUT                                                  /*!< Input Floating Mode                   */
#define  GPIO_MODE_OUTPUT_PP                    (MODE_OUTPUT | OUTPUT_PP)                                   /*!< Output Push Pull Mode                 */
#define  GPIO_MODE_OUTPUT_OD                    (MODE_OUTPUT | OUTPUT_OD)                                   /*!< Output Open Drain Mode                */
#define  GPIO_MODE_AF_PP                        (MODE_AF | OUTPUT_PP)                                       /*!< Alternate Function Push Pull Mode     */
#define  GPIO_MODE_AF_OD                        (MODE_AF | OUTPUT_OD)                                       /*!< Alternate Function Open Drain Mode    */

#define  GPIO_MODE_ANALOG                       MODE_ANALOG                                                 /*!< Analog Mode  */
    
#define  GPIO_MODE_IT_RISING                    (MODE_INPUT | EXTI_IT | TRIGGER_RISING)                     /*!< External Interrupt Mode with Rising edge trigger detection          */
#define  GPIO_MODE_IT_FALLING                   (MODE_INPUT | EXTI_IT | TRIGGER_FALLING)                    /*!< External Interrupt Mode with Falling edge trigger detection         */
#define  GPIO_MODE_IT_RISING_FALLING            (MODE_INPUT | EXTI_IT | TRIGGER_RISING | TRIGGER_FALLING)   /*!< External Interrupt Mode with Rising/Falling edge trigger detection  */
 
#define  GPIO_MODE_EVT_RISING                   (MODE_INPUT | EXTI_EVT | TRIGGER_RISING)                     /*!< External Event Mode with Rising edge trigger detection             */
#define  GPIO_MODE_EVT_FALLING                  (MODE_INPUT | EXTI_EVT | TRIGGER_FALLING)                    /*!< External Event Mode with Falling edge trigger detection            */
#define  GPIO_MODE_EVT_RISING_FALLING           (MODE_INPUT | EXTI_EVT | TRIGGER_RISING | TRIGGER_FALLING)   /*!< External Event Mode with Rising/Falling edge trigger detection     */

/**
  * @}
  */

#define IS_GPIO_MODE(__MODE__) (((__MODE__) == GPIO_MODE_INPUT)              ||\
                                ((__MODE__) == GPIO_MODE_OUTPUT_PP)          ||\
                                ((__MODE__) == GPIO_MODE_OUTPUT_OD)          ||\
                                ((__MODE__) == GPIO_MODE_AF_PP)              ||\
                                ((__MODE__) == GPIO_MODE_AF_OD)              ||\
                                ((__MODE__) == GPIO_MODE_IT_RISING)          ||\
                                ((__MODE__) == GPIO_MODE_IT_FALLING)         ||\
                                ((__MODE__) == GPIO_MODE_IT_RISING_FALLING)  ||\
                                ((__MODE__) == GPIO_MODE_EVT_RISING)         ||\
                                ((__MODE__) == GPIO_MODE_EVT_FALLING)        ||\
                                ((__MODE__) == GPIO_MODE_EVT_RISING_FALLING) ||\
                                ((__MODE__) == GPIO_MODE_ANALOG))

#define  GPIO_SPEED_FREQ_LOW              (0x00000000U)  /*!< range up to 0.4 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_MEDIUM           (0x00000001U)  /*!< range 0.4 MHz to 2 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_HIGH             (0x00000002U)  /*!< range   2 MHz to 10 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_VERY_HIGH        (0x00000003U)  /*!< range  10 MHz to 35 MHz, please refer to the product datasheet */


#define IS_GPIO_SPEED(__SPEED__) (((__SPEED__) == GPIO_SPEED_FREQ_LOW     )  || ((__SPEED__) == GPIO_SPEED_FREQ_MEDIUM     ) || \
                                  ((__SPEED__) == GPIO_SPEED_FREQ_HIGH  ) || ((__SPEED__) == GPIO_SPEED_FREQ_VERY_HIGH))

#define  GPIO_NOPULL        (0x00000000U)   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_PULLUP        (0x00000001U)   /*!< Pull-up activation                  */
#define  GPIO_PULLDOWN      (0x00000002U)   /*!< Pull-down activation                */

/**
  * @}
  */

#define IS_GPIO_PULL(__PULL__) (((__PULL__) == GPIO_NOPULL) || ((__PULL__) == GPIO_PULLUP) || \
                                ((__PULL__) == GPIO_PULLDOWN))

#define __HAL_GPIO_EXTI_GET_FLAG(__EXTI_LINE__) (EXTI->PR & (__EXTI_LINE__))

#define __HAL_GPIO_EXTI_CLEAR_FLAG(__EXTI_LINE__) (EXTI->PR = (__EXTI_LINE__))

#define __HAL_GPIO_EXTI_GET_IT(__EXTI_LINE__) (EXTI->PR & (__EXTI_LINE__))

#define __HAL_GPIO_EXTI_CLEAR_IT(__EXTI_LINE__) (EXTI->PR = (__EXTI_LINE__))

#define __HAL_GPIO_EXTI_GENERATE_SWIT(__EXTI_LINE__) (EXTI->SWIER |= (__EXTI_LINE__))

#include "stm32l0xx_hal_gpio_ex.h"

void  HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void  HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void          gpio_set_pin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void          HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void          HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
void          HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#define GPIO_MODE_Pos                           0U
#define GPIO_MODE                               (0x3UL << GPIO_MODE_Pos)
#define MODE_INPUT                              (0x0UL << GPIO_MODE_Pos)
#define MODE_OUTPUT                             (0x1UL << GPIO_MODE_Pos)
#define MODE_AF                                 (0x2UL << GPIO_MODE_Pos)
#define MODE_ANALOG                             (0x3UL << GPIO_MODE_Pos)
#define OUTPUT_TYPE_Pos                         4U
#define OUTPUT_TYPE                             (0x1UL << OUTPUT_TYPE_Pos)
#define OUTPUT_PP                               (0x0UL << OUTPUT_TYPE_Pos)
#define OUTPUT_OD                               (0x1UL << OUTPUT_TYPE_Pos)
#define EXTI_MODE_Pos                           16U
#define EXTI_MODE                               (0x3UL << EXTI_MODE_Pos)
#define EXTI_IT                                 (0x1UL << EXTI_MODE_Pos)
#define EXTI_EVT                                (0x2UL << EXTI_MODE_Pos)
#define TRIGGER_MODE_Pos                         20U
#define TRIGGER_MODE                            (0x7UL << TRIGGER_MODE_Pos)
#define TRIGGER_RISING                          (0x1UL << TRIGGER_MODE_Pos)
#define TRIGGER_FALLING                         (0x2UL << TRIGGER_MODE_Pos)

#ifdef __cplusplus
}
#endif

#endif /* __STM32L0xx_HAL_GPIO_H */
