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
//          manual digitalWrite() can cause problems when power is supplied
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
#include "keymap.h"

#define AC 0
#define DC 1

SWMTRX relayMux;
keymap key;

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
      
    }
    else if (command == "DUTS")
    {
      String dut = received.substring(5, received.length());

      relayMux.setDUT(dut);
    }
    else if (command == "INVT")
    {
      int relay_indx = received.indexOf(" ");
      int gnd_indx = received.lastIndexOf(" ");
      String relay = received.substring(relay_indx);
      int gnd = received.substring(gnd + 1, received.length() + 1).toInt();

      relayMux.setInverting(relay, gnd);
    }
    else if (command == "NINV")
    {
      int relay_indx = received.indexOf(" ");
      int gnd_indx = received.lastIndexOf(" ");
      String relay = received.substring(relay_indx);
      int gnd = received.substring(gnd + 1, received.length() + 1).toInt();

      relayMux.setNonInverting(relay, gnd);
    }
    else if (command == "VOUT")
    {
      String index = received.substring(5, received.length());
      relayMux.setOutput(index);
    }
    else if (command == "MEAS")
    {
      String index = received.substring(5, received.length());
      relayMux.setMeasure(index);
    }
    else if (command == "ALL0")
    {
      relayMux.resetAll();
    }
  }
}

