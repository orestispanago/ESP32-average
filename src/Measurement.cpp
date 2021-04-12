#include "Arduino.h"
#include "Measurement.h"

Measurement::Measurement()
{
}

float Measurement::getCurrent()
{
    return _current;
}

float Measurement::getTotal()
{
    return _total;
}

float Measurement::getAverage()
{
    return _average;
}

long Measurement::getCount()
{
    return _count;
}

void Measurement::update(float newVal)
{
    _count++;
    _total = _total + newVal;
    _current = newVal;
    _average = (_total / _count);
}
void Measurement::reset()
{
    _total = 0.0;
    _count = 0.0;
}

String Measurement::toString()
{
    return "Measurement: { _count: " + String(_count) + "," +
           " _current: " + String(_current) + "," +
           " _total: " + String(_total) + "," +
           " _average: " + String(_average) + "}";
}