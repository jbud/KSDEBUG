/*
  KSDEBUG.cpp - Library for debugging with SSD1306 on KSDM3, REQUIRES Adafruit SSD1306 libs.
  Created by Joe Jackson, February 9, 2021.
  Released into the public domain.
*/

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "KSDEBUG.h"
#include "splash.h"

KSDEBUG::KSDEBUG()
{
}

void KSDEBUG::writeln(char* v)
{
    _display.println(v);
    _display.display();
    delay(1000);
    _i++;
    if (_i >= 8) {
        _i = 0;
        _display.clearDisplay();
        _display.setCursor(0, 0);
    }
}

void KSDEBUG::init()
{
    _display = new Adafruit_SSD1306(128, 64, &Wire, -1);
    _display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    _display.clearDisplay();
    _display.drawBitmap((128 - splash1_width) / 2, (64 - splash1_height) / 2,
        splash1_data, splash1_width, splash1_height, 1);
    _display.display();
    delay(2000); // Pause for 2 seconds

    // Clear the buffer
    _display.clearDisplay();
    _display.setTextSize(2);      // Normal 1:1 pixel scale
    _display.setTextColor(SSD1306_WHITE); // Draw white text
    _display.setCursor(0, 0);     // Start at middle
    _display.cp437(true);
    _display.write("KSDM3\n");
    _display.write("Debug Tool\n");
    _display.setTextSize(1);
    _display.write("v0.9");
    _display.display();
    delay(2000);
    _display.clearDisplay();
    _display.setTextSize(1);      // Normal 1:1 pixel scale
    _display.setTextColor(SSD1306_WHITE); // Draw white text
    _display.setCursor(0, 0);     // Start at top-left corner
    _display.cp437(true);
    _i = 0;
}