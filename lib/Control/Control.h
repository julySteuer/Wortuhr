// States -> Running | Config

#include <ClockModule.h>
#include <ClockControl.h>
#include <Renderer.h>
#include <GlobalState.h>
#include <Networking.h>

namespace Control {
    const char* ssid = "Wortuhr";
    const char* password = "test1234";

    void handleConfig() { // This is procedual
        // Serve http TODO
        // get Credentials
        WebServer::run();
        // ClockModule::adjustClock();

    }

    void init() {
        init_networking("Wortuhr", "test1234");
        WebServer::init_server();
    }

    void handleRunning () {
        Serial.println("Now its going bonkers");
        // Get time
        DateTime currTime = ClockModule::getTime();
        // Every hour request new time from time server
        if ((GlobalState::State.lastChecked + TimeSpan(0,1,0,0)) < currTime) {
            // Recheck and reset from server
            GlobalState::State.lastChecked = currTime;
        }
        // parseTime
        ClockControl::t_TimeProperty parsedTime = ClockControl::parseTime(currTime.hour(), currTime.minute());
        // renderTime
        Rendering::renderTime(parsedTime);
    }

    void globalHandler() {
        if (GlobalState::State.isRunning) { // Same can be achived with enums but this will do the job with one byte to spare 
            handleRunning();
        } else {
            handleConfig();
        }
    }
}