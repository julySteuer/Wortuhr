#include "RTClib.h"

namespace ClockModule {
    RTC_DS3231 rtc;

    DateTime getTime() {
        return rtc.now();
    }

    void adjustClock(DateTime currTime) {
        rtc.adjust(currTime);
    }

    void initClock() {
        rtc.begin();
    }
}