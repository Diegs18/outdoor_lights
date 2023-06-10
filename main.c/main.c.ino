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


  uint8_t whiteVal [NUM_LEDS];
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

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 800);
  FastLED.clear();
  FastLED.show();
  Serial.begin(9600);
  setLEDs2EveryOther(GREEN, RED); 

}
void loop() {

    slideLEDs(WHITE, RED, NUM_LEDS);
    slideLEDs(GREEN, RED, NUM_LEDS);
    slideLEDs(WHITE, RED, NUM_LEDS);
    slideLEDs(WHITE, BLUE, NUM_LEDS); 
    
  while(runCnt<50000)
  {
    ledTwinkle();
    runCnt++;
  }
  runCnt=0;
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
}
void blinkLEDs(uint8_t color1, uint8_t color2, uint8_t blinks)
{
  for(uint8_t i = blinks; i>0; i--)
  {
    setLEDs2EveryOther(color1, color2);
    delay(200);
    setLEDs2EveryOther(OFF, OFF);
    delay(200);
  }
  setLEDs2EveryOther(color1, color2);
  
}
/*
void ledPulse(uint8_t color1, uint8_t color2, uint8_t speed)
{
  uint8_t flip =0, upDown = 0;
  int run = 254; 
  
  uint8_t gVal[NUM_LEDS];
  uint8_t bVal[NUM_LEDS];
  setLEDs2EveryOther(color1, color2);
  while(run<255)
  {
    for(int i = 0; i<NUM_LEDS; i++)
    {
      if(flip)
      {
        rVal[i] = r1;
        gVal[i] = g1;
        bVal[i] = b1;
        leds[i]=CRGB(r1, g1, b1);
      }
      else
      {
        rVal[i] = r2;
        gVal[i] = g2;
        bVal[i] = b2;
        leds[i]=CRGB(r2, g2, b2);
      }
      flip ^= 1; 
    }
    FastLED.show();
    if(upDown)
    {
      if(r1)
        r1+=speed;
      if(g1)
        g1+=speed; 
      if(b1)
        b1+=speed;
      if(r2)
        r2+=speed;
      if(g2)
        g2+=speed; 
      if(b2)
        b2+=speed; 
      run+=speed; 
    }
    else
    {
      if(r1)
        r1-=speed;
      if(g1)
        g1-=speed; 
      if(b1)
        b1-=speed;
      if(r2)
        r2-=speed;
      if(g2)
        g2-=speed; 
      if(b2)
        b2-=speed;
      run-=speed; 
    }
    if(run<=speed)
      upDown = 1; //1 = up 
    FastLED.show();
  }


  


}*/

void ledTwinkle(void)
{

  //uint8_t whiteVal [NUM_LEDS];
  //uint8_t upDown   [NUM_LEDS]; //0 means up and 1 means down
  //colorSelect(WHITE, WHITE);
  if(!ran)
  {
    for(int i=0; i<NUM_LEDS; i++)
    {
      whiteVal[i] = random(255); 

      leds[i]=CRGB(whiteVal[i], whiteVal[i], whiteVal[i]);
    }
    FastLED.show();
    ran = 1; 
  }
  for(int i=0; i<NUM_LEDS; i++)
  {
      /*if(whiteVal[i]==255)
      {
        upDown[i] = 1;
      }
      else if(whiteVal[i]==0)
      {
        if(ran&2) //let some of them overflow
          upDown[i] = 0;
        ran^=2; 
      }
      if(upDown[i]==0) //if getting brighter
        whiteVal[i]++;
      else //if LED is getting dimmer*/
        whiteVal[i]--;
      leds[i]=CRGB(whiteVal[i], whiteVal[i], whiteVal[i]);
  }
  FastLED.show();
}
void setLEDs2EveryOther(uint8_t color1, uint8_t color2)
{
  uint8_t flip = 0; 
  colorSelect(color1, color2);
    for(int i=0; i<NUM_LEDS;i++)
    {
      if(flip)
      { 
        leds[i]=CRGB(r1, g1, b1);
      }
      else
      {
        leds[i]=CRGB(r2, g2, b2);
      }
      flip ^= 1;
    }
      FastLED.show();
}


void colorSelect(uint8_t color1, uint8_t color2)
{

  switch(color1)
  {
    case OFF:
      r1 = 0; g1 = 0; b1 = 0;
    break; 
    case WHITE: 
      r1 = 255; g1 = 255; b1 = 255; 
    break; 
    case RED: 
      r1 = 255; g1 = 0; b1 = 0; 
    break;
    case GREEN: 
        r1 = 0; g1 = 255; b1 = 0; 
    break;
    case BLUE: 
        r1 = 0; g1 = 0; b1 = 255; 
    break;
  }
  switch(color2)
  {
    case OFF: 
      r2 = 0; g2 = 0; b2 = 0; 
    break; 
    case WHITE: 
      r2 = 255; g2 = 255; b2 = 255; 
    break; 
    case RED: 
      r2 = 255; g2 = 0; b2 = 0; 
    break;
    case GREEN: 
      r2 = 0; g2 = 255; b2 = 0; 
    break;
    case BLUE: 
      r2 = 0; g2 = 0; b2 = 255; 
    break;
  }

}

void slideLEDs (uint8_t color1, uint8_t color2, int slides)
{
  int i, cnt=0; 
  colorSelect(color1, color2);
  i=0;
  while(cnt<slides)
  {
    if(i==NUM_LEDS-1)
    {
        flip^=1;
        if(flip)
            leds[i]=CRGB(r1, g1, b1);
        else
            leds[i]=CRGB(r2, g2, b2);
        FastLED.show();
        i=0;
        cnt++;  
        delay(150);
    }
    leds[i]=leds[i+1]; 
    i++;

    
  }
}
void slideLEDsBack (uint8_t color1, uint8_t color2, int slides)
{
  int i, cnt=0; 
  uint8_t flip = 0; 
  //colorSelect(color1, color2);
  i=0;
  while(cnt<slides)
  {

    //if(i==NUM_LEDS-

        if(flip)
            leds[0]=CRGB(r1, g1, b1);
        else
            leds[0]=CRGB(r2, g2, b2);
      flip^=1;
    for(int j = NUM_LEDS-1; j>=0; j--)
      leds[j]=leds[j-1];
    i++;
    FastLED.show();
    delay(150);
    
  }

}


/*
void debug(void)
{
  Serial.print("r1=");
  Serial.print(r1);
   
  Serial.print("  g1=");
  Serial.print(g1);

  Serial.print("  b1=");
  Serial.print(b1);
  Serial.println(); 

  Serial.print("r2=");
  Serial.print(r2);
   
  Serial.print("  g2=");
  Serial.print(g2);

  Serial.print("  b2=");
  Serial.print(b2);
  
  Serial.println();
  Serial.println();
  Serial.println();

}
*/