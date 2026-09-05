#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

// ESP32 30 pinos com ST7735 128x160
// Suporte completo: PN532, NRF24, CC1101, GPS NEO 6M V2, IR HX53, Joystick KY043, Encoder JY050

#define USB_VID 0x303a
#define USB_PID 0x1001

static const uint8_t TX = 1;
static const uint8_t RX = 3;

static const uint8_t TXD2 = 16;
static const uint8_t RXD2 = 17;

static const uint8_t SDA = 21;
static const uint8_t SCL = 22;

static const uint8_t SS = -1;
static const uint8_t MOSI = -1;
static const uint8_t MISO = -1;
static const uint8_t SCK = -1;

// ST7735 Display Pins (128x160)
#define USER_SETUP_LOADED 1
#define ST7735_DRIVER 1
#define TFT_RGB_ORDER 1
#define TFT_WIDTH 128
#define TFT_HEIGHT 160
#define TFT_BACKLIGHT_ON 1
#define TFT_BL 2
#define TFT_RST 4
#define TFT_DC 15
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS 5
#define TOUCH_CS 19
#define HAS_TOUCH 1
#define SMOOTH_FONT 1
#define SPI_FREQUENCY 20000000
#define SPI_READ_FREQUENCY 20000000
#define SPI_TOUCH_FREQUENCY 2500000

// SD Card Pins (from TFT module)
#define SDCARD_CS 25
#define SDCARD_SCK 18
#define SDCARD_MISO 12
#define SDCARD_MOSI 23

// Encoder JY050 Pins (5-way)
#define ENCODER_CLK 32
#define ENCODER_DT 33
#define ENCODER_SW 34
#define ENCODER_UP 35
#define ENCODER_DOWN 36

// Joystick KY043 Pins
#define JOYSTICK_X 39
#define JOYSTICK_Y 36
#define JOYSTICK_SW 34

// I2C Pins (PN532 NFC)
#define GROVE_SDA 21
#define GROVE_SCL 22

// SPI Pins
#define SPI_SCK_PIN 18
#define SPI_MOSI_PIN 23
#define SPI_MISO_PIN 12
#define SPI_SS_PIN 5

// NRF24L01 Pins
#define NRF24_CE_PIN 26
#define NRF24_SS_PIN 27
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

// CC1101 Pins
#define CC1101_GDO0_PIN 13
#define CC1101_SS_PIN 14
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

// IR Pins (HX53)
#define IR_TX_PINS '{{"GPIO 25", 25}, {"GPIO 26", 26}}'
#define IR_RX_PINS '{{"GPIO 27", 27}, {"GPIO 28", 28}}'
#define TXLED 25
#define LED_ON HIGH
#define LED_OFF LOW

// GPS UART Pins (NEO 6M V2)
#define SERIAL_TX 16
#define SERIAL_RX 17
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX

// Battery ADC Pin
#define BAT_PIN 35

// Button Configuration
#define HAS_BTN 0
#define BTN_ALIAS "\"Ok\""
#define BTN_PIN 0
#define BTN_ACT LOW

// Screen Setup
#define HAS_SCREEN 1
#define ROTATION 1
#define MINBRIGHT 160

// Language - Portuguese Brazil
#define LANGUAGE_PT_BR 1

// Font sizes
#define FP 1
#define FM 2
#define FG 3

#endif /* Pins_Arduino_h */