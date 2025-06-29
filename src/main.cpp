/**
 * Salut Rolf !
 *
 * Copyright (C) 2025, GPL-3.0-or-later, Nicolas Jeanmonod, ouilogique.com
 */

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "../fonts/Comic_Sans_MS_Bold13pt7b.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setupSSD1306()
{
    display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
    display.clearDisplay();
    display.setRotation(0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setFont(&Comic_Sans_MS_Bold13pt7b);
    display.setCursor(10, 22);
    display.println(F("Salut"));
    display.println(F("    Rolf !"));
    display.display();
}

void setupSerial()
{
    Serial.begin(BAUD_RATE);
}

void setup()
{
    setupSerial();
    setupSSD1306();
}

void loop()
{
    delay(1000 - millis() % 1000);
    Serial.printf("%12lu ms\n", millis());
    display.drawPixel(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, SSD1306_INVERSE);
    display.display();
}
