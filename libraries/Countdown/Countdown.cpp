#include "Countdown.h"

Countdown::Countdown() {
}

// reset the Countdown period
void Countdown::reset(unsigned long _period) {
  m_period = _period;
  m_start = millis();
  m_running = true;
}

unsigned long Countdown::remaining() {
  if (m_running){
    unsigned long elapsed = millis() - m_start;
    // we don't check m_period - elapsed because they are unsigned
    if (elapsed > m_period){
      m_running = false;
      return 0;
    } else {
      return m_period - elapsed;
    }
  } else {
    // not running so no time remaining
    return 0;
  }
}
