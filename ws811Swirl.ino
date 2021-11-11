#include <Adafruit_NeoPixel.h>

#define PIN        10
#define NUMPIXELS 100

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 75

// actual is going from low to high up each row
// index is serpentining according to wiring

int coordToIndex(int x, int y) {
  if (y%2==0) return (y*10)+x;
  return (y*10)+(9-x);
}

void swirlIteration(int i, int j) {
  int iPos[2] = {i,j};
  int cPos[2] = {i,j};
  //right sweep
  for(int n=0; n<10-(2*iPos[0]); n++) {
    strip.setPixelColor(coordToIndex(iPos[0]+n,iPos[1]),255,255,255);
    cPos[0]=iPos[0]+n;
    strip.show();
    delay(DELAYVAL);
  }
  iPos[0]=cPos[0];
  iPos[1]=cPos[1];
  //up sweep
  for(int n=0; n<10-(2*iPos[1]); n++) {
    strip.setPixelColor(coordToIndex(iPos[0],iPos[1]+n),255,255,255);
    cPos[1]=iPos[1]+n;
    strip.show();
    delay(DELAYVAL);
  }
  iPos[0]=cPos[0];
  iPos[1]=cPos[1];
  //left sweep
  for(int n=iPos[0]; n>i-1; n--) {
    strip.setPixelColor(coordToIndex(n,iPos[1]),255,255,255);
    cPos[0]=n;
    strip.show();
    delay(DELAYVAL);
  }
  iPos[0]=cPos[0];
  iPos[1]=cPos[1];
  //down sweep
  for(int n=iPos[1]; n>j-1; n--) {
    strip.setPixelColor(coordToIndex(iPos[0],n),255,255,255);
    cPos[1]=n;
    strip.show();
    delay(DELAYVAL);
  }
  iPos[0]=cPos[0];
  iPos[1]=cPos[1];
}

void swirl() {
  for(int i=0; i<5; i++) {
    swirlIteration(i,i);
  }
}

void setup() {
  strip.begin();
  strip.setBrightness(10);
  strip.clear();
  strip.show();
}

void loop() {
  swirl();
  strip.clear();
  strip.show();
}
