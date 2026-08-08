#ifndef ALARM_SYS_H
#define ALARM_SYS_H

#include "led.h"
#include "buzzer.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum{
    IDEL,
    RUN,
    ALARM,
}alarm_sys_mode;

void alarm_sys(alarm_sys_mode mode);
void blink_led(uint8_t led_num, uint16_t times, uint32_t delay_ms);
void beep(uint32_t beep_ms);

#ifdef __cplusplus
}
#endif

#endif