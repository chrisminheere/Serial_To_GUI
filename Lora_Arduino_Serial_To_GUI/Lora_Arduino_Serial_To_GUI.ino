//*****************************************************************************************************************************//
//Made By: Chris Minheere
//01-09-2018
//Lora Receiver 868Mhz, On ESP32. 
//Hardware: ESP32, SSD1306 OLED, SX1276 868MHz


//Sketch uses 126898 bytes (9%) of program storage space. Maximum is 1310720 bytes.
//Global variables use 10180 bytes (3%) of dynamic memory, leaving 284732 bytes for local variables. Maximum is 294912 bytes.
//*****************************************************************************************************************************//

#include <SPI.h>
#include <LoRa.h>
#include "SSD1306.h"
int yPos = 0;

SSD1306 display(0x3c, 5, 4); // instance for the OLED. Addr, SDA, SCL
String receivedText;


void setup() {

  Serial.begin(115200);
  receivedText = "";

  //Initialise the display
  display.init(); // initialise the OLED
  display.flipScreenVertically(); // does what is says
  display.setFont(ArialMT_Plain_16); // does what is says
  display.setTextAlignment(TEXT_ALIGN_LEFT);  // Set the origin of text to top left


  while (!Serial);

  //Initialize the library with the specified frequency.
  if (!LoRa.begin(868E6)) {
    Serial.println("false");
    while (1);
  }

  //**********Lora Transceiver Settings***********//
  //More ino at:https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md

  //LoRa.setTxPower(txPower);             //Change the TX power of the radio.
  //LoRa.setTxPower(txPower, outputPin);
  LoRa.setSpreadingFactor(7);            //Change the spreading factor of the radio.
  LoRa.setSignalBandwidth(250E3);         //Change the signal bandwidth of the radio.
  LoRa.setCodingRate4(4 / 5);             //Change the coding rate of the radio.
  LoRa.setSyncWord(0x11);                 //Change the sync word of the radio.
  //LoRa.disableCrc();                    //Enable or disable CRC usage, by default a CRC is not used.
  LoRa.setPreambleLength(8);              //Change the preamble length of the radio.
}


void loop() {

  // try to parse packet
  int packetSize = LoRa.parsePacket();

  if (packetSize) {

    // read packet
    while (LoRa.available()) {

      //Get message
      receivedText = "";
      for (int a = 0; a < packetSize; a++)
        receivedText += (char)LoRa.read();

      //Show text in terminal
      Serial.print(receivedText);

      //Show text on display
      display.clear();
      display.drawString(2, 2, "Lora Temperature");
      //display.drawString(45, 30, (counter());
      display.drawString(45, 30, "°C");
      display.drawString(2, 30, receivedText);
      display.drawString(45, 45, (String)LoRa.packetRssi());
      display.drawString(2, 45, "RSSI");
      display.display(); // display whatever is in the buffer

    }

    // print RSSI of packet
    
    Serial.println(LoRa.packetRssi());
  }
}
