#include "MoistureSensor.h"
#include <pin_config.h>

int soilMoistureValue = 0;  // Variable to store sensor readings
const int AirValue =584;    // you need to change this value that you had recorded in the air
const int WaterValue = 280; // you need to change this value that you had recorded in the water
int intervals =(AirValue-WaterValue)/3; 

void MoistureSensor::begin() 
{
    pinMode(ArduinoPins::SOIL_MOISTURE_PIN, INPUT);
}

int MoistureSensor::read() 
{
    return analogRead(ArduinoPins::SOIL_MOISTURE_PIN);
}

void MoistureSensor::status(int soilMoistureValue)
{
    if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
    {
        Serial.print("Very Wet: ");
    }
    else if(soilMoistureValue>(WaterValue+intervals)&& soilMoistureValue<(AirValue-intervals))
    {
        Serial.print("Wet: ");
    }
    else if(soilMoistureValue < AirValue && soilMoistureValue >(AirValue-intervals))
    {
        Serial.print("Dry: ");
    }
    else 
    {
        Serial.print("Something went wrong: ");
    }
    Serial.println(String(soilMoistureValue));
    
    delay(1000);
}