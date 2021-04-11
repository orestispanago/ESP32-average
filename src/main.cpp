#include <Arduino.h>

long uploadInterval = 10000;
long lastUploadMillis;

long readInterval = 1000; // milliseconds
long lastReadMillis;
long count;
float currentValue;
float total;
float average;


void setup()
{
  Serial.begin(9600);
}

void read()
{
  if (millis() - lastReadMillis > readInterval)
  {
    count++;
    currentValue = hallRead();
    total = total + currentValue;
    average = total / count;

    lastReadMillis = millis();

    Serial.print(count);
    Serial.print(" ");
    Serial.print(currentValue);
    Serial.print(" ");
    Serial.print(total);
    Serial.print(" ");
    Serial.println(average);

    delay(readInterval);
  }
}

void upload()
{
}
void loop()
{
  read();
  if (millis() - lastUploadMillis > uploadInterval)
  {
    lastUploadMillis = millis();
    Serial.print("Uploaded: ");
    Serial.println(average);
    total = 0;
    count = 0;
  }
}