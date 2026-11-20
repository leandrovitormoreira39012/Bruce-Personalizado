#include "CYD28_TouchscreenR.h"
#include "core/powerSave.h"
#include "core/utils.h"
#include "hal/bright/bright.h"
#include "hal/device.h"
#include "hal/inputs/touch.h"
#include <interface.h>

#define BTN_ACT LOW

// Pinos dos 6 botoes fisicos (ligados ao GND quando pressionados)
#define SEL_BTN_PIN 0   // Selecionar / OK (pull-up interno)
#define ESC_BTN_PIN 15  // ESC / Voltar ao menu principal (pull-up interno)
#define R_BTN_PIN   3   // Direita / RX0 (pull-up interno)
#define L_BTN_PIN   39  // Esquerda / SN (input-only -> usar resistor pull-up 10k para 3.3V)
#define UP_BTN_PIN  34  // Cima (input-only -> usar resistor pull-up 10k para 3.3V)
#define DW_BTN_PIN  35  // Baixo (input-only -> usar resistor pull-up 10k para 3.3V)

// Pinos dos modulos configurados na placa
#define IR_TX_PIN   13
#define IR_RX_PIN   14
#define PN532_SDA   33
#define PN532_SCL   22
#define CC1101_CS   25
#define CC1101_GDO0 26
#define CC1101_GDO2 27
#define NRF24_CSN   2
#define NRF24_CE    4

extern CYD28_TouchR touch; // defined by hal/inputs/touch.cpp

static DeviceTouch touchCfg() {
    DeviceTouch cfg;
    // The XPT2046 reports landscape (rotation 1) coordinates
    // rotation:        0      1      2      3
    const bool swapXY[4] = {true, false, true, false};
    const bool mirrorX[4] = {true, false, false, true};
    const bool mirrorY[4] = {false, false, true, true};
    for (int i = 0; i < 4; i++) {
        cfg.SwapXY[i] = swapXY[i];
        cfg.MirrorX[i] = mirrorX[i];
        cfg.MirrorY[i] = mirrorY[i];
    }
    return cfg;
}

static void handleSingleButton(uint8_t pin, void (*action)()) {
    if (digitalRead(pin) == BTN_ACT) {
        if (!wakeUpScreen()) {
            AnyKeyPress = true;
        }
        action();
        unsigned long startTime = millis();
        while ((millis() - startTime) < 180 && digitalRead(pin) == BTN_ACT) {
            delay(5);
        }
    }
}

static void pressSelect() { SelPress = true; }
static void pressEsc()    { EscPress = true; }
static void pressUp()     { UpPress = true; PrevPress = true; }
static void pressDown()   { DwPress = true; NextPress = true; }
static void pressLeft()   { PrevPress = true; }
static void pressRight()  { NextPress = true; }

/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description:   initial setup for the device
***************************************************************************************/
void _setup_gpio() {
    bruceConfigPins.rotation = 1;

    // Infravermelho (TX / RX)
    bruceConfigPins.irTx = IR_TX_PIN;
    bruceConfigPins.irRx = IR_RX_PIN;

    // I2C / PN532
    bruceConfigPins.i2c_bus = {(gpio_num_t)PN532_SDA, (gpio_num_t)PN532_SCL};
    bruceConfigPins.PN532_bus = {
        (gpio_num_t)18, (gpio_num_t)19, (gpio_num_t)23, (gpio_num_t)PN532_SDA
    };

    // RF / UART / GPS / BadUSB
    bruceConfigPins.rfTx = CC1101_GDO0;
    bruceConfigPins.rfRx = CC1101_GDO2;
    bruceConfigPins.uart_bus = {(gpio_num_t)3, (gpio_num_t)1};   // rx, tx
    bruceConfigPins.gps_bus = {(gpio_num_t)3, (gpio_num_t)1};    // rx, tx
    bruceConfigPins.badusb_bus = {(gpio_num_t)3, (gpio_num_t)1}; // rx, tx

    // Barramentos SPI (sck, miso, mosi, cs, gdo0/ce)
    bruceConfigPins.outer_bus = {(gpio_num_t)18, (gpio_num_t)19, (gpio_num_t)23, (gpio_num_t)CC1101_CS};
    bruceConfigPins.CC1101_bus = {
        (gpio_num_t)18, (gpio_num_t)19, (gpio_num_t)23, (gpio_num_t)CC1101_CS, (gpio_num_t)CC1101_GDO0
    };
    bruceConfigPins.NRF24_bus = {
        (gpio_num_t)18, (gpio_num_t)19, (gpio_num_t)23, (gpio_num_t)NRF24_CSN, (gpio_num_t)NRF24_CE
    };
    bruceConfigPins.SDCARD_bus = {
        (gpio_num_t)18, (gpio_num_t)19, (gpio_num_t)23, (gpio_num_t)12
    };

    // Garante CS inativos no barramento SPI antes de iniciar os drivers
    pinMode(XPT2046_SPI_CONFIG_CS_GPIO_NUM, OUTPUT);
    digitalWrite(XPT2046_SPI_CONFIG_CS_GPIO_NUM, HIGH);
    pinMode(CC1101_CS, OUTPUT);
    digitalWrite(CC1101_CS, HIGH);
    pinMode(NRF24_CSN, OUTPUT);
    digitalWrite(NRF24_CSN, HIGH);
    pinMode(12, OUTPUT);
    digitalWrite(12, HIGH);

    // Configuracao dos 6 botoes fisicos
    pinMode(SEL_BTN_PIN, INPUT_PULLUP);
    pinMode(ESC_BTN_PIN, INPUT_PULLUP);
    pinMode(R_BTN_PIN,   INPUT_PULLUP);
    pinMode(L_BTN_PIN,   INPUT);
    pinMode(UP_BTN_PIN,  INPUT);
    pinMode(DW_BTN_PIN,  INPUT);

    bruceConfig.colorInverted = 1;
}

/***************************************************************************************
** Function name: _post_setup_gpio()
** Location: main.cpp
** Description:   second stage gpio setup — runs AFTER tft.init()
***************************************************************************************/
void _post_setup_gpio() {
    // Initialize XPT2046 touch using hardware SPI (shares bus with display)
    if (!hal_touch_init(touchCfg(), 0, TFT_MOSI == CYD28_TouchR_MOSI)) {
        Serial.println("[TOUCH] XPT2046 not started");
    } else {
        Serial.println("[TOUCH] XPT2046 started OK");
    }

    // Backlight com brilho nativo mais alto (0 a 255)
    hal_bright_attach(TFT_BL);
    hal_bright_set(TFT_BL, 230);
}

/*********************************************************************
** Function: setBrightness
** location: settings.cpp
** set brightness value
**********************************************************************/
void _setBrightness(uint8_t brightval) { hal_bright_set(TFT_BL, brightval); }

/*********************************************************************
** Function: InputHandler
** Handles the variables PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
**********************************************************************/
void InputHandler(void) {
    static long d_tmp = 0;
    if (millis() - d_tmp > 200 || LongPress) {
        BruceTouchPoint t;
        if (hal_touch_read(touchCfg(), t)) {
            d_tmp = millis();
            hal_touch_apply(t);
        }
    }

    checkPowerSaveTime();

    handleSingleButton(SEL_BTN_PIN, pressSelect);
    handleSingleButton(ESC_BTN_PIN, pressEsc);
    handleSingleButton(UP_BTN_PIN,  pressUp);
    handleSingleButton(DW_BTN_PIN,  pressDown);
    handleSingleButton(L_BTN_PIN,   pressLeft);
    handleSingleButton(R_BTN_PIN,   pressRight);
}

/*********************************************************************
** Function: powerOff
** location: mykeyboard.cpp
** Turns off the device (or try to)
**********************************************************************/
void powerOff() { esp_deep_sleep_start(); }

/*********************************************************************
** Function: goToDeepSleep
** location: mykeyboard.cpp
** Puts the device into DeepSleep
**********************************************************************/
void goToDeepSleep() { esp_deep_sleep_start(); }

/*********************************************************************
** Function: checkReboot
** location: mykeyboard.cpp
** Btn logic to turn off the device
**********************************************************************/
void checkReboot() {}
