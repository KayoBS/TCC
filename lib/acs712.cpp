#include "acs712.h"

Acs712::Acs712(unsigned short out_pin) {
  this->out_pin = out_pin;
  pinMode(this->out_pin, INPUT);
}

float Acs712::getCurrent() {
  float current;

  current = (analogRead(out_pin) - 64) / 185.0;

  return current;
}
