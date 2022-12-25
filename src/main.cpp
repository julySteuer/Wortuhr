#include <Control.h>


void setup() {
  Serial.begin(9600);
  Control::init();
}

void loop() {
  Control::globalHandler();
}


