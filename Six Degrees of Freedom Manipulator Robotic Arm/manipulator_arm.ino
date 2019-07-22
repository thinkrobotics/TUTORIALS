#include<Servo.h>
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;

void J1Left()
{
  s1.write(120);
}

void J1Center()
{
  s1.write(65);
}

void J1Right()
{
  s1.write(10);
}

void J2Back()
{
  s2.write(0);
}

void J2Center()
{
  s2.write(35);
}

void J2Forw()
{
  s2.write(45);
}

void J3Up()
{
  s3.write(180);
}

void J3Center()
{
  s3.write(145);
}

void J3Down()
{
  s3.write(110);
}

void J4Up()
{
  s4.write(50);
}

void J4Center()
{
  s4.write(120);
}

void J4Down()
{
  s4.write(150);
}

void J5Left()
{
  s5.write(5);
}

void J5Center()
{
  s5.write(85);
}

void J5Right()
{
  s5.write(175);
}

void J6Open()
{
  s6.write(40);
}

void J6Close()
{
  s6.write(80);
}

void Init()
{
  J1Center();
  J3Center();
  J2Back();
  J3Down();
  J4Center();
  J5Center();
  J6Open();
  delay(2000);
}

void Ready()
{
  J2Forw();
  J3Center();
  delay(1000);
  J3Up();
  delay(1000);
}

void Pick()
{
  J1Left();
  delay(600);
  J3Center();
  delay(600);
  J4Down();
  delay(600);
  J6Close();
  delay(600);
  J2Center();
  delay(600);
  J4Center();
  delay(600);
  J3Center();
  delay(600);
  J3Up();
  delay(600);
  J1Center();
  delay(1000);
}

void Drop()
{
  J1Right();
  delay(600);
  J3Center();
  delay(600);
  J4Down();
  delay(600);
  J6Open();
  delay(600);
  J4Center();
  delay(600);
  J3Center();
  delay(600);
  J3Up();
  delay(600);
  J1Center();
  delay(600);
}

void setup()
{
  s1.attach(3);
  s2.attach(5);
  s3.attach(6);
  s4.attach(9);
  s5.attach(10);
  s6.attach(11);
  Init();
  Ready();
  Pick();
  Drop();
  Init();
}

void loop()
{
}