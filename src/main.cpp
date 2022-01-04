#include <Arduino.h>
#include <DMXSerial.h>
#include <Adafruit_NeoPixel.h>

#define LEDPIN 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, LEDPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  DMXSerial.init(DMXReceiver);
  
  strip.begin();
  strip.setBrightness(100);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // put your main code here, to run repeatedly:

  strip.setPixelColor(1, strip.Color(0, DMXSerial.read(29), 0)); // Green
  strip.setPixelColor(5, strip.Color(255, 0, 0)); // Green
  strip.show();

  delay(100);
} 