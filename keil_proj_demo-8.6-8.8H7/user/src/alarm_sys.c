#include "alarm_sys.h"

static alarm_sys_mode current_mode =IDEL ;


void blink_led(uint8_t led_num, uint16_t times, uint32_t delay_ms)
{
  uint16_t i = 0U; /* 循环计数变量 */

  /* if 判断：LED 编号只允许 1~4 */
  if (led_num > 4U)
  {
    return; /* return 直接结束当前函数 */
  }
  
  /* for 循环：初始化; 判断条件; 每次循环后执行 */
  for (i = 0U; i < times; i++)
  {
    led_on(led_num);          /* 点亮指定 LED */
    HAL_Delay(delay_ms);      /* 延时一段时间 */
    led_off(led_num);         /* 熄灭指定 LED */
    HAL_Delay(delay_ms);
  }
}

void beep(uint32_t beep_ms)
{
  buzzer_on();          /* 打开蜂鸣器 */
  HAL_Delay(beep_ms);   /* 保持响一段时间 */
  buzzer_off();         /* 关闭蜂鸣器 */
}
void alarm_sys(alarm_sys_mode mode)
{
    uint8_t led_num = 1U; 
     uint16_t times=1U;
     uint32_t delay_ms=250U;
     uint32_t delay_ms_fast=100U;
    if (mode != current_mode)
    {
        current_mode = mode;
        HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN, GPIO_PIN_RESET);//用于关闭所有的led
        HAL_GPIO_WritePin(BUZZER_GPIO_PORT, BUZZER_PIN, GPIO_PIN_RESET);//关闭蜂鸣器
    }
    switch (current_mode)
  {case IDEL:
     HAL_GPIO_WritePin(LED_GPIO_PORT, LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(BUZZER_GPIO_PORT, BUZZER_PIN, GPIO_PIN_RESET);
    break;
    case RUN:
    while(1){
        while (led_num <= 4U)
    {
      blink_led(led_num,times, delay_ms);
      led_num++; 
    }

    }
    
    break;
    case ALARM:
    while(1){
        while (led_num <= 4U)
    {
      blink_led(led_num,times, delay_ms_fast);
      led_num++; 
        beep(delay_ms_fast);}
        break;
    }

  }
}