#include <Arduino.h>
#include <Control.h>

const char* ssid = "Wortuhr";
const char* password = "test1234";

void setup() {
  Serial.begin(9600);
}

void loop() {
  // WebServer::run();
  Control::globalHandler();
}