#include "LED.h"

// Driver Libraries
#include "Gpio.h"

// Utility
#include "Delay.h"

void led_init(void) {
	// Set 3 led pins to outputs.
	gpio_set_mode(P_LED_R, Output);
	gpio_set_mode(P_LED_G, Output);
	gpio_set_mode(P_LED_B, Output);
	led_set(0, 0, 0);
}

void led_set(int red_on, int green_on, int blue_on) {
	// Boolean operation to decide on state for both active
	// high and low LEDs.
	gpio_set(P_LED_R, (!red_on) != LED_ON);
	gpio_set(P_LED_G, (!green_on) != LED_ON);
	gpio_set(P_LED_B, (!blue_on) != LED_ON);
}

void light_error(void){ 			
	led_set(1,0,0);
	delay_ms(EVENT_TRIG_US);
	led_set(0,0,0);
}

void light_arrival(void){			
	led_set(0,1,0);
	delay_ms(EVENT_TRIG_US);
	led_set(0,0,0);
}

void light_departure(void){			
	led_set(0,0,1);
	delay_ms(EVENT_TRIG_US);
	led_set(0,0,0);
}
