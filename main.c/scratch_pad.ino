
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

}*/