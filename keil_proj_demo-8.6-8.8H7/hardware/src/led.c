/**
 * @file    led.c
 * @brief   LED 驱动实现文件。
 */
#include "led.h"

/* 点亮指定编号的 LED */
void led_on(uint8_t led_num)
{
    /* switch 根据 led_num 的值选择执行哪一个 case */
    switch (led_num)
    {
        case 1:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_PIN, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED2_PIN, GPIO_PIN_SET);
            break;
        case 3:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED3_PIN, GPIO_PIN_SET);
            break;
        case 4:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED4_PIN, GPIO_PIN_SET);
            break;
        default:
            /* 1~4 以外的编号不处理；break 表示跳出 switch */
            break;
    }
}

/* 熄灭指定编号的 LED */
void led_off(uint8_t led_num)
{
    switch (led_num)
    {
        case 1:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_PIN, GPIO_PIN_RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED2_PIN, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED3_PIN, GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(LED_GPIO_PORT, LED4_PIN, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}
void blink_led_func(void)
{
    uint8_t led_num = 1U; /* 当前 LED 编号 */
    uint32_t delay_ms = 250U; /* LED 亮/灭持续时间，单位毫秒 */
    uint16_t i = 0U;
     uint8_t led_count = 4U; /* 板载 LED 数量，U 表示 unsigned 无符号数 */
    while (led_num <=led_count)
    {
       if (led_num > led_count)
  {
    return; /* return 直接结束当前函数 */
  }

  /* for 循环：初始化; 判断条件; 每次循环后执行 */
  for (i = 0U; i < led_num; i++)
  {
    led_on(led_num);          /* 点亮指定 LED */
    HAL_Delay(delay_ms);      /* 延时一段时间 */
    led_off(led_num);         /* 熄灭指定 LED */
    HAL_Delay(delay_ms);
  }
        led_num++;
    }

}
