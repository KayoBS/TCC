#include "esp32-hal-gpio.h"
#include "led.h"

Led::Led() {}
Led::Led(byte pin, bool state) {
  this->pin = pin;
  this->state = state;
  digitalWrite(this->pin, this->state);
}

void Led::begin() {
  pinMode(this->pin, OUTPUT);
}

void Led::toggle_state() {
  this->state = !this->state;
  digitalWrite(this->pin, this->state);
}

void Led::set_state(bool state) {
  this->state = state;
  digitalWrite(this->pin, this->state);
}

bool Led::get_state() {
  return this->state;
}
