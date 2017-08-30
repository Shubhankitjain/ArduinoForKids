// Motor Driver contain 4 pin (m1a, m1b, m2a, m2b) for arduino
// Assign pin (8 to 11) to arduino 
int m1a = 8 ;
int m1b = 9 ;

int m2a = 10 ;
int m2b = 11 ;

void setup()
{
  Serial.begin(9600);
  
  pinMode(m1a, OUTPUT) ;
  pinMode(m1b, OUTPUT) ;
  pinMode(m2a, OUTPUT) ;
  pinMode(m2b, OUTPUT) ;
}

// Forward direction for car
void forward()
{
  digitalWrite(m1a, LOW);  
  digitalWrite(m1b, HIGH);

  digitalWrite(m2a, HIGH);  
  digitalWrite(m2b, LOW); 
}

// Back direction for car
void back()
{
  digitalWrite(m1a, HIGH);  
  digitalWrite(m1b, LOW);

  digitalWrite(m2a, LOW);  
  digitalWrite(m2b, HIGH);
}

// Left direction for car
void left()
{
  setDirection("left", "back");
  setDirection("right", "forward");
}

// Right direction for car
void right()
{
  setDirection("left", "forward");
  setDirection("right", "back");
}

// Stop method
void stop(String motor)
{
  if(motor == "left")
  {
    digitalWrite(m1a, LOW);  
    digitalWrite(m1b, LOW);
  }
  else
  {
    digitalWrite(m2a, LOW);  
    digitalWrite(m2b, LOW);
  }
}

void loop()
{
  forward();
  delay(3);
  back(3);
  delay(1);
  left();
  delay(2);
  right();
  delay(2);
}
