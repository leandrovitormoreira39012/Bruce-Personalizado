# Ambiente-03 (ESP32 DevKit 30p + 1.8" TFT)

Notas:
- GPS em UART (pinos 16/17) — recomendado para não conflitar com USB-Serial do chip.
- PN532 incluído como opcional; se não for usado, remova a inicialização no código.

Compilar:
- pio run -e ambiente-03
