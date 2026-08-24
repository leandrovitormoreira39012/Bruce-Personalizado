//   Adapted for ESP32-S3 + 2.8" ILI9341 + JY50 5-Way Digital Joystick

#include "../src/modules/others/battery_information.h"
#include "core/powerSave.h"
#include "core/utils.h"
#include <Arduino.h>

// ======================================================
//          SETTINGS
// ======================================================
const unsigned long readDelay = 30;         // Tempo entre leituras para debounce/limite

// ======================================================
//          PINS (Sincronizados com pins_arduino.h)
// ======================================================
#ifndef JOY_UP
#define JOY_UP 8
#endif
#ifndef JOY_DOWN
#define JOY_DOWN 9
#endif
#ifndef JOY_LEFT
#define JOY_LEFT 14
#endif
#ifndef JOY_RIGHT
#define JOY_RIGHT 12
#endif
#ifndef JOY_CLICK
#define JOY_CLICK 46
#endif
#ifndef SEL_BTN
#define SEL_BTN 0
#endif
#ifndef TFT_BL
#define TFT_BL 7
#endif

// ======================================================
//          FLAGS
// ======================================================
volatile bool upPress_flag = false;
volatile bool downPress_flag = false;
volatile bool leftPress_flag = false;
volatile bool rightPress_flag = false;
volatile bool slPress_flag = false;

unsigned long lastReadTime = 0;

// ======================================================
// SETUP GPIO
// ======================================================
void _setup_gpio() {
    // Configura os botões do Joystick de 5 vias e Select como Pull-Up interno
    pinMode(JOY_UP, INPUT_PULLUP);
    pinMode(JOY_DOWN, INPUT_PULLUP);
    pinMode(JOY_LEFT, INPUT_PULLUP);
    pinMode(JOY_RIGHT, INPUT_PULLUP);
    pinMode(JOY_CLICK, INPUT_PULLUP);
    pinMode(SEL_BTN, INPUT_PULLUP);

    // Configuração do Backlight da tela 2.8"
    pinMode(TFT_BL, OUTPUT);    
    digitalWrite(TFT_BL, HIGH); 

    bruceConfig.colorInverted = 0;
    bruceConfigPins.rotation = 3; // Rotação ajustada para a tela 2.8" ILI9341
}

void _post_setup_gpio() {
    // nothing
}

// ======================================================
//          BATTERY
// ======================================================
int getBattery() { return Battery_information::getBatteryPercentage(); }

// ======================================================
//          SCREEN BRIGHTNESS
// ======================================================
void _setBrightness(uint8_t brightval) { analogWrite(TFT_BL, brightval); }

// ======================================================
//          Mapeamento de Navegação do Menu
// ======================================================
void joystickMap() {
    if (menuOptionLabel == "Main Menu") {
        PrevPress = leftPress_flag;  
        NextPress = rightPress_flag; 
    } else {
        PrevPress = upPress_flag;    
        NextPress = downPress_flag;  
        EscPress = leftPress_flag;   
        DownPress = rightPress_flag; 
    }
}

// ======================================================
//          INPUT HANDLER (Joystick Digital + Botões)
// ======================================================
void InputHandler(void) {
    unsigned long now = millis();
    if (now - lastReadTime < readDelay) { return; } // Limite de taxa de leitura
    lastReadTime = now;

    // Como os pinos usam INPUT_PULLUP, o clique aciona em nível LOW (0)
    upPress_flag    = (digitalRead(JOY_UP) == LOW);
    downPress_flag  = (digitalRead(JOY_DOWN) == LOW);
    leftPress_flag  = (digitalRead(JOY_LEFT) == LOW);
    rightPress_flag = (digitalRead(JOY_RIGHT) == LOW);
    
    // O clique do joystick ou o botão de ação acionam a seleção
    slPress_flag    = (digitalRead(JOY_CLICK) == LOW) || (digitalRead(SEL_BTN) == LOW);

    // ==================================================
    //          EVENT SUBMISSION
    // ==================================================
    if (upPress_flag || downPress_flag || leftPress_flag || rightPress_flag || slPress_flag) {
        AnyKeyPress = true;

        joystickMap();

        SelPress = slPress_flag; // Select
    }
}

// ======================================================
// POWER
// ======================================================
void powerOff() {}
void checkReboot() {}
