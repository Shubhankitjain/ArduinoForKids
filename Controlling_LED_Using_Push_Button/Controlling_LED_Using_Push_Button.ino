// Controlling LED Using Push Button

int buttonState     = 0;        // variable for reading the button state

void setup()
{
  pinMode(2, OUTPUT);           // set LED pin
  pinMode(12, INPUT);           // set button pin
}

void loop()
{
  // read the state of button
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if button is pressed, set buttonState is HIGH
  
  if (buttonState == HIGH)
  {
    digitalWrite(ledPin, HIGH);     // set the LED to on
  }
  else
  {
    digitalWrite(ledPin, LOW);      // set the LED to off
  }
}
