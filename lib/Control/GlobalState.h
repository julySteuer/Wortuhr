#include "RTClib.h"

namespace GlobalState {
    struct t_State {
        bool isRunning;
        DateTime lastChecked;
    } State = {false, DateTime(FPSTR(__DATE__), FPSTR(__TIME__))}; // Init to compile time timestamp 
}