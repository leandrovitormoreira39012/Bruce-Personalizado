#include <Arduino.h>
#include "core/powerSave.h"
#include <interface.h>


// ============================================================
// BRUCE - CHATGPT
// ESP32-S3 N16R8
// Interface personalizada
// ============================================================


// ============================================================
// INICIALIZAÇÃO DOS GPIOs
// ============================================================

void _setup_gpio() {
    // A configuração específica dos periféricos será feita
    // pelos módulos do Bruce.
}


// ============================================================
// PÓS-INICIALIZAÇÃO
// ============================================================

void _post_setup_gpio() {
    // Reservado para inicializações adicionais.
}


// ============================================================
// BATERIA
// ============================================================

int getBattery() {
    // Temporariamente retorna 100%.
    // A leitura real será ativada quando confirmarmos
    // o divisor de tensão da bateria.

    return 100;
}


// ============================================================
// CARREGAMENTO
// ============================================================

bool isCharging() {
    // O circuito TP4056 ainda não possui um GPIO de
    // indicação de carregamento definido.

    return false;
}


// ============================================================
// BRILHO
// ============================================================

void _setBrightness(uint8_t brightval) {
    // O LED/backlight da tela está ligado diretamente ao 3V3.
    // Portanto, não há controle de brilho por GPIO neste momento.

    (void)brightval;
}


// ============================================================
// ENTRADAS
// ============================================================

void InputHandler(void) {
    // As entradas do JY050 serão integradas aqui conforme
    // o sistema de entrada utilizado pelo Bruce.
}


// ============================================================
// DESLIGAMENTO
// ============================================================

void powerOff() {
    // Implementação de desligamento será adicionada quando
    // definirmos o circuito de alimentação/controle.
}


// ============================================================
// REINICIALIZAÇÃO
// ============================================================

void checkReboot() {
    // O RST do JY050 está conectado diretamente ao EN
    // da ESP32-S3, portanto o reset físico já é realizado
    // pelo próprio circuito.
}
