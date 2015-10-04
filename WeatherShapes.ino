#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <util.h>

#include <SPI.h>
#include "Adafruit_GFX.h"
#include <Adafruit_HX8357.h>

#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8

 // Network declaration information
byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x2D, 0xAC}; //Assign mac address to ethernet module 
byte ip[] = {192,168,1,181}; //IP address of the device
byte server[] = { 64, 233, 187, 99 }; // Google
byte gateway[] = {192,168,1,1};  // IP of google 
//EthernetClient GCClient (server,80); // Set to client mode to send message
EthernetClient client; // Set Arduino to client mode


// Create object for display screen
Adafruit_HX8357 dScreen = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
int screenWidth = dScreen.width();
int screenHeight = dScreen.height();  
int xScreen =0;
int yScreen=0;

void setup() {
// Initialize network information 
Ethernet.begin(mac,ip);
delay(500);
  
dScreen.begin(HX8357D);
dScreen.setRotation(1);
dScreen.setCursor(0,0);
dScreen.fillScreen(0);

}


void loop() {
     dScreen.fillScreen(0);
     dScreen.setTextSize(3);
     dScreen.setCursor(xScreen,yScreen);
    if (client.available()) {
    char c = client.read();
    dScreen.print(c);
  }

  if (!client.connected()) {
    dScreen.println();
    Serial.println("disconnecting.");
    client.stop();
    for(;;)
      ;
  }
  

 
     delay(300);

}





