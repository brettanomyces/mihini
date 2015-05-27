#include "Button.h"
#include "Delay.h"
#include "Relay.h"

Button onButton;
Button offButton;
Delay offDelay;
Relay relay;

// on and off buttons are two pin, monmentary push buttons, connected 
// from pin X to ground. When the button is pressed down,  digitalRead 
// will return 0.
int ON_PIN = 2;
int OFF_PIN = 3;
int RELAY_PIN = 4;
//long ON_PERIOD = 5400000;  // 90 minutes
long ON_PERIOD = 5000;  // 5 seconds

void setup() {                
  onButton = onButton(ON_PIN);
  offButton = offButton(OFF_PIN);
  offDelay = offDelay(ON_PERIOD);
  relay = relay(RELAY_PIN);
}

void loop() {
  if (relay.isOn()){
    if(offDelay.check() || offButton.wasPressed()){
      relay.off();
    }
  } else {  // (relay.isOff()
    if (onButton.wasPressed()){
      relay.on();
      offDelay.reset();
    }
  }
}
