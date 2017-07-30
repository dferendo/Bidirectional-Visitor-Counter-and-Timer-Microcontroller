/*!																	
 * \file      ISR.h
 * \brief     Interrupt service routine for the IR Modules, switch 
 *						and the Timer.
 */
#ifndef ISR_H					
#define ISR_H

#include "EEPROMReadMode.h"
#include <stdint.h>

/*! Error timer if only 1 IRModule is triggered */
#define TIMER_LIMIT_US 3000000

/*! Defines the new state whenever IR modules trigger an interrupt. These enums
 *	represent all the states found in the interrupt state diagram found
 *	in the design brief. 
 *
 *	\see Interrupt section in the design brief.
 */
typedef enum {
	S_IDLE = 1,									//!< No IR module is triggered.
	S_VALIDATE_ARRIVAL = 2,			//!< The entry IR module (P_IR_1) is triggered.
	S_VALIDATE_DEPARTURE = 3,		//!< The exit IR module (P_IR_2) is triggered.
	S_ARRIVAL = 4,							//!< The entry IR module (P_IR_1) is triggered followed 
															//!< by the exit IR module (P_IR_2) within a specified time.
															//!< This incidates an arrival.
	S_DEPARTURE = 5							//!< The exit IR module (P_IR_2) is triggered followed 
															//!< by the entry IR module (P_IR_1) within a specified time.
															//!< This incidates a deparature.
} InterruptStatePossible;

/*! Indicates the current Mode of the system, can be changed pressing the 
 * switch. */
extern Mode currentMode;

/*! Indicates the current state the system is on, adjusted by the interrupts 
 * caused by IR Modules. */
extern InterruptStatePossible currentState;

/*!
 * \brief 	The interrupt service rountine of the system. Multiple 
 *        	interrupts can be handled at one go. currentState is 
 *					changed if IR Modules request an interrupt. currentMode
 *					is changed is switch requests an interrupt.
 * \param 	sources All the pins that requested an interrupt.
 * 
 * \see 		Interrupt section in the design brief.
 * 
 * \warning The initial currentState value needs to be set to S_IDLE before
 * 					using the isr to avoid errors.
 * 
 * Sources can indicate up to 32 pins that have requested an interrupt. If the 
 * switch (P_SW) gets triggered, the mode is changed to the next
 * corresponding mode. If either the IR modules (P_IR_1, P_IR_2) request an 
 * interrupt, the currentState is changed depending on which IR module 
 * requested an interrupt and the previous currentState. For more detailed actions 
 * refer to the Interrupt section found in the design brief where a state diagram 
 * is shown.
 */
void ir_isr(uint32_t sources);

/*!
 * \brief The interrupt service routine for the timer, used to indicate 
 * 				that the arriving/departing object failed to trigger both IR 
 * 				sensors within a specified time and that it will be counted 
 *				as an error. The currentState will be set to idle again and
 *				LED made to indicate an error.
 */
void timer_isr(void);

#endif
