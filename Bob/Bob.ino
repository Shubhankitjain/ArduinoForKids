#include <Servo.h>
#include <SoftwareSerial.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

long gmotor,gnum1,gnum2;

int pos, pos2;
int flag = 0; 
int poss1, poss2, poss3, poss4;

void setup() 
{
   servo1.attach(3);
   servo2.attach(5);
   servo4.attach(9);
   servo5.attach(10);

   // setting servo default angle
   servo1.write(110);
   servo2.write(100);
   servo4.write(90);
   servo5.write(80);
   
   Serial.begin(19200);
}

void call(int motor, int num1, int num2)
{
  switch (motor)
  {  
      case 1:
      {
        if(num1<num2)
        {
          for (pos = num1; pos <= num2; pos+=1)
          {
            servo1.write(pos);
            delay(20);
          }
        }
        if(num1 > num2)
        {
          for (pos = num1; pos>=num2; pos-=1)
          {
            servo1.write(pos);
            delay(20);
          }
        }
          
        break;
     }     
    
    case 2:
      {
        if(num1 < num2)
        {
          for (pos = num1; pos <= num2; pos+=1)
          {
            servo2.write(pos);
            delay(20);
          }
        }
        if(num1 > num2)
        {
          for ( pos = num1; pos>=num2; pos-=1)
          {
            servo2.write(pos);
            delay(20);
          }
        }
      
        break;
     }     
            
    case 4:
    {
      if(num1 < num2)
      {
        for ( pos = num1; pos<=num2; pos+=1)
        {
          servo4.write(pos);
          delay (20);
        }
      }
      
      if(num1 > num2)
      {
        for ( pos = num1; pos >= num2; pos-=1)
        {
          servo4.write(pos);
          delay (20);
        }
      }
      
      break;
    }
      
    case 5:
    {
      {
        for ( pos = num1; pos<=num2; pos+=1)
        if(num1<num2)
        {
          servo5.write(pos);
          delay (20);
        }
      }
      
      if(num1>num2)
      {
        for ( pos = num1; pos>=num2; pos-=1)
        {
          servo5.write(pos);
          delay (20);
        }
      }
      
      break;
    }
  }
}

void loop()
{  
  walk1();
}
 
void stay_put()
{
   servo5.attach(10);
   servo1.write(110);
   servo2.write(100);
   servo4.write(90);
   servo5.write(80);
   
   delay(20);
}

void left_leg_up()
{
  poss1 = 80;
  poss2 = 110;
  
  do
  {
    servo5.write(poss1);
    servo4.write(poss2);
    poss1++;
    poss2++;
    delay(20);
  }
  
  while(poss1 < 100 || poss2 < 140);
 
  call(4,130,100);
}

void right_leg_up()
{
  poss1 = 80;
  poss2 = 100;
  
  do
  {
    servo4.write(poss2);
    servo5.write(poss1);
    poss1--;
    poss2--;
    
    delay(20);
  }
   
  while(poss1 > 50 || poss2 > 60);
  
  call(5,50,80);
}

void move_left_front()
{
  poss1 = 120;
  poss2 = 110;
  poss3 = 110;
  
  do
  {
    servo2.write(poss1);
    servo1.write(poss2);
    servo5.write(poss3);
    
    poss1--;
    poss2--;
    poss3--;
    
    delay(20);
  }
   
  while(poss1 > 100 || poss2 > 80 || poss3 > 80);
}

void move_right_front()
{
    poss1 = 80;
    poss2 = 100;
    poss3 = 60;
    
    do
    {
      servo1.write(poss1);
      servo2.write(poss2);
      servo4.write(poss3);
      
      poss1++;
      poss2++;
      poss3++;
      
      delay(20);
    }
    
    while(poss1 < 110 || poss2 < 120 || poss3 < 90);
}

void walk1()
{
  stay_put();
  
  char temp = 15; //number of steps to make * 2
  
  do
  {
    right_leg_up();
    move_right_front();
    left_leg_up();
    move_left_front();  
    
    temp--;
  }
  
  while(temp > 0);
}
