/**
  ******************************************************************************
  * @file    operatio.c
  * @author  Brandon Ortiz
  * @version V1.0.0
  * @date    15-May-2017
  * @brief
  *
  */

/* Includes ------------------------------------------------------------------*/
#include <alesi.h>
#include <stm32f7xx_hal_gpio.h>

#include "operation.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

static Alesi_StatusTypeDef setup(void);
static uint32_t event_handler(uint32_t const flags);

static Alesi_AO_OpsTypeDef const operation_ops =
{
    .setup = setup,
    .event_handler = event_handler
};

Alesi_AO_DescTypeDef const operation_desc =
{
    .ops = &operation_ops
};

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/**
  * @brief
  * @param  none
  * @retval
  */
static Alesi_StatusTypeDef setup(void)
{
    return ALESI_OK;
}

/**
  * @brief
  * @param  none
  * @retval
  */

static uint32_t event_handler(uint32_t const flags)
{
    static uint8_t i;

    if (i)
    {
        HAL_GPIO_WritePin(GPIOB, (1 << 7), GPIO_PIN_SET);

        i = 0;
    }
    else
    {
        HAL_GPIO_WritePin(GPIOB, (1 << 7), GPIO_PIN_RESET);

        i = 1;
    }

    return 0;
}

/* Exported functions --------------------------------------------------------*/

/**
  * @brief  
  * @param  none
  * @retval 
  */

/*****************************END OF FILE************************************/
