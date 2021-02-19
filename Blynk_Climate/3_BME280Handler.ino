#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

void bme280Setup() {
  Serial.println(F("BME280 test"));

  bool status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  Serial.print("BME Serial ID:");
  Serial.println(bme.sensorID(),16);
  blinkLed();
  timer.setInterval(10000, printValues);
  timer.setInterval(10000, sendValuesBlynk);
}


void bme280Values(float values[]) {
  values[0] = bme.readTemperature();
  values[1] = bme.readHumidity();
  values[2] = bme.readPressure() / 100.0F;
  values[3] = bme.readAltitude(SEALEVELPRESSURE_HPA);
}



void printValues() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");

  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println();
}

void sendValuesBlynk() {
  float values[4];
  bme280Values(values);
  Blynk.virtualWrite(V0, String(values[0], 1));
  Blynk.virtualWrite(V1, String(values[1], 1));
}
