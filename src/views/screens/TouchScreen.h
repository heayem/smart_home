#ifndef TOUCH_SCREEN_H
#define TOUCH_SCREEN_H

#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>
#include <U8g2_for_Adafruit_GFX.h>

extern Adafruit_ILI9341 tft;
extern Adafruit_FT6206 ctp;
extern U8G2_FOR_ADAFRUIT_GFX u8g2_for_adafruit_gfx;

void initTouchScreen();
void drawUI();
void handleTouch();

#endif
