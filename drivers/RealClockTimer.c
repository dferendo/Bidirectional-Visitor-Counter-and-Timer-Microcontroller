#include "RealClockTimer.h"

// Board Interfacing
#include "LPC407x_8x_177x_8x.h"

void enable_clock(void) {
	// Setting clock to default 0.
	LPC_RTC -> SEC = 0;
	LPC_RTC -> MIN = 0;
	LPC_RTC -> HOUR = 0;
	// Enable Clock.
	LPC_RTC -> CCR = 1;
}

void disable_clock(void) {
	LPC_RTC -> CCR = 0;
}

void get_time(RTCTime * time) {
	// The current Time is saved in the passed argument.
	time -> sec = (int) LPC_RTC -> SEC;
	time -> min = (int) LPC_RTC -> MIN;
	time -> hr  = (int) LPC_RTC -> HOUR;
}
