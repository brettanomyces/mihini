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
int RELAY_PIN = 7;
uint8_t RELAY_OFF = HIGH;
int OFF_PIN = 13;
int ON_PIN = 12;
int LED_0_PIN = 11;  // on if time remaining > 0
int LED_1_PIN = 10;  // on if time remaining > ON_PERIOD_INCREMENT
int LED_2_PIN = 9;  // on if time remainint > 2 * ON_PERIOD_INCREMENT

// unsigned long ON_PERIOD_INCREMENT = 5000; // 5 seconds
unsigned long ON_PERIOD_INCREMENT = 1800000; // 30 minutes
unsigned long ON_PERIOD_MAX = 3 * ON_PERIOD_INCREMENT;
unsigned long WAIT_PERIOD = 1000;  // 2 seconds, time to wait for more button presses
unsigned long onRemaining;

void setup() {                
  Serial.begin(9600);
  onRemaining = 0;
  onButton.setup(ON_PIN);
  offButton.setup(OFF_PIN);
  relay.setup(RELAY_PIN, "", 0, RELAY_OFF);
  pinMode(LED_0_PIN, OUTPUT);
  digitalWrite(LED_0_PIN, LOW);
  pinMode(LED_1_PIN, OUTPUT);
  digitalWrite(LED_1_PIN, LOW);
  pinMode(LED_2_PIN, OUTPUT);
  digitalWrite(LED_2_PIN, LOW);
}

void loop() {
  displayOnRemaining(onRemaining);
  if (relay.isOn()){
    onRemaining = onCountdown.remaining();
    if(onRemaining == 0) {
      relay.off();
    } else if (offButton.wasPressed()){
      onRemaining = 0;
      relay.off();
    }
  } else {  // relay is off 
    if (onButton.wasPressed()){
      if (onRemaining < ON_PERIOD_MAX){
        onRemaining += ON_PERIOD_INCREMENT;
      }
      waitCountdown.reset(WAIT_PERIOD);
    }
    if (waitCountdown.remaining() == 0 && onRemaining != 0){
      // turn on
      relay.on();
      onCountdown.reset(onRemaining);
    }
  }
}

void displayOnRemaining(unsigned long _remaining){
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
