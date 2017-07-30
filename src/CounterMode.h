/*!																
 * \file      CounterMode.h
 * \brief     Controller of the counter mode.
 * 
 * Uses 2 IR Modules to detect an arrival or departure. To trigger an 
 * arrival, the entry IR Module (P_IR_1) needs to be interrupted first
 * and then the exit IR Module (P_IR_2) needs to be interrupted within 
 * a specified time period. To trigger a departure, the exit IR Module 
 * (P_IR_2) needs to be interrupted first and then the entry IR Module 
 * (P_IR_1) needs to be interrupted within the a specified time period.
 * If only one IR module is interrupted within the time frame, it will
 * be counted as an error. The current amount of objects in a room 
 * and the total arrivals are displayed on a LCD screen.
 */
#ifndef COUNTERMODE_H					
#define COUNTERMODE_H

// Utility 
#include "EEPROMReadMode.h"
#include <stdint.h>

/*!
 * 	\brief The initialisation all of variables and periphirals needed
 * 				 for the counter to work. Also the Timer and both IR Modules 
 *				 are enabled to trigger interrupts.
 */
void counter_init(void);

/*!
 *	\brief The main loop used to do the action depending on the current state. 
 *				 It also checks if an error occured. If the mode is changed, the loop
 * 				 will stop.
 *
 * 	If the current state indicates that there was an arrival, it will handle the
 * 	arrival. If the current state indicates that there was a depature, it will 
 *	handle the departure. The other states are ignored. 
 *
 *	\note To exit the method, the switch needs to be trigger to change the mode.
 */ 
void counter_do_action_state(void);

/*!
 *	\brief Handle an arrival. The current amount arrivals and total arrivals 
 *				 are incremented. The LED is turned green, the buzzer makes a sound
 *				 and the LCD is updated.
 */
void handle_arrival(void);

/*!
 *	\brief Handle a departure. If the current amount is 0 or less, it indicates 
 *				 that there is an error and the LED is lit red. Otherwise, the current 
 *				 amount of arrivals is decremented, the LED is turned blue, the buzzer
 *				 makes a sound and the LCD is updated.
 */ 
void handle_departure(void);

/*!
 *	\brief Updates the LCD containing the current amount of people arrived 
 * 				 and showing the total amount of people arrived since the program
 *				 was running.
 *
 *	The top row contains the current amount of people while the buttom row
 *	contains the total amount of people.
 */ 
void update_LCD(void);

#endif
