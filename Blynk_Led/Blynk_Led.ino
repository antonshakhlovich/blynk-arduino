#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "nG2m27dGxppSe48hUjcDRQQDDkkOrmw0";
char ssid[] = "Keenetic-2906";
char pass[] = "863NitNQ";
int OUTPUT_LED = 2;

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  digitalWrite(OUTPUT_LED, pinValue);
}

void setup() { 
  pinMode(OUTPUT_LED, OUTPUT);
  digitalWrite(OUTPUT_LED, HIGH);
  Serial.begin(115200);
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected"); 
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  Blynk.run();    
}
