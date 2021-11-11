#include <Adafruit_NeoPixel.h>

#define PIN        10
#define NUMPIXELS 100

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 100


void setup() {
  pixels.begin();
  pixels.setBrightness(10);
}

void loop() {
  pixels.clear();
  pixels.setPixelColor(random(0-99), random(0-255), random(0-255), random(0-255));
  pixels.show();
  delay(DELAYVAL);
}
