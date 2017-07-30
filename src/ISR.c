#include "ISR.h"

// Driver Libraries
#include "Timer.h"

// Peripherals Interface
#include "LED.h"
#include "IRModule.h"

// Utility 
#include "EEPROMReadMode.h"
#include <stdint.h>

Mode currentMode;
InterruptStatePossible currentState;

void ir_isr(uint32_t sources) {
	
	if(sources & (1 << GET_PIN_INDEX(P_IR_1))) { 
		if(currentState == S_IDLE) {
			timer_enable();
			currentState = S_VALIDATE_ARRIVAL;
		} else if(currentState == S_VALIDATE_DEPARTURE) {
			timer_disable();
			currentState = S_DEPARTURE;
		} else if(currentState == S_VALIDATE_ARRIVAL) {
			// Reset the timer since the the IR Module was re-triggered.
			timer_enable();
		}
	} 
	
	if (sources & (1 << GET_PIN_INDEX(P_IR_2))) {
		if(currentState == S_IDLE) {
			timer_enable();
			currentState = S_VALIDATE_DEPARTURE;
		} else if (currentState == S_VALIDATE_ARRIVAL) {
			timer_disable();
			currentState = S_ARRIVAL;
		} else if (currentState == S_VALIDATE_DEPARTURE) {
			// Reset the timer since the IR Module was re-triggered.
			timer_enable();
		}
	}
	
	if (sources & (1 << GET_PIN_INDEX(P_SW))) {
		if(currentMode == M_COUNTER_MODE) {
			currentMode = M_INTERVIEW_MODE;
		} else {
			currentMode = M_COUNTER_MODE;
		}
		save_mode(currentMode);
	}
}

void timer_isr(void) {
	currentState = S_IDLE;
	light_error();
	timer_disable();
}
