#ifndef TERMINAL_H
#define TERMINAL_H

#include <Arduino.h>

class Terminal {
  private:
  public:
    static void clear() {
      Serial.print("\x1B[H\x1B[2J");
    }
};

#endif