#include <lpc214x.h>

// bit_config.h file include
// |- MCA
// |   |- 1_LED_Blink
// |   |       |- LED blink.c
// |   |- general
// |         |- bit_config.h

#include "../general/bit_config.h"

// LEDs Connected to Port P0.0 - P0.7

void delay()
{
	int i = 0, j = 0;
	for (i = 0; i < 10000; i++)
		for (j = 0; j < 1000; j++)
		{
		}
}

int main(void)
{
	// Set Port P0.0 - P0.7 as GPIO function
	PINSEL0 &= ~0xffff;
	// Set Port P0.0 - P0.7 as Output
	SET_REG_BITS(IO0DIR, 0, 7); // Expands to IO0DIR |= 0xff;
	while (1)
	{
		// Set Port P0.0 - P0.7 as HIGH
		SET_REG_BITS(IO0SET, 0, 7); //  Expands to IO0SET |= 0xff;
		CLR_REG_BITS(IO0SET, 0, 7);
		// Delay of approx 1 second
		delay();
		// Clear Port P0.0 - P0.7 as LOW
		SET_REG_BITS(IO0CLR, 0, 7); //  Expands to IO0CLR |= 0xff;
		// Delay of approx 1 second
		delay();
	}
}
