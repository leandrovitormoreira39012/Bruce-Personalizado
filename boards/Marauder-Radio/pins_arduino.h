#ifndef PINS_ARDUINO_MARAUDER_RADIO_H
#define PINS_ARDUINO_MARAUDER_RADIO_H

/* SPI Principal (Display, SD e Touch) */
#define PIN_SPI_SCK     18
#define PIN_SPI_MOSI    23
#define PIN_SPI_MISO    19
#define PIN_SPI_SS      5

/* ST7789 Display 2.8" */
#define PIN_TFT_CS      17
#define PIN_TFT_DC      16
#define PIN_TFT_RST     15
#define PIN_TFT_BL      14
#define TFT_WIDTH       240
#define TFT_HEIGHT      320

/* Touch Controller (Movido para o pino 21 para liberar o 33) */
#define PIN_TOUCH_CS    21

/* Cartão SD */
#define PIN_SD_CS       4

/* NRF24L01 (2.4GHz) */
#define PIN_NRF24_CE    25
#define PIN_NRF24_CS    PIN_SPI_SS

/* CC1101 (433MHz) */
#define PIN_CC1101_GDO0 26
#define PIN_CC1101_CS   22

/* Infravermelho (IR) */
#define PIN_IR_TX       27
#define PIN_IR_RX       33

/* GPS (Neo 6M) */
#define PIN_GPS_TX      39
#define PIN_GPS_RX      40

/* PN532 NFC (I2C) */
#define PIN_I2C_SDA     4
#define PIN_I2C_SCL     5

/* Joystick / Navegação */
#define PIN_JOY_VRX     36
#define PIN_JOY_VRY     37
#define PIN_JOY_SW      6

#endif

