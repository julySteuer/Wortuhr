#ifndef __NETWORKING
#define __NETWORKING
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Storage.h>

IPAddress init_networking(const char* ssid, const char* password) {
  WiFi.softAP(ssid, password); // init wifi
  return WiFi.softAPIP();
}

IPAddress connectWithWiFi(const char* ssid, Storage::t_Crendentials creds) {
  WiFi.begin(ssid, creds.password);
  while(WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(1000);
  }
  return WiFi.localIP();
}

namespace WebServer {
  ESP8266WebServer server(80);
  static const char root[] PROGMEM = "<html><form action='/submit' method='POST'><label for='username'>Username:</label><br><input type='text' id='username' name='username'><br><label for='username'>Password:</label><br><input type='text' id='username' name='username'><input type='submit'></form></html>";

  struct WebServerState {
    bool isRunning;
  } WebServerState = {false};

  namespace Routes {
    void handleRoot() {
      server.send(200, "text/html", FPSTR(root));
    }

    void sendCredentials() {
      String username = server.arg("username");
      String password = server.arg("password");
      // Save Credentials
      // Set Global State 
      WebServerState.isRunning = true;
      server.send(200, "text/html", username);
    }
  }

  void init_server() {
    server.begin();
    server.on("/", Routes::handleRoot);
    server.on("/submit", Routes::sendCredentials);
  }

  void run() {
    server.handleClient();
  }
}
#endif