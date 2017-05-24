/**
  ******************************************************************************
  * @file    main.c
  * @author  Brandon Ortiz
  * @version V1.0.0
  * @date    11-May-2017
  * @brief   Provides main() for the hyperloop-control application which targets
  *          the ST Nucleo-F746ZG board.
  *
  *          Main manages the following:
  *           + Initialization of Alesi framework
  *
  */

/* Includes ------------------------------------------------------------------*/
#include <alesi.h>
#include <util/sizes.h>

#include "control/operation.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
/**
  * @brief
  * @param
  * @retval
  */
static Alesi_StatusTypeDef init_control_session(void)
{
    static Alesi_AO_DescTypeDef const * const ao_descs[] =
    {
        &operation_desc
    };

    static Alesi_Session_DescTypeDef const session_desc =
    {
        .ao_descs = ao_descs,
        .num_ao_descs = COUNT_OF(ao_descs)
    };

    Alesi_StatusTypeDef status;

    status = alesi_init_session(&session_desc);

    return status;
}

/* Exported functions --------------------------------------------------------*/

/**
  * @brief  Main program entry point after startup code
  * @param  none
  * @retval never return
  */
int main(void)
{
    Alesi_StatusTypeDef status;

    status = alesi_init();

    if (status == ALESI_OK)
    {
        status = init_control_session();
    }

    if (status == ALESI_OK)
    {
        /* never return */
        alesi_start();
    }
    else
    {
        while (1);
    }

    return 0;
}

/*****************************END OF FILE************************************/
