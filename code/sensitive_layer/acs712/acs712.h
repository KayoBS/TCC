#ifndef ACS712_H
#define ACS712_H

//#include <ArduinoSTL.h>
//#include <Arduino.h>
#include "consts.h"


class acs712 {
  private:
    float current;
    byte pin;

    //math
    //std::vector<float> median;
    float median[5];
    float mid;

    float zero_voltage;
    float get_voltage();
    acs712();

  public:
    acs712( short pin );
    void calibrate();
    void measure_current();
    void measure_current_ma();
    float get_current();
    float get_zero();
};

#endif
