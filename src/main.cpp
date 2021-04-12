#include <Arduino.h>
#include "Measurement.h"

long uploadInterval = 10000;
long lastUploadMillis;

long readInterval = 1000;
long lastReadMillis;

Measurement hallMeasurement;

void setup()
{
  Serial.begin(9600);
  hallMeasurement = Measurement();
}

void loop()
{
  if (millis() - lastReadMillis > readInterval)
  {
    hallMeasurement.update(hallRead());

    Serial.println(hallMeasurement.toString());
    lastReadMillis = millis();

    delay(readInterval);
  }
  if (millis() - lastUploadMillis > uploadInterval)
  {
    lastUploadMillis = millis();
    Serial.print("Uploaded: ");
    Serial.println(hallMeasurement.getAverage());
    hallMeasurement.reset();
  }
}