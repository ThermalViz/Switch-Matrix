#ifndef PARSE
#define PARSE

#include <Arduino.h>

#define AC_MODE 2
#define DC_MODE 18

#define DUT_1 3
#define DUT_2 4
#define DUT_3 15
#define DUT_4 16

#define I_IN0 7
#define I_IN1 6
#define I_IN2 5
#define I_GND 19

#define NI_IN0 11
#define NI_IN1 12
#define NI_IN2 13
#define NI_GND 17

#define OUT_GND 8
#define OUT_FEEDBACK 9

#define DMM 10
#define SCOPE 14

// Relay Mappings
#define K2 6
#define K4 5
#define K6 7

#define K11 A5
#define K3 AC_MODE
#define K36 DC_MODE

#define K8 11
#define K10 12
#define K13 13

#define K35 DC_MODE
#define K14 AC_MODE
#define K1 A3

#define K5 8
#define K7 9
#define K9 10
#define K12 A0

class keymap
{
public:
    int Parse(String command);

private:
};

#endif