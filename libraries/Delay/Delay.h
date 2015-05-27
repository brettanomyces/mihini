#ifndef _LIB_DELAY_
#define _LIB_DELAY_

#include <Arduino.h> 

class Delay {

  public:
    Delay(long);
    void reset();
    bool ok();

  private:
    unsigned long m_period;
    unsigned long m_start;
};

#endif  // _LIB_DELAY_
