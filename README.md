# Monitoring Temperature on 7-Segment
</br>

This project contain a code based on connection between TM1638 , Esp8266 , SHT20 and a 7-segment (LTD-322KD-31);
</br>
that monitoring Temperature and Humidity on serial monitor and shows the temperature on 7-segment.
</br>
</br>

# This is how it starts:
</br>

If the Temperature going ahead of 28°C , The LED lights up And its brightness is affected by temperature changes.</br>

If the temperature rises above 47°C, the LED will start flashing until the temperature drops below 47°C.</br>

When the device starts working, information about the ambient temperature and humidity is received by the SHT20 </br>

and sent to the ESP8266. Then, by connecting this component and the TM1638, the temperature Value is displayed on the 7-segment display.</br>
</br>


# List of Libraires which used in this code :
</br>

1- DFRobot_SHT20.h
</br>

2- TM1638.h

</br>
</br>

*** you can read other discriptions about some parts of the code in below link : </br>

<< https://github.com/Sobhanht/Brightness_Temp/blob/main/README.md >>
</br>
</br>
# Hints :</br>
*** Hint -1 :
</br>
```C++
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
```
A- This function takes a number from 0 to 9 and returns the corresponding binary value for displaying it on a 7-segment display.</br>
B- Each bit in the returned byte represents the on/off state of a segment in the display.</br>
C- Note: The binary values may vary depending on the type and configuration of the 7-segment display.</br>
</br>
*** Hint -2:
```C++ 
tm.displaySetBrightness(PULSE14_16);
```
A- Set the brightness of the 7-segment display to a high level (approximately 90–100%).</br>
</br>
*** Hint -3:
```C++
int temperature = round(temp)
```
A- Round the temperature value to the nearest whole number and store it in 'temperature'.</br>
</br>
*** Hint -4:
```C++ 
int yekan = temperature % 10;
``` 
A- Extract the ones (unit) digit of the temperature. </br>
```C++ 
int dahgan = temperature / 10;
```
B- Extract the tens digit of the temperature.</br>
</br>

*** Hint -5:
```C++
tm.displayDig(7, getBinaryForNumber(dahgan));
```
A- Display the tens digit on the leftmost 7-segment (position 7)</br>
```C++ 
tm.displayDig(6, getBinaryForNumber(yekan));
```
B-  Display the ones digit on the segment next to it (position 6)</br>

Board parts:
<img width="1280" height="606" alt="image" src="https://github.com/user-attachments/assets/466b9a8d-3a53-470c-8e97-e95ddcb5e8d3" />
 1- SHT20 Temperature and Humedity sensor .</br>
 2- ESP8266 micro controler . </br>
 3- Onboard LED .</br>
 4- TM1638 ic .</br>
 5- 7-Segment (LTD-322KD-31)</br>
</br>
You can see how this board and program work in the Link below:</br>
https://drive.google.com/file/d/14bUTkPwOohenCnhuUlnqbG6yIWm1A8Zo/view?usp=sharing





