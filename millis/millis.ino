#include <ESP8266WiFi.h>
#define INTERVAL 1000
#define LED_PIN_BLUE D2
#define LED_PIN_GREEN D1
#define LED_PIN_RED D0

int ledState = LOW;
long previousMillis = 0;
int ledPin = LED_PIN_BLUE;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN_BLUE, OUTPUT);
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);
  digitalWrite(ledPin, LOW); 
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
          
  if(currentMillis - previousMillis > INTERVAL) {
    previousMillis = currentMillis;
    unsigned long milis = currentMillis / 3000; 
    digitalWrite(LED_PIN_RED, HIGH);
    digitalWrite(LED_PIN_BLUE, HIGH);
    digitalWrite(LED_PIN_GREEN, HIGH);
    if (milis % 15 == 0) {
      digitalWrite(LED_PIN_RED, LOW);
    }
    if (milis % 5 == 0) {
      digitalWrite(LED_PIN_BLUE, LOW);
    }
    if (milis % 3 == 0) {
      digitalWrite(LED_PIN_GREEN, LOW);
    }
  }
}
