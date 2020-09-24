/*
This is an example of how to use the OLED 128x64 I2C with SSD1306 driver using the Adafruit library.
It also applies to the 128x32 version, but not all components would fit the smaller screen.

Pins:
 * GND = GND
 * VCC = 5V
 * SCL = A5
 * SDA = A4

You can connect VCC to 3.3V to reduce the amount of high pitched noise that the display produces.

It's a good idea to put a resistor between A4-5V and A5-5V to help stabilize the connection.
What that does is pull-up the I2C pins to make it more reliable and prevents lock-ups.


Libraries needed:
https://github.com/adafruit/Adafruit_SSD1306
https://github.com/adafruit/Adafruit-GFX-Library


Guide for the GFX Library: https://cdn-learn.adafruit.com/downloads/pdf/adafruit-gfx-graphics-library.pdf

List of fonts: https://learn.adafruit.com/adafruit-gfx-graphics-library/using-fonts

List of fonts that support right alignment:
FreeMono9pt7b.h
FreeMono12pt7b.h
FreeMono18pt7b.h
FreeMono24pt7b.h
FreeMonoBold9pt7b.h
FreeMonoBold12pt7b.h
FreeMonoBold18pt7b.h
FreeMonoBold24pt7b.h
FreeMonoBoldOblique9pt7b.h
FreeMonoBoldOblique12pt7b.h
FreeMonoBoldOblique18pt7b.h
FreeMonoBoldOblique24pt7b.h
FreeMonoOblique9pt7b.h  
FreeMonoOblique12pt7b.h
FreeMonoOblique18pt7b.h
FreeMonoOblique24pt7b.h


This sketch was featured on my video tutorial for this display: https://www.youtube.com/watch?v=PrIAnDZ9dp8

Sketch made by: InterlinkKnight
Last modification: 10/05/2019
*/



#include <Adafruit_GFX.h>  // Include core graphics library for the display
#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display
#include <Fonts/FreeMono9pt7b.h>  // Add a custom font
#include <DHT.h>  // Include Adafruit Sensors library to drive the display
Adafruit_SSD1306 display(128, 64);  // Create display
#define DHTTYPE DHT11  // Set DHT Type
#define DHTPIN 9  // Set DHT pin




DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT

float hum;  //  Humidity Variable

float temp; //  Temperature Variable

boolean heatON = false;


void setup()  // Start of setup
{                

  pinMode(8,OUTPUT);

  delay(100);  // This delay is needed to let the display to initialize

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
 
  display.clearDisplay();  // Clear the buffer

  display.setTextColor(WHITE);  // Set color of the text

  display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3

  display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.
                               // To override this behavior (so text will run off the right side of the display - useful for
                               // scrolling marquee effects), use setTextWrap(false). The normal wrapping behavior is restored
                               // with setTextWrap(true).

  display.dim(0);  //Set brightness (0 is maximun and 1 is a little dim)

  dht.begin();

  digitalWrite(8,HIGH);  //Turn on Relay

}  // End of setup





void loop()  // Start of loop
{

  char stringHumidity[10];
  
  char stringTemperature[10];

  hum = dht.readHumidity();  //Read Humidity from the DHT11
  
  temp = dht.readTemperature();  //Read Teamperature from the DHT11

  display.clearDisplay();  // Clear the display so we can refresh

  display.setFont(&FreeMono9pt7b);  // Set a custom font
  
  display.setTextSize(0);  // Set text size. We are using a custom font so you should always use the text size of 0

  // Print Temperature text:
  display.setCursor(4, 10);  // (x,y)
  display.println("Temperature");  // Text or value to print

  // Draw rectangle:
  display.drawRect(32, 16, 64, 16, WHITE);  // Draw rectangle (x,y,width,height,color)from the location to down-right
   
  // Print variable with left alignment:
  display.setCursor(36, 28);  // (x,y)
  dtostrf(temp, 2, 2, stringTemperature);
  display.println(stringTemperature);  // Text or value to print

  // Print Humidity text:
  display.setCursor(20, 43);  // (x,y)
  display.println("Humidity");  // Text or value to print

  // Draw rounded rectangle:
  display.drawRoundRect(32, 48, 64, 16, 16, WHITE);  // Draw rounded rectangle (x,y,width,height,radius,color)from the location to down-right

  // Print variable with right alignment:
  display.setCursor(36, 60);  // (x,y)
  dtostrf(hum, 2, 2, stringHumidity);
  display.println(stringHumidity);  // Text or value to print

  if(temp<=25){
    heatON = true;
    digitalWrite(8,LOW);  //Turn off Relay
  }
  if(temp>=30){
    heatON = false;
    digitalWrite(8,HIGH);  //Turn on Relay
  }
  
  display.display();  // Print everything we set previously
  
  delay(2000);

}  // End of loop
