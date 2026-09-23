#ifndef VOLTAGE_DIVIDER_METRICS_H
#define VOLTAGE_DIVIDER_METRICS_H

#ifdef TYPE_DATA_TENSION_CURRENT_POWER_H
#include "tdata.h"
#endif

#include <Arduino.h>

typedef unsigned int uint;

class VoltageDividerMetrics {
  private:
    byte pin;

    float voltage;
    float current;
    uint resistance;
    uint num_res; //number of resistors

    VoltageDividerMetrics();
    
  public:
    //considerando resistores de mesma resistência
    VoltageDividerMetrics(byte pin, uint num_resistors, uint resistor_value);
    
    void measure();
    void get_data(tdata *data);
};

#endif
