#ifndef VOLTAGE_READER_H
#define VOLTAGE_READER_H

#ifdef NECESSARY_CONSTS_H
#include "consts.h"
#endif

class tension_divisor {
  private:
    float voltage;
    short num_res;
    short pin;

    tension_divisor();

  public:
   //num_res = número de resistores (considerando que tem a mesma resistência)
    tension_divisor( short pin, short num_res );

    void measure_voltage();
    float get_voltage();
};

#endif
