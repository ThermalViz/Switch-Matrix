#include "keymap.h"
#include <Arduino.h>

int keymap::Parse(String command) {
    if(command == "AC_MODE") return AC_MODE;
    if(command == "DC_MODE") return DC_MODE;
    if(command == "DUT_1") return DUT_1;
    if(command == "DUT_2") return DUT_2;
    if(command == "DUT_3") return DUT_3;
    if(command == "DUT_4") return DUT_4;
    if(command == "I_IN0") return I_IN0;
    if(command == "I_IN1") return I_IN1;
    if(command == "I_IN2") return I_IN2;
    if(command == "I_GND") return I_GND;
    if(command == "NI_IN0") return NI_IN0;
    if(command == "NI_IN1") return NI_IN1;
    if(command == "NI_IN2") return NI_IN2;
    if(command == "NI_GND") return NI_GND;
    if(command == "OUT_GND") return OUT_GND;
    if(command == "OUT_FEEDBACK") return OUT_FEEDBACK;
    if(command == "DMM") return DMM;
    if(command == "SCOPE") return SCOPE;

    return 0;
}