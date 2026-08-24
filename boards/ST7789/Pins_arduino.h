//   Developed by leandrovitormoreira39012

#define Pins_Arduino_h

#include <stdint.h>

// =============================================
// SPI Principal (HSPI Externo - 100% Seguro)
// =============================================
#define SPI_SCK_PIN 18
#define SPI_MOSI_PIN 11
#define SPI_MISO_PIN 13
#define SPI_SS_PIN 10
#define USE_HSPI_PORT

// =============================================
// Display 2.8" ILI9341 & Touch XPT2046
// =============================================
#define HAS_SCREEN 1
#define ILI9341_2_DRIVER 1
#define USER_SETUP_LOADED 1
#define TFT_WIDTH 240
#define TFT_HEIGHT 320
#define TFT_SCLK SPI_SCK_PIN
#define TFT_MOSI SPI_MOSI_PIN
#define TFT_MISO SPI_MISO_PIN
#define TFT_CS 17
#define TFT_DC 16
#define TFT_RST 15
#define TFT_BL 7
#define TFT_BACKLIGHT_ON HIGH

#define HAS_TOUCH 1
#define TFT_TOUCH_CS 6
#define TFT_TOUCH_IRQ 3

// =============================================
// SD Card
// =============================================
#define SDCARD_CS 5
#define SDCARD_SCK SPI_SCK_PIN
#define SDCARD_MISO SPI_MISO_PIN
#define SDCARD_MOSI SPI_MOSI_PIN

// =============================================
// Joystick JY50 (5 Vias Digital) & Botões
// =============================================
#define HAS_BTN 1
#define BTN_ALIAS "\"Boot\""
#define BTN_PIN 0
#define BTN_ACT LOW
#define SEL_BTN 0

#define JOY_UP 8
#define JOY_DOWN 9
#define JOY_LEFT 14
#define JOY_RIGHT 12
#define JOY_CLICK 46

// =============================================
// Módulos de Rádio (CC1101 & NRF24L01)
// =============================================
#define USE_CC1101_VIA_SPI
#define CC1101_CE_PIN 2
#define CC1101_SS_PIN SPI_SS_PIN

#define USE_NRF24_VIA_SPI
#define NRF24_CE_PIN 1
#define NRF24_SS_PIN SPI_SS_PIN

// =============================================
// I2C (PN532) & Infravermelho
// =============================================
#define GROVE_SDA 27
#define GROVE_SCL 22
#define SYS_I2C_SDA GROVE_SDA
#define SYS_I2C_SCL GROVE_SCL

#define TXLED 39
#define RXLED 40
#define LED_ON HIGH
#define LED_OFF LOW

// =============================================
// GPS (Portas seguras fora da faixa 35-42)
// =============================================
#define SERIAL_TX 1
#define SERIAL_RX 2
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX

// =============================================
// Bateria (Canal ADC1 Seguro)
// =============================================
#define ANALOG_BAT_PIN 4
#define ANALOG_BAT_MULTIPLIER 2.0f

#endif /* Pins_Arduino_h */
