#include <FastLED.h>

#define NUM_LEDS 256

#define joyX A0
#define joyY A1
#define joystick_button 7

CRGB leds[NUM_LEDS];
int state = LOW;
int previous = HIGH;

long time = 0;
long debounce = 200;

int red_light_pin = 11;
int green_light_pin = 10;
int blue_light_pin = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  pinMode(7, INPUT_PULLUP);

  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS);
  FastLED.setBrightness(2);
}

void loop()
{
  check_switch_state();

  float xValue = analogRead(joyX);
  float yValue = analogRead(joyY);
  float x = map(xValue, 0, 1023, -24, 24);
  float y = map(yValue, 0, 1023, -24, 24);

  joystick_action(x, y, state);
  FastLED.clear();
  FastLED.show();
}

//JOYSTICK POSITION LOGIC FOR FOUR DIFFERNT POSITIONS
void joystick_action(int x, int y, int STATE)
{
  //LEFT POSITION
  if (x < -12 && y < 12 && y > -12)
  {
    if (STATE)
    {
      byeHoe(leds);
    }
    else
    {
      devilEmoji(leds);
    }
  }
  //RIGHT POSITION
  if (x > 12 && y < 12 && y > -12)
  {
    if (STATE)
    {
      laughingEmoji(leds);
    }
    else
    {
      niceGTI(leds);
    }
  }
  //UP POSITION
  if (y > 12 && x < 12 && x > -12)
  {
    if (STATE)
    {
      displayqMark(leds);
    }
    else
    {
      flushedEmoji(leds);
    }
  }
  //DOWN POSITION
  if (y < -12 && x < 12 && x > -12)
  {
    if (STATE)
    {
      displayHeart(leds);
    }
    else
    {
      honkCountDown(leds);
    }
  }
}

//Switch layer toggling
void check_switch_state()
{
  int switch_state = digitalRead(joystick_button);
  if (switch_state == LOW && previous == HIGH && millis() - time > debounce)
  {
    if (state == HIGH)
    {
      RGB_color(20, 0, 40);
      state = LOW;
    }
    else
    {
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

void displayHeart(CRGB leds[])
{
  FastLED.clear();

  const int heart[] PROGMEM = {19, 20, 21, 26, 27, 28, 34, 38, 41, 45, 49, 55, 56, 62, 65, 78, 81, 94, 97, 110, 114, 125, 130, 141, 147, 156, 164, 171, 181, 186, 198, 201, 215, 216};
  for (int i = 0; i < (sizeof(heart) / sizeof(heart[0])); i++)
  {
    leds[heart[i]] = CRGB::Red;
  }
  FastLED.show();
          delay(1000);

}

void displayqMark(CRGB leds[])
{
  FastLED.clear();

  int qMark[] = {9, 8, 7, 6, 21, 22, 23, 24, 25, 26, 43, 42, 37, 36, 51, 52, 59, 60, 76, 75, 68, 67, 83, 84, 91, 92, 100, 99, 122, 123, 124, 134, 133, 132, 151, 152, 153, 168, 167, 183, 184, 200, 199, 232, 231, 247, 248};
  for (int i = 0; i < (sizeof(qMark) / sizeof(qMark[0])); i++)
  {
    leds[qMark[i]] = CRGB::Yellow;
  }
  FastLED.show();
          delay(1000);

}

void byeHoe(CRGB leds[])
{
  FastLED.clear();
  const int purpLex[] PROGMEM = {17, 18, 19, 22, 26, 28, 29, 30, 31, 46, 44, 40, 38, 35, 49, 50, 51, 52, 56, 60, 61, 62, 78, 75, 71, 67, 81, 84, 88, 92, 110, 109, 108, 107, 103, 99, 98, 97, 96, 145, 148, 156, 157, 158, 159, 174, 171, 163, 177, 178, 179, 180, 188, 189, 190, 206, 203, 195, 209, 212, 220, 238, 235, 227, 226, 225, 224};
  const int pinkLex[] PROGMEM = {150, 154, 170, 169, 168, 166, 165, 164, 181, 182, 183, 184, 185, 186, 187, 201, 200, 199, 198, 197, 215, 216, 217, 231};
  for (int i = 0; i < (sizeof(purpLex) / sizeof(purpLex[0])); i++)
  {
    leds[purpLex[i]] = CRGB::Purple;
  }
  for (int j = 0; j < (sizeof(pinkLex) / sizeof(pinkLex[0])); j++)
  {
    leds[pinkLex[j]] = CRGB::Pink;
  }
  FastLED.show();
          delay(1000);

}

void niceGTI(CRGB leds[])
{
  FastLED.clear();
  const int niceGTIPurple[] = {15, 11, 9, 8, 7, 5, 4, 3, 16, 17, 18, 22, 26, 28, 47, 45, 43, 41, 37, 36, 35, 48, 50, 52, 54, 58, 79, 77, 75, 73, 72, 71, 69, 68, 67, 111, 110,109,106, 103, 112, 114, 117, 143, 142, 141, 139, 138, 137, 135, 146, 149, 152, 175, 174, 173, 170, 167};
  const int niceGTIRed[] = {101, 100, 98, 97, 122, 123, 124, 125, 126, 133, 132, 131, 130, 129, 155, 156, 157, 163};
  for (int i = 0; i < (sizeof(niceGTIPurple) / sizeof(niceGTIPurple[0])); i++)
  {
    leds[niceGTIPurple[i]] = CRGB::Purple;
  }
  for (int j = 0; j < (sizeof(niceGTIRed) / sizeof(niceGTIRed[0])); j++)
  {
    leds[niceGTIRed[j]] = CRGB::Red;
  }
  FastLED.show();
          delay(1000);

}

void devilEmoji(CRGB leds[])
{
  FastLED.clear();
  const int devilEmojiPurple[] = {14, 9, 8, 7, 6, 5, 0, 17, 18, 21, 22, 26, 27, 30, 31, 46, 45, 44, 43, 42, 36, 35, 34, 33, 32, 50, 62, 77, 65, 81, 82, 94, 95, 110, 96, 113, 127, 142, 128, 145, 146, 158, 159, 161, 173, 179, 189, 190, 204, 203, 195, 194, 212, 213, 214, 218, 219, 220, 233, 232, 231, 230, 229};
  const int devilEmojiLightPurple[] = {23, 24, 25, 41, 40, 36, 38,39, 37, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 76, 73, 72, 71, 70, 69, 66, 83, 84, 85, 87, 88, 89, 91, 92, 93, 109, 108, 107, 104,103, 106, 102, 99, 98, 97, 114, 115, 116, 119, 120, 121, 124, 125, 126, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 172, 171, 170, 169, 168, 167, 166, 165, 163, 162, 180, 188, 212, 217, 202, 201, 200, 199, 198, 197, 196, 215, 216};
  for (int i = 0; i < (sizeof(devilEmojiPurple) / sizeof(devilEmojiPurple[0])); i++)
  {
    leds[devilEmojiPurple[i]] = CRGB::Purple;
  }
  for (int j = 0; j < (sizeof(devilEmojiLightPurple) / sizeof(devilEmojiLightPurple[0])); j++)
  {
    leds[devilEmojiLightPurple[j]] = CRGB::MediumPurple;
  }
  FastLED.show();
          delay(1000);
}

void flushedEmoji(CRGB leds[])
{
  FastLED.clear();
  const int flushedEmojiYellow[] = {196, 121, 9, 8, 7, 6, 5, 20, 21, 22, 23, 24, 25, 26, 27, 28, 44, 39, 34, 50, 52, 53, 54, 55, 56, 57, 58, 59, 60, 62, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 81, 82, 86, 87, 88, 89, 90, 94, 95, 110, 104, 103, 102, 96, 113, 119, 120, 127, 142, 136, 135, 134, 128, 145, 146, 150, 151, 152, 153, 154, 158, 159, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 178, 179, 181, 182, 183, 184, 185, 186, 187, 189, 190, 204, 203, 202, 201, 197, 195, 194, 212, 213, 214, 215, 216, 217, 218, 219, 220, 234, 233, 232, 231, 230, 229, 228};
  const int flushedEmojiWhite[] = {157, 130, 83, 84, 85, 91, 92, 93, 109, 106, 105, 101, 100, 98, 97, 114, 118, 122, 126, 141, 140, 138, 137, 133, 132, 130, 129, 147, 148, 149, 155, 156};
  const int flushedEmojiPink[] = {180, 188};
  for (int i = 0; i < (sizeof(flushedEmojiYellow) / sizeof(flushedEmojiYellow[0])); i++)
  {
    leds[flushedEmojiYellow[i]] = CRGB::Yellow;
  }
  for (int j = 0; j < (sizeof(flushedEmojiWhite) / sizeof(flushedEmojiWhite[0])); j++)
  {
    leds[flushedEmojiWhite[j]] = CRGB::White;
  }
  for (int k = 0; k < (sizeof(flushedEmojiPink) / sizeof(flushedEmojiPink[0])); k++)
  {
    leds[flushedEmojiPink[k]] = CRGB::Red;
  }
  FastLED.show();
          delay(1000);

}

void laughingEmoji(CRGB leds[])
{
  const int yellowLaugh[] PROGMEM = {10, 9, 8, 7, 6, 5, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 49, 50, 52, 53, 54, 55, 56, 57, 58, 59, 61, 62, 65, 79, 78, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 65, 64, 80, 82, 86, 87, 88, 89, 93, 95, 111, 110, 109, 107, 106, 105, 104, 103, 102, 101, 100, 98, 97, 96, 112, 113, 126, 127, 143, 128, 179, 180, 187, 188, 204, 203, 201, 202, 201, 200, 199, 198, 197, 196, 195, 212, 213, 216, 215, 214, 217, 218, 219};
  const int whiteLaugh[] PROGMEM = {139, 138, 137, 136, 135, 134, 133, 132};
  const int darkBlueLaugh[] PROGMEM = {108, 99, 114, 125, 142, 129, 144, 159, 175, 172, 163, 160, 177, 178, 189, 190};
  const int lightBlueLaugh[] PROGMEM = {115, 124, 141, 140, 131, 130, 145, 146, 147, 156, 157, 158, 174, 173, 162, 161};

  for (int i = 0; i < (sizeof(yellowLaugh) / sizeof(yellowLaugh[0])); i++)
  {
    leds[yellowLaugh[i]] = CRGB::Yellow;
  }
  for (int j = 0; j < (sizeof(whiteLaugh) / sizeof(whiteLaugh[0])); j++)
  {
    leds[whiteLaugh[j]] = CRGB::White;
  }
  for (int k = 0; k < (sizeof(darkBlueLaugh) / sizeof(darkBlueLaugh[0])); k++)
  {
    leds[darkBlueLaugh[k]] = CRGB::Blue;
  }
  for (int l = 0; l < (sizeof(lightBlueLaugh) / sizeof(lightBlueLaugh[0])); l++)
  {
    leds[lightBlueLaugh[l]] = CRGB::LightBlue;
  }
  FastLED.show();
          delay(1000);

}

void honkCountDown(CRGB leds[]){
    int honkIn[] = {15, 16, 24, 28, 47, 46, 45, 43, 42, 41, 39, 38, 37, 35, 33, 48, 50, 52, 54, 56, 58, 60, 61, 79, 77, 75, 74, 73, 71, 69, 67, 65, 105, 120, 121, 122, 137, 135, 133, 150, 152, 154};
    int five[] = {182, 183, 184, 185, 201, 214, 215, 216, 217, 230, 246, 247, 248, 249};
    int four[] = {182, 185, 201, 198, 214, 215, 216, 217, 230, 249};
    int three[] = {182, 183, 184, 185, 198, 215, 216, 217, 230, 246, 247, 248, 249};
    int two[] = {182, 183, 184, 185, 198, 214, 215, 216, 217, 233, 246, 247, 248, 249};
    int one[] = {184, 200, 199, 216, 231, 247, 248, 249};
    int honk[] = {15, 16, 24, 28, 47, 46, 45, 43, 42, 41, 39, 38, 37, 35, 33, 48, 50, 52, 54, 56, 58, 60, 61, 79, 77, 75, 74, 73, 71, 69, 67, 65};

    for (int honkCountdown = 0; honkCountdown < 6; honkCountdown++){
        FastLED.clear();
      
       if(honkCountdown < 5) for (int i = 0; i < (sizeof(honkIn) / sizeof(honkIn[0])); i++){leds[honkIn[i]] = CRGB::Blue;}
                if (honkCountdown == 0) for (int i = 0; i < (sizeof(five) / sizeof(five[0])); i++){ leds[five[i]] = CRGB::Red; }
                else if (honkCountdown == 1) for (int i = 0; i < (sizeof(four) / sizeof(four[0])); i++){leds[four[i]] = CRGB::Red; }
                else if (honkCountdown == 2) for (int i = 0; i < (sizeof(three) / sizeof(three[0])); i++){leds[three[i]] = CRGB::Red;}
                else if (honkCountdown == 3) for (int i = 0; i < (sizeof(two) / sizeof(two[0])); i++) {leds[two[i]] = CRGB::Yellow;}
                else if (honkCountdown == 4) for (int i = 0; i < (sizeof(one) / sizeof(one[0])); i++) {leds[one[i]] = CRGB::Green;}
                else if (honkCountdown == 5) for (int i = 0; i < (sizeof(honk) / sizeof(honk[0])); i++) {leds[honk[i]] = CRGB::Green;}

         FastLED.show();
        delay(1000);
    }
}
