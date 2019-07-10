#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include <SPI.h>
#define echo 6
#define trig 7

long duration;
int d;

const int pinCS = 53; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
const int numberOfHorizontalDisplays = 4;
const int numberOfVerticalDisplays = 1;
const int wait = 20; // In milliseconds
const int spacer = 1;
const int width = 5 + spacer; // The font width is 5 pixels
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

int length;
String msg1;
String msg2;
String msg3;
unsigned long previousMillis = 0; 

void setup(){
  
  Serial.begin(9600);
  matrix.setIntensity(15); // Use a value between 0 and 15 for brightness
  // Adjust to your own needs
    matrix.setPosition(0, 0, 0); // The first display is at <0, 0>
    matrix.setPosition(1, 1, 0); // The second display is at <1, 0>
    matrix.setPosition(2, 2, 0); // The third display is at <2, 0>
    matrix.setPosition(3, 3, 0); // And the last display is at <3, 0>
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);


}



void loop(){
  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration=pulseIn(echo,HIGH);
  d= duration*0.034/2;
  
  Serial.print("Distnce:");
  Serial.println(d);
      msg1 = String(d) +"cm";
    length = msg1.length() * width;
    for (int i = 8; i>0; i--)
    {
      msg1 += " ";
    }
    matrix.setCursor(0,0); // Center text 
    matrix.fillScreen(LOW);
    matrix.print(msg1);
    matrix.write();
    delay(1000);

  

  
  
}
