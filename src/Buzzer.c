#include "Buzzer.h"

// Utility
#include "Delay.h"

// Driver Libraries
#include "Gpio.h"

void buzz_init(void) {
	gpio_set_mode(P_BUZZ, Output);
	gpio_set(P_BUZZ, BUZZ_OFF);
}

void buzz_enable(void) {
		gpio_set(P_BUZZ, BUZZ_ON);
		delay_ms(EVENT_TRIG);
		gpio_set(P_BUZZ, BUZZ_OFF);
}
