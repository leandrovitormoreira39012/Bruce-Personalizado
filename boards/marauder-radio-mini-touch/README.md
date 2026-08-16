# Marauder Radio Mini (Ambiente 05)

Placa: ESP32 DevKit (30 pinos)
Tela: TFT 1.8" 128x160 (SPI) com leitor SD embutido e touch (se o módulo tiver)

Módulos incluidos:
- nRF24L01+PA/LNA
- CC1101
- HX-53 (TX) / HX-M121 (RX) - Infrared
- Leitor SD (ligado ao SPI da tela)
- Touch (se presente na tela)

Notas:
- Verifique pins_arduino.h para confirmar os GPIOs físicos com sua placa/tela.
- Para ativar o setup do TFT (ST7735 1.8"), inclua em lib/TFT_eSPI/User_Setup.h:
    #include <User_Setups/Setup_ambiente01_ST7735.h>

