  uint8_t whiteVal [NUM_LEDS];
  //uint8_t whiteVal;
/////////////////////////////////////////////////////////////////////////////////////
///////
/////////////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////////////
///////
/////////////////////////////////////////////////////////////////////////////////////

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


/////////////////////////////////////////////////////////////////////////////////////
///////
/////////////////////////////////////////////////////////////////////////////////////


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

void slideXLEDs (uint8_t color1, uint8_t color2, int slides)
{
  uint8_t x = 4;
  int i, cnt=0; 
  colorSelect(color1, color2);
  i=0;
  while(cnt<slides)
  {
    if(i==NUM_LEDS-1)
    {
        if(cnt%x==0)
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

/////////////////////////////////////////////////////////////////////////////////////
///////
/////////////////////////////////////////////////////////////////////////////////////