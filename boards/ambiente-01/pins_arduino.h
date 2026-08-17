/* ADDED: pins_arduino.h for Ambiente-01
   Mapeamento de pinos (use este arquivo se quiser incluir diretamente nos sources)
*/

#ifndef PINS_ARDUINO_AMBIENTE_01_H
#define PINS_ARDUINO_AMBIENTE_01_H

/* SPI Compartilhado (Tela, SD, Touch, NRF24, CC1101) */
#define PIN_SPI_SCK     18
#define PIN_SPI_MOSI    11
#define PIN_SPI_MISO    10
#define PIN_SPI_SS      4

/* Display 1.8" 128x160 */
#define PIN_TFT_CS      17
#define PIN_TFT_DC      16
#define PIN_TFT_RST     15
#define PIN_TFT_BL      6
#define TFT_WIDTH       128
#define TFT_HEIGHT      160

/* Touch Controller */
#define PIN_TOUCH_CS    5
#define PIN_TOUCH_IRQ   -1

/* SD Card (SPI) */
#define PIN_SD_CS       4

/* NRF24L01+PA */
#define PIN_NRF24_CE    13
#define PIN_NRF24_CS    12

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

/* Joystick KY-023 (Pinos Analógicos ADC1 e Digital) */
#define PIN_JOY_VRX     1
#define PIN_JOY_VRY     2
#define PIN_JOY_SW      3

#endif /* PINS_ARDUINO_AMBIENTE_01_H */
