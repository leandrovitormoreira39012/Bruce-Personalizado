/* ADDED: interface.h for Ambiente-04
   - ADDED NOTE: duas instâncias de NRF24 definidas; você precisará de lógica no firmware para alternar CS/CE
*/

#ifndef INTERFACE_AMBIENTE_04_H
#define INTERFACE_AMBIENTE_04_H

#include "pins_arduino.h"

/* Exemplo de macro para selecionar nRF24 (no código):
   #define NRF24_SELECT_1()  digitalWrite(PIN_NRF24_2_CS, HIGH); digitalWrite(PIN_NRF24_1_CS, LOW)
   #define NRF24_SELECT_2()  digitalWrite(PIN_NRF24_1_CS, HIGH); digitalWrite(PIN_NRF24_2_CS, LOW)
   /* ADDED: Essa lógica deve existir no driver antes de iniciar a transação SPI */
*/

#endif /* INTERFACE_AMBIENTE_04_H */
