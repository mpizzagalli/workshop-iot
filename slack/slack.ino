#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid     = "WoloxHQPublic";
const char* password = "Wolox4all";

#define FINGERPRINT "AC 95 5A 58 B8 4E 0B CD B3 97 D2 88 68 F5 CA C1 0A 81 E3 6E"

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("WiFi connected");  

  HTTPClient http;                 
  http.begin("https://hooks.slack.com/services/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", FINGERPRINT);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.POST("{\"text\": \":sad-non-vector-coluccio: :sad-non-vector-coluccio: :sad-non-vector-coluccio: :sad-non-vector-coluccio: :sad-non-vector-coluccio: \"}");
  http.end();
}

void loop() {
  
}

