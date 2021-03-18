#include <Arduino.h>
#include "Sonar.h"

const float vs = 331.5 + 0.6*20;

Sonar::Sonar(int echo, int trig, int measures){
      this->echo = echo;
      this->trig = trig;
      this->measures = measures;
}

float Sonar::getDistance(){
  float sum = 0;
  for(int i = 0; i < this->measures; i++){
     digitalWrite(trig,LOW);
     delayMicroseconds(5);
     digitalWrite(trig,HIGH);
     delayMicroseconds(10);
     digitalWrite(trig,LOW);
     // Echo received.
     float tUS = pulseIn(echo, HIGH);
     float t = tUS / 1000.0 / 1000.0 / 2;
     float d = t*vs;
     sum += d * 100; // Aggregate value in cm.
  }
  return sum / this->measures;
}

void Sonar::initDevice(){
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}
