#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

BlynkTimer timer;

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

void setup() {
  Serial.begin(115200);
  delay(5000);
  ledSetup();
  bme280Setup();
  connect();
}

void loop()
{
  Blynk.run();
  timer.run();
}
