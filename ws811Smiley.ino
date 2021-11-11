#include <Adafruit_NeoPixel.h>

#define PIN        10
#define NUMPIXELS 100

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

// actual is going from low to high up each row
// index is serpentining according to wiring

int pos[22] = {13,14,15,16,22,23,24,25,26,27,31,32,37,38,72,73,76,77,82,83,86,87};

int actualToIndex(int n) {
  if(n/10%2==0) return n;
  return ((n/10)*10)+(9-n%10);
}

void smiley1() {
  for(int i=0; i<NUMPIXELS; i++) {
    strip.setPixelColor(i,0,0,0);
    for(int j=0; j<22; j++) {
      strip.setPixelColor(pos[actualToIndex(j)],255,255,0);
    }
  }
  strip.show();
}

void smiley2() {
  for(int i=0; i<NUMPIXELS; i++) {
    strip.setPixelColor(i,0,0,0);
    for(int j=0; j<22; j++) {
      strip.setPixelColor(pos[actualToIndex(j)],0,255,255);
    }
  }
  strip.show();
}

void smiley() {
  smiley1();
  delay(500);
  strip.clear();
  smiley2();
  delay(500);
  strip.clear();
}

void setup() {
  strip.begin();
  strip.setBrightness(20);
}

void loop() {
  smiley();
}
