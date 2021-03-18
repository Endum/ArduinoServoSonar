#ifndef __SONAR__
#define __SONAR__
#include <Arduino.h>

class Sonar {
public:
    Sonar(int echo, int trig, int measures);
    void initDevice();
    float getDistance();
private:
    int echo;
    int trig;
    int measures;
};

#endif
