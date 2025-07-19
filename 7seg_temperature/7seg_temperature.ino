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
    case 0: return 0b11111110;fir
    default: return 0b00000000;
  }
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
