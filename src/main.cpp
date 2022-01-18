#include <Arduino.h>
#include <DMXSerial.h>
#include <Adafruit_NeoPixel.h>

#define LEDPIN 8
#define NUMPIXELS 60

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  DMXSerial.init(DMXReceiver);
  
  strip.begin();
  strip.setBrightness(100);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // put your main code here, to run repeatedly:
  // for loop iterate up to numpixels
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(DMXSerial.read((i * 3) + 1), DMXSerial.read((i * 3) + 2), DMXSerial.read((i * 3) + 3)));
  }
  strip.show();

  delay(35);
}