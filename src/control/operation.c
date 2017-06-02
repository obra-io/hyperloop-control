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

static Alesi_StatusTypeDef setup(Alesi_HandleTypeDef const me_h, Alesi_AO_ModeTypeDef const mode,
        void const * const params);

static Alesi_StatusTypeDef event_handler(Alesi_HandleTypeDef const me_h,
        Alesi_AO_ModeTypeDef const mode, Alesi_HandleTypeDef const signal);

static Alesi_StatusTypeDef inspect(Alesi_HandleTypeDef const me_h);

static Alesi_AO_OpsTypeDef const operation_ops =
{
    .setup = setup,
    .event_handler = event_handler,
    .inspect = inspect
};

Alesi_AO_DescTypeDef const operation_desc =
{
    .ops = &operation_ops,
    .name = "operation"
};

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/**
  * @brief
  * @param  none
  * @retval
  */
static Alesi_StatusTypeDef setup(Alesi_HandleTypeDef const me_h, Alesi_AO_ModeTypeDef const mode,
        void const * const params)
{
    Alesi_StatusTypeDef status = ALESI_ERROR;

    if (mode == ALESI_AO_MODE__PRE_OPERATIONAL)
    {

    }

    return status;
}

/**
  * @brief
  * @param  none
  * @retval
  */
static Alesi_StatusTypeDef event_handler(Alesi_HandleTypeDef const me_h,
        Alesi_AO_ModeTypeDef const mode, Alesi_HandleTypeDef const signal)
{
    Alesi_StatusTypeDef status = ALESI_ERROR;
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

    return status;
}

/**
  * @brief
  * @param  none
  * @retval
  */
static Alesi_StatusTypeDef inspect(Alesi_HandleTypeDef const me_h)
{
    Alesi_StatusTypeDef status = ALESI_ERROR;

    return status;
}

/*****************************END OF FILE************************************/
