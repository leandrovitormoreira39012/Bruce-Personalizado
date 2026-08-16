# Ambiente-02 (ESP32 S3N16R8 + 2.8" ST7789 240x320 + touch)

Notas:
- Este ambiente assume ST7789 para o display; caso o controlador seja outro ou a pinagem do touch controller difira, faça ajustes em pins_arduino.h.
- ADDED: se precisar, posso gerar um arquivo dedicado em lib/TFT_eSPI/User_Setups/ para este ambiente (veja interface.h comentário).

Compilar:
- pio run -e ambiente-02
