#include <FastLED.h>

#define DATA_PIN     2
#define NUM_LEDS    100

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);

}

void loop() {
  P_flag();
  //P_2();
  P_flagColors();

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
  delay(5000);
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

