# Ambiente-01 (ESP32 S3N16R8 + 1.8" 128x160)

O que contém:
- platformio.ini para o ambiente
- pins_arduino.h com mapeamento de pinos
- interface.h com notas e ponto de entrada para inicialização

Observações importantes:
- Conferir controlador da tela (ST7735 vs ST7789). Se for ST7735, ajuste o User_Setup/TFT_eSPI.
- GPS mapeado em UART0 (TX=1/RX=3) — isso pode conflitar com a porta série principal.
- Se quiser que eu gere um arquivo hw_ambiente01.cpp com funções de init (SPI.begin, Wire.begin...), solicite que eu gere.

/* ADDED: Se for necessária alteração no driver TFT_eSPI, adicione a anotação no User_Setup (lib/TFT_eSPI/User_Setups)
   Exemplo de anotação a ser adicionada no repositório:
   // ADDED for Ambiente-01: use ST7735 controller for 1.8" display (see boards/ambiente-01/README.md)
*/
