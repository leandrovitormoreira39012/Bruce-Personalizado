/* ADDED: pins_arduino.h for Ambiente-02 (ST7789 240x320 2.8" + Touch + SD) */

#ifndef PINS_ARDUINO_AMBIENTE_02_H
#define PINS_ARDUINO_AMBIENTE_02_H

/* SPI Compartilhado (S3) - Pinos Seguros */
#define PIN_SPI_SCK     12
#define PIN_SPI_MOSI    11
#define PIN_SPI_MISO    10
#define PIN_SPI_SS      5

/* Display 2.8" ST7789 240x320 */
#define PIN_TFT_CS      17
#define PIN_TFT_DC      16
#define PIN_TFT_RST     15
#define PIN_TFT_BL      14
#define TFT_WIDTH       240
#define TFT_HEIGHT      320

/* Touch Controller (XPT2046) */
#define PIN_TOUCH_CS    41
#define PIN_TOUCH_IRQ   -1

/* SD Card (SPI embutido na tela) */
#define PIN_SD_CS       4

/* NRF24L01+PA */
#define PIN_NRF24_CE    13
#define PIN_NRF24_CS    42

/* CC1101 */
#define PIN_CC1101_GDO0 45
#define PIN_CC1101_CS   21

/* Infravermelho (IR) */
#define PIN_IR_TX       37
#define PIN_IR_RX       38

/* GPS (UART) */
#define PIN_GPS_TX      40
#define PIN_GPS_RX      39

/* PN532 (I2C) */
#define PIN_I2C_SDA     8
#define PIN_I2C_SCL     9

/* Joystick / Botões (Botão SW no GPIO 6) */
#define PIN_JOY_VRX     1
#define PIN_JOY_VRY     2
#define PIN_JOY_SW      6

#endif /* PINS_ARDUINO_AMBIENTE_02_H */
