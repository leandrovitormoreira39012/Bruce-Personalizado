#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define USB_VID 0x303a
#define USB_PID 0x1001
#define USB_AS_HID 1

#define SERIAL_TX 43
#define SERIAL_RX 17
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX
static const uint8_t TX = SERIAL_TX;
static const uint8_t RX = SERIAL_RX;

#define GROVE_SDA 1
#define GROVE_SCL 2
#define SYS_I2C_SDA GROVE_SDA
#define SYS_I2C_SCL GROVE_SCL
static const uint8_t SDA = GROVE_SDA;
static const uint8_t SCL = GROVE_SCL;

#define SPI_MOSI_PIN 7
#define SPI_MISO_PIN 5
#define SPI_SCK_PIN 6
#define SPI_SS_PIN 14
static const uint8_t MOSI = SPI_MOSI_PIN;
static const uint8_t MISO = SPI_MISO_PIN;
static const uint8_t SCK = SPI_SCK_PIN;
static const uint8_t SS = SPI_SS_PIN;

#define SDCARD_CS 8
#define SDCARD_MOSI SPI_MOSI_PIN
#define SDCARD_MISO SPI_MISO_PIN
#define SDCARD_SCK SPI_SCK_PIN

#define USE_CC1101_VIA_SPI
#define CC1101_SS_PIN 14
#define CC1101_GDO0_PIN 15
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN

#define USE_NRF24_VIA_SPI
#define NRF24_SS_PIN 16
#define NRF24_CE_PIN 42
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN

#define HAS_SCREEN 1
#define USER_SETUP_LOADED 1
#define USE_HSPI_PORT
#define ST7789_DRIVER 1

#define BRUCE_PANEL_INVERTED 0
#define TFT_WIDTH 240
#define TFT_HEIGHT 320
#define TFT_RGB_ORDER TFT_BGR

#if BRUCE_PANEL_INVERTED
#define TFT_INVERSION_ON
#else
#define TFT_INVERSION_OFF
#endif

#define TFT_RST 12
#define TFT_BL 11
#define TFT_BACKLIGHT_ON HIGH

#define TFT_CS 10
#define TFT_DC 9
#define TOUCH_CS -1
#define SPI_FREQUENCY 20000000
#define SPI_READ_FREQUENCY 10000000
#define SMOOTH_FONT 1
#define ROTATION 1
#define WINBRIGHT 1

#define HAS_TOUCH 1
#define BRUCE_INPUT_SYNC 1
#define TOUCH_XPT2040_SPI
#define XPT2040_TOUCH_CONFIG_INT_GPIO_NUM -1
#define XPT2040_SPI_CONFIG_CS_GPIO_NUM 4
#define XPT2040_SPI_BUS_MOSI_IO_NUM SPI_MOSI_PIN
#define XPT2040_SPI_BUS_MISO_IO_NUM SPI_MISO_PIN
#define XPT2040_SPI_BUS_SCLK_IO_NUM SPI_SCK_PIN

#define HAS_5_BUTTONS
#define UP_BTN 38
#define DW_BTN 39
#define L_BTN 40
#define R_BTN 41
#define SEL_BTN 42
#define ESC_BTN 47
#define JY050_SET_BTN 13
#define BTN_ACT LOW
#define BTN_ALIAS "OK"

#define TXLED 18
#define RXLED 21
#define LED_ON HIGH
#define LED_OFF LOW

#endif
