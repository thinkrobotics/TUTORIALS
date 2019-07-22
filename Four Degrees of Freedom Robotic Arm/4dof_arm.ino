#include<Servo.h>
Servo s1;
Servo s2;
Servo s3;
Servo s4;
int s1angle = 95;
int s2angle = 80;
int s3angle = 30;
int s4angle = 90;

void ServoControl(Servo k, int startangle, int stopangle, int speedangle)
{
  if (startangle < stopangle)
    for (int i = startangle; i <= stopangle; i++)
    {
      k.write(i);
      delay(1000 / speedangle);
    }
  else
    for (int i = startangle; i >= stopangle; i--)
    {
      k.write(i);
      delay(1000 / speedangle);
    }
  k.write(stopangle);
}

void Left()
{
  ServoControl(s1, s1angle, 180, 80);
  s1angle = 180;
}

void Center()
{
  ServoControl(s1, s1angle, 95, 80);
  s1angle = 95;
}

void Right()
{
  ServoControl(s1, s1angle, 10, 80);
  s1angle = 10;
}

void Up()
{
  ServoControl(s2, s2angle, 140, 80);
  s2angle = 140;
}

void Down()
{
  ServoControl(s2, s2angle, 80, 80);
  s2angle = 80;
}
 
void Forw()
{
  ServoControl(s3, s3angle, 70, 80);
  s3angle = 70;
}

void Back()
{
  ServoControl(s3, s3angle, 40, 80);
  s3angle = 30;
}

void Open()
{
  ServoControl(s4, s4angle, 90, 80);
  s4angle = 90;
}

void Close()
{
  ServoControl(s4, s4angle, 52, 80);
  s4angle = 52;
}

void Init()
{
  Center();
  Down();
  Back();
  Open();
  delay(1000);
}
void setup()
{
  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);
  Init();
}

 

void loop()
{
  Left();
  delay(500);
  Center();
  delay(500);
  Right();
  delay(500);
  Center();
  delay(500);
  Forw();
  delay(500);
  Back();
  delay(500);
  Up();
  delay(500);
  Down();
  delay(500);
  Close();
  delay(500);
  Open();
  delay(500);
}