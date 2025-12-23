#include <Arduino.h>  // Default Arduino library
#include "LightSensor.h"
#include "TempSensor.h"
#include "MoistureSensor.h"
#include "SerialDisplay.h"

// Create instances of the sensor classes
LightSensor lightsensor;
TempSensor tempsensor;
MoistureSensor moisturesensor;
SerialDisplay display;

void setup() 
{
  Serial.begin(9600);
  
  lightsensor.begin();
  tempsensor.begin();
  moisturesensor.begin();
}

void loop() 
{
  // Light sensor
  float light = lightsensor.read();
  //lightsensor.status(light);

  // Tempterature and humidity 
  float temp = tempsensor.readtemp();
  float hum = tempsensor.readhumidity();
  //tempsensor.status(hum, temp);

  // Moisture sensor
  float moisture = moisturesensor.read();
  // moisturesensor.status(moisture);
  display.printSerialData(light, moisture, temp, hum);
}