/* Pinos para Marauder Radio Mini (Ambiente 05) */

#ifndef PINS_ARDUINO_MARAUDER_RADIO_MINI_H
#define PINS_ARDUINO_MARAUDER_RADIO_MINI_H

/* SPI */
#define PIN_SPI_SCK     18
#define PIN_SPI_MOSI    23
#define PIN_SPI_MISO    19
#define PIN_SPI_SS      5

/* Display 1.8" 128x160 */
#define PIN_TFT_CS      15
#define PIN_TFT_DC      2
#define PIN_TFT_RST     4
#define PIN_TFT_BL      21
#define TFT_WIDTH       128
#define TFT_HEIGHT      160

/* Touch (if present) */
#define PIN_TOUCH_CS    33
#define PIN_TOUCH_IRQ   -1

/* SD Card (SPI) */
#define PIN_SD_CS       4

/* NRF24 */
#define PIN_NRF24_CE    25
#define PIN_NRF24_CS    PIN_SPI_SS

/* CC1101 */
#define PIN_CC1101_GDO0 26
#define PIN_CC1101_CS   21

/* IR */
#define PIN_IR_TX       27
#define PIN_IR_RX       13

/* PN532 (I2C) */
#define PIN_I2C_SDA     21
#define PIN_I2C_SCL     22

/* Joystick (optional) */
#define PIN_JOY_VRX     34
#define PIN_JOY_VRY     35
#define PIN_JOY_SW      32

#endif /* PINS_ARDUINO_MARAUDER_RADIO_MINI_H */
