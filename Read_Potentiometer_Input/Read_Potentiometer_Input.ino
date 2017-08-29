void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Attach center pin to A0
  int sensorValue = analogRead(A0);
  
  // print the value
  Serial.println(sensorValue);
  delay(1);
}
