//////////////////////////////////////////////////////////////////////////
//
//    Switch Matrix Board MUX
//    Developed by CID:
//        - Joshua Chan
//        - John Juvi De Villa
//        - Ace Alexander Ilog
//
//    WARNING!
//        Do not use digitalwrite() unless YOU KNOW WHAT YOU'RE DOING.
//        manual digitalWrite() can cause problems when power is supplied
//        to the relays. At worst, the board or DUT can break.
//
//    Commands:
//        - RLAY [Pin] [1/0] - manually sets a relay
//            do not use this command unless you know what you're doing!.
//            Ex: RLAY A0 1   | sets relay on A0 to HIGH
//
//        - DUTS [number] - sets the active DUT. Only one DUT can be active at a time
//            Ex: DUTS 3      | sets DUT 3 as the active DUT.
//
//        - INVT [0/1/2] [0/1] - Sets the inverting input resistors and if input is GND.
//            Ex: INVT 2 1    | sets the inverting input to the 3rd option and is grounded.
//
//        - NINV [0/1/2] [0/1] - Sets the non-inverting input resistors and if input is GND.
//            Ex: NINV 2 1    | sets the non-inverting input to the 3rd option and is grounded.
//
//        - VOUT [0/1] - Sets the output if to GND or to the feedback resistor.
//            Ex: VOUT 0      | sets the output to the 1st option which is to ground.
//
//        - MEAS [0/1] - Sets the instrument measuring to either the DMM or the oscilloscope.
//            Ex: MEAS 1      | sets the measurement tool to the 2nd option which is the oscilloscope.
//
//        - ALL0 - Sets all relays OFF.
//
//
//
//////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include "SwitchMatrix_CID.h"

#define AC 0
#define DC 1

SWMTRX relayMux;

void setup()
{
  Serial.begin(9600);
  relayMux.begin();
}

void loop()
{
  if (Serial.available())
  {
    String received = Serial.readStringUntil('\n');
    String command = received.substring(0, 4); // select the first 4 characters of command

    if (received == "WHOU")
    {
      Serial.println("I am main board, ready for service");
    }
    else if (command == "RLAY")
    {
      int relay_indx = received.indexOf(" ");
      int status_indx = received.lastIndexOf(" ");
      int relay = received.substring(relay_indx + 1, status_indx).toInt();
      int status = received.substring(status_indx + 1, received.length() + 1).toInt();

      relayMux.toggleRelay(relay, status);
    }
    else if (command == "DUTS")
    {
      int dut = received.substring(5, 6).toInt();
      relayMux.setDUT(dut);
    }
    else if (command == "INVT")
    {
      int index = received.substring(5, 6).toInt();
      int gnd = (received.substring(7, 8).toInt() == 1 ? HIGH : LOW);

      switch (index)
      {
      case 0:
        relayMux.setInverting(I_IN0, gnd);
        break;
      case 1:
        relayMux.setInverting(I_IN1, gnd);
        break;
      case 2:
        relayMux.setInverting(I_IN2, gnd);
        break;
      default:
        break;
      }
    }
    else if (command == "NINV")
    {
      int index = received.substring(5, 6).toInt();
      int gnd = (received.substring(7, 8).toInt() == 1 ? HIGH : LOW);

      switch (index)
      {
      case 0:
        relayMux.setInverting(NI_IN0, gnd);
        break;
      case 1:
        relayMux.setInverting(NI_IN1, gnd);
        break;
      case 2:
        relayMux.setInverting(NI_IN2, gnd);
        break;
      default:
        break;
      }
    }
    else if (command == "VOUT")
    {
      int index = received.substring(5, 6).toInt();
      switch (index)
      {
      case 0:
        relayMux.setOutput(OUT_GND);
        break;
      case 1:
        relayMux.setOutput(OUT_FEEDBACK);
        break;
      default:
        break;
      }
    }
    else if (command == "MEAS")
    {
      int index = received.substring(5, 6).toInt();
      switch (index)
      {
      case 0:
        relayMux.setMeasure(DMM);
        break;
      case 1:
        relayMux.setMeasure(SCOPE);
        break;
      default:
        break;
      }
    }
    else if (command == "ALL0")
    {
      relayMux.resetAll();
    }
  }
}