#ifndef SWITCH_MATRIX
#define SWITCH_MATRIX

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

class SWMTRX
{
    public:
        void begin();
        void toggleRelay(int relay, int status);
        void setMode(int mode);
        void setInverting(int input, bool ground);
        void setNonInverting(int input, bool ground);
        void setOutput(int output);
        void setMeasure(int index);
        void setDUT(int index);
        void resetInverting();
        void resetNonInverting();
        void resetDUT();
        void resetOut();
        void resetMeasure();
        void resetInput();
        void resetAll();
};

#endif