#include <lpc214x.h>
#include "../pll/pll.h"
#include "../timer/timer.h"

// bit_config.h file include
// |- MCA
// |   |- 1_LED_Blink
// |   |       |- LED blink.c
// |   |- general
// |         |- bit_config.h

#include "../general/bit_config.h"

// LEDs Connected to Port P0.0 - P0.7

int main(void)
{
	// Set Port P0.0 - P0.7 as GPIO function
	PINSEL0 &= ~0xffff;
	// Init PLL for 61MHz at 12MHz osc
	PLL_Init_60MHz();
	// Set Port P0.0 - P0.7 as Output
	SET_REG_BITS(IO0DIR, 0, 7); // Expands to IO0DIR |= 0xff;
	while (1)
	{
		// Set Port P0.0 - P0.7 as HIGH
		SET_REG_BITS(IO0SET, 0, 7); //  Expands to IO0SET |= 0xff;
		// Delay of approx 1 second
		delay_ms_timer0(1000);
		// Clear Port P0.0 - P0.7 as LOW
		SET_REG_BITS(IO0CLR, 0, 7); //  Expands to IO0CLR |= 0xff;
		// Delay of approx 1 second
		delay_ms_timer0(1000);
	}
}
