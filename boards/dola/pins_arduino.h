#ifndef PINS_ARDUINO_H
#define PINS_ARDUINO_H

// ==============================================
//  PINOUT — BRANCH "dola"
//  Tela ST7789 2.8" + Touch XPT2046 + SD + Encoder
//  ESP32-S3 N16R8 — Pinos confirmados
// ==============================================

// Tela principal
#define TFT_CS   16
#define TFT_DC    7
#define TFT_RST  15
#define TFT_MOSI  6
#define TFT_SCLK  5
#define TFT_MISO  8
#define TFT_BL    4

// Touch XPT2046
#define TOUCH_CS 39
#define TOUCH_IRQ 40

// Cartão SD
#define SD_CS    17

// Encoder
#define ENCODER_CLK 36
#define ENCODER_DT  37
#define ENCODER_BTN 38

// Botões
#define SEL_BTN    38   // Mesmo do encoder
#define ESC_BTN    21

// Joystick (mantém se precisar depois)
#define JOY_X      12
#define JOY_Y      13

// Barra de LEDs — Bateria
#define BAT_LED1   26
#define BAT_LED2   27
#define BAT_LED3   28
#define BAT_LED4   29
#define BAT_LED5   30
#define BAT_LED6   31
#define BAT_LED7   32
#define BAT_LED8   33
#define BAT_LED9   34
#define BAT_LED10  35

#endif // PINS_ARDUINO_H
