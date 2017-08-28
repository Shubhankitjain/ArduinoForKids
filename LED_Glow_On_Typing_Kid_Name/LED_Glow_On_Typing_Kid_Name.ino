
 //LED_Glow_On_Typing_Kid_Name

int incomingByte;           // variable for storage incoming serial data into

void setup()
{
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);      // LED pin
}

void loop()
{
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    
    // check, if H/(ASCII 72), turn on the LED:
    if (incomingByte == 'H')
    {
      digitalWrite(13, HIGH);
    }
    
    // check, if L/(ASCII 76) turn off the LED:
    if (incomingByte == 'L')
    {
      digitalWrite(13, LOW);
    }
  }
}
