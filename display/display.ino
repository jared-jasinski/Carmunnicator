#include <FastLED.h>

#define NUM_LEDS 256

#define joyX A0
#define joyY A1
#define joystick_button 7

CRGB leds[NUM_LEDS];
int state = HIGH;
int previous = LOW;

long time = 0;
long debounce = 200;

int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

void setup() {
    Serial.begin(9600);
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  pinMode(7, INPUT_PULLUP);
  
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  FastLED.addLeds<NEOPIXEL, 6 > (leds, NUM_LEDS);
  FastLED.setBrightness(2);
}

void loop() {
  check_switch_state();
  
  float xValue = analogRead(joyX);
  float yValue = analogRead(joyY);
  float x = map(xValue, 0, 1023, -24, 24);
  float y = map(yValue, 0, 1023, -24, 24);
  //Serial.print("x: ");
  //Serial.print(xValue);
  //Serial.print("   |   y: ");
  //Serial.println(yValue);
  Serial.println(state);
 joystick_action(x,y,state);
 //testLEDs(leds);
 byeHoe(leds);
}

  //JOYSTICK POSITION LOGIC FOR FOUR DIFFERNT POSITIONS
void joystick_action(int x,int y,int STATE){
    //LEFT POSITION
  if(x < -12 && y < 12 && y >-12){
    if(STATE){
      //layer one do something
    }else{
      //layer two do something
    }
  }
  //RIGHT POSITION
  if(x > 12 && y < 12 && y >-12){
    if(STATE){
      //layer one do something
    }else{
      //layer two do something
    }    
  }
  //UP POSITION
  if(y> 12 && x < 12 && x >-12){
    if(STATE){
      //layer one do something
    }else{
      //layer two do something
    }    
  }
  //DOWN POSITION
  if(y < -12 && x < 12 && x >-12){
    if(STATE){
      //layer one do something
    }else{
      //layer two do something
    }    
  } 
}

  //Switch layer toggling
void check_switch_state(){
int switch_state = digitalRead(joystick_button);
  if (switch_state  == HIGH  && previous == LOW && millis() - time > debounce) {
    if (state == HIGH){
      RGB_color(20, 0, 40);
       state = LOW;
    }else{
      state = HIGH;
      RGB_color(0, 40, 0);
    }
 
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

void displayHeart(CRGB leds[]){
int heart[] = {19,20,21,26,27,28,34,38,41,45,49,55,56,62,65,78,81,94,97,110,114,125,130,141,147,156,164,171,181,186,198,201,215,216};
for (int i = 0; i <(sizeof(heart) / sizeof(heart[0])); i++){
  leds[heart[i]] = CRGB::Red; 
}
  FastLED.show();
}

void displayqMark(CRGB leds[]){
int qMark[] = {6,7,8,9,21,22,23,24,25,26,36,37,42,43,51,52,59,60,67,68,75,76,83,84,91,92,107,108,115,116,117,137,138,139,150,151,152,167,168,183,184,199,200,231,232,247,248};
for (int i = 0; i <(sizeof(qMark) / sizeof(qMark[0])); i++){
  leds[qMark[i]] = CRGB::Yellow; 
}
  FastLED.show();
}

void byeHoe(CRGB leds[]){
int purpLex[] = {17,18,19,22,26,28,29,30,31,46,44,40,38,35,49,50,51,52,56,60,61,62,78,75,71,67,81,84,88,92,110,109,108,107,103,99,98,97,96,145,148,156,157,158,159,174,171,163,177,178,179,180,188,189,190,206,203,195,209,212,220,238,235,227,226,225,224};
int pinkLex[] = {150,154,170,169,168,166,165,164,181,182,183,184,185,186,187,201,200,199,198,197,215,216,217,231};
for (int i = 0; i <(sizeof(purpLex) / sizeof(purpLex[0])); i++){
  leds[purpLex[i]] = CRGB::Purple; 
}
for (int j = 0; j <(sizeof(pinkLex) / sizeof(pinkLex[0])); j++){
  leds[pinkLex[j]] = CRGB::Pink; 
}
  FastLED.show();
}
