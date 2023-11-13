#include <lpc214x.h>
#include "../../timer/timer.h"
#include "../../pll/pll.h"

int main(void)
{
	PLL_Init_60MHz();
	IO0DIR |= (1 << 5);
	IO0DIR |= (1 << 8);
	IO0DIR &= ~(1 << 6);
	while (1)
	{

		if (!(IO0PIN & (1 << 6)))
		{
			IO0SET |= ((1 << 5) | (1 << 8));
			delay_us_timer0(1000);
			IO0CLR |= ((1 << 5) | (1 << 8));
			delay_us_timer0(1000);
		}
		else
		{
			IO0SET |= ((1 << 5) | (1 << 8));
			delay_us_timer0(500);
			IO0CLR |= ((1 << 5));
			delay_us_timer0(500);
			IO0SET |= (1 << 5);
			IO0CLR |= (1 << 8);
			delay_us_timer0(500);
			IO0CLR |= (1 << 5);
			delay_us_timer0(500);
		}
	}
}
