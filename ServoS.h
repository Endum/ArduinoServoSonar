#ifndef __ServoS__

#define __ServoS__
#include <Arduino.h>
#include <Servo.h>
#include "PolarCord.h"

class ServoS{

	public:
	  ServoS(int pin);
	  void initDevice();
	  void reset();
    

	private:
	  Servo myservo;
	  int pin;
	};

#endif
