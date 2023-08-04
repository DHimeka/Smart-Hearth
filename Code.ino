#include "max6675.h" // max6675.h file is part of the library that you should download from Robojax.com
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int soPin = 5;// SO=Serial Out
int csPin = 6;// CS = chip select CS pin
int sckPin = 7;// SCK = Serial Clock pin
int analogPin = A3; 
int celTemp;
int tempSet;
int fanPin1 = A1;
int fanPin2 = A0;
int T1;
int T2;
MAX6675 robojax(sckPin, csPin, soPin);// create instance object of MAX6675
bool prevLower = false; // keep track of whether temperature was outside range in previous iteration of loop
bool prevHigher = false;
int prevCount = 0; // keep track of iterations where temperature was below or above range consecutively
String prev_disp;

void setup() {

  pinMode(analogPin, INPUT);
  pinMode(fanPin1, OUTPUT);
  pinMode(fanPin2, OUTPUT);        
  Serial.begin(9600);// initialize serial monitor with 9600 baud
  Serial.println("Robojax MAX6675"); 

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(30, 10);
  display.println("   HELLO   ");
  display.display();
  prev_disp = "   HELLO   ";
}

void disp(String txt1,String txt2){  //OLED Display Function
  if(txt1!=txt2){
    display.setCursor(30, 10);
    display.setTextColor(BLACK);
    display.println(txt2);
    display.display();
    display.setCursor(30,10);
    display.setTextColor(WHITE);
    display.println(txt1);
    display.display();
  }
}

void loop() {
  // basic readout test, just print the current temp
  // Robojax.com MAX6675 Temperature reading on Serial monitor
   celTemp=robojax.readCelsius();
   tempSet=analogRead(analogPin);
   Serial.print("C = "); 
   Serial.print(celTemp);
   //Serial.print(" C = ");
   //Serial.println(robojax.readCelsius());
   Serial.print(" Controller= ");
   Serial.print(tempSet);

 //celTemp = 200;

   if(tempSet<200){
    T1 = 50;
    T2 = 120; 
    disp("     LOW   ",prev_disp);
    prev_disp = "     LOW   ";
   }else if(tempSet<300){
    T1 = 120;
    T2 = 150;
    disp(" MEDIUM LOW",prev_disp);
    prev_disp = " MEDIUM LOW";
   }else if(tempSet<400){
    T1 = 150;
    T2 = 190;
    disp("  MEDIUM   ",prev_disp);
    prev_disp = "  MEDIUM   ";
   }else if(tempSet<500){
    T1 = 190;
    T2 = 231;
    disp("MEDIUM HIGH",prev_disp);
    prev_disp = "MEDIUM HIGH";
   }else if(tempSet<600){
    T1 = 231;
    T2 = 288;
    disp("    HIGH   ",prev_disp);
    prev_disp = "    HIGH   ";
   }else if(tempSet<700){
    T1 = 288;
    T2 = 372;
    disp(" VERY HIGH ",prev_disp); 
    prev_disp = " VERY HIGH ";
   }

   if(celTemp<T1){
    analogWrite(fanPin1,0);
    analogWrite(fanPin2,255);
    if (prevLower) {
         prevCount++;
      } else {
        prevLower = true;
        prevHigher = false;
        prevCount = 1;
      }
   }else if(celTemp<T2){
    analogWrite(fanPin1,0);
    analogWrite(fanPin2,140);
    prevCount = 0;
    prevLower = false;
    prevHigher = false;
   }else{
    analogWrite(fanPin1,0);
    analogWrite(fanPin2,0);
    if (prevHigher) {
         prevCount++;
      } else {
        prevLower = false;
        prevHigher = true;
        prevCount = 1;
      }
   }

   if (prevCount > 600) { // if temperature has consecutively been lower or higher for n number of iterations then do something
      
    tone(4,255);
    display.setTextColor(WHITE);
    display.setCursor(30, 20);
    display.println("   ERROR   ");
    display.display();
    }
  else{
    display.setTextColor(BLACK);
    display.setCursor(30, 20);
    display.println("   ERROR   ");
    display.display();
    noTone(4);
    }

  Serial.print("\n loop");
  Serial.print(prevCount);
  Serial.print(prevLower);
  Serial.print(prevHigher);   
             
   delay(1000);
}
