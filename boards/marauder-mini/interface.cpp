#include "core/powerSave.h"
#include <interface.h>

/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description:   initial setup for the device
***************************************************************************************/
void _setup_gpio() {
    pinMode(UP_BTN, INPUT);
    pinMode(SEL_BTN, INPUT);
    pinMode(DW_BTN, INPUT);
    pinMode(R_BTN, INPUT);
    pinMode(L_BTN, INPUT);

    // Inicialização do novo botão dedicado ESC/VOLTAR (GPIO 0)
#if defined(BACK_BTN)
    pinMode(BACK_BTN, INPUT_PULLUP);
#elif defined(ESC_BTN)
    pinMode(ESC_BTN, INPUT_PULLUP);
#endif

    bruceConfig.colorInverted = 0;
    bruceConfigPins.rotation = 0; // portrait mode for Phantom
}

/***************************************************************************************
** Function name: _post_setup_gpio()
** Location: main.cpp
** Description:   second stage gpio setup to make a few functions work
***************************************************************************************/
void _post_setup_gpio() { 
    pinMode(TFT_BL, OUTPUT); 
    digitalWrite(TFT_BL, HIGH); // Ativa o brilho máximo da tela
}

/***************************************************************************************
** Function name: getBattery()
** location: display.cpp
** Description:   Delivers the battery value from 1-100
***************************************************************************************/
int getBattery() { return 0; }

/*********************************************************************
** Function: setBrightness
** location: settings.cpp
** set brightness value
**********************************************************************/
void _setBrightness(uint8_t brightval) {
    pinMode(TFT_BL, OUTPUT);
    if (brightval > 5) {
        digitalWrite(TFT_BL, LOW);
        digitalWrite(TFT_BL, HIGH);
    } else {
        digitalWrite(TFT_BL, HIGH);
        digitalWrite(TFT_BL, LOW);
    }
}

/*********************************************************************
** Function: InputHandler
** Handles the variables PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
**********************************************************************/
void InputHandler(void) {
    static unsigned long tm = millis();
    static unsigned long esc_tm = millis();
    static bool esc_armed = false;
    if (!(millis() - tm > 200 || LongPress)) return;

    bool u = digitalRead(UP_BTN);
    bool d = digitalRead(DW_BTN);
    bool r = digitalRead(R_BTN);
    bool l = digitalRead(L_BTN);
    bool s = digitalRead(SEL_BTN);

    // Leitura do novo botão dedicado de ESC/VOLTAR (GPIO 0)
#if defined(BACK_BTN)
    bool b = digitalRead(BACK_BTN);
#elif defined(ESC_BTN)
    bool b = digitalRead(ESC_BTN);
#else
    bool b = HIGH;
#endif

    // Detecta se qualquer botão foi pressionado para acender/acordar a tela
    if (!s || !u || !d || !r || !l || !b) {
        tm = millis();
        if (!wakeUpScreen()) AnyKeyPress = true;
        else return;
    }

    // 1. Ação Instantânea do Botão Físico ESC (GPIO 0 / BOOT)
    if (!b) {
        EscPress = true;
        return;
    }

    // 2. Atalho combinado (Esquerda + Selecionar)
    if (!l && !s) {
        EscPress = true;
        return;
    }

    // 3. Pressionamento longo no botão Esquerda (Segurar 1 segundo para ESC)
    if (!l) {
        PrevPress = true;
        if (esc_armed == false) {
            esc_tm = millis();
            esc_armed = true;
        }
    }
    if (esc_armed && millis() - esc_tm > 1000) {
        esc_armed = false;
        esc_tm = millis();
        PrevPress = false;
        EscPress = true;
    }

    if (!r) NextPress = true;
    if (!u) UpPress = true;
    if (!d) DownPress = true;
    if (!s) SelPress = true;
}

/*********************************************************************
** Function: powerOff
** location: mykeyboard.cpp
** Turns off the device (or try to)
**********************************************************************/
void powerOff() {}

/*********************************************************************
** Function: checkReboot
** location: mykeyboard.cpp
** Btn logic to turn off the device (name is odd btw)
**********************************************************************/
void checkReboot() {}
