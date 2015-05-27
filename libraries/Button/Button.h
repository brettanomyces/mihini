#ifndef _LIB_BUTTON_
#define _LIB_BUTTON_

#include <Arduino.h> 

class button {

  public:
    button(int);
    bool wasPressed();

  private:
    int pin;
    int previousState; // either HIGH or LOW
};

#endif  // _LIB_BUTTON_
