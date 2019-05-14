#include "FastLED.h"
#define NUM_LEDS 100
#define DATA_PIN 2

CRGB leds[NUM_LEDS];
uint8_t count = 0;
uint8_t walker = 0;
uint8_t low = 50;
uint8_t high = 150;
uint8_t center = 29;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {

  for (int j = low; j < high; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {

      walker = i + count;
      if (walker % 5 == 1) {
        leds[i] = CHSV(count + i, 190, j);
      }
      else {
        leds[i] = CRGB::Black;
      }
    }
    count++; //index count up
    // Show the leds
    FastLED.show();

    delay(35);
  }
  for (int j = high; j >= low; j--) {
    for (int i = 0; i < NUM_LEDS; i++) {

      walker = i + count;
      if (walker % 5 == 1) {
        leds[i] = CHSV(count + i, 190, j);
      }
      else {
        leds[i] = CRGB::Black;
      }
    }


    FastLED.show();
    //delay(35);
  }
}
