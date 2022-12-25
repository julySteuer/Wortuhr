// States -> Running | Config

#include <ClockModule.h>
#include <ClockControl.h>
#include <Renderer.h>
#include <Networking.h>

namespace Control {
    struct t_Controller {
        bool isRunning; 
        DateTime lastChecked;
    } GlobalController = {false, DateTime(FPSTR(__DATE__), FPSTR(__TIME__))}; // First init to compile time datetime 

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
        if ((GlobalController.lastChecked + TimeSpan(0,1,0,0)) < currTime) {
            // Recheck and reset from server
            GlobalController.lastChecked = currTime;
        }
        // parseTime
        ClockControl::t_TimeProperty parsedTime = ClockControl::parseTime(currTime.hour(), currTime.minute());
        // renderTime
        Rendering::renderTime(parsedTime);
    }

    void globalHandler() {
        if (WebServer::WebServerState.isRunning) { // Same can be achived with enums but this will do the job with one byte to spare 
            handleRunning();
        } else {
            handleConfig();
        }
    }
}