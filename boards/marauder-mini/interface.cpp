#include "core/powerSave.h"
#include <interface.h>

void _setup_gpio() {
    pinMode(UP_BTN, INPUT);
    pinMode(DWN_BTN, INPUT);
    pinMode(R_BTN, INPUT);
    pinMode(L_BTN, INPUT);
    pinMode(SEL_BTN, INPUT);

    // Inicialização do Botão Físico Vermelho (ESC / VOLTAR)
    #if defined(BACK_BTN)
        pinMode(BACK_BTN, INPUT_PULLUP);
    #elif defined(ESC_BTN)
        pinMode(ESC_BTN, INPUT_PULLUP);
    #endif

    bruceConfig.colorInverted = 0;

    // Aplica a rotação configurada no pins_arduino.h (0, 1, 2 ou 3)
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
    digitalWrite(TFT_BL, HIGH); // Ativa o backlight da tela
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

    if (!(millis() - tm > 200 || LongPress)) return;

    bool u = digitalRead(UP_BTN);
    bool d = digitalRead(DWN_BTN);
    bool r = digitalRead(R_BTN);
    bool l = digitalRead(L_BTN);
    bool s = digitalRead(SEL_BTN);

    // Leitura do Botão Vermelho Físico ESC (Ativo em nível LOW via INPUT_PULLUP)
    #if defined(BACK_BTN)
        bool b = (digitalRead(BACK_BTN) == LOW);
    #elif defined(ESC_BTN)
        bool b = (digitalRead(ESC_BTN) == LOW);
    #else
        bool b = false;
    #endif

    // Detecta se qualquer botão foi pressionado para acender/acordar a tela
    if (s || u || d || r || l || b) {
        tm = millis();
        if (wakeUpScreen()) AnyKeyPress = true;
        else return;
    }

    // 1. Ação Instantânea do Botão Físico Vermelho ESC (Voltando direto ao menu)
    if (b) {
        EscPress = true;
        return;
    }

    // 2. Atalho combinado (Esquerda + Selecionar)
    if (l && s) {
        EscPress = true;
        return;
    }

    // 3. Pressionamento longo no botão Esquerda (Segurar por 1 segundo para acionar ESC)
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

    // Mapeamento das ações dos botões direcionais
    if (r) NextPress = true;
    if (u) UpPress = true;
    if (d) DownPress = true;
    if (s) SelPress = true;
}

void powerOff() {
    // Função para desligamento por software (se implementado)
}

void checkReboot() {
    // Verificação de reinicialização
}
