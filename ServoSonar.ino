#include <Arduino.h>
#include "ServoS.h"
#include "Sonar.h"

#define SERVO 3
#define ECHO 11
#define TRIG 10
#define MEASURES 100
#define WAIT_FOR_SERVO 200

ServoS* servo;
Sonar* sonar;

void setup(){
  Serial.begin(9600);
  
  servo = new ServoS(SERVO);
  servo->initDevice();

  sonar = new Sonar(ECHO, TRIG, MEASURES);
  sonar->initDevice();

  // Wait for servo to reset.
  delay(3000);
}

bool go = 0;

void loop(){
  while(Serial.available()){
    Serial.read();
    go = 1;
  }

  if(go){
    // Get current distance and angle.
    float curDist = sonar->getDistance();
    int curAngle = servo->getAngle();
  
    // Send info via serial.
    //Serial.write("[");
    Serial.print(curDist);
    Serial.write(",");
    Serial.print(curAngle);
    Serial.write("\n");
  
    // Update servo.
    bool over = servo->nextStep();

    // Wait for servo to stop.
    delay(WAIT_FOR_SERVO);
  
    if(over){
      Serial.write("Cycle over\n");
      go = 0;
    }
  }
}
