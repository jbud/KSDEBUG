/*
  KSDEBUG.h - Library for debugging with SSD1306 on KSDM3, REQUIRES Adafruit SSD1306 libs.
  Created by Joe Jackson, February 9, 2021.
  Released into the public domain.
*/
#ifndef KSDEBUG_h
#define KSDEBUG_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH    128 // OLED display width, in pixels
#define SCREEN_HEIGHT   64 // OLED display height, in pixels

#define OLED_RESET      -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS  0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32



class KSDEBUG
{
public:
    KSDEBUG();
    void writeln(char* v);
    void init();
private:
    
    int _i;
    Adafruit_SSD1306 _display;
};

#endif