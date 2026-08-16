/* ADDED: interface.h for Ambiente-02
   - ADDED note: this environment presume ST7789 controller. If your 2.8" uses ST7789V, OK.
   - If your screen uses different pinout, ajuste PIN_TFT_* e PIN_TOUCH_CS.
*/

#ifndef INTERFACE_AMBIENTE_02_H
#define INTERFACE_AMBIENTE_02_H

#include "pins_arduino.h"

/* ADDED: Se for necessário criar um custom User_Setup do TFT_eSPI,
   adicione um arquivo em lib/TFT_eSPI/User_Setups/Setup_ambiente02.h
   e inclua nele:
   #define TFT_MOSI PIN_SPI_MOSI
   #define TFT_SCLK PIN_SPI_SCK
   #define TFT_CS   PIN_TFT_CS
   #define TFT_DC   PIN_TFT_DC
   #define TFT_RST  PIN_TFT_RST
   #define TFT_BL   PIN_TFT_BL
   // ADICIONE: // ADDED for Ambiente-02: ST7789 240x320
*/

#endif /* INTERFACE_AMBIENTE_02_H */
