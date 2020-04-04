#include <HyperDisplay_UG2856KLBAG01.h>
#include <HyperDisplay_SSD1309.h>
#include <hyperdisplay.h>

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

char input[50] = "Hello world!";


void setup() {
  Serial.begin(9600);

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
  
  myTOLED.setTextCursor(128, 0);
  myTOLED.print(input);
  delay(1000);
}
