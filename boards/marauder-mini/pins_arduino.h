#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

#define USB_VID 0x303A
#define USB_PID 0x1001

// --- Definições Padrão de Barramento ---
#define SDA 21
#define SCL 22
#define SCK 18
#define MISO 19
#define MOSI 23
#define SS 17

// --- Barramento SPI Principal (Compartilhado) ---
#define SPI_SCK_PIN 18
#define SPI_MISO_PIN 19
#define SPI_MOSI_PIN 23
#define SPI_SS_PIN 17

// --- Joystick 5-Way + Botão ESC/Voltar ---
#define HAS_BTN 1
#define HAS_5_BUTTONS 1
#define SEL_BTN 34
#define UP_BTN 36
#define DWN_BTN 35
#define DW_BTN 35
#define R_BTN 39
#define L_BTN 13
#define BTN_ALIAS "OK"
#define BTN_ACT LOW

// Botão ESC / VOLTAR (Botão BOOT do ESP32 ou botão externo ao GND)
#define HAS_BACK_BTN 1
#define BACK_BTN 0
#define ESC_BTN 0

#define TXLED -1
#define LED_IN HIGH
#define LED_OFF LOW

// --- Módulo CC1101 (Sub-GHz) ---
#define CC1101_GDO0_PIN 2
#define CC1101_SS_PIN 15
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

// --- Módulo NRF24L01+PA+LNA (2.4GHz) ---
#define NRF24_CE_PIN 12
#define NRF24_SS_PIN 14
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

// --- Módulos IR (Infravermelho: Emissor e Receptor) ---
#define HAS_IR 1
#define IR_TX_PIN 25
#define IR_RX_PIN 27

// --- Módulo PN532 (NFC / RFID via I2C) ---
#define HAS_PN532 1
#define PN532_SDA 33
#define PN532_SCL 26

// --- Cartão Micro SD ---
#define SDCARD_CS 4
#define SDCARD_SCK 18
#define SDCARD_MISO 19
#define SDCARD_MOSI 23

// --- Configuração Geral de Tela ---
#define HAS_SCREEN 1
#define ROTATION 0
#define TFT_BRIGHT 255  // Brilho no máximo absoluto (scale 0..255)

#endif /* Pins_Arduino_h */
