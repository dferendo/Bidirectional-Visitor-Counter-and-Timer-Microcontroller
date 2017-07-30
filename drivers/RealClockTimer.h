/*!
 *	\file   RealClockTimer.h
 *	\brief 	Controller for real time clock found in the chip.
 *
 *	Measures the passage of time to maintain a calendar and clock. Provides seconds,
 *	minutes and hours. Whenever the clock is re-enabled it will be reset.
 */
#ifndef REALCLOCKTIMER_H
#define REALCLOCKTIMER_H

/*! Holds the seconds, minutes and hours of the clock. */
typedef struct {
  int  sec;        //!< Second value - [0 - 59].
  int  min;        //!< Minute value - [0 - 59].
  int  hr;         //!< Hour value - [0 - 23].
} RTCTime;

/*!
 *  \brief Starts the clock. It will reset the clock to start from 0 seconds.
 */
void enable_clock(void);

/*!
 *	\brief Stops the clock. The lastest clock value will not be reset. 
 */
void disable_clock(void);

/*!
 *  \brief Get the current time of the clock.
 *	
 *  \param time 	The struct that will hold the current time.
 *
 * 	Returns the seconds, minutes and hours from the clock and 
 *  typecasted to integer values.
 */
void get_time(RTCTime * time);

#endif
