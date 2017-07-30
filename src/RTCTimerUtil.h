/*!																	
 * \file      RTCTimerUtil.h
 * \brief     Utility used to convert time taken from RTC driver to string format.
 */
#ifndef RTCTIMERUTIL_H
#define RTCTIMERUTIL_H

#include "RealClockTimer.h"

/*!
 * 	\brief Convert the time from a rtcTime struct to the passed string in
 *				 H:M:S format.
 */
void convertTimeToString(RTCTime * currentTime, char * outputString);

#endif
