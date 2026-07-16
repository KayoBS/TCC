#ifndef ACS712_H
#define ACS712_H

#include <ArduinoSTL.h>
#include <Arduino.h>
#include "consts.h"

class acs712 {
  private:
    byte pin;
    float zero_voltage;
    acs712();

  public:
    acs712( byte pin );
    void calibrate();
    float getvolts();
    float getamps();
    float getmiliamps();
};

#endif