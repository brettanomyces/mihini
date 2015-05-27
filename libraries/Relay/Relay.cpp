#include "Relay.h"

Relay::Relay(){
}

void Relay::setup(int _pin){
  setup(_pin, "relay", 0);
}

void Relay::setup(int _pin, String _name, long _delay) {
  m_name = _name;

  m_pin = _pin;
  pinMode(m_pin, OUTPUT);
  digitalWrite(m_pin, HIGH);

  m_on = false;

  m_delay.setup(_delay);
  m_delay.reset();
}

void Relay::on(){
  if(!m_on){
    if(m_delay.ok()){
      digitalWrite(m_pin, LOW);
      m_on = true;
      m_delay.reset();
      log("turned on");
    } else {
      log("waiting to turn on");
    }
  }
}

void Relay::off(){
  if(m_on){
    if(m_delay.ok()){
      digitalWrite(m_pin, HIGH);
      m_on = false;
      m_delay.reset();
      log("turned off");
    } else {
      log("waiting to turn off");
    }
  }
}

void Relay::log(String str){
  Serial.print(m_name);
  Serial.print("(");
  Serial.print(m_pin);
  Serial.print("): ");
  Serial.print(str);
  Serial.println();
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
