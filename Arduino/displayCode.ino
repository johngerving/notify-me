#include "HyperDisplay_UG2856KLBAG01.h"   // Your library can be installed here: http://librarymanager/All#SparkFun_Transparent_Graphical_OLED
                                          // The rest of the Layer Cake:         http://librarymanager/All#SparkFun_HyperDisplay_SSD1309
                                          //                                     http://librarymanager/All#SparkFun_HyperDisplay
//////////////////////////
//      User Setup      //
//////////////////////////
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

void showLogo( void ){ //BIG BOY
  myTOLED.clearDisplay();
  myTOLED.pixelSet(0, 0); myTOLED.pixelSet(5, 0); myTOLED.pixelSet(9, 0); myTOLED.pixelSet(10, 0); myTOLED.pixelSet(11, 0); myTOLED.pixelSet(12, 0); myTOLED.pixelSet(16, 0); myTOLED.pixelSet(17, 0); myTOLED.pixelSet(18, 0); myTOLED.pixelSet(19, 0); myTOLED.pixelSet(20, 0); myTOLED.pixelSet(21, 0); myTOLED.pixelSet(22, 0); myTOLED.pixelSet(24, 0); myTOLED.pixelSet(25, 0); myTOLED.pixelSet(26, 0); myTOLED.pixelSet(27, 0); myTOLED.pixelSet(28, 0); myTOLED.pixelSet(29, 0); myTOLED.pixelSet(30, 0); myTOLED.pixelSet(32, 0); myTOLED.pixelSet(33, 0); myTOLED.pixelSet(34, 0); myTOLED.pixelSet(35, 0); myTOLED.pixelSet(36, 0); myTOLED.pixelSet(37, 0); myTOLED.pixelSet(40, 0); myTOLED.pixelSet(46, 0); 
  myTOLED.pixelSet(0, 1); myTOLED.pixelSet(1, 1); myTOLED.pixelSet(5, 1); myTOLED.pixelSet(8, 1); myTOLED.pixelSet(13, 1); myTOLED.pixelSet(19, 1); myTOLED.pixelSet(27, 1); myTOLED.pixelSet(33, 1); myTOLED.pixelSet(41, 1); myTOLED.pixelSet(45, 1); 
  myTOLED.pixelSet(0, 2); myTOLED.pixelSet(2, 2); myTOLED.pixelSet(5, 2); myTOLED.pixelSet(8, 2); myTOLED.pixelSet(13, 2); myTOLED.pixelSet(19, 2); myTOLED.pixelSet(27, 2); myTOLED.pixelSet(33, 2); myTOLED.pixelSet(42, 2); myTOLED.pixelSet(44, 2); 
  myTOLED.pixelSet(0, 3); myTOLED.pixelSet(2, 3); myTOLED.pixelSet(5, 3); myTOLED.pixelSet(8, 3); myTOLED.pixelSet(13, 3); myTOLED.pixelSet(19, 3); myTOLED.pixelSet(27, 3); myTOLED.pixelSet(33, 3); myTOLED.pixelSet(34, 3); myTOLED.pixelSet(35, 3); myTOLED.pixelSet(36, 3); myTOLED.pixelSet(43, 3); 
  myTOLED.pixelSet(0, 4); myTOLED.pixelSet(3, 4); myTOLED.pixelSet(5, 4); myTOLED.pixelSet(8, 4); myTOLED.pixelSet(13, 4); myTOLED.pixelSet(19, 4); myTOLED.pixelSet(27, 4); myTOLED.pixelSet(33, 4); myTOLED.pixelSet(43, 4); 
  myTOLED.pixelSet(0, 5); myTOLED.pixelSet(3, 5); myTOLED.pixelSet(5, 5); myTOLED.pixelSet(8, 5); myTOLED.pixelSet(13, 5); myTOLED.pixelSet(19, 5); myTOLED.pixelSet(27, 5); myTOLED.pixelSet(33, 5); myTOLED.pixelSet(43, 5); 
  myTOLED.pixelSet(0, 6); myTOLED.pixelSet(4, 6); myTOLED.pixelSet(5, 6); myTOLED.pixelSet(8, 6); myTOLED.pixelSet(13, 6); myTOLED.pixelSet(19, 6); myTOLED.pixelSet(27, 6); myTOLED.pixelSet(33, 6); myTOLED.pixelSet(43, 6); 
  myTOLED.pixelSet(0, 7); myTOLED.pixelSet(5, 7); myTOLED.pixelSet(9, 7); myTOLED.pixelSet(10, 7); myTOLED.pixelSet(11, 7); myTOLED.pixelSet(12, 7); myTOLED.pixelSet(19, 7); myTOLED.pixelSet(24, 7); myTOLED.pixelSet(25, 7); myTOLED.pixelSet(26, 7); myTOLED.pixelSet(27, 7); myTOLED.pixelSet(28, 7); myTOLED.pixelSet(29, 7); myTOLED.pixelSet(30, 7); myTOLED.pixelSet(33, 7); myTOLED.pixelSet(43, 7); 
  
  
  myTOLED.pixelSet(9, 10); myTOLED.pixelSet(20, 10); myTOLED.pixelSet(25, 10); myTOLED.pixelSet(26, 10); myTOLED.pixelSet(27, 10); myTOLED.pixelSet(28, 10); myTOLED.pixelSet(29, 10); myTOLED.pixelSet(30, 10); myTOLED.pixelSet(31, 10); myTOLED.pixelSet(32, 10); myTOLED.pixelSet(33, 10); myTOLED.pixelSet(34, 10); myTOLED.pixelSet(35, 10); myTOLED.pixelSet(36, 10); 
  myTOLED.pixelSet(9, 11); myTOLED.pixelSet(10, 11); myTOLED.pixelSet(19, 11); myTOLED.pixelSet(20, 11); myTOLED.pixelSet(25, 11); myTOLED.pixelSet(26, 11); myTOLED.pixelSet(27, 11); myTOLED.pixelSet(28, 11); myTOLED.pixelSet(29, 11); myTOLED.pixelSet(30, 11); myTOLED.pixelSet(31, 11); myTOLED.pixelSet(32, 11); myTOLED.pixelSet(33, 11); myTOLED.pixelSet(34, 11); myTOLED.pixelSet(35, 11); myTOLED.pixelSet(36, 11); 
  myTOLED.pixelSet(9, 12); myTOLED.pixelSet(10, 12); myTOLED.pixelSet(11, 12); myTOLED.pixelSet(18, 12); myTOLED.pixelSet(19, 12); myTOLED.pixelSet(20, 12); myTOLED.pixelSet(25, 12); myTOLED.pixelSet(26, 12); 
  myTOLED.pixelSet(9, 13); myTOLED.pixelSet(10, 13); myTOLED.pixelSet(11, 13); myTOLED.pixelSet(12, 13); myTOLED.pixelSet(17, 13); myTOLED.pixelSet(18, 13); myTOLED.pixelSet(19, 13); myTOLED.pixelSet(20, 13); myTOLED.pixelSet(25, 13); myTOLED.pixelSet(26, 13); 
  myTOLED.pixelSet(9, 14); myTOLED.pixelSet(10, 14); myTOLED.pixelSet(11, 14); myTOLED.pixelSet(12, 14); myTOLED.pixelSet(13, 14); myTOLED.pixelSet(16, 14); myTOLED.pixelSet(17, 14); myTOLED.pixelSet(18, 14); myTOLED.pixelSet(19, 14); myTOLED.pixelSet(20, 14); myTOLED.pixelSet(25, 14); myTOLED.pixelSet(26, 14); 
  myTOLED.pixelSet(9, 15); myTOLED.pixelSet(10, 15); myTOLED.pixelSet(12, 15); myTOLED.pixelSet(13, 15); myTOLED.pixelSet(14, 15); myTOLED.pixelSet(15, 15); myTOLED.pixelSet(16, 15); myTOLED.pixelSet(17, 15); myTOLED.pixelSet(19, 15); myTOLED.pixelSet(20, 15); myTOLED.pixelSet(25, 15); myTOLED.pixelSet(26, 15); 
  myTOLED.pixelSet(9, 16); myTOLED.pixelSet(10, 16); myTOLED.pixelSet(13, 16); myTOLED.pixelSet(14, 16); myTOLED.pixelSet(15, 16); myTOLED.pixelSet(16, 16); myTOLED.pixelSet(19, 16); myTOLED.pixelSet(20, 16); myTOLED.pixelSet(25, 16); myTOLED.pixelSet(26, 16); 
  myTOLED.pixelSet(9, 17); myTOLED.pixelSet(10, 17); myTOLED.pixelSet(14, 17); myTOLED.pixelSet(15, 17); myTOLED.pixelSet(19, 17); myTOLED.pixelSet(20, 17); myTOLED.pixelSet(25, 17); myTOLED.pixelSet(26, 17); myTOLED.pixelSet(27, 17); myTOLED.pixelSet(28, 17); myTOLED.pixelSet(29, 17); myTOLED.pixelSet(30, 17); myTOLED.pixelSet(31, 17); myTOLED.pixelSet(32, 17); myTOLED.pixelSet(33, 17); 
  myTOLED.pixelSet(9, 18); myTOLED.pixelSet(10, 18); myTOLED.pixelSet(19, 18); myTOLED.pixelSet(20, 18); myTOLED.pixelSet(25, 18); myTOLED.pixelSet(26, 18); myTOLED.pixelSet(27, 18); myTOLED.pixelSet(28, 18); myTOLED.pixelSet(29, 18); myTOLED.pixelSet(30, 18); myTOLED.pixelSet(31, 18); myTOLED.pixelSet(32, 18); myTOLED.pixelSet(33, 18); 
  myTOLED.pixelSet(9, 19); myTOLED.pixelSet(10, 19); myTOLED.pixelSet(19, 19); myTOLED.pixelSet(20, 19); myTOLED.pixelSet(25, 19); myTOLED.pixelSet(26, 19); 
  myTOLED.pixelSet(9, 20); myTOLED.pixelSet(10, 20); myTOLED.pixelSet(19, 20); myTOLED.pixelSet(20, 20); myTOLED.pixelSet(25, 20); myTOLED.pixelSet(26, 20); 
  myTOLED.pixelSet(9, 21); myTOLED.pixelSet(10, 21); myTOLED.pixelSet(19, 21); myTOLED.pixelSet(20, 21); myTOLED.pixelSet(25, 21); myTOLED.pixelSet(26, 21); 
  myTOLED.pixelSet(9, 22); myTOLED.pixelSet(10, 22); myTOLED.pixelSet(19, 22); myTOLED.pixelSet(20, 22); myTOLED.pixelSet(25, 22); myTOLED.pixelSet(26, 22); 
  myTOLED.pixelSet(9, 23); myTOLED.pixelSet(10, 23); myTOLED.pixelSet(19, 23); myTOLED.pixelSet(20, 23); myTOLED.pixelSet(25, 23); myTOLED.pixelSet(26, 23); 
  myTOLED.pixelSet(9, 24); myTOLED.pixelSet(10, 24); myTOLED.pixelSet(19, 24); myTOLED.pixelSet(20, 24); myTOLED.pixelSet(25, 24); myTOLED.pixelSet(26, 24); myTOLED.pixelSet(27, 24); myTOLED.pixelSet(28, 24); myTOLED.pixelSet(29, 24); myTOLED.pixelSet(30, 24); myTOLED.pixelSet(31, 24); myTOLED.pixelSet(32, 24); myTOLED.pixelSet(33, 24); myTOLED.pixelSet(34, 24); myTOLED.pixelSet(35, 24); myTOLED.pixelSet(36, 24); 
  myTOLED.pixelSet(9, 25); myTOLED.pixelSet(10, 25); myTOLED.pixelSet(19, 25); myTOLED.pixelSet(20, 25); myTOLED.pixelSet(25, 25); myTOLED.pixelSet(26, 25); myTOLED.pixelSet(27, 25); myTOLED.pixelSet(28, 25); myTOLED.pixelSet(29, 25); myTOLED.pixelSet(30, 25); myTOLED.pixelSet(31, 25); myTOLED.pixelSet(32, 25); myTOLED.pixelSet(33, 25); myTOLED.pixelSet(34, 25); myTOLED.pixelSet(35, 25); myTOLED.pixelSet(36, 25); 
}

void loop() {
  showLogo(); //SHows logo on startup... hopefully
  //TIME --- TIME --- TIME --- TIME --- TIME --- TIME
  int hr = 2; //Hour
  int mn = 30; //Minute
  while(true){
    delay(60000); // 1 min delay
    mn += 1;
    if(mn > 60) { //Logic for hour reset
      hr += 1;
      mn = 0;
    }
    if(hr > 12) { //Logic for 12 hr reset 
      hr = 1;
    }
    myTOLED.windowClear(); //Clear display
    myTOLED.setWindowColorSet();
    myTOLED.setTextCursor(128,0);
    myTOLED.print(hr + ":" + mn); //Hr:Minute
    //NEWS --- NEWS --- NEWS --- NEWS --- NEWS --- NEWS
  }
}
