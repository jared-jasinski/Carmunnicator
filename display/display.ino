//#include <FastLED.h>

#define NUM_LEDS 256

#define joyX A0
#define joyY A1
#define joystick_button 7

//CRGB leds[NUM_LEDS];
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
 //FastLED.addLeds<NEOPIXEL, 6 > (leds, NUM_LEDS);
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
