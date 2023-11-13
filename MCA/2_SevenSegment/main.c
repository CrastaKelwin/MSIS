#include <lpc214x.h>
#include "../pll/pll.h"
#include "../timer/timer.h"
#include <stdint.h>
#include "../general/bit_config.h"

#define SEG1_CTRL_ON SET_REG_BIT(IO0CLR, 7)
#define SEG1_CTRL_OFF SET_REG_BIT(IO0SET, 7)

#define SEG2_CTRL_ON SET_REG_BIT(IO0CLR, 8)
#define SEG2_CTRL_OFF SET_REG_BIT(IO0SET, 8)

void T0isr(void) __irq;
volatile uint32_t ms_since_boot = 0;
void Timer0InterruptInit(void)
{

    T0MR0 = 59999; // 1mSec = 60000-1 counts
    T0MCR = 3;     // Interrupt and Reset on MR0
    T0TCR = 1;     // Timer0 Enable

    VICVectAddr4 = (unsigned)T0isr; // Set the timer ISR vector address
    VICVectCntl4 = 0x00000024;      // Set channel
    VICIntEnable |= 0x00000010;     // Enable the interrupt Timer0
}
void T0isr(void) __irq
{
    ms_since_boot++;
    T0IR |= 0x00000001;       // Clear match 0 interrupt
    VICVectAddr = 0x00000000; // Dummy write to signal end of interrupt
}

int seg = 0;
int seg_value = 0;
const uint8_t seg_values[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
const int count_inc_time_ms = 100;
uint32_t prev_count_inc = 0;
int main(void)
{
    uint32_t prev_ms = 0;
    PLL_Init_60MHz();
    CLR_REG_BITS(PINSEL0, 0, 31); 
    CLR_REG_BITS(PINSEL1, 0, 31); 
    SET_REG_BITS(IO0DIR, 0, 8);   
    SET_REG_BIT(IO0DIR, 16);      
    Timer0InterruptInit();
    SET_REG_BITS(IO0SET, 0, 6); 
    while (1)
    {
        if (ms_since_boot - prev_ms > 5)
        {
            uint8_t current_val = 0;
            if (seg)
            {
                current_val = seg_values[seg_value % 10];
                SEG2_CTRL_OFF;
                SEG1_CTRL_OFF;

                IO0PIN = (IO0PIN & 0xffffff00) | current_val;
                SEG1_CTRL_OFF;
                SEG2_CTRL_ON;
            }
            else
            {
                current_val = seg_values[(seg_value / 10) % 10];
                SEG2_CTRL_OFF;
                SEG1_CTRL_OFF;
                IO0PIN = (IO0PIN & 0xffffff00) | current_val;
                SEG1_CTRL_ON;
                SEG2_CTRL_OFF;
            }
            seg ^= 1;
            prev_ms = ms_since_boot;
        }
        if(ms_since_boot - prev_count_inc >count_inc_time_ms)
        {
            seg_value = (++seg_value)%100;
            prev_count_inc = ms_since_boot;
        }
    }
}
