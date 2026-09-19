#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

#define USB_VID 0x303a
#define USB_PID 0x1001

// --- Definições Padrão I2C e SPI ---
#define SDA 33
#define SCL 26
#define SCK 18
#define MISO 19
#define MOSI 23
#define SS 17

// --- Módulo GPS NEO-6M ---
#define SERIAL_TX 4
#define SERIAL_RX 22
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX

#define HAS_BTN 0
#define BTN_ALIAS "\"Ok\""
#define BTN_PIN 0
#define BTN_ACT LOW

#define TXLED -1
#define LED_ON HIGH
#define LED_OFF LOW

// --- Barramento SPI Principal (Compartilhado) ---
#define SPI_SCK_PIN 18
#define SPI_MISO_PIN 19
#define SPI_MOSI_PIN 23
#define SPI_SS_PIN 17

// --- Módulo CC1101 (Sub-GHz) ---
#define CC1101_GDO0_PIN 2
#define CC1101_SS_PIN 15
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

// --- Módulo NRF24L01+PA+LNA (2.4GHz) ---
#define NRF24_CE_PIN 27
#define NRF24_SS_PIN 14
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

// --- Módulos IR (Infravermelho) ---
#define HAS_IR 1
#define IR_TX_PIN 25
#define IR_RX_PIN 34

// --- Módulo PN532 (NFC / RFID via I2C) ---
#define HAS_PN532 1
#define PN532_SDA 33
#define PN532_SCL 26

#define FP 1
#define FM 2
#define FG 3

// --- Configurações da Tela ILI9341 2.8" Touch ---
#define HAS_SCREEN 1
#define ROTATION 3
#define TFT_BRIGHT 160

#define USER_SETUP_LOADED 1
#define ILI9341_DRIVER 1
#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS 17
#define TFT_DC 16
#define TFT_RST 5
#define TFT_BL 32
#define TFT_BACKLIGHT_ON HIGH
#define SMOOTH_FONT 1
#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 16000000
#define SPI_TOUCH_FREQUENCY 25000000
#define TOUCH_CS 21
#define HAS_TOUCH 1

// --- Cartão Micro SD ---
#define SDCARD_CS 12
#define SDCARD_SCK 18
#define SDCARD_MISO 19
#define SDCARD_MOSI 23

// --- Módulo BadUSB ---
#define BAD_RX -1
#define BAD_TX -1

#endif /* Pins_Arduino_h */

