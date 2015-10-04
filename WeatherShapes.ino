#include <SPI.h>
#include "Adafruit_GFX.h"
#include <Adafruit_HX8357.h>

#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8

// Create object for display screen
Adafruit_HX8357 dScreen = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
int screenWidth = dScreen.width();
int screenHeight = dScreen.height();  
int xScreen =0;
int yScreen=0;
void setup() {
dScreen.begin(HX8357D);
dScreen.setRotation(1);
dScreen.setCursor(0,0);
dScreen.fillScreen(0);

}


void loop(void) {
     dScreen.fillScreen(0);
     dScreen.setTextSize(3);
     dScreen.setCursor(xScreen,yScreen);
     xScreen = xScreen + 5;
     dScreen.print("Argorob");
     delay(300);

}





