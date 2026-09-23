// #include <cstddef>
// #include <algorithm>
#include "Arduino.h"
#include "acs712.h"
#include "ordenation_methods.h"

acs712::acs712() {}
acs712::acs712( short pin ) : pin(pin) {
  pinMode(this->pin, INPUT);
  zero_voltage = 2.5f;
}

void acs712::calibrate() {
  zero_voltage = 0;
  for (size_t i = 0; i < 100; ++i) {
    zero_voltage += analogRead(pin) * converter;
    delay(5);
  }
  this->zero_voltage = (zero_voltage / 100.f);
}

float acs712::get_voltage() {
  this->mid = 0.f;
  for(short j = 0; j < 10; ++j) {
    for(short i = 0; i < 5; ++i) {
      this->median[i] = (analogRead(pin) * converter);
    }

    unsigned int size = sizeof(median) / sizeof(median[0]);
    bsort(median, size);
    
    mid += median[2];
  }
  
  mid /= 10;

  return this->mid;
}

float acs712::get_current() {
  return this->current;
}

float acs712::get_zero() {
  return this->zero_voltage;
}

/*existe uma alta probabilidade do erro de leitura do ACS712 estar
na parte em que eu divido todo o valor da saída do OUT do sensor
pela sua sensibilidade em mV/A (185) quando talvez eu devesse
estar dividindo pela sensibilidade em V/A (0.185). Vou deixar uma
versão com essa alteração comentada em baixo para ver se funciona
posteriormente no laboratório. Também não sei se as multiplicações
estão completamente corretas, vou analizar as questões de
grandezas uma outra hora*/
void acs712::measure_current() {
  this->current = ( ( (this->get_voltage() - zero_voltage) * 1000) / 185.f); //amperes A
  // this->current = ( ( (this->get_voltage() - zero_voltage) * 1000) / 0.185f); //amperes A
}

void acs712::measure_current_ma() {
  //return ( ( (this->getvolts() - zero_voltage) * 1000) / 185.f) * 1000;
  this->current = ( ( (this->get_voltage() - zero_voltage) * 1000000) / 185.f); //miliamperes mA
  // this->current = ( ( (this->get_voltage() - zero_voltage) * 1000000) / 0.185f); //miliamperes mA
}