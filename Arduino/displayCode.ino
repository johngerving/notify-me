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

char headlines[][150] = {
  "Fox Anchor Confronts Surgeon General Over Trump Declining to Issue Lockdown - Newsweek",
  "Andrew Cuomo's not your boyfriend � and Joe Biden's definitely not your dad - Salon",
  "Esper defends removing USS Theodore Roosevelt commander who sounded alarm over coronavirus - CNN",
  "European Slowdown in Virus Deaths Bolsters Leaders on Lockdowns - Bloomberg",
  "Bill Gates calls coronavirus pandemic a 'nightmare scenario,' but predicts lower death toll than Trump - CNBC",
  "President Donald Trump Tweetstorm � The Sunday Edition - Deadline",
  "Georgia Mayor Blasts Governor for Reopening State's Beaches During Pandemic - Newsweek",
  "Significant storm system begins to impact California with heavy rain, flash flooding - ABC News",
  "Jared Kushner and his shadow corona unit: what is Trump's son-in-law up to? - The Guardian",
  "Fed's Bullard says US economy not in 'free fall' despite 32% unemployment projection - CNBC",
  "Queen Elizabeth II's coronavirus address | LBC - LBC",
  "Pope Francis Livestreams Palm Sunday Mass In An 'Empty' St. Peter's Amid The Pandemic - NPR",
  "Some pastors defiant as churches celebrate Palm Sunday during coronavirus outbreak - Fox News",
  "Spain coronavirus: Death toll rise shows signs of flattening - CNN",
  "Global economy screeches to a halt as coronavirus job losses take toll - New York Post ",
  "3 Top Stocks to Buy With Dividends Yielding More Than 3% - Motley Fool",
  "Gig Workers Struggle To Get Financial Help During Pandemic - NPR",
  "This Dirt-Cheap Warren Buffett Stock Should Be Your Top Pick Right Now - Motley Fool",
  "Every upcoming phone available this spring and summer of 2020 - CNET",
  "Apple Music's success is helping the company meet a long time revenue goal - PhoneArena",
  "Amazon's Project Tempo could crush Google Stadia � here's why - Tom's Guide",
  "This Week in Apps: Zoom has issues, Pinterest founder�s new COVID-19 research app, record Q1 spending - TechCrunch",
  "'Tiger King' star Jeff Lowe says Netflix is adding a new episode of the show 'next week' - Fox News",
  "Tearful Michelle Money Pleads for Prayers for Hospitalized Daughter - E! Online",
  "Quibi app launch: best or worst timing? - The Verge",
  "'Atlanta's Missing and Murdered': New HBO Series Dives Into the Darkness - Showbiz Cheat Sheet",
  "Tom Dempsey, NFL kicker who set a record for the longest field goal, dies of coronavirus - CNN",
  "Where Kobe Bryant, Tim Duncan and the 2020 Basketball Hall of Fame class rank among all-time best groups - CBS Sports",
  "Ranking the 7 Biggest Draft Mistakes of the Past 5 Years - Bleacher Report",
  "Pre-race show and concert ft. Austin Dillon and Justin Moore - NASCAR",
  "NASA astronauts share their workout routine aboard the ISS to help motivate those on Earth living in isolation amid the coronavirus pandemic - msnNOW",
  "Biggest, brightest supermoon of 2020 rises this week, when to see it - WKMG News 6 & ClickOrlando",
  "NASA lays out plans for building a long-term moon base - Digital Trends",
  "Coronavirus lockdowns have caused the Earth to effectively stop shaking - Fox News",
  "Are you wearing your face mask properly? Many people aren�t, coronavirus experts say - Sacramento Bee",
  "1918 to COVID-19: 100 years of covering pandemics | The Listening Post (Feature) - Al Jazeera English",
  "Onondaga County warns of potential coronavirus exposure at 3 pharmacies, liquor store - syracuse.com",
  "Maine coronavirus cases rise to 470; no new deaths reported, CDC says - WMTW Portland"
};


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
  showLogo(); //SHows logo on startup... hopefully
}

void showLogo( void ){
  myTOLED.clearDisplay();
  myTOLED.pixelSet(40, 11); myTOLED.pixelSet(41, 11); myTOLED.pixelSet(42, 11); myTOLED.pixelSet(43, 11); myTOLED.pixelSet(44, 11); myTOLED.pixelSet(45, 11); myTOLED.pixelSet(46, 11); myTOLED.pixelSet(47, 11); 
  myTOLED.pixelSet(41, 12); 
  myTOLED.pixelSet(42, 13); myTOLED.pixelSet(43, 13); 
  myTOLED.pixelSet(44, 14); myTOLED.pixelSet(45, 14); 
  myTOLED.pixelSet(46, 15); 
  myTOLED.pixelSet(40, 16); myTOLED.pixelSet(41, 16); myTOLED.pixelSet(42, 16); myTOLED.pixelSet(43, 16); myTOLED.pixelSet(44, 16); myTOLED.pixelSet(45, 16); myTOLED.pixelSet(46, 16); myTOLED.pixelSet(47, 16); 
  
  
  myTOLED.pixelSet(41, 19); myTOLED.pixelSet(42, 19); myTOLED.pixelSet(43, 19); myTOLED.pixelSet(44, 19); myTOLED.pixelSet(45, 19); myTOLED.pixelSet(46, 19); 
  myTOLED.pixelSet(40, 20); myTOLED.pixelSet(47, 20); myTOLED.pixelSet(50, 20); myTOLED.pixelSet(51, 20); myTOLED.pixelSet(52, 20); myTOLED.pixelSet(53, 20); myTOLED.pixelSet(54, 20); myTOLED.pixelSet(55, 20); myTOLED.pixelSet(56, 20); myTOLED.pixelSet(57, 20); myTOLED.pixelSet(58, 20); myTOLED.pixelSet(59, 20); myTOLED.pixelSet(60, 20); myTOLED.pixelSet(61, 20); myTOLED.pixelSet(62, 20); myTOLED.pixelSet(63, 20); myTOLED.pixelSet(64, 20); myTOLED.pixelSet(65, 20); 
  myTOLED.pixelSet(40, 21); myTOLED.pixelSet(47, 21); myTOLED.pixelSet(51, 21); myTOLED.pixelSet(52, 21); myTOLED.pixelSet(53, 21); myTOLED.pixelSet(54, 21); myTOLED.pixelSet(55, 21); myTOLED.pixelSet(56, 21); myTOLED.pixelSet(57, 21); myTOLED.pixelSet(58, 21); myTOLED.pixelSet(59, 21); myTOLED.pixelSet(60, 21); myTOLED.pixelSet(61, 21); myTOLED.pixelSet(62, 21); myTOLED.pixelSet(63, 21); myTOLED.pixelSet(64, 21); myTOLED.pixelSet(65, 21); 
  myTOLED.pixelSet(40, 22); myTOLED.pixelSet(47, 22); myTOLED.pixelSet(52, 22); myTOLED.pixelSet(53, 22); myTOLED.pixelSet(54, 22); 
  myTOLED.pixelSet(40, 23); myTOLED.pixelSet(47, 23); myTOLED.pixelSet(53, 23); myTOLED.pixelSet(54, 23); myTOLED.pixelSet(55, 23); 
  myTOLED.pixelSet(41, 24); myTOLED.pixelSet(42, 24); myTOLED.pixelSet(43, 24); myTOLED.pixelSet(44, 24); myTOLED.pixelSet(45, 24); myTOLED.pixelSet(46, 24); myTOLED.pixelSet(54, 24); myTOLED.pixelSet(55, 24); myTOLED.pixelSet(56, 24); 
  myTOLED.pixelSet(55, 25); myTOLED.pixelSet(56, 25); myTOLED.pixelSet(57, 25); 
  myTOLED.pixelSet(55, 26); myTOLED.pixelSet(56, 26); myTOLED.pixelSet(57, 26); 
  myTOLED.pixelSet(40, 27); myTOLED.pixelSet(54, 27); myTOLED.pixelSet(55, 27); myTOLED.pixelSet(56, 27); 
  myTOLED.pixelSet(40, 28); myTOLED.pixelSet(53, 28); myTOLED.pixelSet(54, 28); myTOLED.pixelSet(55, 28); 
  myTOLED.pixelSet(40, 29); myTOLED.pixelSet(52, 29); myTOLED.pixelSet(53, 29); myTOLED.pixelSet(54, 29); 
  myTOLED.pixelSet(40, 30); myTOLED.pixelSet(41, 30); myTOLED.pixelSet(42, 30); myTOLED.pixelSet(43, 30); myTOLED.pixelSet(44, 30); myTOLED.pixelSet(45, 30); myTOLED.pixelSet(46, 30); myTOLED.pixelSet(47, 30); myTOLED.pixelSet(51, 30); myTOLED.pixelSet(52, 30); myTOLED.pixelSet(53, 30); myTOLED.pixelSet(54, 30); myTOLED.pixelSet(55, 30); myTOLED.pixelSet(56, 30); myTOLED.pixelSet(57, 30); myTOLED.pixelSet(58, 30); myTOLED.pixelSet(59, 30); myTOLED.pixelSet(60, 30); myTOLED.pixelSet(61, 30); myTOLED.pixelSet(62, 30); myTOLED.pixelSet(63, 30); myTOLED.pixelSet(64, 30); myTOLED.pixelSet(65, 30); 
  myTOLED.pixelSet(40, 31); myTOLED.pixelSet(50, 31); myTOLED.pixelSet(51, 31); myTOLED.pixelSet(52, 31); myTOLED.pixelSet(53, 31); myTOLED.pixelSet(54, 31); myTOLED.pixelSet(55, 31); myTOLED.pixelSet(56, 31); myTOLED.pixelSet(57, 31); myTOLED.pixelSet(58, 31); myTOLED.pixelSet(59, 31); myTOLED.pixelSet(60, 31); myTOLED.pixelSet(61, 31); myTOLED.pixelSet(62, 31); myTOLED.pixelSet(63, 31); myTOLED.pixelSet(64, 31); myTOLED.pixelSet(65, 31); 
  myTOLED.pixelSet(40, 32); 
  myTOLED.pixelSet(40, 33); 
  
  myTOLED.pixelSet(40, 35); myTOLED.pixelSet(47, 35); 
  myTOLED.pixelSet(40, 36); myTOLED.pixelSet(47, 36); myTOLED.pixelSet(50, 36); myTOLED.pixelSet(51, 36); myTOLED.pixelSet(52, 36); myTOLED.pixelSet(53, 36); myTOLED.pixelSet(54, 36); myTOLED.pixelSet(55, 36); myTOLED.pixelSet(56, 36); myTOLED.pixelSet(57, 36); myTOLED.pixelSet(58, 36); myTOLED.pixelSet(59, 36); myTOLED.pixelSet(60, 36); myTOLED.pixelSet(61, 36); myTOLED.pixelSet(62, 36); myTOLED.pixelSet(63, 36); myTOLED.pixelSet(64, 36); myTOLED.pixelSet(65, 36); 
  myTOLED.pixelSet(40, 37); myTOLED.pixelSet(47, 37); myTOLED.pixelSet(50, 37); myTOLED.pixelSet(51, 37); myTOLED.pixelSet(52, 37); myTOLED.pixelSet(53, 37); myTOLED.pixelSet(54, 37); myTOLED.pixelSet(55, 37); myTOLED.pixelSet(56, 37); myTOLED.pixelSet(57, 37); myTOLED.pixelSet(58, 37); myTOLED.pixelSet(59, 37); myTOLED.pixelSet(60, 37); myTOLED.pixelSet(61, 37); myTOLED.pixelSet(62, 37); myTOLED.pixelSet(63, 37); myTOLED.pixelSet(64, 37); myTOLED.pixelSet(65, 37); 
  myTOLED.pixelSet(40, 38); myTOLED.pixelSet(41, 38); myTOLED.pixelSet(42, 38); myTOLED.pixelSet(43, 38); myTOLED.pixelSet(44, 38); myTOLED.pixelSet(45, 38); myTOLED.pixelSet(46, 38); myTOLED.pixelSet(47, 38); myTOLED.pixelSet(50, 38); myTOLED.pixelSet(51, 38); myTOLED.pixelSet(57, 38); myTOLED.pixelSet(58, 38); myTOLED.pixelSet(64, 38); myTOLED.pixelSet(65, 38); 
  myTOLED.pixelSet(40, 39); myTOLED.pixelSet(47, 39); myTOLED.pixelSet(50, 39); myTOLED.pixelSet(51, 39); myTOLED.pixelSet(57, 39); myTOLED.pixelSet(58, 39); myTOLED.pixelSet(64, 39); myTOLED.pixelSet(65, 39); 
  myTOLED.pixelSet(40, 40); myTOLED.pixelSet(47, 40); myTOLED.pixelSet(50, 40); myTOLED.pixelSet(51, 40); myTOLED.pixelSet(57, 40); myTOLED.pixelSet(58, 40); myTOLED.pixelSet(64, 40); myTOLED.pixelSet(65, 40); 
  myTOLED.pixelSet(40, 41); myTOLED.pixelSet(47, 41); myTOLED.pixelSet(50, 41); myTOLED.pixelSet(51, 41); myTOLED.pixelSet(57, 41); myTOLED.pixelSet(58, 41); myTOLED.pixelSet(64, 41); myTOLED.pixelSet(65, 41); 
  myTOLED.pixelSet(50, 42); myTOLED.pixelSet(51, 42); myTOLED.pixelSet(57, 42); myTOLED.pixelSet(58, 42); myTOLED.pixelSet(64, 42); myTOLED.pixelSet(65, 42); 
  myTOLED.pixelSet(40, 43); myTOLED.pixelSet(50, 43); myTOLED.pixelSet(51, 43); myTOLED.pixelSet(57, 43); myTOLED.pixelSet(58, 43); myTOLED.pixelSet(64, 43); myTOLED.pixelSet(65, 43); 
  myTOLED.pixelSet(40, 44); myTOLED.pixelSet(41, 44); myTOLED.pixelSet(42, 44); myTOLED.pixelSet(43, 44); myTOLED.pixelSet(44, 44); myTOLED.pixelSet(45, 44); myTOLED.pixelSet(46, 44); myTOLED.pixelSet(47, 44); myTOLED.pixelSet(50, 44); myTOLED.pixelSet(51, 44); myTOLED.pixelSet(57, 44); myTOLED.pixelSet(58, 44); myTOLED.pixelSet(64, 44); myTOLED.pixelSet(65, 44); 
  myTOLED.pixelSet(40, 45); myTOLED.pixelSet(43, 45); myTOLED.pixelSet(50, 45); myTOLED.pixelSet(51, 45); myTOLED.pixelSet(64, 45); myTOLED.pixelSet(65, 45); 
  myTOLED.pixelSet(40, 46); myTOLED.pixelSet(43, 46); myTOLED.pixelSet(50, 46); myTOLED.pixelSet(51, 46); myTOLED.pixelSet(64, 46); myTOLED.pixelSet(65, 46); 
  myTOLED.pixelSet(40, 47); myTOLED.pixelSet(43, 47); myTOLED.pixelSet(50, 47); myTOLED.pixelSet(51, 47); myTOLED.pixelSet(64, 47); myTOLED.pixelSet(65, 47); 
  myTOLED.pixelSet(40, 48); 
  
  
  myTOLED.pixelSet(40, 51); 
  myTOLED.pixelSet(41, 52); 
  myTOLED.pixelSet(42, 53); 
  myTOLED.pixelSet(43, 54); myTOLED.pixelSet(44, 54); myTOLED.pixelSet(45, 54); myTOLED.pixelSet(46, 54); myTOLED.pixelSet(47, 54); 
  myTOLED.pixelSet(42, 55); 
  myTOLED.pixelSet(41, 56); 
  myTOLED.pixelSet(40, 57); 

  delay(3000);
}


void loop() {
  myTOLED.windowClear();
  /*
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
    */
    //NEWS --- NEWS --- NEWS --- NEWS --- NEWS --- NEWS
    for(int i = 0; i < sizeof(headlines); i++) {
      myTOLED.setTextCursor(128, 0);
      myTOLED.print(headlines[i]);
      delay(10000);
      myTOLED.windowClear();
    }
}
