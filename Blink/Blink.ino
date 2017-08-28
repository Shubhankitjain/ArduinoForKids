// Blinking led on pin 13

void setup()
{
  pinMode(13, OUTPUT);      // Configuring pin 13 to behave as output pin
}

void loop() 
{
  digitalWrite(13, HIGH);   // turn the LED off by making the voltage HIGH
  delay(1000);              // wait for 1000 milliseconds (1 second)
  
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for 1000 milliseconds (1 second)
}
