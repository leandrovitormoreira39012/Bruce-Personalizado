/* interface.h - Marauder Radio Touch
   Notas rápidas sobre touch e SD embutidos
*/

#ifndef INTERFACE_MARAUDER_RADIO_TOUCH_H
#define INTERFACE_MARAUDER_RADIO_TOUCH_H

#include "pins_arduino.h"

// void hwInit_MarauderRadioTouch();

/* Nota:
   - Tela 1.8" com leitor SD e touch compartilha SPI. Garanta que o CS de cada dispositivo
     esteja inativo quando não for usado.
   - Para ativar o setup do TFT (ST7735 1.8"), inclua em lib/TFT_eSPI/User_Setup.h:
       #include <User_Setups/Setup_ambiente01_ST7735.h>
*/

#endif // INTERFACE_MARAUDER_RADIO_TOUCH_H
