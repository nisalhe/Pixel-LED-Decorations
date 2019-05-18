#include <FastLED.h>
FASTLED_USING_NAMESPACE

#define DATA_PIN            2      // Change
#define NUM_LEDS            50    // Change
#define BRIGHTNESS          250     // Change
#define FRAMES_PER_SECOND   120
#define COLOR_ORDER RGB
uint8_t count = 0;
uint8_t walker = 0;
#define low 20
#define high  150
#define delay_time 20

CRGB leds[NUM_LEDS];

void setup() {
  delay(1000);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm };
uint8_t gCurrentPatternNumber = 0; 
uint8_t gHue = 0; 

void loop() {
  P_flag();
  FastLED.clear();
  P_flag();
  FastLED.clear();
  P_2();
  FastLED.clear();
  P_flagColors();
  FastLED.clear();
  P_Burning();
  FastLED.clear();
  P_Cylon();
  FastLED.clear();
  P_Mix();
  FastLED.clear();

 
  
}

void P_flag() {
  int TIME_1 = 20;

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(TIME_1);
  }
  for (int i = 0; i < 4 * NUM_LEDS / 5; i++) {
    leds[i] = CRGB::Yellow;
    FastLED.show();
    delay(TIME_1);
  }
  for (int i = 0; i < 3 * NUM_LEDS / 5; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(TIME_1);
  }

  for (int i = 0; i < 2 * NUM_LEDS / 5; i++) {
    leds[i] = CRGB::White;
    FastLED.show();
    delay(TIME_1);
  }

  for (int i = 0; i < NUM_LEDS / 5; i++) {
    leds[i] = CRGB::Orange;
    FastLED.show();
    delay(TIME_1);
  }
  delay(3000);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(20);
  }
}

void P_2() {

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    leds[i + 1] = CRGB::Red;
    leds[i + 2] = CRGB::Blue;
    FastLED.show();
    delay(10);
    leds[i] = CRGB::Black;
    FastLED.show();
  }

  for (int i = NUM_LEDS; i > 0; i--) {
    leds[i] = CRGB::Red;
    leds[i + 1] = CRGB::Red;
    leds[i + 2] = CRGB::Blue;
    FastLED.show();
    delay(10);
    leds[i - 3] = CRGB::Black;
    FastLED.show();
  }

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::BurlyWood ;
    leds[i + 1] = CRGB::BurlyWood ;
    leds[i + 2] = CRGB::BurlyWood ;
    FastLED.show();
    delay(10);
    leds[i] = CRGB::Black;
    FastLED.show();
  }

  for (int i = NUM_LEDS; i > 0; i--) {
    leds[i] = CRGB::DeepSkyBlue ;
    leds[i + 1] = CRGB::DeepSkyBlue ;
    leds[i + 2] = CRGB::DeepSkyBlue ;
    FastLED.show();
    delay(10);
    leds[i - 3] = CRGB::Black;
    FastLED.show();
  }
}

void P_flagColors() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
  }
  FastLED.show();
  delay(1000);

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Yellow;

  }
  FastLED.show();
  delay(1000);

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
  }
  FastLED.show();
  delay(1000);

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(1000);

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Orange;
  }
  FastLED.show();
  delay(1000);
}

void P_Burning() {
  for (int j = low; j < high; j++) {
    for (int i = 0; i < NUM_LEDS / 2; i++) {

      walker = i + count;
      if (walker % 2 == 1) {
        leds[i] = CHSV(count + i * 8, 190, j);
        //Serial.println(j);
      }
      else {
        leds[i] = CRGB::Black;
      }
    }

    for (int i = 0; i < NUM_LEDS / 2; i++) {
      leds[NUM_LEDS - i] = leds[i];
    }


    FastLED.show();

    delay(delay_time);
  }

  for (int j = high; j > low; j--) {
    for (int i = 0; i < NUM_LEDS / 2; i++) {

      walker = i + count;
      if (walker % 2 == 1) {
        leds[i] = CHSV(count + i * 8, 190, j);
        //Serial.println(j);
      }
      else {
        leds[i] = CRGB::Black;
      }
    }

    for (int i = 0; i < NUM_LEDS / 2; i++) {
      leds[NUM_LEDS - i] = leds[i];
    }
    count++;
    FastLED.show();
    delay(delay_time);
  }
}

void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(250);
  }
}

void P_Cylon() {
  static uint8_t hue = 0;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show();
    fadeall();
    delay(10);
  }

  for (int i = (NUM_LEDS) - 1; i >= 0; i--) {
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show();
    fadeall();
    delay(10);
  }
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}

void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}

void rainbowWithGlitter() 
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void addGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void confetti() 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}

void P_Mix(){
  gPatterns[gCurrentPatternNumber]();
  FastLED.show();  
  FastLED.delay(1000/FRAMES_PER_SECOND); 
  EVERY_N_MILLISECONDS( 20 ) { gHue++; } 
  EVERY_N_SECONDS( 10 ) { nextPattern(); } 
}


