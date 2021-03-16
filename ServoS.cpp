#include <Arduino.h>
#include "ServoS.h"

ServoS::ServoS(int servoPin){
  this->servoPin = servoPin;
}

void ServoS::initDevice(){
  this->myservo.attach(this->servoPin);
  this->reset();
}
void ServoS::reset(){
  this->angle = STARTSS;
  this->myservo.write(STARTSS);
  this->direc = 1;
}

bool ServoS::nextStep(){
  this->angle += this->direc;

  // For the sake of readability.
  if(angle == STARTSS)
    this->direc = 1;
  if(this->angle == ENDSS)
    this->direc = -1;

  // Update servo.
  this->myservo.write(this->angle);

  // If true a cycle is over.
  return this->angle == STARTSS || this->angle == ENDSS;
}

int ServoS::getAngle(){
  return this->angle;
}
