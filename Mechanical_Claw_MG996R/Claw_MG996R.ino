#include<Servo.h>
Servo claw;

void setup()
{
	claw.attach(6);
}

void OpenClaw()
{
	claw.write(90);
}

void CloseClaw()
{
	claw.write(120);
}

void loop()
{

OpenClaw();
delay(1000);
CloseClaw();
delay(1000);

}