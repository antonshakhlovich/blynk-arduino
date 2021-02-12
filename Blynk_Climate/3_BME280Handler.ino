#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

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
  timer.setInterval(3000, printValues);
}


void bme280Values(int values[]) {
  values[0] = bme.readTemperature();
  values[1] = bme.readPressure() / 100.0F;
  values[2] = bme.readAltitude(SEALEVELPRESSURE_HPA);
  values[3] = bme.readHumidity();
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
