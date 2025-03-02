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
    int parsed = key.Parse(mode);

    if (parsed == AC_MODE || parsed == DC_MODE)
    {
        resetMode();
        toggleRelay(mode, HIGH);
    }
    else
    {
        Serial.println("Invalid Mode: " + mode + " (" + parsed + ")");
    }
}
void SWMTRX::setInverting(String input, bool ground)
{
    int parsed = key.Parse(input);

    if (
        parsed == I_IN0 ||
        parsed == I_IN1 ||
        parsed == I_IN2 ||
        parsed == I_GND)
    {
        resetInverting();
        toggleRelay(input, HIGH);
        toggleRelay("I_GND", (ground == true ? HIGH : LOW));
    }
    else
    {
        Serial.println("Invalid Inverting Input: " + input + " (" + parsed + ")");
    }
}
void SWMTRX::setNonInverting(String input, bool ground)
{
    int parsed = key.Parse(input);

    if (
        parsed == NI_IN0 ||
        parsed == NI_IN1 ||
        parsed == NI_IN2 ||
        parsed == NI_GND)
    {
        resetNonInverting();
        toggleRelay(input, HIGH);
        toggleRelay("NI_GND", (ground == true ? HIGH : LOW));
    }
    else
    {
        Serial.println("Invalid Non-Inverting Input: " + input + " (" + parsed + ")");
    }
}

void SWMTRX::setDUT(String index)
{
    int parsed = key.Parse(index);
    Serial.println("Setting DUT to " + String(index));

    if (
        parsed == DUT_1 ||
        parsed == DUT_2 ||
        parsed == DUT_3 ||
        parsed == DUT_4)
    {
        resetDUT();
        toggleRelay(index, HIGH);
    }
}
void SWMTRX::setMeasure(String index)
{
    int parsed = key.Parse(index);

    if (
        parsed == DMM ||
        parsed == SCOPE)
    {
        resetMeasure();
        toggleRelay(index, HIGH);
    }
}

void SWMTRX::setOutput(String output)
{
    int parsed = key.Parse(output);

    if (
        parsed == OUT_FEEDBACK ||
        parsed == OUT_GND)
    {
        resetOut();
        toggleRelay(output, HIGH);
    }
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
    Serial.println("Disconnecting Non-Inverting pins");
    toggleRelay("NI_IN0", LOW);
    toggleRelay("NI_IN1", LOW);
    toggleRelay("NI_IN2", LOW);
    toggleRelay("NI_GND", LOW);
}
void SWMTRX::resetDUT()
{
    Serial.println("Disconnecting DUT pins");
    toggleRelay("DUT_1", LOW);
    toggleRelay("DUT_2", LOW);
    toggleRelay("DUT_3", LOW);
    toggleRelay("DUT_4", LOW);
}
void SWMTRX::resetOut()
{
    Serial.println("Disconnecting Output");
    toggleRelay("OUT_GND", LOW);
    toggleRelay("OUT_FEEDBACK", LOW);
}
void SWMTRX::resetMeasure()
{
    Serial.println("Disconnecting DMM and Oscilloscope");
    toggleRelay("DMM", LOW);
    toggleRelay("SCOPE", LOW);
}
void SWMTRX::resetInput()
{
    Serial.println("Resetting all inputs");
    toggleRelay("AC_MODE", LOW);
    toggleRelay("DC_MODE", LOW);
    toggleRelay("I_GND", LOW);
    toggleRelay("I_GND", LOW);
}

void SWMTRX::resetMode()
{
    Serial.println("Disconnecting Inverting pins");
    toggleRelay("AC_MODE", LOW);
    toggleRelay("DC_MODE", LOW);
}

void SWMTRX::resetAll()
{
    Serial.println("Resetting all relays");
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