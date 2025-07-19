#include "DFRobot_SHT20.h";
DFRobot_SHT20 sht20(&Wire, SHT20_I2C_ADDR);
const int ledPin = LED_BUILTIN;
void setup() {
  sht20.initSHT20();
  delay(100);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  float humd = sht20.readHumidity();
  float temp = sht20.readTemperature();
  int temperature = round(temp)

  Serial.print("Time");
  Serial.print(millis());
  Serial.print("Temprature:");
  Serial.print(temperature);
  Serial.print(" Humidity:");
  Serial.print(humd, 1);
  Serial.print("%");
}
