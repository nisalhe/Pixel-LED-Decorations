#include "FastLED.h"
#define NUM_LEDS 100
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

uint8_t count = 0;
uint8_t walker = 0;
#define low 20
#define high  150

#define delay_time 20

void setup() {

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

}

void loop() {

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
