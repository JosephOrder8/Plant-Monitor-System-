#include <Arduino.h>  // Default Arduino library
#include "LightSensor.h"
#include "TempSensor.h"

// Create instances of the sensor classes
LightSensor lightsensor;
TempSensor tempsensor;

void setup() 
{
  Serial.begin(9600);
  //lightsensor.begin();
  tempsensor.begin();
}

void loop() 
{
  // Light sensor
  //float light = lightsensor.read();
  //lightsensor.status(light);

  // Tempterature and humidity 
  float temp = tempsensor.readtemp();
  float hum = tempsensor.readhumidity();
  tempsensor.status(hum, temp);
}