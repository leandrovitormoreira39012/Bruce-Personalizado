#ifndef Pins_Arduino_h
#define Pins_Arduino_h

/* SPI Principal */
  #define PIN_SPI_SCK 18
  #define PIN_SPI_MOSI 11
  #define PIN_SPI_MISO 13
  #define PIN_SPI_SS 10        /* Movido de 35 (ocupado pela Flash/PSRAM interna do S3) */
  #define TOUCH_CS 6
  #define TOUCH_IRQ 5
  #define GROVE_SDA 27
  #define GROVE_SCL 22
  
/* Configurações da tela */
  #define HAS_SCREEN 1
  #define RROTATION 3
  #define BACKLIGHT 21
  #define MINBRIGHT 160

/* Drivers da tela - TFT_eSPI Setup */
  #define USER_SETUP_LOADED 1
  #define ILI9341_2_DRIVER 1
  #define USE_HSPI_PORT 1
  #define TFT_HEIGHT 320
  #define TFT_WIDTH 240
  #define TFT_MISO 13
  #define TFT_MOSI 11
  #define TFT_SCLK 18
  #define TFT_CS 17
  #define TFT_DC 16
  #define TFT_RST 15
  #define TFT_BL 7
  #define TFT_BACKLIGHT_ON HIGH
  #define SMOOTH_FONT 1

/* TouchScreen (XPT2046) */
  #define HAS_TOUCH 1
  #define TFT_TOUCH_CS 6
  #define TFT_TOUCH_IRQ 5
    
/* Tamanho da fonte */
  #define FP 1
  #define FM 2
  #define FG 3
   
/* SD Card */
  #define SDCARD_CS 5
  #define SDCARD_SCK 18
  #define SDCARD_MISO 13
  #define SDCARD_MOSI 11

/* PN532 */
  #define SYS_I2C_SDA GROVE_SDA
  #define SYS_I2C_SCL GROVE_SCL

/* CC1101 Sub-GHz Radio */
  #define USE_CC1101_VIA_SPI
  #define CC1101_CE_PIN 2
  #define CC1101_SS_PIN PIN_SPI_SS
  #define CC1101_MOSI_PIN PIN_SPI_MOSI
  #define CC1101_SCK_PIN PIN_SPI_SCK
  #define CC1101_MISO_PIN PIN_SPI_MISO

/* NRF24L01 2.4GHz */
  #define USE_NRF24_VIA_SPI
  #define NRF24_CE_PIN 1
  #define NRF24_SS_PIN PIN_SPI_SS
  #define NRF24_MOSI_PIN PIN_SPI_MOSI
  #define NRF24_SCK_PIN PIN_SPI_SCK
  #define NRF24_MISO_PIN PIN_SPI_MISO

/* Infravermelho */
  #define TXLED 39             /* Movido de 37 para pino seguro fora da área de memória */
  #define RXLED 40             /* Movido de 38 para pino seguro fora da área de memória */
  #define LED_ON HIGH
  #define LED_OFF LOW

/* Serial (GPS) */
  #define SERIAL_TX 43
  #define SERIAL_RX 44
  #define GPS_SERIAL_TX SERIAL_TX
  #define GPS_SERIAL_RX SERIAL_RX
    
/* Joystick JY50 - 5 Vias */
  #define JOY_UP 8
  #define JOY_DOWN 9
  #define JOY_LEFT 14          /* Alterado de 10 para evitar conflito com PIN_SPI_SS */
  #define JOY_RIGHT 12
  #define JOY_CLICK 46

/* Botões */
  #define HAS_BTN 1
  #define BTN_ALIAS "\"Boot\""
  #define BTN_PIN 0 
  #define BTN_ACT LOW
  #define SEL_BTN 0 

/* Bateria */
  #define ANALOG_BAT_PIN 4     /* Movido de 36 para o GPIO 4 (canal ADC seguro) */
  #define ANALOG_BAT_MULTIPLIER 2.0f

#endif /* Pins_Arduino_h */
