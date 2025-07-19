#include "DFRobot_SHT20.h";
DFRobot_SHT20 sht20(&Wire, SHT20_I2C_ADDR);
const int ledPin = LED_BUILTIN;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  sht20.initSHT20();
  delay(100);
  pinMode(ledPin, OUTPUT);

}
