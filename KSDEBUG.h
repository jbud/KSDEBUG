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