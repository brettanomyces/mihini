#ifndef _LIB_BUTTON_
#define _LIB_BUTTON_

#include <Arduino.h> 

class Button {

  public:
    Button();
    void setup(int);
    bool wasPressed();

  private:
    int m_pin;
    int m_previousState; // either HIGH or LOW
};

#endif  // _LIB_BUTTON_
