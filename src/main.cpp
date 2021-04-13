#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "MCUFRIEND_kbv.h"
MCUFRIEND_kbv tft;
#include "Fonts/FreeSans9pt7b.h"
#include "Fonts/FreeSans12pt7b.h"
#include "Fonts/FreeSerif12pt7b.h"
#include "FreeDefaultFonts.h"

#define PI 3.1415926535897932384626433832795
int col[8];
void showmsgXY(int x, int y, int sz, const GFXfont *f, const char *msg)
{
  int16_t x1, y1;
  uint16_t wid, ht;
  tft.setFont(f);
  tft.setCursor(x, y);
  tft.setTextColor(0x0000);
  tft.setTextSize(sz);
  tft.print(msg);
}
void setup() {
  tft.reset();
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.invertDisplay(true);
  tft.fillScreen(0xffff);
  showmsgXY(20, 100, 5, &FreeSans9pt7b, ".");
  col[0] = tft.color565(0, 0, 0);
 
}
void loop() {
  for (int i = 0; i < 1; i++) {
   tft.drawCircle(240 + 1 * (cos(-i * PI / 4)), 150 + 1 * (sin(-i * PI / 4)), 90, col[0]);
   tft.drawCircle(240 + 1* (cos(-i * PI / 4)), 150 + 1 * (sin(-i * PI / 4)), 120, col[0]);
   tft.drawLine(320, 200, 320, 200, 0x07E0);
  }
}