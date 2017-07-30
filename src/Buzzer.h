/*!																	
 * \file      Buzzer.h
 * \brief     Control the buzzer.
 * 
 * Temporary makes the buzzer produce a sound and interface
 * with the GPIO bis.
 */
#ifndef BUZZER_H
#define BUZZER_H

/*! Pin 10 on the microcontroller. */
#define P_BUZZ P0_1	

/*! Light time duration. */
#define EVENT_TRIG 200
/*! Buzzer is on. */
#define BUZZ_ON 1	
/*! Buzzer is off. */
#define BUZZ_OFF 0

/*!
 * \brief Initialised GPIO bus to communicate with the Buzzer pin
 * 				P0_1.
 */
void buzz_init(void);

/*!
 * \brief	 	Temporary enable the buzzer to transmit a sound for a limited
 *  				time.
 *
 * \warning Thread will be delayed depending on the specified 
 * 					time.
 */
void buzz_enable(void);

#endif
