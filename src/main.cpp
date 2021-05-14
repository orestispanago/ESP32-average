#include <Arduino.h>
#include "Measurement.h"

unsigned long currentMillis;

unsigned long uploadInterval = 10000;
unsigned long lastUploadMillis;

unsigned long readInterval = 1000;
unsigned long lastReadMillis;

Measurement hallMeasurement;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  currentMillis = millis();
  if (currentMillis - lastReadMillis > readInterval)
  {
    hallMeasurement.sample(hallRead());
    hallMeasurement.print();
    lastReadMillis = currentMillis;
  }
  currentMillis = millis();
  if (currentMillis - lastUploadMillis > uploadInterval)
  {
    Serial.print("Uploaded: ");
    Serial.println(hallMeasurement.mean());
    hallMeasurement.reset();
    lastUploadMillis = currentMillis;
  }
}