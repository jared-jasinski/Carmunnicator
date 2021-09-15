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

int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
 FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS)
}

void loop() {

  check_switch_state()

  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
  x = map(xValue, 0, 1023, -24, 24);
  y = map(yValue, 0, 1023, -24, 24);
  
  joystick_action(x,y)

}

  //JOYSTICK POSITION LOGIC FOR FOUR DIFFERNT POSITIONS
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

  //Switch layer toggling
void check_switch_state(){
  switch_state = digitalRead(sw)
  if (switch_state == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;
    time = millis();    
  }
  previous = switch_state;  
}
//STATE LED
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
