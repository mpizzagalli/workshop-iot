#include <ESP8266WiFi.h>

#define SENSOR A0

void setup() {
  Serial.begin(115200);
}

void loop() {
  int RawValue = analogRead(SENSOR);
  int temp = (RawValue * 300)/1024;
  Serial.println(String("Hacen ") + temp + " Grados");
  delay(30);
}
