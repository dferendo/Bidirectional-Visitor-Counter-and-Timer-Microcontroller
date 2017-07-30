#include "CounterMode.h"

// Driver Libraries
#include "Timer.h"

// Peripherals Interface
#include "LED.h"
#include "IRModule.h"
#include "LCD.h"
#include "Buzzer.h"
#include "ISR.h"

// Utility
#include "stdio.h"

/*! counter: Indicates the current amount of arrivals.*/
int counter;
/*! counterTotal: Indicates the total amount of arrivals and excluding departures. */
int counterTotal;

void counter_init(void) {
	// Variables Declarations.
	counter = 0;
	counterTotal = 0;
	currentState = S_IDLE;
	
	// Peripherihals Initialisation.
	led_init();
	lcd_init();
	ir_init();
	
	// Set the timer callback to the ISR.
	timer_set_callback(timer_isr);
	
	// Enable GPIO Interrupts for both IR Modules.
	gpio_set_trigger(P_IR_1, Rising);
	gpio_set_callback(P_IR_1, ir_isr);
	gpio_set_trigger(P_IR_2, Rising);
	gpio_set_callback(P_IR_2, ir_isr);
	
	timer_init((TIMER_LIMIT_US * 2) * (CLK_FREQ / 1000000UL));
	
	lcd_set_cursor(0, 0);
	lcd_print("Mode 1");
	lcd_set_cursor(0, 1);
	lcd_print("Counter Mode");
	counter_do_action_state();
}

void counter_do_action_state(void) {
	
	while(1) {
		// Break if mode is changed.
		if(currentMode != M_COUNTER_MODE) {
			break;
		}
		if (currentState == S_DEPARTURE) {
			handle_departure();
		} else if (currentState == S_ARRIVAL) {
			handle_arrival();
		} 
	}
}


void handle_arrival(void) {
		counterTotal++;
		counter++;
		light_arrival();
		update_LCD();
		buzz_enable();
		currentState = S_IDLE;
}

void handle_departure(void) {
		// No Departures can happen if there are no objects in the room. 
		if (counter <= 0) {
				light_error();	
				timer_disable();
		} else {
				counter--;
				light_departure();
				update_LCD();
				buzz_enable();
		}
		currentState = S_IDLE;
}

void update_LCD(){
	sprintf(lcdTopRow, "Current: %d", counter);
	sprintf(lcdBottomRow, "Total: %d", counterTotal);
	lcd_clear();
	lcd_set_cursor(0, 0);
	lcd_print(lcdTopRow);
	lcd_set_cursor(0, 1);
	lcd_print(lcdBottomRow);	
}
