#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid     = "WoloxHQPublic";
const char* password = "Wolox4all";

#define FINGERPRINT "AC 95 5A 58 B8 4E 0B CD B3 97 D2 88 68 F5 CA C1 0A 81 E3 6E"

#define LED_HUMEDAD D0
#define LED_LUZ D1
#define SENSOR_HUMEDAD D4
#define SENSOR_LUZ D8
#define SENSOR_TEMP A0

void setup() {
  pinMode(LED_HUMEDAD, OUTPUT);
  pinMode(LED_LUZ, OUTPUT);
  pinMode(SENSOR_HUMEDAD, INPUT);
  pinMode(SENSOR_LUZ, INPUT);

  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("WiFi connected");  
}

void loop() {
  int value_humedad = digitalRead(SENSOR_HUMEDAD);
  int value_luz = digitalRead(SENSOR_LUZ);
  int RawValue = analogRead(SENSOR_TEMP);
  int temp = (RawValue * 300)/1024;
  Serial.println(String("Hacen ") + temp + " Grados");
  Serial.println(String("Luz sensada: ") + value_luz + " , Humedad sensada:" + value_humedad + " y temperatura: " + temp);
  digitalWrite(LED_LUZ, value_luz);
  digitalWrite(LED_HUMEDAD, value_humedad);

  char* string_luz;
  char* string_humedad;
  if (value_luz == 1) {
    string_luz = "desnudo";
  } else {
    string_luz = "con poca ropa";
  }

  if (value_humedad == 1) {
    string_humedad = "seco";
  } else {
    string_humedad = "humedo";
  }
  
  HTTPClient http;                 
  http.begin("https://hooks.slack.com/services/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", FINGERPRINT);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.POST(String("{\"text\": \"") + "Prudi :prudi: esta " + string_luz + ", " + string_humedad + " y a " + temp + " grados :eggplant: :sad-non-vector-coluccio: y sigue sin ser gracioso.\"}");
  http.end();

  delay(10000);
}

