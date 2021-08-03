//CODE TO BLINK LED WHEN GAS IS DETECTED

int sensor = A5;     // connect Analog pin to A5
int led = 13;        // Inbuilt Led of arduino 
int sensorThreshold = 400;   //value may vary
void setup() {
  pinMode(sensor,INPUT);  //setting sensor as i/p
  pinMode(led,OUTPUT);     //setting led as o/p
  Serial.begin(9600);
}
void loop() {
  int analogSensor = analogRead(sensor); //reading 
  Serial.print("Pin A0: ");
  Serial.println(analogSensor); 
  // Checks if it has reached the threshold value
   if(analogSensor > sensorThreshold)//gas detected
  {
    digitalWrite(led, HIGH);  //led turns on 
  }
  else
  {
    digitalWrite(led, LOW);  //led turns off
  }
  delay(100);
}
