/*!
* \file  EEPROMReadMode.h
* \brief Facilitates Simple 8-bit single word Read/Write Operations 
*				 to the Built-in EEPROM for the purposes of switching between 
*				 modes of operation
*/

#ifndef EEPROMREADMODE_H
#define EEPROMREADMODE_H

/*! Different Modes available */
typedef enum {
	M_COUNTER_MODE = 1, 	 //!< Visitor Counter Mode, total amount of objects in a room.
	M_INTERVIEW_MODE = 2  	 //!< Interview Mode, holds the amount of time spend after an arrival.
} Mode;

/*!
 * 	\brief Reads a single byte from the first page of the EEPROM memory.
 * 
 * 	\note If no previous saved memory is found, M_COUNTER_MODE is 
 *				returned by default.
 */
Mode read_mode(void);

/*! \brief Save the mode passed as an argument to the EEPROM.
 *  \param mode Current Mode to be saved to EEPROM. 
 */
void save_mode(Mode mode); 

#endif
