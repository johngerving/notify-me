#include <HyperDisplay_UG2856KLBAG01.h>
#include <HyperDisplay_SSD1309.h>
#include <hyperdisplay.h>
#include <ArduinoBLE.h>


#define SERIAL_PORT Serial  
#define WIRE_PORT Wire      // Used if USE_SPI == 0
#define SPI_PORT SPI        // Used if USE_SPI == 1

#define RES_PIN 2           // Optional
#define CS_PIN 4            // Used only if USE_SPI == 1
#define DC_PIN 5            // Used only if USE_SPI == 1

#define USE_SPI 0           // Choose your interface. 0 = I2C, 1 = SPI

// END USER SETUP


// Object Declaration. A class exists for each interface option
#if USE_SPI
  UG2856KLBAG01_SPI myTOLED;  // Declare a SPI-based Transparent OLED object called myTOLED
#else
  UG2856KLBAG01_I2C myTOLED;  // Declare a I2C-based Transparent OLED object called myTOLED
#endif /* USE_SPI */

//char input[50] = "Hello world!";

BLEService notifyMeService("19B10000-E8F2-537E-4F6C-D104768A1214"); // BLE LED Service

// BLE LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);


void setup() {
  Serial.begin(9600);

  Serial1.begin(9600);
  while (!Serial1);
  // begin initialization
  if (!BLE.begin()) {
    Serial1.println("starting BLE failed!");

    while (1);
  }

  // set advertised local name and service UUID:
  BLE.setLocalName("NotifyMe");
  BLE.setAdvertisedService(notifyMeService);

  // add the characteristic to the service
  notifyMeService.addCharacteristic(switchCharacteristic);

  // add service
  BLE.addService(notifyMeService);

  // set the initial value for the characeristic:
  switchCharacteristic.writeValue(0);

  // start advertising
  BLE.advertise();

  Serial1.println("NotifyMe Peripheral");
  

#if USE_SPI 
  SPI_PORT.begin();
  myTOLED.begin(CS_PIN, DC_PIN, SPI_PORT);                  // Begin for SPI requires that you provide the CS and DC pin numbers
#else
  WIRE_PORT.begin();
  myTOLED.begin(WIRE_PORT, false, SSD1309_ARD_UNUSED_PIN);  // Begin for I2C has default values for every argument
  Wire.setClock(400000);
#endif /* USSE_SPI */
}

void loop() {
  // Blue Text Black Background
  myTOLED.windowClear();
  myTOLED.setWindowColorSet();
  
  // listen for BLE peripherals to connect:
  BLEDevice central = BLE.central();
  
  // if a central is connected to peripheral:
  if (central) {
    Serial1.print("Connected to central: ");
    // print the central's MAC address:
    Serial1.println(central.address());

    // while the central is still connected to peripheral:
    while (central.connected()) {
      // if the remote device wrote to the characteristic,
      // use the value to control the LED:
      /*
      if(switchCharacteristic.value() == 1) {
        myTOLED.setTextCursor(128, 0);
        myTOLED.print("Text");
      } else if(switchCharacteristic.value() == 2) {
        myTOLED.setTextCursor(128, 0);
        myTOLED.print("Missed Call");
      } else if(switchCharacteristic.value() == 3) {
        myTOLED.setTextCursor(128, 0);
        myTOLED.print("Voicemail");
      } else if(switchCharacteristic.value() == 4) {
        myTOLED.setTextCursor(128, 0);
        myTOLED.print("Gmail");
      } else if(switchCharacteristic.value() == 5) {
        myTOLED.setTextCursor(128, 0);
        myTOLED.print("Discord");
      } else if(switchCharacteristic.value() == 6) {
        myTOLED.setTextCursor(128, 0);
        myTOLED.print("Other");
      }
      */
      if(switchCharacteristic.written()) {
        myTOLED.print("test");
      }
    }

    // when the central disconnects, print it out:
    Serial1.print(F("Disconnected from central: "));
    Serial1.println(central.address());
  } else {
    myTOLED.setTextCursor(128, 0);
    myTOLED.print("No connection");
  }
 }
