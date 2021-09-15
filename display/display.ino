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

  //JOYSTICK POSITION LOGIC FOR FOUR DIFFERNT POSITIONS
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
  x = map(xValue, 0, 1023, -24, 24);
  y = map(yValue, 0, 1023, -24, 24);
  joystick_action(x,y)

}

void joystick_action(int x,int y){
    //LEFT POSITION
  if(x < -12 && y < 12 && y >-12){
    if(STATE){
      //layer one do something
    }
    else{
      //layer two do something
    }
  }
  //RIGHT POSITION
  if(x > 12 && y < 12 && y >-12){
    if(STATE){
      //layer one do something
    }
    else{
      //layer two do something
    }    
  }
  //UP POSITION
  if(y> 12 && x < 12 && x >-12){
    if(STATE){
      //layer one do something
    }
    else{
      //layer two do something
    }    
  }
  //DOWN POSITION
  if(y < -12 && x < 12 && x >-12){
    if(STATE){
      //layer one do something
    }
    else{
      //layer two do something
    }    
  } 
}
