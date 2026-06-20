#include "acs712.h"

acs712::acs712( byte pin ) : pin(pin) {
  pinMode(this->pin, INPUT);
}

float acs712::getvolts() {
  return (analogRead(pin) * converter);
  //return (analogRead(pin) * converter) - 2.5f;
}

float acs712::getamps() {
  return ( ((this->getvolts() -2.5f) *1000) / 185.f); //miliamperes
  //return (this->getvolts() / 185.f); //miliamperes
}
