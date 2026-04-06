/**
 ******************************************************************************
 * @file    task_led
 * @author  sloop
 * @date    2025-1-13
 * @brief   led demo 任务
 *****************************************************************************/

#include "common.h"

void flow_led(void);

FLOW_STATE_DEFINE(flow_led);
FLOW_EVENT_DEFINE(flow_led);

void task_led(void)
{
    /* 初次进入任务时，执行一次 */
    _INIT;
    FLOW_START(flow_led);

    /* 任务结束，不再执行时，释放资源 */
    _FREE;
    FLOW_STOP(flow_led);

    /* 下方开始进入任务运行逻辑 */
    _RUN;

    FLOW_SEND_EVENT(flow_led);

    sl_prt_withFunc("event sent");

    sl_wait(1000);
}

void flow_led(void)
{
    /* 工作流上下文，工作流需要的数据在此静态定义 */
    _FLOW_CONTEXT(flow_led);

    /* 初次进入工作流，执行一次，初始化工作流上下文 */
    _FLOW_INIT;
    sl_prt_withFunc("flow start");

    /* 工作流结束，不再执行时，释放资源 */
    _FLOW_FREE(flow_led);
    sl_prt_withFunc("flow stop");

    /* 下方开始进入工作流运行逻辑 */
    _FLOW_RUN;

    FLOW_WAIT_EVENT(flow_led);

    sl_prt_withFunc("event met");

    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);

    FLOW_WAIT(50);

    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);

    FLOW_WAIT(50);

    HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);

    FLOW_WAIT(200);

    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);

    FLOW_WAIT(50);

    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);

    FLOW_WAIT(50);

    HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);

    FLOW_WAIT(200);

    _FLOW_END;
}

/************************** END OF FILE **************************/
