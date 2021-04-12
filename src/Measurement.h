#ifndef Measurement_h
#define Measurement_h

#include "Arduino.h"

class Measurement
{
public:
    Measurement();
    float getCurrent();
    float getTotal();
    float getAverage();
    long getCount();
    void update(float newVal);
    void reset();
    String toString();
private:
    float _current;
    float _total;
    float _average;
    long _count;
};

#endif