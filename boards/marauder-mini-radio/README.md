# Ambiente-04 (ESP32 DevKit + ST7789 240x240 sem CS + 2xNRF24)

Notas críticas:
- Tela ST7789 sem CS: defina TFT_CS=-1 no User_Setup do TFT_eSPI (já feito via macro DST7789_NO_CS em platformio.ini).
  - ADDED: Recomendo adicionar um User_Setup específico (lib/TFT_eSPI/User_Setups/Setup_ambiente04_ST7789.h) com TFT_CS -1 e mapeamento de pinos conforme pins_arduino.h.
- Dois módulos nRF24: cuidado com gestão de CS/CE e alimentação; coloque chave física ou lógica para evitar curto de SPI.
- PN532 incluído como pronto — se for usar, ajuste o driver (I2C/UART) conforme necessário.

Compilar:
- pio run -e ambiente-04
