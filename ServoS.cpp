#include <Arduino.h>
#include "ServoS.h"

ServoS::ServoS(int pin){
  this->pin = pin;
}

void ServoS::initDevice(){
  this->myservo.attach(this->pin);
}
void ServoS::setAngle(int angle){
  this->myservo.write(angle);
