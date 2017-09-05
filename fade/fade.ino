#include <ESP8266WiFi.h>

#define LED D2
int brightness = 0;
int fadeAmount = 8;


void setup() {
  pinMode(LED, OUTPUT);
}
void loop() {
  analogWrite(LED, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30);
}
