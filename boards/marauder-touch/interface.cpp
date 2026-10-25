#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

// Barramento SPI Compartilhado (Tela, SD, NRF24, CC1101)
static const uint8_t SCK  = 6;
static const uint8_t MOSI = 7;
static const uint8_t MISO = 5;

// Display ST7789
static const uint8_t TFT_CS   = 10;
static const uint8_t TFT_DC   = 9;
static const uint8_t TFT_RST  = 12; // GPIO12 (Atenção ao guia: não ligar RESET ao 3V3)
static const uint8_t TFT_LED  = 11; // GPIO11 (Controle de LED)

// Leitor SD e Touch
static const uint8_t SD_CS    = 8;
static const uint8_t T_CS     = 4;

// Módulos de Rádio (NRF24L01 e CC1101)
static const uint8_t NRF_CSN  = 16;
static const uint8_t NRF_CE   = 48;
static const uint8_t CC1101_CSN = 14;
static const uint8_t CC1101_GDO0 = 15;

// Botões (JY050)
static const uint8_t BTN_UP   = 38;
static const uint8_t BTN_DWN  = 39;
static const uint8_t BTN_LEFT = 40;
static const uint8_t BTN_RHT  = 41;
static const uint8_t BTN_MID  = 42;
static const uint8_t BTN_SET  = 13;
static const uint8_t BTN_RST  = 47;

#endif
