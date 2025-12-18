#include <Arduino.h>
#include "LightSensor.h"

LightSensor lightsensor;

void setup() 
{
  Serial.begin(9600);
  lightsensor.begin();
}

void loop() 
{
  float light = lightsensor.read();
  lightsensor.status(light);
  delay(1000);
}