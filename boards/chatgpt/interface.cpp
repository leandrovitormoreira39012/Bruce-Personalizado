#include "core/powerSave.h"

#include <Arduino.h>
#include <interface.h>

/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description: initial setup for the device
***************************************************************************************/

void _setup_gpio() {
}

/***************************************************************************************
** Function name: _post_setup_gpio()
** Location: main.cpp
** Description: second stage gpio setup
***************************************************************************************/

void _post_setup_gpio() {
}

/***************************************************************************************
** Function: getBattery()
** Location: display.cpp
** Description: Delivers the battery value from 1-100
***************************************************************************************/

int getBattery() {
    return 100;
}

/***************************************************************************************
** Function: isCharging()
** Description: Battery charging status
***************************************************************************************/

bool isCharging() {
    return false;
}

/***************************************************************************************
** Function: setBrightness
** Location: settings.cpp
** Description: Set display brightness
***************************************************************************************/

void _setBrightness(uint8_t brightval) {
}

/***************************************************************************************
** Function: InputHandler
** Description: Handles device input
***************************************************************************************/

void InputHandler(void) {
}

/***************************************************************************************
** Function: powerOff
** Location: mykeyboard.cpp
** Description: Turns off the device
***************************************************************************************/

void powerOff() {
}

/***************************************************************************************
** Function: checkReboot
** Location: mykeyboard.cpp
** Description: Reboot handling
***************************************************************************************/

void checkReboot() {
}

