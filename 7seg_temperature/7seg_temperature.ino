#include "DFRobot_SHT20.h";
#include <TM1638.h>

  #define DIO 13 
  #define CLK 10
  #define STB 14
  TM1638 tm(CLK, DIO, STB);

  byte getBinaryForNumber(int num) {
   switch (num) {
    case 1: return 0b11000000;
    case 2: return 0b10110111;
    case 3: return 0b11010111;
    case 4: return 0b11001001;
    case 5: return 0b01011111;
    case 6: return 0b01111111;
    case 7: return 0b11000100;
    case 8: return 0b11111111;
    case 9: return 0b11011111;
    case 0: return 0b11111110;
    default: return 0b00000000;
  }
}
  DFRobot_SHT20 sht20(&Wire, SHT20_I2C_ADDR);
  const int ledPin = LED_BUILTIN;
  int brightness  = 0;

void setup() {
  Serial.begin(115200);
  tm.displaySetBrightness(PULSE14_16);
  tm.reset();
  tm.test ();
  sht20.initSHT20();
  delay(100);
  sht20.checkSHT20();
  pinMode(ledPin, OUTPUT);
  
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

  int yekan    = temperature % 10; 
  int dahgan = (temperature / 10);
  tm.displayDig(7, getBinaryForNumber(dahgan)); //for left segment
  tm.displayDig(6, getBinaryForNumber(yekan)); //for right segment

  if (temperature>39)
  {
      digitalWrite(ledPin ,1);
      delay(50);
      digitalWrite(ledPin ,0);
      delay(50);
  }

  else 
  {
  brightness = map(temp, 40, 20, 0, 255);
  analogWrite(ledPin, brightness);
  delay(1000);
  }

}
