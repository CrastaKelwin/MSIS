#include "timer.h"
#include <lpc214x.h>

void delay_ms_timer0(uint32_t ms)
{
    T0CTCR = 0x00;
    T0TCR = 0x00;
    T0TC = 0;
    T0PC = 0;
    T0PR = 59999;
    T0TCR = 0x01;
    while (T0TC < ms)
        ;
    T0TCR = 0x00;
}

void delay_us_timer0(uint32_t us)
{
    T1CTCR = 0x00;
    T1TCR = 0x00;
    T1TCR = 0x02;
    T1PR = 59;
    T1TC = 0;
    T1TCR = 0x01;
    while (T1TC < us)
        ;
    T1TCR = 0x00;
}

void delay_ms_timer1(uint32_t ms)
{
    T1CTCR = 0x00;
    T1TCR = 0x00;
    T1TC = 0;
    T1PC = 0;
    T1PR = 59999;
    T1TCR = 0x01;
    while (T1TC < ms)
        ;
    T1TCR = 0x00;
}

void delay_us_timer1(uint32_t us)
{
    T1CTCR = 0x00;
    T1TCR = 0x00;
    T1TCR = 0x02;
    T1PR = 59;
    T1TC = 0;
    T1TCR = 0x01;
    while (T1TC < us)
        ;
    T1TCR = 0x00;
}
