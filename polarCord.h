#ifndef __PolarCord__

#define __PolarCord__

class PolarCord{

  public:
    PolarCord(float distance, float angle);
    float readDistance();
    float readAngle();
    
  private:
    float distance;
    float angle;
  };

#endif
