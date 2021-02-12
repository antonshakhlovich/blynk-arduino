#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

void setup() { 
  ledSetup();
  Serial.begin(115200);
  connect();
}

void loop()
{
  Blynk.run();    
}
