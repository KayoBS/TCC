#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
private:
    byte pin;
    bool state;

    Led();

public:
    Led(byte pin, bool state);

    void begin();

    void toggle_state();
    void set_state(bool state);
    bool get_state();
};

#endif
