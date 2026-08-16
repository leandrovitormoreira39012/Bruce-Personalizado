/* ADDED: pins_arduino.h for Ambiente-04 (ST7789 240x240 sem CS, 2xNRF24) */

#ifndef PINS_ARDUINO_AMBIENTE_04_H
#define PINS_ARDUINO_AMBIENTE_04_H

/* SPI */
#define PIN_SPI_SCK     18
#define PIN_SPI_MOSI    23
#define PIN_SPI_MISO    19
#define PIN_SPI_SS      5

/* ST7789 240x240 (no CS) */
#define PIN_TFT_CS      -1
#define PIN_TFT_DC      21
#define PIN_TFT_RST     22
#define PIN_TFT_BL      19
#define TFT_WIDTH       240
#define TFT_HEIGHT      240

/* SD */
#define PIN_SD_CS       4

/* Two NRF24 modules */
#define PIN_NRF24_1_CE  25
#define PIN_NRF24_1_CS  5
#define PIN_NRF24_2_CE  26
#define PIN_NRF24_2_CS  27

/* CC1101 */
#define PIN_CC1101_GDO0 32
#define PIN_CC1101_CS   33

/* IR */
#define PIN_IR_TX       13
#define PIN_IR_RX       14

/* PN532 (I2C) */
#define PIN_I2C_SDA     21
#define PIN_I2C_SCL     22

/* Joystick */
#define PIN_JOY_VRX     34
#define PIN_JOY_VRY     35
#define PIN_JOY_SW      32

#endif /* PINS_ARDUINO_AMBIENTE_04_H */
