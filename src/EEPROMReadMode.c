#include "EEPROMReadMode.h"

// Driver Libraries
#include "EEPROM.h"

// Utility
#include <stdlib.h>

uint8_t * rwBuffer; 	//!< 8-bit Temporary Storage Buffer

Mode read_mode(void){
	uint8_t mode; 
	
	rwBuffer = (uint8_t*) malloc(sizeof(uint8_t)); 
	
	EEPROM_8Bit_Read(0, 0, rwBuffer); 
	mode = *rwBuffer; 		
	
	free(rwBuffer);
	
	if(mode == 1) {
		return M_COUNTER_MODE;
	} else if (mode == 2) {
		return M_INTERVIEW_MODE;
	} else {
		// If no previous data was found, return default starting.
		return M_COUNTER_MODE;
	}
}

void save_mode(Mode mode) {
	rwBuffer = (uint8_t*) malloc(sizeof(uint8_t));
	
	if (mode == M_COUNTER_MODE) {
		*rwBuffer = (uint8_t) 1;
	} else if (mode == M_INTERVIEW_MODE) {
		*rwBuffer = (uint8_t) 2;
	} else {
		// No correct mode passed, error.
		return;
	}
	
	EEPROM_8Bit_Write(0, 0, rwBuffer);
	free(rwBuffer);
}
