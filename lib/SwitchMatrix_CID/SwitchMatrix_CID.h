#ifndef SWITCH_MATRIX
#define SWITCH_MATRIX
#include "keymap.h"
#include <Arduino.h>

class SWMTRX
{
    public:
        void begin();
        void toggleRelay(String relay, int status);
        void setMode(String mode);
        void setInverting(String input, bool ground);
        void setNonInverting(String input, bool ground);
        void setOutput(String output);
        void setMeasure(String index);
        void setDUT(String index);
        void resetInverting();
        void resetNonInverting();
        void resetDUT();
        void resetOut();
        void resetMeasure();
        void resetInput();
        void resetAll();
        void resetMode();
    private:
        keymap key;
};

#endif
