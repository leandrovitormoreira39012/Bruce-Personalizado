#ifndef PINS_ARDUINO_MARAUDER_RADIO_H
#define PINS_ARDUINO_MARAUDER_RADIO_H

/* SPI Principal */
#define PIN_SPI_SCK     18
#define PIN_SPI_MOSI    11
#define PIN_SPI_MISO    13
#define PIN_SPI_SS      17

/* ST7789 Display 2.8" */
#define PIN_TFT_CS      17
#define PIN_TFT_DC      16
#define PIN_TFT_RST     15
#define PIN_TFT_BL      7
#define TFT_WIDTH       240
#define TFT_HEIGHT      320

/* Touch (XPT2046) */
#define TOUCH_CS        6
#define TOUCH_IRQ       5

/* Joystick 5 Vias */
#define JOY_UP          8
#define JOY_DOWN        9
#define JOY_LEFT        10
#define JOY_RIGHT       12
#define JOY_CLICK       3

#endif
