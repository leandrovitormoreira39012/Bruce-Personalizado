#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

// ESP32-S3 N16R8 com ST7789 240x320 + Oled 0.93" secundária
// Suporte completo: PN532, NRF24, CC1101, GPS NEO 6M V2, IR HX53, Joystick KY043, Encoder JY050
// Tela OLED 0.93" via I2C para exibir módulos ativos (letreiro)

#define USB_VID 0x303a
#define USB_PID 0x1001

static const uint8_t TX = 43;
static const uint8_t RX = 44;

static const uint8_t TXD2 = 1;
static const uint8_t RXD2 = 2;

static const uint8_t SDA = 13;
static const uint8_t SCL = 15;

static const uint8_t SS = -1;
static const uint8_t MOSI = -1;
static const uint8_t MISO = -1;
static const uint8_t SCK = -1;

static const uint8_t G0 = 0;
static const uint8_t G1 = 1;
static const uint8_t G2 = 2;
static const uint8_t G3 = 3;
static const uint8_t G4 = 4;
static const uint8_t G5 = 5;
static const uint8_t G6 = 6;
static const uint8_t G7 = 7;
static const uint8_t G8 = 8;
static const uint8_t G9 = 9;
static const uint8_t G10 = 10;
static const uint8_t G11 = 11;
static const uint8_t G12 = 12;
static const uint8_t G13 = 13;
static const uint8_t G14 = 14;
static const uint8_t G15 = 15;
static const uint8_t G39 = 39;
static const uint8_t G40 = 40;
static const uint8_t G41 = 41;
static const uint8_t G42 = 42;
static const uint8_t G43 = 43;
static const uint8_t G44 = 44;
static const uint8_t G46 = 46;

static const uint8_t ADC1 = 7;
static const uint8_t ADC2 = 8;

// ST7789 Display Pins (240x320)
#define USER_SETUP_LOADED 1
#define ST7789_2_DRIVER 1
#define TFT_RGB_ORDER 1
#define TFT_WIDTH 240
#define TFT_HEIGHT 320
#define TFT_BACKLIGHT_ON 1
#define TFT_BL 4
#define TFT_RST 15
#define TFT_DC 7
#define TFT_MOSI 6
#define TFT_SCLK 5
#define TFT_CS 16
#define TOUCH_CS 11
#define HAS_TOUCH 1
#define SMOOTH_FONT 1
#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 20000000
#define SPI_TOUCH_FREQUENCY 2500000

// SD Card Pins
#define SDCARD_CS 40
#define SDCARD_SCK 5
#define SDCARD_MISO 41
#define SDCARD_MOSI 6

// Encoder JY050 Pins (5-way)
#define ENCODER_CLK 12
#define ENCODER_DT 13
#define ENCODER_SW 14
#define ENCODER_UP 20
#define ENCODER_DOWN 19

// Joystick KY043 Pins
#define JOYSTICK_X 3
#define JOYSTICK_Y 9
#define JOYSTICK_SW 14

// I2C Pins (PN532 NFC + OLED 0.93" secundária)
#define GROVE_SDA 18
#define GROVE_SCL 8
#define OLED_SDA 18
#define OLED_SCL 8
#define OLED_ADDRESS 0x3C

// SPI Pins
#define SPI_SCK_PIN 5
#define SPI_MOSI_PIN 6
#define SPI_MISO_PIN 41
#define SPI_SS_PIN 16

// NRF24L01 Pins
#define NRF24_CE_PIN 21
#define NRF24_SS_PIN 47
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

// CC1101 Pins
#define CC1101_GDO0_PIN 35
#define CC1101_SS_PIN 47
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

// IR Pins (HX53)
#define IR_TX_PINS '{{"GPIO 1", 1}, {"GPIO 2", 2}}'
#define IR_RX_PINS '{{"GPIO 2", 2}, {"GPIO 1", 1}}'
#define TXLED 1
#define LED_ON HIGH
#define LED_OFF LOW

// GPS Pins (NEO 6M V2)
#define SERIAL_TX 17
#define SERIAL_RX 38
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX

// Battery ADC Pin
#define BAT_PIN 10

// Button Configuration
#define HAS_BTN 0
#define BTN_ALIAS "\"Ok\""
#define BTN_PIN 0
#define BTN_ACT LOW

// Screen Setup
#define HAS_SCREEN 1
#define ROTATION 1
#define MINBRIGHT 160

// OLED Display Setup (0.93" - Module indicator)
#define HAS_OLED_SECONDARY 1
#define OLED_SECONDARY_WIDTH 128
#define OLED_SECONDARY_HEIGHT 32

// Language - Portuguese Brazil
#define LANGUAGE_PT_BR 1

// Font sizes
#define FP 1
#define FM 2
#define FG 3

#endif /* Pins_Arduino_h */