// Copyright SKJ Technologies Pvt Ltd.
// Licensed under MIT licence
// fun2dolabs.org

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

// Variable for hold bluetooth data
char data ;

void setup()
{
  Serial.begin(9600);

  motor1.setSpeed(250);
  motor1.run(RELEASE);

  motor2.setSpeed(250);
  motor2.run(RELEASE);
}

void forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void backward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void left()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}

void right()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}

void loop()
{
   // Check if data exist
   if(Serial.available() > 0)
   {
     // Read the data
     data = Serial.read();

     if(data == '0')              // Check if input = 0
     {
       forward();
     }
     else if(data == '1')         // Check if input = 1
     {
       backward();
     }
     else if(data == '2')         // Check if input = 2
     {
       left();
     }
     else if(data == '3')         // Check if input = 3
     {
       right();
     }
   }
}
