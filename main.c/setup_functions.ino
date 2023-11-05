/////////////////////////////////////////////////////////////////////////////////////
///////
/////////////////////////////////////////////////////////////////////////////////////
void colorSelect(uint8_t color1, uint8_t color2)
{
  //Serial.println("setting colors");
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
    case PURPLE: 
        r1 = 255; g1 = 0; b1 = 255; 
    break;
    case ORANGE: 
        r1 = 255; g1 = 75; b1 = 0;
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
    case PURPLE: 
        r2 = 255; g2 = 0; b2 = 255;
    break;
    case ORANGE:
        r2 = 255; g2 = 75; b2 = 0;
    break;

  }

}

/////////////////////////////////////////////////////////////////////////////////////
///////
/////////////////////////////////////////////////////////////////////////////////////

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


/////////////////////////////////////////////////////////////////////////////////////
///////
/////////////////////////////////////////////////////////////////////////////////////
void setXLEDs (uint8_t color1, uint8_t color2, uint8_t x)
{
  colorSelect(color1, color2);
  
        for(int i=0; i < NUM_LEDS; i=i+8)
        {
            for(uint8_t j=0; j<x; j++)
              leds[i+j]=CRGB(r1, g1, b1);
        
            for(uint8_t j=4; j<x*2; j++)
              leds[i+j]=CRGB(r2, g2, b2);
        }
        FastLED.show();   

}