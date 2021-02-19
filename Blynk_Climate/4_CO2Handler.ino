#define RXD2 16
#define TXD2 17

byte CO2req[] = {0xFE, 0X44, 0X00, 0X08, 0X02, 0X9F, 0X25};
byte CO2out[] = {0, 0, 0, 0, 0, 0, 0};

void setupCO2() {
  Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
  timer.setInterval(2000, sendValuesBlynkCO2);
}

void sendValuesBlynkCO2() {
  // Get Data from the Sensor
  RequestCO2();
  unsigned long CO2 = CO2count();
  Blynk.virtualWrite(V3, CO2);
  Serial.println("CO2:" + CO2);
}



void RequestCO2 ()
{
  while (!Serial1.available())
  {
    Serial1.write(CO2req, 7);
    delay(50);
  }

  int timeout = 0;
  while (Serial1.available() < 7 )
  {
    timeout++;
    if (timeout > 10)
    {
      while (Serial1.available())
        Serial1.read();
      break;
    }
    delay(50);
  }

  for (int i = 0; i < 7; i++)
  {
    CO2out[i] = Serial1.read();
  }
}

unsigned long CO2count()
{
  int high = CO2out[3];
  int low = CO2out[4];
  unsigned long val = high * 256 + low;
  return val * 1; // S8 = 1. K-30 3% = 3, K-33 ICB = 10
}
