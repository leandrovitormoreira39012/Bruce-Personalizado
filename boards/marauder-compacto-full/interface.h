/* ADDED: interface.h for Ambiente-01
   Pequena documentação + protótipos (opcional)
   Updated to include touch and SD usage notes
*/

#ifndef INTERFACE_AMBIENTE_01_H
#define INTERFACE_AMBIENTE_01_H

#include "pins_arduino.h"

/* Use this to centralize hardware init calls in your main code:
   void hwInit_Ambiente01();
   Implementation pode estar em src/hw_ambiente01.cpp
*/

/* ADDED: Nota sobre touch e SD embutidos na tela:
   - PIN_TOUCH_CS define o chip select do controlador de touch (XPT2046 comum).
   - PIN_SD_CS define o chip select do leitor de SD embutido.
   - Ambos compartilham o barramento SPI com o display (SCK/MOSI/MISO). Garanta que o CS do dispositivo
     esteja alto/inativo quando não estiver sendo usado.
*/

#endif /* INTERFACE_AMBIENTE_01_H */
