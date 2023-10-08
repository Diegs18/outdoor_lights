void chatter (void)
{
  uint8_t randi, randj;
  setLEDs2EveryOther(PURPLE, PURPLE);
  randi = random(200);
  delay(randi);

  randj = random (50);
  if (randj < 5)
    randj = 5;
  randi = random(255-randj);
  
  
  for(uint8_t i=randi; i<randi+randj; i++)
  {
    leds[i]=CRGB(255, 255, 255);
  }
  FastLED.show();
  randi = random(200);
  delay(randi);

}

