/* ADDED: pins_arduino.h for Ambiente-03 (ESP32 DevKit 30p) */

#ifndef PINS_ARDUINO_AMBIENTE_03_H
#define PINS_ARDUINO_AMBIENTE_03_H

/* SPI Compartilhado (VSPI) */
#define PIN_SPI_SCK     18
#define PIN_SPI_MOSI    23
#define PIN_SPI_MISO    19
#define PIN_SPI_SS      5

/* Display 1.8" 128x160 */
#define PIN_TFT_CS      15
#define PIN_TFT_DC      2
#define PIN_TFT_RST     4
#define PIN_TFT_BL      32
#define TFT_WIDTH       128
#define TFT_HEIGHT      160

/* SD Card (SPI) */
#define PIN_SD_CS       14

/* NRF24L01+PA */
#define PIN_NRF24_CE    25
#define PIN_NRF24_CS    26

/* CC1101 */
#define PIN_CC1101_GDO0 27
#define PIN_CC1101_CS   22

/* Infravermelho (IR) */
#define PIN_IR_TX       33
#define PIN_IR_RX       32

/* GPS (UART2) */
#define PIN_GPS_TX      17
#define PIN_GPS_RX      16

/* PN532 (I2C) */
#define PIN_I2C_SDA     21
#define PIN_I2C_SCL     22

/* Joystick KY-023 */
#define PIN_JOY_VRX     34
#define PIN_JOY_VRY     35
#define PIN_JOY_SW      36

#endif /* PINS_ARDUINO_AMBIENTE_03_H */
