#include <ArduinoJson.h>
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
//#include <EthernetServer.h>
#include <EthernetUdp.h>
//#include <util.h>

#include <SPI.h>
#include "Adafruit_GFX.h"
#include <Adafruit_HX8357.h>

#define TFT_CS 7
#define TFT_DC 9
#define TFT_RST 8

 // Network declaration information
byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x2D, 0xAC}; //Assign mac address to ethernet module 
byte ip[] = {192,168,1,181}; //IP address of the device
byte server[] = "http://www.google.com"; // Weather API
//byte server[] = "http://api.openweathermap.org/data/2.5/weather"; // Weather API
byte gateway[] = {192,168,1,1};  // IP of google 
//EthernetClient GCClient (server,80); // Set to client mode to send message
// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
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
//delay(500);
  
dScreen.begin(HX8357D);
dScreen.setRotation(2);
dScreen.setCursor(0,0);
dScreen.fillScreen(0);
     dScreen.setTextSize(3);
     
     //Check for connection
  if (client.connect(server, 80)) {
  dScreen.println("connected");

    //Set up buffer
   // StaticJsonBuffer<200> jsonBuffer;
    //char json[] =
    //  "{\"q\"}";
      // Create JSON object
     // JsonObject& root = jsonBuffer.parseObject(json);

  } else {
    dScreen.println("connection failed");
  }

}


void loop() {
    

     //dScreen.setCursor(xScreen,yScreen);
    /*if (client.available()) {
    char c = client.read();
    dScreen.print(c);
    Serial.println("connecting");
     client.println("GET ?q=pensacola,us&appid=ea0cf6df0bf1a578823a05c9f99f4499 HTTP/1.1");
  }

  if (!client.connected()) {
    dScreen.println();
    Serial.println("disconnecting.");
    client.stop();
    for(;;)
      ;
  }*/
  
dScreen.print("Loop");
 
     delay(300);

}





