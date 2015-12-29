// testcolors demo for Adafruit RGBmatrixPanel library.
// Renders 512 colors on our 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420
// Library supports 4096 colors, but there aren't that many pixels!  :)

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT 3
#define OE  9
#define A   10
#define B   11
#define C   12
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

uint8_t r=0, g=0, b=0;
uint16_t t = 0;
uint16_t blue = matrix.Color333(0, 0, 7);
uint16_t red = matrix.Color333(7, 0, 0);
uint16_t green = matrix.Color333(0, 1, 0);
uint16_t brown = matrix.Color333(1, 1, 0);

void setup() {
  matrix.begin();
  Serial.begin(9600);
}

void loop() {
  // do nothing
  t++;
  uint8_t x;
  uint8_t w = 1;
  uint8_t h = 3;
  uint16_t i = 0;
  uint16_t rando, random_t;
  for (x=2; x < 32; x++) {      
    for (uint8_t y=8 - w; y < 16 - (8 - w); y++) {
      i++;
      rando = (i * 89) % 13;
      if (rando == 1)
        matrix.drawPixel(x, y, ((t + i) * 157) % 19 > 5 ? blue : green);
      else if (rando == 7)
        matrix.drawPixel(x, y, ((t + i) * 173) % 31 > 13 ? red : green);
      else
        matrix.drawPixel(x, y, green);
    }
    w++;
    if (w > h){
      w = 1;
      h++;
    }
    if (h == 8)
      break;
  };
  while (x < 32){
    matrix.drawPixel(x, 7, brown);
    matrix.drawPixel(x, 8, brown);
    x++;
  }
  while (Serial.available() > 0) {
    incomingByte = Serial.read();
  }
  delay(500);  
}

