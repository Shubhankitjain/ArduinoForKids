// Include library
#include <AFMotor.h>

// Assign shield pin
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup()
{
  Serial.begin(9600);

  // Set the speed
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
   forward();
   delay(3);

   backward();
   delay(3);

   left();
   delay(3);

   right();
   delay(3);
}
