#include <lpc214x.h>

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
	IO0DIR |= 0xff;
	while (1)
	{
		// Set Port P0.0 - P0.7 as HIGH
		IO0SET |= 0xff;
		// Delay of approx 1 second
		delay();
		// Clear Port P0.0 - P0.7 as LOW
		IO0CLR |= 0xff;
		// Delay of approx 1 second
		delay();
	}
}
