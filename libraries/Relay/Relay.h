#ifndef _LIB_RELAY_
#define _LIB_RELAY_

#include <Arduino.h>
#include "Delay.h"

class Relay {
  public:
    Relay();
    void setup(int);
    void setup(int, String, long, uint8_t);
    void on();
    void off();
    bool isOn();
    bool waiting();

  private:
    uint8_t onLevel();
    uint8_t offLevel();

    int m_pin;
    String m_name;
    bool m_on;
    uint8_t m_on_level; // HIGH or LOW
    Delay m_delay;
};

#endif  // _LIB_RELAY_
