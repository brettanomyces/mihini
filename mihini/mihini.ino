#include "Button.h"
#include "Relay.h"
#include "Delay.h"  // depended on by Relay
#include "Countdown.h"

Button onButton;
Button offButton;
Countdown onCountdown;
Countdown waitCountdown;
Relay relay;

// on and off buttons are two pin, monmentary push buttons, connected 
// from pin X to ground. When the button is pressed down,  digitalRead 
// will return 0.
// TODO tell relay if on is LOW or HIGH.
int ON_PIN = 2;
int OFF_PIN = 3;
int RELAY_PIN = 4;
int LED_0_PIN = 5;  // on if time remaining > 0
int LED_1_PIN = 6;  // on if time remaining > 30 min
int LED_2_PIN = 7;  // on if time remainint > 60 min
int LED_3_PIN = 8;  // on if time remainint > 1 hour 30 min

unsigned long ON_PERIOD_INCREMENT = 1800000; // 30 minutes
unsigned long ON_PERIOD_MAX = 7200000; // 2 hours
unsigned long WAIT_PERIOD = 2000;  // 2 seconds, time to wait for more button presses
unsigned long onPeriod;

void setup() {                
  onPeriod = 0;
  onButton.setup(ON_PIN);
  offButton.setup(OFF_PIN);
  relay.setup(RELAY_PIN);
  digitalWrite(LED_0_PIN, LOW);
  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
}

void loop() {
  unsigned long onRemaining = onCountdown.remaining();
  displayOnRemaining(onRemaining);
  if (relay.isOn()){
    if(onRemaining == 0 || offButton.wasPressed()){
      relay.off();
    }
  } else {  // relay is off 
    if (onButton.wasPressed()){
      if (onPeriod < ON_PERIOD_MAX){
        onPeriod += ON_PERIOD_INCREMENT;
      }
      waitCountdown.reset(WAIT_PERIOD);
    }
    if (waitCountdown.remaining() == 0){
      // turn on
      relay.on();
      onCountdown.reset(onPeriod);
      onPeriod = 0;  // reset on period
    }
  }
}

void displayOnRemaining(unsigned long _remaining){
  if (_remaining > 3 * ON_PERIOD_INCREMENT) {
    digitalWrite(LED_3_PIN, HIGH);
  } else {
    digitalWrite(LED_3_PIN, LOW);
  }
  if (_remaining > 2 * ON_PERIOD_INCREMENT) {
    digitalWrite(LED_2_PIN, HIGH);
  } else {
    digitalWrite(LED_2_PIN, LOW);
  }
  if (_remaining > ON_PERIOD_INCREMENT) {
    digitalWrite(LED_1_PIN, HIGH);
  } else {
    digitalWrite(LED_1_PIN, LOW);
  }
  if (_remaining > 0) {
    digitalWrite(LED_0_PIN, HIGH);
  } else {
    digitalWrite(LED_0_PIN, LOW);
  }
}
