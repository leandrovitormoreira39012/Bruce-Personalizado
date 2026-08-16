// ADDED: small init example for Ambiente-02
// hw_ambiente02.cpp - optional helper to initialize SPI and I2C used by the board

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include "../boards/ambiente-02/pins_arduino.h"

void hwInit_Ambiente02() {
  // Initialize SPI bus with defined pins (ESP32 uses VSPI/HSPI via pin matrix)
  SPI.begin(PIN_SPI_SCK, PIN_SPI_MISO, PIN_SPI_MOSI, PIN_SPI_SS);
  // Initialize I2C (PN532) if used
  Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);
  // TFT backlight pin
  pinMode(PIN_TFT_BL, OUTPUT);
  digitalWrite(PIN_TFT_BL, HIGH);
}
