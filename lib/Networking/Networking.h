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

  void handleRoot() {
    Serial.println("Here");
    server.send(200, "text/html", "<h1>Hello World</h1>");
  }

  void init_server() {
    server.on("/", handleRoot);
  }

  void run() {
    server.handleClient();
  }
}