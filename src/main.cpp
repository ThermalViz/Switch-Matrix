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
//    Keymap:
//        DUT_1     I_IN0     NI_IN0      OUT_GND         AC_MODE
//        DUT_2     I_IN1     NI_IN1      OUT_FEEDBACK    DC_MODE
//        DUT_3     I_IN2     NI_IN2      DMM 
//        DUT_4     I_GND     NI_GND      SCOPE      
//
//    Commands:
//        - RLAY [Key] - manually sets a relay
//            do not use this command unless you know what you're doing!.
//            Ex: RLAY I_IN1 1   | sets relay I_IN1 to HIGH
//
//        - DUTS [Key] - sets the active DUT. Only one DUT can be active at a time
//            Ex: DUTS DUT_1      | sets DUT_1 as the active DUT.
//
//        - INVT [Key] [0/1] - Sets the inverting input resistors and if input is GND.
//            Ex: INVT I_IN1 1 1    | sets the inverting input to the 3rd option and is grounded.
//
//        - NINV [Key] [0/1] - Sets the non-inverting input resistors and if input is GND.
//            Ex: NINV NI_IN1 1 1    | sets the non-inverting input to the 3rd option and is grounded.
//
//        - VOUT [Key] - Sets the output if to GND or to the feedback resistor.
//            Ex: VOUT OUT_GND      | sets the output to ground.
//
//        - MEAS [Key] - Sets the instrument measuring to either the DMM or the oscilloscope.
//            Ex: MEAS SCOPE      | sets the measurement tool to the oscilloscope.
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
      int relay_indx = received.indexOf(" ");
      int status_indx = received.lastIndexOf(" ");
      String relay = received.substring(relay_indx);
      int status = received.substring(status_indx + 1, received.length() + 1).toInt();

      relayMux.toggleRelay(relay, status);
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

