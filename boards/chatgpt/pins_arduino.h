#pragma once

// ============================================================
// Bruce - ESP32-S3 N16R8 - Placa personalizada "chatgpt"
// ============================================================

// SPI principal
#define TFT_MOSI 11
#define TFT_SCLK 12
#define TFT_MISO 13

// TFT ST7789 240x320
#define TFT_CS   10
#define TFT_DC   16
#define TFT_RST  17

// Touch XPT2046
#define TOUCH_CS 9

// SD
#define SD_CS 8

// NRF24
#define NRF24_CE 4
#define NRF24_CS 5

// CC1101
#define CC1101_CS 7
#define CC1101_GDO0 6

// PN532
#define PN532_SS 18

// OLED I2C
#define SDA_PIN 39
#define SCL_PIN 38

