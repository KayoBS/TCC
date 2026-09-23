#include "voltage_divider_metrics.h"

VoltageDividerMetrics::VoltageDividerMetrics() {}

VoltageDividerMetrics::VoltageDividerMetrics(byte pin, uint num_resistors, uint resistor_value) {
  this->pin = pin;
  this->num_res = num_resistors;
  this->resistance = (resistor_value * num_resistors);
  pinMode(pin, INPUT);
}

void VoltageDividerMetrics::measure() {
  //this->voltage = (analogRead(this->pin) * 5.f / 1023.f) * this->num_res; //arduino uno
  this->voltage = (analogRead(this->pin) * 3.3f / 4095.f) * this->num_res; //esp32
  this->current = (voltage / resistance);
}

void VoltageDividerMetrics::get_data(tdata *data) {
  data->voltage = this->voltage;
  data->current = this->current;
  data->power   = (this->voltage * this->current);
}