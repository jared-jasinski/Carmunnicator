#include <FastLED.h>

#define NUM_LEDS 256

#define joyX A0
#define joyY A1
#define sw 2

CRGB leds[NUM_LEDS];
int state = HIGH;
int previous = LOW;

long time = 0;
long debounce = 200;

void setup() {
 FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS)
}

void loop() {

  //Switch layer toggling USE STATE TO SELECT LAYER WHICH LAYER
  switch_state = digitalRead(sw)
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;

    time = millis();    
  }
  previous = reading;
  //End of switch layer toggling logic



  
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);

  


  
}
