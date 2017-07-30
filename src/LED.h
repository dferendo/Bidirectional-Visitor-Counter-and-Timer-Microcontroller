/*!																	
 * \file      LED.h
 * \brief     Controls an RGB LED.
 * 
 * Temporary light RGB LED depending on the action taken. 
 * Possible actions are Arrival (Green), Departure (Blue) 
 * and Error (Red). 
 */
#ifndef LED_H
#define LED_H

/*! Light time duration. */
#define EVENT_TRIG_US 200

/*! \brief Initializes the pins for the red, green, and blue LEDs.
 */
void led_init(void);

/*! \brief Sets the RGB LED to a certain colour.
 *  \param red_on    Turn on the red LED.
 *  \param green_on  Turn on the green LED.
 *  \param blue_on   Turn on the blue LED.
 */
void led_set(int red_on, int green_on, int blue_on);

/*!
 * \brief 	Temporary light the colour red on the RGB LED.
 * 
 * \warning Thread will be delayed depending on the specified 
 * 					time.
 */
void light_error(void);

/*!
 * \brief 	Temporary light the colour green on the RGB LED.
 *
 * \warning Thread will be delayed depending on the specified 
 * 					time.
 */
void light_arrival(void);

/*!
 * \brief 	Temporary light the colour blue on the RGB LED.
 *
 * \warning Thread will be delayed depending on the specified 
 * 					time.
 */
void light_departure(void);

#endif // LED_H
