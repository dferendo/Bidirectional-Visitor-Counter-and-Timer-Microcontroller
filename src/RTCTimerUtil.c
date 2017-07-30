#include "RTCTimerUtil.h"

// Utility
#include <stdio.h>

void convertTimeToString(RTCTime * currentTime, char * outputString) {
	sprintf(outputString, "Time: %02d:%02d:%02d", currentTime -> hr, currentTime -> min, currentTime -> sec);
}
