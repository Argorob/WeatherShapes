#include <SPI.h>
#include "Adafruit_GFX.h"
#include <Adafruit_HX8357.h>

#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8

// Create object for display screen
Adafruit_HX8357 dScreen = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
  int screenWidth = dScreen.width();
void setup() {
  dScreen.begin(HX8357D);
  dScreen.setRotation(1);
  dScreen.setCursor(0,0);

}


void loop(void) {
      dScreen.fillScreen(0);
        dScreen.setCursor(0,0);
        dScreen.println("Give me a name");
        String readResult = Serial.readString();
            delay(5000);
      dScreen.setTextSize(5);
    dScreen.print (readResult);
    delay(5000);
  
  
  /*for(uint8_t rotation=0; rotation<4; rotation++) {
    dScreen.setRotation(rotation);
    //testFillScreen();
   // dScreen.fillScreen(0);
    dScreen.println (screenWidth);
    delay(1000);
  }*/
}

unsigned long testFillScreen() {
  unsigned long start = micros();
  dScreen.fillScreen(HX8357_RED);
  dScreen.fillScreen(HX8357_GREEN);
  dScreen.fillScreen(HX8357_BLUE);
  dScreen.fillScreen(HX8357_WHITE);
  return micros() - start;
}




