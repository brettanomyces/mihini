#include "Button.h"

Button::Button(){
}

void Button::setup(int _pin) {
  m_pin = _pin;
  pinMode(m_pin, INPUT);
  digitalWrite(m_pin, HIGH);
  m_previousState = HIGH;
}

// returns true if a button press has occured. a button press involves
// the button being pushed down and then released.
bool Button::wasPressed(){
  int pressed = false;
  int currentState = digitalRead(m_pin);
  if (m_previousState == HIGH && currentState == HIGH){
    // no button interaction has occured
    pressed = false;
  } else if (m_previousState == HIGH  && currentState == LOW){
    // button pushed down
    pressed = false;
    m_previousState = currentState;
  } else if (m_previousState == LOW  && currentState == LOW){
    // button held down
    pressed = false;
  } else {  //(m_previousState == LOW  && currentState == HIGH)
    // button released
    pressed = true;
    m_previousState = currentState;
  }
  return pressed;
}
