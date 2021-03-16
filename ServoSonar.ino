#include <Arduino.h>
#include "ServoS.h"
#include "Sonar.h"

#define SERVO 3
#define ECHO 11
#define TRIG 10

ServoS* servo;
Sonar* sonar;

void setup(){
  Serial.begin(9600);
  
  servo = new ServoS(SERVO);
  servo->initDevice();

  sonar = new Sonar(ECHO, TRIG);
  sonar->initDevice();

  // Wait for servo to reset.
  delay(3000);
}

void loop(){
  // Get current distance and angle.
  float curDist = sonar->getDistance();
  int curAngle = servo->getAngle();

  // Send info via serial.
  Serial.print(curDist);
  Serial.write(", ");
  Serial.print(curAngle);
  Serial.write("\n");

  // Update servo.
  bool over = servo->nextStep();

  if(over){
    Serial.write("Cycle over\n");
  }
}
