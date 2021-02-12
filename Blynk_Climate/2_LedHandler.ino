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
