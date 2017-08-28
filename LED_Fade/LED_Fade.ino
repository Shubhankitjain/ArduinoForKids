// Fade

int brightness = 0;     // variable for setting brightness of LED
int fadeAmount = 5;     // how much to fade the LED by

void setup()
{
  pinMode(11, OUTPUT);   // output pin
}

void loop() 
{
  analogWrite(11, brightness);            // set the brightness value to pin 11

  brightness = brightness + fadeAmount;   // change the brightness for next time through the loop

  // reverse the direction of the fading at the ends of the fade
  if (brightness < 0 || brightness > 255)
  {
    fadeAmount = -fadeAmount;
  }
  
  // wait for 100 milliseconds
  delay(100);
}
