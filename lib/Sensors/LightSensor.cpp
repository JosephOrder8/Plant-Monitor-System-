#include "LightSensor.h"
#include <pin_config.h>

void LightSensor::begin() 
{
    pinMode(ArduinoPins::LIGHT_SENSOR_PIN, INPUT);
}

int LightSensor::read() 
{
    return analogRead(ArduinoPins::LIGHT_SENSOR_PIN);
}

void LightSensor::status(int value)
{
  if (value >= 30 && value <= 50) 
  {
    Serial.print("Dark:");
  } 
  else if (value > 50 && value <= 500) 
  {
    Serial.print("Dim:");
  } 
  else if (value > 500 && value <= 800) 
  {
    Serial.print("Light:");
  } 
  else if (value > 800 && value <= 1023) 
  {
    Serial.print("Bright:");
  } 
  else 
  {
    Serial.print("Something went wrong value is out of range: ");
  }
  Serial.println(String(value));
}