#include "core/powerSave.h"
#include <interface.h>

void _setup_gpio() {
    // 1. Força o acionamento do Backlight no GPIO 32 imediatamente na inicialização
    pinMode(32, OUTPUT);
    digitalWrite(32, HIGH);

    // 2. Desativa outros barramentos CS para não interferir na inicialização do display
    pinMode(15, OUTPUT); digitalWrite(15, HIGH); // CC1101 CS
    pinMode(14, OUTPUT); digitalWrite(14, HIGH); // NRF24 CS
    pinMode(4, OUTPUT);  digitalWrite(4, HIGH);  // SD CS
    pinMode(5, OUTPUT);  digitalWrite(5, HIGH);  // TFT CS

    // 3. Pulso de Reset Físico no Display (GPIO 17) para destravar o ST7735
    pinMode(17, OUTPUT);
    digitalWrite(17, LOW);
    delay(100);
    digitalWrite(17, HIGH);
    delay(100);

    // Configuração dos Botões de Navegação
    pinMode(UP_BTN, INPUT);
    pinMode(DWN_BTN, INPUT);
    pinMode(R_BTN, INPUT);
    pinMode(L_BTN, INPUT);
    pinMode(SEL_BTN, INPUT);

    // Botão Físico ESC no Pino D2 (GPIO 2)
#if defined(BACK_BTN)
    pinMode(BACK_BTN, INPUT_PULLUP);
#elif defined(ESC_BTN)
    pinMode(ESC_BTN, INPUT_PULLUP);
#endif

    bruceConfig.colorInverted = 0;

#ifdef ROTATION
    bruceConfigPins.rotation = ROTATION;
#else
    bruceConfigPins.rotation = 1;
#endif

#if defined(HAS_SCREEN) && HAS_SCREEN
    tft.setRotation(bruceConfigPins.rotation);
#endif
}

void _post_setup_gpio() {
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
}

int getBattery() {
    return 0;
}

void _setBrightness(uint8_t brightval) {
    pinMode(TFT_BL, OUTPUT);
    if (brightval > 5) {
        digitalWrite(TFT_BL, HIGH);
    } else {
        digitalWrite(TFT_BL, LOW);
    }
}

void InputHandler(void) {
    static unsigned long tm = millis();
    static unsigned long esc_tm = millis();
    static bool esc_armed = false;

    if ((millis() - tm > 200 || LongPress)) return;

    bool u = digitalRead(UP_BTN);
    bool d = digitalRead(DWN_BTN);
    bool r = digitalRead(R_BTN);
    bool l = digitalRead(L_BTN);
    bool s = digitalRead(SEL_BTN);

#if defined(BACK_BTN)
    bool b = (digitalRead(BACK_BTN) == LOW);
#elif defined(ESC_BTN)
    bool b = (digitalRead(ESC_BTN) == LOW);
#else
    bool b = false;
#endif

    if (s || u || d || r || l || b) {
        tm = millis();
        if (!wakeUpScreen()) AnyKeyPress = true;
        else return;
    }

    if (b) {
        EscPress = true;
        return;
    }

    if (l && s) {
        EscPress = true;
        return;
    }

    if (l) {
        PrevPress = true;
        if (esc_armed == false) {
            esc_tm = millis();
            esc_armed = true;
        }
        if (esc_armed && (millis() - esc_tm > 1000)) {
            esc_armed = false;
            esc_tm = millis();
            PrevPress = false;
            EscPress = true;
        }
    } else {
        esc_armed = false;
    }

    if (r) NextPress = true;
    if (u) UpPress = true;
    if (d) DownPress = true;
    if (s) SelPress = true;
}

void powerOff() {}
void checkReboot() {}
