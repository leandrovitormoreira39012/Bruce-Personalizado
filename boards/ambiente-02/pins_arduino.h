/* ADDED: pins_arduino.h for Ambiente-02 (ST7789 240x320 + touch) */

#ifndef PINS_ARDUINO_AMBIENTE_02_H
#define PINS_ARDUINO_AMBIENTE_02_H

/* SPI */
#define PIN_SPI_SCK     18
#define PIN_SPI_MOSI    23
#define PIN_SPI_MISO    19
#define PIN_SPI_SS      5

/* ST7789 Display */
#define PIN_TFT_CS      17
#define PIN_TFT_DC      16
#define PIN_TFT_RST     15
#define PIN_TFT_BL      14
#define TFT_WIDTH       240
#define TFT_HEIGHT      320

/* Touch (if XPT2046) */
#define PIN_TOUCH_CS    21

/* SD Card */
#define PIN_SD_CS       4

/* NRF24 */
#define PIN_NRF24_CE    25
#define PIN_NRF24_CS    PIN_SPI_SS

/* CC1101 */
#define PIN_CC1101_GDO0 26
#define PIN_CC1101_CS   22

/* IR */
#define PIN_IR_TX       27
#define PIN_IR_RX       33

/* GPS */
#define PIN_GPS_TX      1
#define PIN_GPS_RX      3

/* PN532 (I2C) */
#define PIN_I2C_SDA     4
#define PIN_I2C_SCL     5

/* Joystick */
#define PIN_JOY_VRX     36
#define PIN_JOY_VRY     37
#define PIN_JOY_SW      38

#endif /* PINS_ARDUINO_AMBIENTE_02_H */
