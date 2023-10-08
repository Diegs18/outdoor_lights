//#include "main.h"
//#include "setup.h"
#include <FastLED.h>
#define SKIP 1
#define LED_PIN 2
#define NUM_LEDS 375
#define OFF 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define PURPLE 5
#define ORANGE 7



  //uint8_t upDown   [NUM_LEDS/8]; //0 means up and 1 means down


uint8_t ran = 0;
int runCnt=0;
CRGB leds[NUM_LEDS];
uint8_t flip = 0, r1, g1, b1, r2, g2, b2;
void setLEDs2EveryOther(uint8_t color1, uint8_t color2);
void colorSelect(uint8_t color1, uint8_t color2);
void slideLEDs (uint8_t color1, uint8_t color2);
void ledTwinkle(void);
void blinkLEDs(uint8_t color1, uint8_t color2, uint8_t blinks);
void setXLEDs (uint8_t color1, uint8_t color2, uint8_t x);
void setXLEDs (uint8_t color1, uint8_t color2);


void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 800);
  FastLED.clear();
  FastLED.show();
  Serial.begin(9600);
  //setLEDs2EveryOther(PURPLE, PURPLE); 
  setXLEDs(ORANGE, PURPLE, 4);

}
/////////////////////////////////////////////////////////////////////////////////////
/////// halloween Main
/////////////////////////////////////////////////////////////////////////////////////
void loop() 
{
  
  slideXLEDs(ORANGE, PURPLE, 5000);//150 ms per run 6.1 times per second => 5000/6.1 gives about 13.7 minutes 
  
  while(runCnt<5000)
  {
    chatter(); //200 ms per run 5 times a second => 5000 gives 16.6 minutes typical 
    runCnt++;
  }
  runCnt=0;

  
  
}


/////////////////////////////////////////////////////////////////////////////////////
/////// Christmas Main
/////////////////////////////////////////////////////////////////////////////////////
/*
void loop() {

    //slideLEDs(WHITE, RED, NUM_LEDS);
    //slideLEDs(GREEN, RED, NUM_LEDS);
    //slideLEDs(WHITE, RED, NUM_LEDS);
    //slideLEDs(WHITE, BLUE, NUM_LEDS); 
    
  /*while(runCnt<50000)
  {
    ledTwinkle();
    runCnt++;
  }
  runCnt=0;
  */
/*
  slideLEDs(WHITE, BLUE, NUM_LEDS); 
  blinkLEDs(WHITE, BLUE, 5);
  slideLEDs(WHITE, BLUE, 3);
  blinkLEDs(WHITE, BLUE, 5);
  blinkLEDs(WHITE, RED, 3);
  slideLEDs(WHITE, RED, 20);
  blinkLEDs(WHITE, RED, 3);
  //slideLEDsBack(WHITE, RED, 10);
  blinkLEDs(WHITE, RED, 3);
  blinkLEDs(GREEN, RED, 6);
  blinkLEDs(WHITE, RED, 3);
*/


