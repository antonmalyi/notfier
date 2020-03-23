#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void displayPrint(String string, byte x=0, byte y=0)
{
  display.clearDisplay();
  display.setCursor(x, y);
  display.print(string);
  display.display();

}


bool displaySetup()
{

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
      return false;
  }

  display.clearDisplay();
  display.display();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  return true;
}
