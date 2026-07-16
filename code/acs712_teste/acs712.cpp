#include <algorithm>
#include "Arduino.h"
#include "acs712.h"

acs712::acs712() {}
acs712::acs712( byte pin ) : pin(pin) {
  pinMode(this->pin, INPUT);
}

void acs712::calibrate() {
  float sum;
  for (size_t i = 0; i < 100; ++i) {
    sum += analogRead(pin) * converter;
    delay(5);
  }
  this->zero_voltage = (sum / 100.f);
}

float acs712::getvolts() {
  /*TODO: depois transformar esse vector median em uma propriedade privada
  para evitar essa constante alocação de memória*/
  std::vector<float> median;
  
  for (size_t i = 0; i < 5; ++i) {
    median.insert(median.begin() + i, (analogRead(pin) * converter));
  }
  std::sort( median.begin(), median.end());

  return median[2];
}

float acs712::getamps() {
  return ( ( (this->getvolts() - zero_voltage) * 1000) / 185.f); //amperes A
}

float acs712::getmiliamps() {
  //return ( ( (this->getvolts() - zero_voltage) * 1000) / 185.f) * 1000;
  return ( ( (this->getvolts() - zero_voltage) * 1000000) / 185.f); //miliamperes mA
}