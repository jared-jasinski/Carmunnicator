#include <FastLED.h>

#define NUM_LEDS 256

#define joyX A0
#define joyY A1

CRGB leds[NUM_LEDS];
void setup() {
 FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS)
}

void loop() {
  // put your main code here, to run repeatedly:
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
}
