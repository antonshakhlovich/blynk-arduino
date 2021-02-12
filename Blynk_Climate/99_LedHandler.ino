int OUTPUT_LED = 2;

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  digitalWrite(OUTPUT_LED, pinValue);
}

int ledSetup() {
  pinMode(OUTPUT_LED, OUTPUT);
  digitalWrite(OUTPUT_LED, HIGH);
  return OUTPUT_LED;
}

void blinkLed() {
  for(int i = 0; i < 5; i++) {
    delay(100);
    digitalWrite(OUTPUT_LED, HIGH);
    delay(100);
    digitalWrite(OUTPUT_LED, LOW);
  }
  Blynk.syncVirtual(V2);
}
