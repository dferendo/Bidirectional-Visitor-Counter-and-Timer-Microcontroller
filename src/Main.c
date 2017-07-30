
// Mode Includes
#include "CounterMode.h"
#include "InterviewMode.h"

// Driver Libraries
#include "Platform.h"
#include "Gpio.h"
#include "EEPROM.h"
#include "EEPROMReadMode.h"
#include "ISR.h"

// Peripherals Interface
#include "Buzzer.h"

int main(void) {
	// Start permanent storage and Buzzer
	EEPROM_start();
	buzz_init();
	// Sets gpio interrupt for mode changing button
	gpio_set_trigger(P_SW, Rising);
	gpio_set_callback(P_SW, ir_isr);
	// Reads last mode of system 
	currentMode = read_mode();
	//Enters main while loop
	while(1) {
		//Checks current mode (global variable) and enters correct mode of function
		if(currentMode == M_INTERVIEW_MODE) {
			interview_mode_init();
		} else if(currentMode == M_COUNTER_MODE) {
			counter_init();
		}
	}
}
