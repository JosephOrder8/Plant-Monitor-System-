#include "LightSensor.h"
#include "pin.h"

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
  if (value >= 0 && value <= 50) 
  {
    Serial.println("Dark:"+String(value));
  } 
  else if (value > 50 && value <= 500) 
  {
    Serial.println("Dim:"+String(value));
  } 
  else if (value > 500 && value <= 800) 
  {
    Serial.println("Light:"+String(value));
  } 
  else if (value > 800 && value <= 1023) 
  {
    Serial.println("Bright:"+String(value));
  } 
  else 
  {
    Serial.println("something went wrong");
  }
}