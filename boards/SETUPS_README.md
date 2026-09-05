# Setups Bruce-Personalizado

Este diretório contém dois setups customizados em Português (Brasil) com diferentes microcontroladores e telas.

## Setup 1: ESP32 30 pinos + ST7735 128x160

**Nome da Pasta:** `ESP32-30P-ST7735-PT-BR`

**Especificações:**
- **Microcontrolador:** ESP32 30 pinos (DevKit V1)
- **Tela Principal:** ST7735 128x160 com Touch
- **Módulos Suportados:**
  - PN532 (NFC/RFID) via I2C
  - NRF24L01+ (RF 2.4GHz)
  - CC1101 (Sub-GHz)
  - GPS NEO 6M V2 via UART
  - IR Transmissor HX53
  - IR Receptor
  - Joystick KY043
  - Encoder 5-vias JY050
  - SD Card (integrado na tela)

**Pinagem Otimizada:**
- Display (ST7735): GPIO 2, 4, 5, 15, 18, 19, 23
- Encoder JY050: GPIO 32, 33, 34, 35, 36
- SD Card: GPIO 12, 18, 23, 25
- I2C: GPIO 21 (SDA), 22 (SCL)
- GPS UART: GPIO 16 (TX), 17 (RX)
- NRF24: GPIO 26, 27 + SPI
- CC1101: GPIO 13, 14 + SPI
- IR: GPIO 25 (TX), 27, 28 (RX)

**Compile Command:**
```bash
pio run -e ESP32-30P-ST7735-PT-BR
```

**Upload Command:**
```bash
pio run -e ESP32-30P-ST7735-PT-BR --target upload
```

---

## Setup 2: ESP32-S3 N16R8 + ST7789 240x320 + OLED 0.93" Secundária

**Nome da Pasta:** `ESP32-S3-ST7789-OLED-PT-BR`

**Especificações:**
- **Microcontrolador:** ESP32-S3 N16R8 (16MB Flash, 8MB PSRAM)
- **Tela Principal:** ST7789 240x320 com Touch
- **Tela Secundária:** OLED 0.93" 128x32 (Letreiro dos módulos ativos)
- **Módulos Suportados:** *(MESMOS do Setup 1)*
  - PN532 (NFC/RFID) via I2C
  - NRF24L01+ (RF 2.4GHz)
  - CC1101 (Sub-GHz)
  - GPS NEO 6M V2 via UART
  - IR Transmissor HX53
  - IR Receptor
  - Joystick KY043
  - Encoder 5-vias JY050
  - SD Card
  - **NOVO:** Tela OLED 0.93" exibindo módulos ativos

**Pinagem Otimizada:**
- Display (ST7789): GPIO 4, 5, 6, 7, 11, 15, 16
- Encoder JY050: GPIO 12, 13, 14, 19, 20
- OLED 0.93": GPIO 8 (SCL), 18 (SDA) via I2C
- SD Card: GPIO 5, 6, 40, 41
- I2C (compartilhado): GPIO 18 (SDA), 8 (SCL)
- GPS UART: GPIO 17 (TX), 38 (RX)
- NRF24: GPIO 21, 47 + SPI
- CC1101: GPIO 35, 47 + SPI
- IR: GPIO 1, 2

**Funcionalidade da OLED Secundária:**
- Exibe "CUSTOM BY LEANDRO" no boot
- Mostra lista de módulos ativos em tempo real (como um letreiro)
- Atualiza quando módulos são ativados/desativados
- Tamanho pequeno (0.93") ideal para montagem compacta

**Compile Command:**
```bash
pio run -e ESP32-S3-ST7789-OLED-PT-BR
```

**Upload Command:**
```bash
pio run -e ESP32-S3-ST7789-OLED-PT-BR --target upload
```

**Monitor Serial Output:**
```bash
pio device monitor -e ESP32-S3-ST7789-OLED-PT-BR
```

---

## Diferenças Entre os Setups

| Aspecto | Setup 1 (ESP32) | Setup 2 (ESP32-S3) |
|--------|-----------------|-------------------|
| **Microcontrolador** | ESP32 30 pinos | ESP32-S3 N16R8 |
| **Tela Principal** | ST7735 128x160 | ST7789 240x320 |
| **Tela Secundária** | Nenhuma | OLED 0.93" (letreiro) |
| **Flash** | Variável | 16MB |
| **PSRAM** | Nenhuma | 8MB |
| **Módulos** | Mesmos | Mesmos |
| **Linguagem** | Português (BR) | Português (BR) |
| **Boot Message** | Não | "CUSTOM BY LEANDRO" |

---

## Características Comuns

✅ Menu completo em Português (Brasil)
✅ Suporte para todos os módulos RF/NFC/GPS/IR
✅ Encoder 5-vias JY050 fully integrated
✅ Joystick KY043 para navegação
✅ Touch screen em ambos os setups
✅ SD Card support para logs e arquivos
✅ Pinagem otimizada sem conflitos
✅ Compilação separada para cada setup

---

## Compilar Ambos os Setups

```bash
# Compilar Setup 1
pio run -e ESP32-30P-ST7735-PT-BR

# Compilar Setup 2
pio run -e ESP32-S3-ST7789-OLED-PT-BR

# Compilar ambos
pio run
```

---

## Notas Importantes

- A OLED 0.93" no Setup 2 funciona via I2C compartilhado com PN532
- Certifique-se de que a OLED tem endereço I2C 0x3C
- O firmware em Português traduz todos os menus e mensagens
- Setup 1 é mais compacto; Setup 2 oferece mais espaço na tela principal
- Ambos os setups usem a mesma pinagem para módulos RF/NFC/GPS quando possível
