#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

#define USB_VID 0x303A
#define USB_PID 0x1001

// --- Definições Padrão de Barramento SPI (Exigidas pela biblioteca SPI.cpp) ---
#define SCK 18
#define MISO 19
#define MOSI 23
#define SS 5 // Ajustado para GPIO 5 conforme a Foto 1 (CS da Tela)

// --- Barramento SPI Principal (Compartilhado para Módulos) ---
#define SPI_SCK_PIN SCK
#define SPI_MISO_PIN MISO
#define SPI_MOSI_PIN MOSI
#define SPI_SS_PIN SS

// --- Definições Padrão de I2C ---
#define SDA 21
#define SCL 22

// --- Navegação: Joystick / Botões Direcionais ---
#define HAS_BTN 1
#define HAS_5_BUTTONS 1
#define SEL_BTN 34 // Pino D34
#define UP_BTN 36  // Pino VP
#define DWN_BTN 35 // Pino D35
#define R_BTN 39   // Pino VN
#define L_BTN 13   // Pino D13
#define BTN_ALIAS "OK"
#define BTN_ACT LOW

// --- Botão ESC / VOLTAR (Botão Vermelho Dedicado / BOOT) ---
#define HAS_BACK_BTN 1
#define BACK_BTN 0
#define ESC_BTN 0

#define TXLED -1
#define LED_IN HIGH
#define LED_OFF LOW

// --- Módulos Desativados / Compatibilidade de Código ---
#define BAD_RX -1
#define BAD_TX -1

// --- Módulo CC1101 (Sub-GHz) ---
#define HAS_CC1101 1
#define CC1101_GDO0_PIN 2
#define CC1101_SS_PIN 15
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

// --- Módulo NRF24L01+PA+LNA (2.4GHz) ---
#define HAS_NRF24 1
#define NRF24_CE_PIN 12
#define NRF24_SS_PIN 14
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

// --- Módulo IR (Infravermelho Emissor e Receptor) ---
#define HAS_IR 1
#define IR_TX_PIN 25
#define IR_RX_PIN 27

// --- Módulo PN532 (NFC / RFID via I2C) ---
#define HAS_PN532 1
#define PN532_SDA 33
#define PN532_SCL 26

// --- Cartão Micro SD (SPI) ---
#define HAS_SD 1
#define SDCARD_CS 4
#define SDCARD_SCK SPI_SCK_PIN
#define SDCARD_MISO SPI_MISO_PIN
#define SDCARD_MOSI SPI_MOSI_PIN

// --- Configuração Geral de Tela ---
#define HAS_SCREEN 1
#define ROTATION 1
#define TFT_BRIGHT 255

#endif /* Pins_Arduino_h */
