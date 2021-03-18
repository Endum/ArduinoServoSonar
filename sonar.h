#ifndef __SONAR__
#define __SONAR__
#include <Arduino.h>

// Means max 5 meters.
#define TIMEOUT 30000

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
