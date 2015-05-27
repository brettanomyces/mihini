#include "Delay.h"

Delay::Delay(long _period) {
  m_period = _period;
  m_start = 0;
}

// reset the delay period
void Delay::reset() {
  m_start = millis();
}

// check if delay period has been exceeded
// true if delay has been exceeded
bool Delay::ok() {
  if (millis() - m_start > m_period) {
    // note that unlike DoEvery's check() we do not increment start
    return true;
  } else {
    return false;
  }
}
