#include <EEPROM.h>
#define INTERVAL 1000
#define ADDRESS 0

byte seconds;
long previousMillis = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  EEPROM.begin(512);
  seconds = EEPROM.read(ADDRESS);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis > INTERVAL) {
    previousMillis = currentMillis;
    EEPROM.write(ADDRESS, ++seconds);
    EEPROM.commit();
    Serial.println(EEPROM.read(ADDRESS));
  }
}
