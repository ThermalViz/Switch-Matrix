#include "SwitchMatrix_CID.h"
#include <Arduino.h>

void SWMTRX::begin()
{
    pinMode(DUT_1, OUTPUT);
    pinMode(DUT_2, OUTPUT);
    pinMode(DUT_3, OUTPUT);
    pinMode(DUT_4, OUTPUT);

    pinMode(I_IN0, OUTPUT);
    pinMode(I_IN1, OUTPUT);
    pinMode(I_IN2, OUTPUT);
    pinMode(I_GND, OUTPUT);

    pinMode(NI_IN0, OUTPUT);
    pinMode(NI_IN1, OUTPUT);
    pinMode(NI_IN2, OUTPUT);
    pinMode(NI_GND, OUTPUT);

    pinMode(OUT_GND, OUTPUT);
    pinMode(OUT_FEEDBACK, OUTPUT);

    pinMode(DMM, OUTPUT);
    pinMode(SCOPE, OUTPUT);
    resetAll();
}

void SWMTRX::setMode(String mode)
{
    resetMode();
    toggleRelay(mode, HIGH);
}
void SWMTRX::setInverting(String input, bool ground)
{
    resetInverting();
    toggleRelay(input, HIGH);
    toggleRelay("I_GND", (ground == true ? HIGH : LOW));
}
void SWMTRX::setNonInverting(String input, bool ground)
{
    resetNonInverting();
    toggleRelay(input, HIGH);
    toggleRelay("NI_GND", (ground == true ? HIGH : LOW));
}

void SWMTRX::setDUT(String index)
{
    resetDUT();
    toggleRelay(index, HIGH);
}
void SWMTRX::setMeasure(String index)
{
    resetMeasure();
    toggleRelay(index, HIGH);
}

void SWMTRX::setOutput(String output)
{
    resetOut();
    toggleRelay(output, HIGH);
}

void SWMTRX::toggleRelay(String index, int status)
{
    int parsed = key.Parse(index);

    if (parsed != 0)
    {
        digitalWrite(parsed, status);
        Serial.println("Relay " + String(parsed) + " toggled to " + String(status));
    }
    else
    {
        Serial.println("Invalid Relay: " + index + " (" + parsed + ")");
    }
}

void SWMTRX::resetInverting()
{
    toggleRelay("I_IN0", LOW);
    toggleRelay("I_IN1", LOW);
    toggleRelay("I_IN2", LOW);
}
void SWMTRX::resetNonInverting()
{
    toggleRelay("NI_IN0", LOW);
    toggleRelay("NI_IN1", LOW);
    toggleRelay("NI_IN2", LOW);
    toggleRelay("NI_GND", LOW);
}
void SWMTRX::resetDUT()
{
    toggleRelay("DUT_1", LOW);
    toggleRelay("DUT_2", LOW);
    toggleRelay("DUT_3", LOW);
    toggleRelay("DUT_4", LOW);
}
void SWMTRX::resetOut()
{
    toggleRelay("OUT_GND", LOW);
    toggleRelay("OUT_FEEDBACK", LOW);
}
void SWMTRX::resetMeasure()
{
    toggleRelay("DMM", LOW);
    toggleRelay("SCOPE", LOW);
}
void SWMTRX::resetInput()
{
    toggleRelay("AC_MODE", LOW);
    toggleRelay("DC_MODE", LOW);
    toggleRelay("I_GND", LOW);
    toggleRelay("I_GND", LOW);
}

void SWMTRX::resetMode()
{
    toggleRelay("AC_MODE", LOW);
    toggleRelay("DC_MODE", LOW);
}

void SWMTRX::resetAll()
{
    toggleRelay("AC_MODE", LOW);
    toggleRelay("DC_MODE", LOW);
    toggleRelay("DUT_1", LOW);
    toggleRelay("DUT_2", LOW);
    toggleRelay("DUT_3", LOW);
    toggleRelay("DUT_4", LOW);
    toggleRelay("I_IN0", LOW);
    toggleRelay("I_IN1", LOW);
    toggleRelay("I_IN2", LOW);
    toggleRelay("I_GND", LOW);
    toggleRelay("NI_IN0", LOW);
    toggleRelay("NI_IN1", LOW);
    toggleRelay("NI_IN2", LOW);
    toggleRelay("NI_GND", LOW);
    toggleRelay("OUT_GND", LOW);
    toggleRelay("OUT_FEEDBACK", LOW);
    toggleRelay("DMM", LOW);
    toggleRelay("SCOPE", LOW);
}