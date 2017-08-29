void setup()
{
  Serial.begin(9600);

  // Assign arduino pin
  pinMode(2, INPUT);
}

void loop()
{
  // get the button state
  int buttonState = digitalRead(2);
  
  // print the value of button state
  Serial.println(buttonState);
  delay(1);
}
