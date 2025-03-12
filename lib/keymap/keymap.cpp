#include "keymap.h"

int keymap::Parse(String command) {
    if(command == "AC_MODE" || command == "K3" || command == "K14") return AC_MODE;
    if(command == "DC_MODE" || command == "K36" || command == "35") return DC_MODE;
    if(command == "DUT_1") return DUT_1;
    if(command == "DUT_2") return DUT_2;
    if(command == "DUT_3") return DUT_3;
    if(command == "DUT_4") return DUT_4;
    if(command == "I_IN0" || command == "K6") return I_IN0;
    if(command == "I_IN1" || command == "K2") return I_IN1;
    if(command == "I_IN2" || command == "K4") return I_IN2;
    if(command == "I_GND" || command == "K11") return I_GND;
    if(command == "NI_IN0" || command == "K8") return NI_IN0;
    if(command == "NI_IN1" || command == "K10") return NI_IN1;
    if(command == "NI_IN2" || command == "K13") return NI_IN2;
    if(command == "NI_GND" || command == "K1") return NI_GND;
    if(command == "OUT_GND" || command == "K5") return OUT_GND;
    if(command == "OUT_FEEDBACK" || command == "K7") return OUT_FEEDBACK;
    if(command == "DMM" || command == "K9") return DMM;
    if(command == "SCOPE" || command == "K12") return SCOPE;

    return 0;
}