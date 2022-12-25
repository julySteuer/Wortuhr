// States -> Running | Config
#include <ClockModule.h>
#include <ClockControl.h>
#include <Renderer.h>

namespace Control {
    struct t_Controller {
        bool isRunning; 
    } GlobalController = {false};

    void handleConfig() {
        // Serve http TODO

        // get Credentials

        // Connect with wifi

        // get time 

        // parse Time

        // adjust rtc clock
        // ClockModule::adjustClock();

    }

    void handleRunning () {
        // Get time
        DateTime currTime = ClockModule::getTime();
        // parseTime
        ClockControl::t_TimeProperty parsedTime = ClockControl::parseTime(currTime.hour(), currTime.minute());
        // renderTime
        Rendering::renderTime(parsedTime);
    }

    void globalHandler() {
        if (GlobalController.isRunning) { // Same can be achived with enums but this will do the job with one byte to spare 
            handleRunning();
        } else {
            handleConfig();
        }
    }
}