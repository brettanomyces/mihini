#ifndef _LIB_COUNTDOWN_
#define _LIB_COUNTDOWN_

#include <Arduino.h> 

class Countdown {
  public:
    Countdown();

    void reset(unsigned long);
    unsigned long remaining();

  private:
    bool m_running;
    unsigned long m_period;
    unsigned long m_start;
};

#endif  // _LIB_COUNTDOWN_
