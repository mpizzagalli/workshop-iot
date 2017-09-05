#include <ESP8266WiFi.h>

#define LED D2
#define SENSOR D8


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);
  Serial.begin(115200);
}
void loop() {
  int value = digitalRead(SENSOR);
  Serial.println(String("Humedad sensada: ") + value);
  digitalWrite(LED, value);
}

