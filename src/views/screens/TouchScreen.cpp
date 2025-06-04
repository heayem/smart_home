#include "TouchScreen.h"
#include "command/led/LedCommands.h"
#include <Arduino.h>

// Define pins for TFT display
#define TFT_DC 15
#define TFT_CS 5

// Button dimensions
#define BUTTON_WIDTH 90
#define BUTTON_HEIGHT 40

// Global state for LED toggle
bool ledState = false;

// TFT and capacitive touchscreen instances
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_FT6206 ctp = Adafruit_FT6206();
U8G2_FOR_ADAFRUIT_GFX u8g2_for_adafruit_gfx;

// Initialize the display and touchscreen
void initTouchScreen()
{
    tft.begin();

    // Initialize touch controller with sensitivity threshold
    if (!ctp.begin(40))
    {
        Serial.println("Couldn't start FT6206 touchscreen controller");
        while (1)
            ; // Stop execution if touch controller fails
    }

    // Clear screen and draw UI
    tft.fillScreen(ILI9341_BLACK);
    drawUI();
}

// Draw the label and toggle button on screen
void drawUI()
{
    // Clear screen
    tft.fillScreen(ILI9341_BLACK);

    // --- Draw the blue label banner ---
    int rectX = 1, rectY = 1;
    int rectWidth = 240, rectHeight = 40;
    tft.fillRect(rectX, rectY, rectWidth, rectHeight, ILI9341_BLUE);

    // Label text
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.setCursor(rectX + 8, rectY + 10);
    tft.println("Welcome Smart Home");

    // --- Draw the ON/OFF button starting from the left ---
    int buttonX = 4; // LEFT-aligned with some margin
    int buttonY = rectY + rectHeight + 14;

    tft.fillRect(buttonX, buttonY, BUTTON_WIDTH, BUTTON_HEIGHT, ILI9341_WHITE);

    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(2);
    tft.setCursor(buttonX + 12, buttonY + 12);
    tft.println("ON/OFF");
}

// Handle touch input
void handleTouch()
{
    delay(10); // Debounce delay

    if (!ctp.touched())
        return;

    TS_Point p = ctp.getPoint();

    // Convert coordinates to match TFT orientation
    p.x = map(p.x, 0, 240, 240, 0);
    p.y = map(p.y, 0, 320, 320, 0);

    Serial.printf("Touch: (%d, %d)\n", p.x, p.y);

    ledState = !ledState;
    handleSerialLedCommand(ledState ? "1" : "2");
}
