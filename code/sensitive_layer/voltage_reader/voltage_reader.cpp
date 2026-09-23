#include "Arduino.h"
#include "voltage_reader.h"

tension_divisor::tension_divisor() {}
tension_divisor::tension_divisor( short pin, short num_res) : pin(pin), num_res(num_res) {
  pinMode(pin, INPUT);
}

void tension_divisor::measure_voltage() {
  this->voltage = (analogRead(this->pin) * this->num_res);
}
float tension_divisor::get_voltage() {
  return this->voltage;
}