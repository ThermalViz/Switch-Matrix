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

void SWMTRX::setMode(int mode)
{
    digitalWrite(AC_MODE, (mode == 1 ? HIGH : LOW));
    digitalWrite(DC_MODE, (mode == 2 ? HIGH : LOW));

    if (mode == 0)
        resetInput();
}
void SWMTRX::setInverting(int input, bool ground)
{
    resetInverting();

    switch (input)
    {
    case I_IN0:
        digitalWrite(I_IN0, HIGH);
        break;
    case I_IN1:
        digitalWrite(I_IN1, HIGH);
        break;
    case I_IN2:
        digitalWrite(I_IN2, HIGH);
        break;
    default:
        break;
    }

    digitalWrite(I_GND, (ground == true ? HIGH : LOW));
}
void SWMTRX::setNonInverting(int input, bool ground)
{
    resetNonInverting();

    switch (input)
    {
    case NI_IN0:
        digitalWrite(NI_IN0, HIGH);
        break;
    case NI_IN1:
        digitalWrite(NI_IN1, HIGH);
        break;
    case NI_IN2:
        digitalWrite(NI_IN2, HIGH);
        break;
    default:
        break;
    }

    digitalWrite(NI_GND, (ground == true ? HIGH : LOW));
}

void SWMTRX::setDUT(int index)
{
    Serial.println("Setting DUT to " + String(index));
    resetDUT();

    switch (index)
    {
    case DUT_1:
        digitalWrite(DUT_1, HIGH);
        break;
    case DUT_2:
        digitalWrite(DUT_2, HIGH);
        break;
    case DUT_3:
        digitalWrite(DUT_3, HIGH);
        break;
    case DUT_4:
        digitalWrite(DUT_4, HIGH);
        break;
    default:
        break;
    }
}
void SWMTRX::setMeasure(int index)
{
    resetMeasure();

    switch (index)
    {
    case DMM:
        digitalWrite(DMM, HIGH);
        break;
    case SCOPE:
        digitalWrite(SCOPE, HIGH);
        break;
    default:
        break;
    }
}

void SWMTRX::setOutput(int output)
{
    resetOut();
    switch (output)
    {
    case OUT_GND:
        digitalWrite(OUT_GND, HIGH);
        break;
    case OUT_FEEDBACK:
        digitalWrite(OUT_FEEDBACK, HIGH);
        break;
    default:
        break;
    }
}

void SWMTRX::toggleRelay(int index, int status)
{
    digitalWrite(index, status);
    Serial.println("Relay " + String(index) + " toggled to " + String(status));
}

void SWMTRX::resetInverting()
{
    Serial.println("Disconnecting Inverting pins");
    digitalWrite(I_IN0, LOW);
    digitalWrite(I_IN1, LOW);
    digitalWrite(I_IN2, LOW);
}
void SWMTRX::resetNonInverting()
{
    Serial.println("Disconnecting Non-Inverting pins");
    digitalWrite(NI_IN0, LOW);
    digitalWrite(NI_IN1, LOW);
    digitalWrite(NI_IN2, LOW);
    digitalWrite(NI_GND, LOW);
}
void SWMTRX::resetDUT()
{
    Serial.println("Disconnecting DUT pins");
    digitalWrite(DUT_1, LOW);
    digitalWrite(DUT_2, LOW);
    digitalWrite(DUT_3, LOW);
    digitalWrite(DUT_4, LOW);
}
void SWMTRX::resetOut()
{
    Serial.println("Disconnecting Output");
    digitalWrite(OUT_GND, LOW);
    digitalWrite(OUT_FEEDBACK, LOW);
}
void SWMTRX::resetMeasure()
{
    Serial.println("Disconnecting DMM and Oscilloscope");
    digitalWrite(DMM, LOW);
    digitalWrite(SCOPE, LOW);
}
void SWMTRX::resetInput()
{
    Serial.println("Resetting all inputs");
    digitalWrite(AC_MODE, LOW);
    digitalWrite(DC_MODE, LOW);
    digitalWrite(I_GND, LOW);
    digitalWrite(I_GND, LOW);
}

void SWMTRX::resetAll()
{
    Serial.println("Resetting all relays");
    digitalWrite(AC_MODE, LOW);
    digitalWrite(DC_MODE, LOW);
    digitalWrite(DUT_1, LOW);
    digitalWrite(DUT_2, LOW);
    digitalWrite(DUT_3, LOW);
    digitalWrite(DUT_4, LOW);
    digitalWrite(I_IN0, LOW);
    digitalWrite(I_IN1, LOW);
    digitalWrite(I_IN2, LOW);
    digitalWrite(I_GND, LOW);
    digitalWrite(NI_IN0, LOW);
    digitalWrite(NI_IN1, LOW);
    digitalWrite(NI_IN2, LOW);
    digitalWrite(NI_GND, LOW);
    digitalWrite(OUT_GND, LOW);
    digitalWrite(OUT_FEEDBACK, LOW);
    digitalWrite(DMM, LOW);
    digitalWrite(SCOPE, LOW);
}