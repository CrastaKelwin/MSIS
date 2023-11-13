#ifndef _LPC214x_TIMER_H_
#define _LPC214x_TIMER_H_

#include <stdint.h>

void delay_ms_timer0(uint32_t ms);
void delay_us_timer0(uint32_t us);
void delay_ms_timer1(uint32_t ms);
void delay_us_timer1(uint32_t us);

#endif // _LPC214x_TIMER_H_
