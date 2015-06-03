#include "Relay.h"

Relay::Relay(){
}

void Relay::setup(int _pin){
  setup(_pin, "relay", 0, LOW);
}

void Relay::setup(int _pin, String _name, long _delay, uint8_t _on_level) {
  m_on_level = _on_level;
  m_name = _name;

  m_pin = _pin;
  pinMode(m_pin, OUTPUT);
  digitalWrite(m_pin, offLevel());

  m_on = false;

  m_delay.setup(_delay);
  m_delay.reset();
}

void Relay::on(){
  if(!m_on){
    // relay not already on
    if(m_delay.ok()){
      // relay not in delay period
      digitalWrite(m_pin, onLevel());
      m_on = true;
      m_delay.reset();
    } 
  }
}

void Relay::off(){
  if(m_on){
    // relay not already off
    if(m_delay.ok()){
      // relay not in delay period
      digitalWrite(m_pin, offLevel());
      m_on = false;
      m_delay.reset();
    }
  }
}

bool Relay::isOn(){
  return m_on;
}

bool Relay::waiting(){
  if(m_delay.ok()){
    return false;
  } else {
    return true;
  }
}

uint8_t Relay::onLevel() {
  if (m_on_level == HIGH) {
    return HIGH;
  }
  return LOW;
}

uint8_t Relay::offLevel() {
  if (m_on_level == HIGH) {
    return LOW;
  }
  return HIGH;
}
