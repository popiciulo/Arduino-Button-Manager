#ifndef ButtonManager_h
#define ButtonManager_h

#include "Arduino.h"

struct Button {
    String name;
    unsigned int pin;
    unsigned int mode; // 0 = INPUT, 1 = OUTPUT, 2 = INPUT_PULLUP
    unsigned int status; // 0 = LOW, 1 = HIGH
    unsigned int prevStatus; // 0 = LOW, 1 = HIGH
    unsigned int timePressed;
};

class ButtonManager {
public:
    ButtonManager(Button *buttons, int totalButtons, unsigned int longPress);
    void checkButtons(void (*clickHandler)(Button, String));

private:
    Button* _buttons;
    int _totalButtons;
    unsigned int _longPress;
};

#endif