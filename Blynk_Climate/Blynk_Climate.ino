#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>

BlynkTimer timer;

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

void setup() {
  Serial.begin(115200);
  delay(5000);
  ledSetup();
  bme280Setup();
  setupCO2();
  connect();
}

void loop()
{
  Blynk.run();
  timer.run();
}
