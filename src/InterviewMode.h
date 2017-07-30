/*!																	
 * \file      InterviewMode.h
 * \brief     Controller for the interview mode.
 */
#ifndef INTERVIEWMODE_H					
#define INTERVIEWMODE_H

/*!
 *	\brief The initialisation all of variables and periphirals needed
 * 				 for the interview mode to work. Also the Timer and both IR Modules 
 *				 are enabled to trigger interrupts.
 */
void interview_mode_init(void);

/*!
 *	\brief The main loop used to do the action depending on the current state.
 *				 It also checks if an error occured. If the mode is changed, the loop
 * 				 will stop.
 *
 *	An arrival will continuously update the LCD screen to display the current 
 *	time spend inside the room. If there is another arrival, the arrival will
 * 	be ignored. When there is a departure, the timer will be stopped and the 
 * 	time spent in the system will be displayed until there is another arrival.
 * 	If there is a departure when the timer is not on, it will be ignored. 
 *
 *	\note To exit the method, the switch needs to be trigger to change the mode.
 */
void interview_do_action_state(void); 

/*!
 *	\brief If the timer is on, update the LCD to display the new time.
 */
void timer_activated_update(void);

/*!
 * 	\brief Activate the real time clock to count the amount of time used until the 
 * 				 next departure. If the timer is already activated, the arrival is 
 *				 ignored. LED is lit Green and buzzer enabled for a brief time
 *				 to indicate an arrival.
 */
void turn_on_timer(int * timerIsOn);

/*!
 * 	\brief De-activate the real time clock to stop couting the amount if time used.
 *				 The LCD is updated to indicate that the time is currently not being taken.
 */
void turn_off_timer(int * timerIsOn);

#endif
