#ifndef __ServoS__

#define __ServoS__
#include <Arduino.h>
#include <Servo.h>

#define STARTSS 10
#define ENDSS 160

class ServoS{

	public:
	  ServoS(int pin);
	  void initDevice();
	  void reset();
    bool nextStep();
    int getAngle();

	private:
	  Servo myservo;
    int servoPin;
    int angle;
    int direc;
	};

#endif
