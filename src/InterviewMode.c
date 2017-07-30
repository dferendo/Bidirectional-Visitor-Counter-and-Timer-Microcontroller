#include "InterviewMode.h"

// Peripherals Interface
#include "LED.h"
#include "IRModule.h"
#include "LCD.h"
#include "Buzzer.h"
#include "ISR.h"

// Utility
#include "Delay.h"
#include "RTCTimerUtil.h"
#include "Timer.h"

void interview_mode_init(void) {
	currentState = S_IDLE;
	// Peripherihals Initialisation.
	led_init();
	lcd_init();
	ir_init();
	
	timer_set_callback(timer_isr);
	
	gpio_set_trigger(P_IR_2, Rising);	
	gpio_set_callback(P_IR_2, ir_isr);
	gpio_set_trigger(P_IR_1, Rising);
	gpio_set_callback(P_IR_1, ir_isr);
	
	timer_init((TIMER_LIMIT_US * 2) * (CLK_FREQ / 1000000UL));
	
	lcd_set_cursor(0,0);
	lcd_print("Mode 2");
	lcd_set_cursor(0,1);
	lcd_print("Interview Mode");
	
	interview_do_action_state();
}

void interview_do_action_state(void) {
	int timerIsOn = 0;
	
	while (1) {
		// If change of mode, stop the mode.
		if (currentMode != M_INTERVIEW_MODE) {
			break;
		}
		if (timerIsOn) {
			timer_activated_update();
		}
		if (currentState == S_ARRIVAL) {
			turn_on_timer(&timerIsOn);
		} else if (currentState == S_DEPARTURE) {
			turn_off_timer(&timerIsOn);
		}
	}
}

void timer_activated_update(void) {
	RTCTime stopwatch;
	lcd_clear();
	get_time(&stopwatch);
	convertTimeToString(&stopwatch, lcdBottomRow);
	lcd_set_cursor(0, 0);
	lcd_print("Occupied");
	lcd_set_cursor(0,1);
	lcd_print(lcdBottomRow);
	// Delay before updating the screen again.
	delay_ms(200);
}

void turn_on_timer(int * timerIsOn) {
	// Timer cannot be activated twice, ignore the arrival.
	if(*timerIsOn) {
		light_error();
	} else {
		*timerIsOn = 1;
		enable_clock();
		light_arrival();
		buzz_enable();
	}
	currentState = S_IDLE;
}

void turn_off_timer(int * timerIsOn) {
	if(!(*timerIsOn)) {
		light_error();
	} else {
		disable_clock();
		*timerIsOn = 0;
		light_departure();
		lcd_set_cursor(0,0);
		lcd_print("Not Occupied");
		buzz_enable();
	}
	currentState = S_IDLE;
}
