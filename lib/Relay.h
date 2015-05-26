#ifndef _LIB_RELAY_
#define _LIB_RELAY_

#include <Arduino.h>
#include "Delay.h"

class Relay {
  public:
    // use default parameters
    Relay(int pin, String name = "", long delay = 0);

    void on();
    void off();
    void log(String str);
    bool isOn();
    bool waiting();

  private:
    int m_pin;
    String m_name;
    bool m_on;
    Delay m_delay;
};

#endif // _LIB_RELAY_
