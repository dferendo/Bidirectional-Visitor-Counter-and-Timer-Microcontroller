/*!																	
 * \file      IRModule.h
 * \brief     Controls an IR sensor.
 */
#ifndef IRMODULE_H						
#define IRMODULE_H

// Driver Libraries
#include "Gpio.h"

/*! Pin 8 on microcontroller. */
#define P_IR_1 P0_21 	
/*! Pin 9 on microcontroller. */
#define P_IR_2 P0_0		

/*!
 * 	\brief Initialised GPIO bus to communicate with the IR pins
 * 				 P0_21, P0_0.
 */
void ir_init(void);

/*!
 * \brief Gets logical value at IR Module pins.
 * 				1 Collision, 0 no Collision
 */
int ir_get(Pin pin);

#endif
