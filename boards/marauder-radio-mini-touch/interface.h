/* interface.h - Marauder Radio Mini
   Notas rápidas sobre touch e SD embutidos
*/

#ifndef INTERFACE_MARAUDER_RADIO_MINI_H
#define INTERFACE_MARAUDER_RADIO_MINI_H

#include "pins_arduino.h"

// Centralizar inicializações de hardware se necessário
// void hwInit_MarauderRadioMini();

/* Nota:
   - A tela 1.8" e o leitor SD compartilham SPI. Garanta que o CS do dispositivo esteja INATIVO
     (HIGH) quando não estiver em uso.
   - Para usar o touch, habilite o User_Setup correspondente (Setup_ambiente01_ST7735.h) em
     lib/TFT_eSPI/User_Setup.h antes de compilar.
*/

#endif // INTERFACE_MARAUDER_RADIO_MINI_H
