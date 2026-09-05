#include "core/powerSave.h"
#include <interface.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

/***************************************************************************************
** Setup para ESP32-S3 N16R8 com ST7789 240x320 + OLED 0.93" secundária
** Módulos: PN532, NRF24, CC1101, GPS NEO 6M V2, IR HX53, Joystick KY043, Encoder JY050
** OLED 0.93" exibe os módulos ativos como um letreiro
** Interface em Português (Brasil)
***************************************************************************************/

// OLED Display object
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 oled_secondary(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void _setup_gpio() {
    // Initialize secondary OLED display via I2C
    if (!oled_secondary.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
        Serial.println("SSD1306 allocation failed");
    } else {
        oled_secondary.display();
        delay(2000);
        oled_secondary.clearDisplay();
        oled_secondary.setTextSize(1);
        oled_secondary.setTextColor(SSD1306_WHITE);
        oled_secondary.setCursor(0, 0);
        oled_secondary.println("CUSTOM BY LEANDRO");
        oled_secondary.println("Modulos Ativos");
        oled_secondary.display();
    }
}

void _post_setup_gpio() {}

int getBattery() { return 0; }

void _setBrightness(uint8_t brightval) {}

void displayActiveModules(String modules) {
    // Display active modules on OLED 0.93" (like a scrolling ticker)
    oled_secondary.clearDisplay();
    oled_secondary.setTextSize(1);
    oled_secondary.setTextColor(SSD1306_WHITE);
    oled_secondary.setCursor(0, 0);
    oled_secondary.println("Ativo:");
    oled_secondary.println(modules);
    oled_secondary.display();
}

void InputHandler(void) {
    checkPowerSaveTime();
    PrevPress = false;
    NextPress = false;
    SelPress = false;
    AnyKeyPress = false;
    EscPress = false;

    // Encoder and Joystick input handling
    if (false /*Conditions for all inputs*/) {
        if (!wakeUpScreen()) AnyKeyPress = true;
        else goto END;
    }
    if (false /*Conditions for previous btn*/) { PrevPress = true; }
    if (false /*Conditions for Next btn*/) { NextPress = true; }
    if (false /*Conditions for Esc btn*/) { EscPress = true; }
    if (false /*Conditions for Select btn*/) { SelPress = true; }
END:
    if (AnyKeyPress) {
        long tmp = millis();
        while ((millis() - tmp) < 200 && false /*Conditions for all inputs*/);
    }
}

String keyboard(String mytext, int maxSize, String msg) {}

void powerOff() {}

void checkReboot() {}
