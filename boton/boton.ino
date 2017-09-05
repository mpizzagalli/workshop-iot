#include <ESP8266WiFi.h>

#define LED D2
#define BUTTON D1

int brightness = 0;
int fadeAmount = 1;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(115200);
}
void loop() {
  digitalWrite(LED, digitalRead(BUTTON));
  Serial.println(digitalRead(BUTTON));
}
