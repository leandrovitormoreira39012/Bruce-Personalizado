#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

#define USB_VID 0x303A
#define USB_PID 0x1001

// --- Barramento SPI Principal (Compartilhado: Tela, NRF24, CC1101, SD) ---
#define SPI_SCK_PIN  18
#define SPI_MISO_PIN 19
#define SPI_MOSI_PIN 23
#define SPI_SS_PIN   5

// --- Barramento I2C Principal (PN532 / Opcionais) ---
#define SDA 21
#define SCL 22

// --- Botões Direcionais e Seleção (Resistores de Pull-down 10k) ---
#define HAS_BTN 1
#define HAS_5_BUTTONS 1
#define UP_BTN  36  // Pino VP (Entrada pura)
#define DWN_BTN 35  // Pino D35 (Entrada pura)
#define L_BTN   13  // Pino D13
#define R_BTN   39  // Pino VN (Entrada pura)
#define SEL_BTN 34  // Pino D34 (Entrada pura)
#define BTN_ALIAS "OK"
#define BTN_ACT HIGH

// --- Botão Físico Vermelho (Função ESC / VOLTAR Direta ao Menu) ---
#define HAS_BACK_BTN 1
#define BACK_BTN 0  // Conectado ao pino BOOT / GPIO 0 (ou pino dedicado para ESC)
#define ESC_BTN  0

// --- Módulo CC1101 (Sub-GHz) ---
#define HAS_CC1101 1
#define CC1101_GDO0_PIN 2
#define CC1101_SS_PIN   15
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN  SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

// --- Módulo NRF24L01+PA+LNA (2.4GHz) ---
#define HAS_NRF24 1
#define NRF24_CE_PIN 12
#define NRF24_SS_PIN 14
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN  SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

// --- Módulo IR (Infravermelho Emissor com Resistor da Foto 9) ---
#define HAS_IR 1
#define IR_TX_PIN 25
#define IR_RX_PIN -1

// --- Módulo PN532 (NFC / RFID via I2C) ---
#define HAS_PN532 1
#define PN532_SDA 21
#define PN532_SCL 22

// --- Cartão Micro SD (SPI) ---
#define HAS_SD 1
#define SDCARD_CS   4
#define SDCARD_SCK  SPI_SCK_PIN
#define SDCARD_MISO SPI_MISO_PIN
#define SDCARD_MOSI SPI_MOSI_PIN

// --- Módulo GPS NEO-6M v2 (UART2) ---
#define HAS_GPS 1
#define GPS_RX 26  // Conectar no TX do módulo GPS
#define GPS_TX 27  // Conectar no RX do módulo GPS

// --- LEDs Indicadores de Acionamento dos Módulos ---
#define LED_NRF24_PIN 33  // LED aciona em operação do NRF24L01
#define LED_CC1101_PIN 27 // LED aciona em operação do CC1101
#define LED_IR_PIN     25 // O próprio LED IR transmite o sinal
#define LED_PN532_PIN  26 // LED aciona no escaneamento NFC
#define LED_SD_PIN     32 // LED aciona em leitura/gravação do Cartão SD

// --- Configuração Geral de Tela ---
#define HAS_SCREEN 1
#define ROTATION 1  // Orientação da tela (0, 1, 2 ou 3 para ajustar a Foto 8)
#define TFT_BRIGHT 255

#endif /* Pins_Arduino_h */
